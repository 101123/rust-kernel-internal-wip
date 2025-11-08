#include "hooks.h"
#include "global.h"	
#include "cheat/cheat.h"
#include "cheat/sdk/sdk.h"
#include "cheat/entities.h"
#include "cheat/glow.h"
#include "cheat/aimbot.h"
#include "cheat/features.h"
#include "notifications.h"
#include "gui.h"

void reset_local_player() {
	local_player = {
		.entity = nullptr,
		.eyes = nullptr,
		.eyes_position = vector3(),
		.body_forward = vector3(),
		.held_item = nullptr,
		.held_entity = nullptr
	};
}

bool cache_local_player( rust::base_player* base_player ) {
	rust::player_eyes* eyes = base_player->get_eyes();

	// These must be valid for the local player to be populated
	if ( !is_valid_ptr( eyes ) ) {
		reset_local_player();
		return false;
	}

	rust::item* held_item = base_player->get_held_item();
	rust::held_entity* held_entity = nullptr;

	if ( held_item && is_valid_ptr( held_item->held_entity.ent_cached ) ) {
		held_entity = held_item->held_entity.ent_cached->as<rust::held_entity>();
	}

	local_player.entity = base_player;
	local_player.eyes = eyes;
	local_player.eyes_position = eyes->get_position();
	local_player.body_forward = eyes->body_forward();
	local_player.held_item = held_item;
	local_player.held_entity = held_entity;

	return true;
}

void cache_belt_icons() {
	rust::ui_belt* ui_belt = rust::singleton_component<rust::ui_belt>::static_fields_->instance;
	if ( !is_valid_ptr( ui_belt ) )
		return;

	sys::list<rust::item_icon*>* item_icons_list = ui_belt->item_icons;
	if ( !is_valid_ptr( item_icons_list ) || item_icons_list->size != 6 )
		return;

	sys::array<rust::item_icon*>* item_icons = item_icons_list->items;
	if ( !is_valid_ptr( item_icons ) )
		return;

	for ( int32_t i = 0; i < item_icons_list->size; i++ ) {
		rust::item_icon* item_icon = item_icons->buffer[ i ];
		if ( !is_valid_ptr( item_icon ) )
			continue;

		unity::transform* transform = item_icon->get_transform();
		if ( !is_valid_ptr( transform ) )
			continue;

		if ( i == 0 ) {
			unity::image* background_image = item_icon->background_image;

			if ( is_valid_ptr( background_image ) ) {
				unity::sprite* sprite = background_image->sprite;

				if ( is_valid_ptr( sprite ) ) {
					unity::texture2d* texture = sprite->get_texture();

					if ( is_valid_ptr( texture ) ) {
						belt_icons.background = texture->get_srv();
					}
				}
			}

			// All lossy scales are the same
			belt_icons.lossy_scale = transform->get_lossy_scale();
		}

		belt_icons.positions[ i ] = transform->get_position();
	}
}

void cache_held_entity( rust::item* held_item, rust::base_entity* held_entity ) {
	rust::item_definition* projectile_item_info = nullptr;
	float velocity_scale = 1.f, max_velocity_scale = 1.f;
	bool mod_hash_broken = false;

	if ( auto base_projectile = held_entity->as<rust::base_projectile>() ) {
		if ( base_projectile->cached_mod_hash != held_weapon.mods.hash ) {
			sys::list<rust::base_entity*>* children_list = base_projectile->children;

			if ( is_valid_ptr( children_list ) ) {
				sys::array<rust::base_entity*>* children = children_list->items;

				if ( is_valid_ptr( children ) ) {
					float projectile_velocity_scale = 1.f, aim_sway_scale = 1.f, recoil_scale = 1.f, sight_aim_cone_scale = 1.f, hip_aim_cone_scale = 1.f;

					for ( size_t i = 0; i < children_list->size; i++ ) {
						rust::base_entity* child = children->buffer[ i ];
						if ( !is_valid_ptr( child ) )
							continue;

						auto projectile_weapon_mod = child->as<rust::projectile_weapon_mod>();
						if ( !projectile_weapon_mod )
							continue;

						if ( projectile_weapon_mod->needs_on_for_effects &&
							!projectile_weapon_mod->has_flag( rust::base_entity::flag::on ) )
							continue;

						rust::projectile_weapon_mod::modifier projectile_velocity = projectile_weapon_mod->projectile_velocity;
						rust::projectile_weapon_mod::modifier aim_sway = projectile_weapon_mod->aim_sway;
						rust::projectile_weapon_mod::modifier recoil = projectile_weapon_mod->recoil;
						rust::projectile_weapon_mod::modifier sight_aim_cone = projectile_weapon_mod->sight_aim_cone;
						rust::projectile_weapon_mod::modifier hip_aim_cone = projectile_weapon_mod->hip_aim_cone;

						// TODO: Fix this as it is probably incorrect - the game doesn't use ProjectileWeaponMod.Mult for all of these modifiers
						if ( projectile_velocity.enabled ) {
							projectile_velocity_scale *= projectile_velocity.scalar;
						}

						if ( aim_sway.enabled ) {
							aim_sway_scale *= aim_sway.scalar;
						}

						if ( recoil.enabled ) {
							recoil_scale *= recoil.scalar;
						}

						if ( sight_aim_cone.enabled ) {
							sight_aim_cone_scale *= sight_aim_cone.scalar;
						}

						if ( hip_aim_cone.enabled ) {
							hip_aim_cone_scale *= hip_aim_cone.scalar;
						}
					}

					held_weapon.mods.projectile_velocity_scale = projectile_velocity_scale;
					held_weapon.mods.aim_sway_scale = aim_sway_scale;
					held_weapon.mods.recoil_scale = recoil_scale;
					held_weapon.mods.sight_aim_cone_scale = sight_aim_cone_scale;
					held_weapon.mods.hip_aim_cone_scale = hip_aim_cone_scale;
					held_weapon.mods.hash = base_projectile->cached_mod_hash;

					mod_hash_broken = true;
				}
			}
		}

		rust::base_projectile::magazine* magazine = base_projectile->primary_magazine;
		if ( !is_valid_ptr( magazine ) )
			return;

		rust::item_definition* ammo_type = magazine->ammo_type;
		if ( !is_valid_ptr( ammo_type ) )
			return;

		projectile_item_info = ammo_type;

		// We don't use the compound bow function here as this caching code only runs once and the compound bow velocity scale is dynamic
		velocity_scale = base_projectile->get_projectile_velocity_scale() * held_weapon.mods.projectile_velocity_scale;

		// Maximum velocity scale is a static number, so it's fine to use the compound bow function here
		max_velocity_scale = base_projectile->is<rust::compound_bow_weapon>() ?
			( ( rust::compound_bow_weapon* )base_projectile )->get_projectile_velocity_scale( true ) : base_projectile->get_projectile_velocity_scale();
	}

	else if ( auto base_melee = held_entity->as<rust::base_melee>() ) {
		rust::item_definition* info = held_item->info;
		if ( !is_valid_ptr( info ) )
			return;

		projectile_item_info = info;
	}

	if ( !projectile_item_info || ( ( held_entity->prefab_id == held_weapon.prefab_id && projectile_item_info->item_id == held_weapon.ammo_item_id ) && !mod_hash_broken ) )
		return;

	unity::game_object* container = projectile_item_info->get_game_object();
	if ( !is_valid_ptr( container ) )
		return;

	auto item_mod_projectile = container->get_component<rust::item_mod_projectile>();
	if ( !is_valid_ptr( item_mod_projectile ) )
		return;

	rust::game_object_ref* projectile_object = item_mod_projectile->projectile_object;
	if ( !is_valid_ptr( projectile_object ) )
		return;

	unity::game_object* projectile_container = projectile_object->cached_object;

	// If the reference hasn't been set yet, we can set it ourselves
	if ( !is_valid_ptr( projectile_container ) ) {
		sys::string* guid = projectile_object->guid;

		if ( is_valid_ptr( guid ) ) {
			unity::object* object = rust::game_manifest::guid_to_object( guid );

			if ( is_valid_ptr( object ) ) {
				projectile_object->cached_object = projectile_container = object->as<unity::game_object>();
			}
		}
	}

	if ( !is_valid_ptr( projectile_container ) )
		return;

	auto projectile = projectile_container->get_component<rust::projectile>();
	if ( !is_valid_ptr( projectile ) )
		return;
	
	// Cache unscaled velocity so we can calculate the correct velocity for compound bows 
	held_weapon.unscaled_velocity = item_mod_projectile->projectile_velocity;
	held_weapon.velocity = item_mod_projectile->projectile_velocity * velocity_scale;
	// BasePlayer.NoteFiredProjectile 
	held_weapon.max_velocity = ( ( item_mod_projectile->get_max_velocity() * max_velocity_scale ) * ( 1.f + rust::antihack::projectile_forgiveness ) );
	held_weapon.drag = projectile->drag;
	held_weapon.gravity_modifier = projectile->gravity_modifier;
	held_weapon.initial_distance = projectile->initial_distance;
	held_weapon.prefab_id = held_entity->prefab_id;
	held_weapon.ammo_item_id = projectile_item_info->item_id;
}

void update_velocity_for_compound_bow( rust::compound_bow_weapon* compound_bow ) {
	held_weapon.velocity = held_weapon.unscaled_velocity * compound_bow->get_projectile_velocity_scale() * held_weapon.mods.projectile_velocity_scale;
}

extern bool w2s( const vector3& world, vector2& screen );

float get_distance_to_center_point( const vector2& position ) {
	const vector2 center_point = vector2( ( float )screen_width / 2.f, ( float )screen_height / 2.f );

	return vector2::distance( position, center_point );
}

const std::pair<rust::base_player*, cached_player>* update_target() {
	util::scoped_spinlock lock( &entity_manager::cache_lock );

	entity_collection entity_collection = entity_manager::get_entities();

	const std::pair<rust::base_player*, cached_player>* best_target = nullptr;
	float best_distance = FLT_MAX;

	for ( const auto& entry : entity_collection.players ) {
		const cached_player& cached_player = entry.second;

		vector2 screen;
		if ( !w2s( cached_player.bone_data.positions[ 1 ], screen ) )
			continue;

		float distance = get_distance_to_center_point( screen );
		if ( distance > aimbot.fov || distance > best_distance )
			continue;

		best_target = &entry;
		best_distance = distance;
	}

	aimbot.player_target = best_target ? best_target : nullptr;

	return best_target;
}

void network_client_create_networkable_hook( rust::base_networkable* networkable ) {
	if ( !is_valid_ptr( networkable ) || !is_valid_ptr( networkable->cached_ptr ) )
		return;

	cache_specifier specifier;
	if ( !entity_manager::belongs_in_cache( networkable, &specifier ) )
		return;

	entity_manager::add_to_cache( networkable, &specifier );
}

void network_client_destroy_networkable_hook( rust::base_networkable* networkable ) {
	if ( !is_valid_ptr( networkable ) || !is_valid_ptr( networkable->cached_ptr ) )
		return;

	cache_specifier specifier;
	if ( !entity_manager::belongs_in_cache( networkable, &specifier ) )
		return;

	entity_manager::remove_from_cache( networkable, &specifier );
}

void player_walk_movement_client_input_pre_hook( rust::player_walk_movement* player_walk_movement, rust::input_state* input_state, rust::model_state* model_state ) {
	if ( !is_valid_ptr( player_walk_movement ) || !is_valid_ptr( input_state ) || !is_valid_ptr( model_state ) )
		return;

	if ( player_walk_movement->owner != local_player.entity )
		return;

	if ( no_attack_restrictions.enabled ) {
		player_walk_movement->admin_cheat = no_attack_restrictions.admin_cheat;
	}
}

void player_walk_movement_client_input_post_hook( rust::player_walk_movement* player_walk_movement, rust::input_state* input_state, rust::model_state* model_state ) {
	if ( !is_valid_ptr( player_walk_movement ) || !is_valid_ptr( input_state ) || !is_valid_ptr( model_state ) )
		return;

	if ( player_walk_movement->owner != local_player.entity )
		return;

	if ( no_attack_restrictions.enabled ) {
		player_walk_movement->admin_cheat = true;
	}

	if ( spider_man ) {
		player_walk_movement->ground_angle_new = 0.f;
	}

	if ( no_fall_damage ) {
		
	}

	if ( infinite_jump ) {
		float time = unity::time::get_time();

		player_walk_movement->ground_time = time + 0.2f;
		player_walk_movement->jump_time = time - 1.f;
	}

	if ( omnisprint ) {
		if ( !model_state->has_flag( rust::model_state::flag::flying ) &&
			!model_state->has_flag( rust::model_state::flag::ducked ) &&
			!model_state->has_flag( rust::model_state::flag::crawling ) &&
			model_state->water_level < 0.65f && !player_walk_movement->ladder ) {
			vector3 current_velocity = player_walk_movement->target_movement;

			if ( vector3::magnitude( current_velocity ) > 0.f ) {
				player_walk_movement->target_movement = vector3::normalize( current_velocity ) * local_player.entity->get_speed( 1.f, 0.f, 0.f );
				model_state->set_flag( rust::model_state::flag::sprinting, true );
			}
		}
	}

	if ( speedhack.enabled ) {
		player_walk_movement->target_movement = player_walk_movement->target_movement * speedhack.multiplier;
	}

	if ( on_ladder ) {
		model_state->set_flag( rust::model_state::flag::on_ladder, true );
	}
}

bool test_flying( vector3 old_position, vector3 new_position, bool verify_grounded ) {
	bool in_air = false;

	vector3 mid_point = ( old_position + new_position ) / 2.f;

	if ( !local_player.entity->on_ladder() ) {
		float player_radius = rust::base_player::get_radius();

		vector3 capsule_start = mid_point + vector3( 0.f, player_radius - rust::antihack::flyhack_extrusion, 0.f );
		vector3 capsule_end = mid_point + vector3( 0.f, rust::base_player::get_height( false ) - player_radius, 0.f );

		float check_radius = player_radius - rust::antihack::flyhack_margin;

		in_air = anti_flyhack.in_air = !unity::physics::check_capsule( capsule_start, capsule_end, check_radius, 1503764737, unity::query_trigger_interaction::ignore );
	}

	if ( in_air ) {
		vector3 delta = new_position - old_position;

		float vertical_delta = fabsf( delta.y );
		float horizontal_delta = vector2::magnitude( vector2( delta.x, delta.z ) );

		if ( delta.y >= vector3::epsilon ) {
			anti_flyhack.vertical += delta.y;
			anti_flyhack.max_vertical = rust::base_player::get_jump_height() + rust::antihack::flyhack_forgiveness_vertical;

			if ( anti_flyhack.vertical > anti_flyhack.max_vertical ) {
				return true;
			}
		}

		if ( vertical_delta < horizontal_delta ) {
			anti_flyhack.horizontal += horizontal_delta;
			anti_flyhack.max_horizontal = 5.f + rust::antihack::flyhack_forgiveness_horizontal;

			if ( anti_flyhack.horizontal > anti_flyhack.max_horizontal ) {
				return true;
			}
		}
	}

	else {
		anti_flyhack.vertical = 0.f;
		anti_flyhack.horizontal = 0.f;
	}

	return false;
}

void protobuf_player_tick_write_to_stream_delta_pre_hook( rust::player_tick* player_tick, rust::buffer_stream* stream, rust::player_tick* previous ) {
	if ( !is_valid_ptr( player_tick ) || !is_valid_ptr( stream ) || !is_valid_ptr( previous ) )
		return;

	rust::model_state* model_state = player_tick->model_state;

	if ( is_valid_ptr( model_state ) ) {
		if ( model_state->has_flag( rust::model_state::flag::flying ) ) {
			// We need to set the sprinting flag so we can get maximum speed, but only set it when we're moving so it's more believable
			if ( vector3::sqr_distance( previous->position, player_tick->position ) > 0.f ) {
				model_state->set_flag( rust::model_state::flag::sprinting, true );
			}

			// The detection for this on a vanilla server is gone, but keep it in anyways just in case
			model_state->set_flag( rust::model_state::flag::flying, false );
		}
	}

	player_tick->eye_pos = local_player.eyes_position;

	if ( local_player.entity ) {
		int32_t ideal_view_mode = local_player.entity->get_ideal_view_mode();

		if ( ideal_view_mode == rust::base_player::camera_mode::eyes ) {
			rust::model* model = local_player.entity->model;

			if ( is_valid_ptr( model ) ) {
				unity::transform* eye_bone = model->eye_bone;

				if ( is_valid_ptr( eye_bone ) ) {
					player_tick->eye_pos = eye_bone->get_position();
				}
			}
		}
	}

	float real_time_since_startup = unity::time::get_real_time_since_startup();

	if ( desync.enabled && game_input.get_async_key_state( desync.key ) ) {
		if ( real_time_since_startup - last_sent_tick_time < desync.time ) {
			sys::array<uint8_t>* buffer = stream->buffer;

			if ( is_valid_ptr( buffer ) ) {
				// The first byte of the packet is the packet id, and by setting it to 139, it is silently discarded by the server
				buffer->buffer[ 0 ] = 139;
				return;
			}
		}
	}

	if ( anti_flyhack.enabled && test_flying( previous->position, player_tick->position, true ) ) {
		player_tick->position = previous->position;

		if ( local_player.entity ) {
			rust::player_walk_movement* movement = local_player.entity->movement;

			if ( is_valid_ptr( movement ) ) {
				movement->teleport_to( previous->position, local_player.entity );
				movement->target_movement = vector3();
			}
		}
	}

	last_sent_tick_time = real_time_since_startup;
}

//
#include <algorithm>

class line2 {
public:
	vector3 point0, point1;

	vector3 closest_2d_point( vector3 pos ) {
		vector2 p0_xz( point0.x, point0.z );
		vector2 p1_xz( point1.x, point1.z );
		vector2 pos_xz( pos.x, pos.z );

		vector2 line = p1_xz - p0_xz;
		float len = vector2::magnitude( line );

		if ( len < 0.001f )
			return point0;

		vector2 dir = line / len;
		float proj = vector2::dot( pos_xz - p0_xz, dir );
		float t = std::clamp( proj / len, 0.f, 1.f );

		return point0 + ( point1 - point0 ) * t;
	}

	vector3 closest_point( vector3 pos ) {
		vector3 a = point1 - point0;
		float magnitude = vector3::magnitude( a );
		if ( magnitude < 0.001f ) {
			return point0;
		}

		vector3 vector = a / magnitude;
		return point0 + ( vector * std::clamp( vector3::dot( pos - point0, vector ), 0.f, magnitude ) );
	}

	float distance( vector3 position ) {
		return vector3::magnitude( position - closest_point( position ) );
	}
};

const std::pair<rust::base_player*, cached_player>* get_target_for_projectile( rust::projectile* projectile ) {
	util::scoped_spinlock lock( &entity_manager::cache_lock );

	entity_collection entity_collection = entity_manager::get_entities();

	const std::pair<rust::base_player*, cached_player>* best_target = nullptr;
	float best_distance = 5.f;

	for ( const auto& entry : entity_collection.players ) {
		const cached_player& cached_player = entry.second;
		if ( entry.first == local_player.entity )
			continue;

		float distance = line2( 
			projectile->current_position, 
			projectile->current_position + ( projectile->current_velocity * 0.03125f ) ).distance( cached_player.bone_data.positions[ 1 ] );

		if ( distance < best_distance ) {
			best_target = &entry;
			best_distance = distance;
		}
	}

	return best_target;
}
//

namespace features {
	void on_projectile_update( rust::projectile* projectile ) {
		if ( projectile_tracers.enabled ) {
			unity::instanced_debug_draw* ddraw = rust::singleton_component<unity::instanced_debug_draw>::static_fields_->instance;

			if ( is_valid_ptr( ddraw ) && projectile->previous_position != vector3() ) {
				ddraw->line( projectile->previous_position, projectile->current_position, unity::color( projectile_tracers.color ), projectile_tracers.duration, false, false );
			}
		}

		if ( !bullet_teleport )
			return;

		auto target = get_target_for_projectile( projectile );
		if ( !target )
			return;

		unity::transform* target_transform = target->second.bone_data.transforms[ 1 ];
		if ( !target_transform )
			return;

		vector3 target_position = target->second.bone_data.positions[ 1 ];

		// Divide one normal update representing 0.03125f seconds, into x amount of updates, based on speed
		vector3 start_position = projectile->current_position;
		vector3 projectile_position = projectile->current_position;
		vector3 projectile_velocity = projectile->current_velocity;
		const float dt = 0.03125f / ( vector3::magnitude( projectile_velocity ) * 0.1875f );

		// Simulate each projectile update
		for ( float t = 0.f; t < 0.03125f; t += dt ) {
			// Check if projectile is within teleport range
			float distance = vector3::distance( projectile_position, target_position );
			if ( distance < 2.2f ) {
				// Check if simulated position is visible to previous valid position
				if ( rust::game_physics::line_of_sight( start_position, projectile_position, 1218510848 ) ) {
					vector3 attack_position = vector3::move_towards( projectile_position, target_position, 2.f );

					// Check if simulated position is visible to attack position
					if ( rust::game_physics::line_of_sight( projectile_position, attack_position, 1218510848 ) ) {
						if ( rust::player_projectile_update* player_projectile_update = rust::player_projectile_update::create() ) {
							// We are teleporting the bullet in a simulated update that would lose line of sight from the previous sent position, so it needs to be done here
							if ( !rust::game_physics::line_of_sight( projectile->sent_position, projectile_position, 1218510848 ) ) {
								player_projectile_update->projectile_id = projectile->projectile_id;
								player_projectile_update->cur_position = start_position;
								player_projectile_update->cur_velocity = projectile->current_velocity;
								player_projectile_update->travel_time = projectile->traveled_time;

								local_player.entity->send_projectile_update( player_projectile_update );
							}

							// Move real projectile to simulated projectile
							projectile->current_position = projectile_position;
							projectile->current_velocity = projectile_velocity;
							projectile->traveled_distance += vector3::distance( start_position, target_position );
							projectile->traveled_time += t;

							// Send projectile update at current point in trajectory
							player_projectile_update->projectile_id = projectile->projectile_id;
							player_projectile_update->cur_position = projectile->current_position;
							player_projectile_update->cur_velocity = projectile->current_velocity;
							player_projectile_update->travel_time = projectile->traveled_time;

							local_player.entity->send_projectile_update( player_projectile_update );

							// Send projectile attack
							rust::hit_test hit_test = {};
							hit_test.did_hit = true;
							hit_test.hit_entity = target->first;
							hit_test.hit_transform = target_transform;
							hit_test.hit_point = target_transform->inverse_transform_point( attack_position );
							hit_test.attack_ray = unity::ray( attack_position, vector3::normalize( target_position - attack_position ) );

							projectile->do_hit( &hit_test, hit_test.hit_point, vector3::zero );

							// Cleanup
							player_projectile_update->should_pool = true;
							player_projectile_update->dispose();

							// Kill the projectile
							projectile->integrity = 0.f;
							break;
						}
					}
				}
			}

			// Move projectile along trajectory
			projectile_position += projectile_velocity * dt;
			projectile_velocity.y -= 9.81f * projectile->gravity_modifier * dt;
			projectile_velocity -= projectile_velocity * projectile->drag * dt;
		}
	}
}

void protobuf_projectile_shoot_write_to_stream_pre_hook( rust::projectile_shoot* projectile_shoot, sys::list<rust::projectile*>* created_projectiles, rust::projectile* melee_projectile ) {
	if ( !is_valid_ptr( projectile_shoot ) )
		return;

	sys::list<rust::projectile_shoot::projectile*>* projectiles = projectile_shoot->projectiles;
	if ( !is_valid_ptr( projectiles ) )
		return;

	sys::array<rust::projectile_shoot::projectile*>* server_projectiles = projectiles->items;
	if ( !is_valid_ptr( server_projectiles ) || server_projectiles->size <= 0 || server_projectiles->size > 128 )
		return;

	rust::projectile** client_projectiles = nullptr;

	if ( created_projectiles && is_valid_ptr( created_projectiles ) && is_valid_ptr( created_projectiles->items ) ) {
		client_projectiles = created_projectiles->items->buffer;
	}

	else if ( melee_projectile && is_valid_ptr( melee_projectile ) && melee_projectile->is<rust::projectile>() ) {
		client_projectiles = &melee_projectile;
	}
	
	// What the fuck happened?
	if ( !client_projectiles )
		return;

	for ( size_t i = 0; i < projectiles->size; i++ ) {
		rust::projectile_shoot::projectile* server_projectile = server_projectiles->buffer[ i ];
		if ( !is_valid_ptr( server_projectile ) )
			continue;

		rust::projectile* client_projectile = client_projectiles[ i ];
		if ( !is_valid_ptr( client_projectile ) )
			continue;

		// Only projectiles launched from a BaseProjectile get Projectile.Launch called on them
		if ( created_projectiles ) {
			// Set a unique value to to this field so we know what projectiles we need to run Projectile.Launch for
			client_projectile->monitor.u64 = 0xDEADBEEFCAFEBEEF;
		}

		// Fix for 5.56 projectiles having a weird deviation from their trajectory even with zero spread
		client_projectile->swim_scale = vector3();
		client_projectile->swim_speed = vector3();

		rust::projectile* source_projectile = client_projectile->source_projectile_prefab;

		if ( is_valid_ptr( source_projectile ) ) {
			float thickness = source_projectile->thickness;

			if ( thicker_projectiles.enabled ) {
				thickness = thicker_projectiles.thickness;
			}

			client_projectile->thickness = thickness;
		}

		if ( faster_projectiles ) {
			vector3 velocity = vector3::normalize( server_projectile->start_velocity ) * held_weapon.max_velocity;

			server_projectile->start_velocity = velocity;
			client_projectile->initial_velocity = velocity;
			client_projectile->current_velocity = velocity;
		}

		if ( aimbot.player_target && aimbot.enabled && aimbot.type == aimbot_type::silent && game_input.get_async_key_state( aimbot.key ) ) {
			vector3 target_position = aimbot.player_target->second.bone_data.positions[ 1 ];
			if ( !prediction( server_projectile->start_position, target_position, get_player_velocity( aimbot.player_target->second ) ) )
				return;

			vector3 direction = ( target_position - server_projectile->start_position );
			vector3 velocity = vector3::normalize( direction ) * ( faster_projectiles ? held_weapon.max_velocity : held_weapon.velocity );

			server_projectile->start_velocity = velocity;
			client_projectile->initial_velocity = velocity;
			client_projectile->current_velocity = velocity;
		}
	}

	// Set the created projectiles list size to 0, so IEnumerator.GetNext fails, which in turn will skip Projectile.Launch/AdjustVelocity
	if ( created_projectiles ) {
		created_projectiles->size = 0;
	}
}

#define BONE( name ) unity::string_ex::manifest_hash( name ) 

uint32_t player_random_hit_bones[] = {
	BONE( "head" ), BONE( "neck" ),
	BONE( "spine4" ), BONE( "spine3" ),
	BONE( "spine2" ), BONE( "spine1" ),
	BONE( "l_clavicle" ), BONE( "r_clavicle" ),
	BONE( "l_upperarm" ), BONE( "r_upperarm" ),
	BONE( "l_forearm" ), BONE( "r_forearm" ),
	BONE( "l_hand" ), BONE( "r_hand" ),
	BONE( "l_hip" ), BONE( "r_hip" ),
	BONE( "l_knee" ), BONE( "r_knee" ),
	BONE( "l_foot" ), BONE( "r_foot" )
};

uint32_t player_hit_bones[] = {
	BONE( "head" ), BONE( "neck" ), BONE( "spine2" )
};

uint32_t patrol_helicopter_weakspot_hit_bones[] = {
	BONE( "main_rotor_col" ), BONE( "engine_col" ), BONE( "tail_rotor_col" )
};

void protobuf_player_projectile_attack_write_to_stream_pre_hook( rust::player_projectile_attack* player_projectile_attack ) {
	if ( !is_valid_ptr( player_projectile_attack ) )
		return;

	rust::player_attack* player_attack = player_projectile_attack->player_attack;
	if ( !is_valid_ptr( player_attack ) )
		return;

	rust::attack* attack = player_attack->attack;
	if ( !is_valid_ptr( attack ) )
		return;

	rust::base_entity* hit_entity = rust::entity_ref( nullptr, attack->hit_id ).get( false );
	if ( !is_valid_ptr( hit_entity ) )
		return;

	if ( player_hit_override.enabled && hit_entity->is<rust::base_player>() ) {
		attack->hit_bone = player_hit_override.bone == hit_override_bone::random ?
			player_random_hit_bones[ util::random() % _countof( player_random_hit_bones ) ] : player_hit_bones[ player_hit_override.bone ];
	}

	else if ( hit_patrol_helicopter_weakspots.enabled && hit_entity->is<rust::patrol_helicopter>() ) {
		if ( ( ( util::random() % 100u ) + 1u ) <= hit_patrol_helicopter_weakspots.chance ) {
			attack->hit_bone = patrol_helicopter_weakspot_hit_bones[ util::random() % _countof( patrol_helicopter_weakspot_hit_bones ) ];
		}
	}
}

void item_icon_try_to_move_post_hook( rust::item_icon* item_icon ) {
	if ( instant_loot ) {
		item_icon->run_timed_action();
	}
}

void client_on_client_disconnected_pre_hook( rust::client* client, sys::string* reason ) {
	entity_manager::invalidate_cache();
	glow_manager::invalidate_cache();

	reset_local_player();

	aimbot.player_target = nullptr;
}

void base_player_client_input_pre_hook( rust::base_player* base_player, rust::input_state* state ) {
	if ( !is_valid_ptr( base_player ) || !is_valid_ptr( state ) )
		return reset_local_player();

	if ( !cache_local_player( base_player ) )
		return;

	cache_belt_icons();
	
	rust::base_movement* movement = base_player->movement;

	if ( is_valid_ptr( movement ) ) {
		if ( no_attack_restrictions.enabled ) {
			no_attack_restrictions.reset = true;

			if ( no_attack_restrictions.noclip ) {
				// We need to call the actual noclip because it calls TerrainCollision.Reset which is necessary
				rust::convar::debugging::noclip();

				no_attack_restrictions.admin_cheat = !no_attack_restrictions.admin_cheat;
				no_attack_restrictions.noclip = false;
			}

			movement->admin_cheat = true;
		}

		else if ( no_attack_restrictions.reset ) {
			rust::model_state* model_state = base_player->model_state;

			if ( is_valid_ptr( model_state ) ) {
				movement->admin_cheat = model_state->has_flag( rust::model_state::flag::flying );
			}

			no_attack_restrictions.reset = false;
		}
	}

	if ( admin_flags ) {
		base_player->set_player_flag( rust::base_player::flag::is_admin, true );


	}

	const std::pair<rust::base_player*, cached_player>* target = update_target();

	if ( local_player.held_entity ) {
		cache_held_entity( local_player.held_item, local_player.held_entity );

		if ( auto base_projectile = local_player.held_entity->as<rust::base_projectile>() ) {
			features::weapon_modifiers( base_projectile );

			if ( target ) {
				if ( aimbot.enabled && aimbot.type == aimbot_type::memory && game_input.get_async_key_state( aimbot.key ) ) {
					memory_aimbot( base_projectile, target );
				}
			}

			if ( auto compound_bow = base_projectile->is<rust::compound_bow_weapon>() ) {
				update_velocity_for_compound_bow( compound_bow );
			}
		}
	}

	features::graphics();
	features::bright_night();
	features::looking_at( base_player );
	features::drop_box();
	features::auto_upgrade_impl( local_player.held_entity );
}

struct command {
	const char* name;
	bool set;
};

command blocked_commands[] = {
	{ J( "noclip" ), false },
	{ J( "debugcamera" ), false },
	{ J( "debugcamera_unfreeze" ), false },
	{ J( "camlerp" ), true },
	{ J( "camlerptilt" ), true },
	{ J( "camlookspeed" ), true },
	{ J( "camspeed" ), true }
};

bool console_system_command_pre_hook( rust::console_system::arg* arg, int32_t index ) {
	if ( !is_valid_ptr( arg ) )
		return true;

	if ( block_server_commands.enabled && arg->option.is_from_server ) {
		if ( block_server_commands.notify && index >= 0 && index < _countof( blocked_commands ) ) {
			const command& command = blocked_commands[ index ];

			notifications::push( FMT( 256, S( "The server tried to %s \x02\xFF\x01\x01\xFF""%s\x03, but we blocked it." ), command.set ? S( "set" ) : S( "run" ), command.name ) );
		}

		return false;
	}

	// If we try to run noclip, we skip the original because this code may run between our hooks if binded, which we don't want
	if ( no_attack_restrictions.enabled && index == 0 ) {
		no_attack_restrictions.noclip = true;

		// Skip original
		return false;
	}

	return true;
}

uint64_t effect_name_hashes[] = {
	H( "assets/prefabs/weapons/rocketlauncher/effects/rocket_explosion.prefab" ),
	H( "assets/prefabs/weapons/rocketlauncher/effects/rocket_explosion_hv.prefab" ),
	H( "assets/prefabs/weapons/rocketlauncher/effects/rocket_explosion_incendiary.prefab" ),
	H( "assets/bundled/prefabs/fx/impacts/additive/explosion.prefab" ),
	H( "assets/prefabs/tools/c4/effects/c4_explosion.prefab" ),
	H( "assets/prefabs/weapons/satchelcharge/effects/satchel-charge-explosion.prefab" ),
	H( "assets/prefabs/ammo/40mmgrenade/effects/40mm_he_explosion.prefab" ),
	H( "assets/content/vehicles/mlrs/effects/pfx_mlrs_rocket_explosion_ground.prefab" )
};

const char* raid_descriptors[] = {
	J( "a rocket" ),
	J( "a high velocity rocket" ),
	J( "an incendiary rocket" ),
	J( "explosive ammo" ),
	J( "C4" ),
	J( "a satchel charge" ),
	J( "an HE grenade" ),
	J( "an MLRS rocket" )
};

void effect_library_setup_effect_hook( rust::effect* effect ) {
	if ( !is_valid_ptr( effect ) )
		return;

	sys::string* pooled_string = effect->pooled_string;
	if ( !is_valid_ptr( pooled_string ) )
		return;

	uint64_t effect_name_hash = util::hash_w( pooled_string->buffer );

	for ( size_t i = 0; i < _countof( effect_name_hashes ); i++ ) {
		if ( effect_name_hash != effect_name_hashes[ i ] )
			continue;

		bool present = false;
		int use_index = -1, top_index = -1;

		for ( size_t j = 0; j < _countof( raids ); j++ ) {
			raid& raid = raids[ j ];

			// Try to find an empty slot in case the raid isn't present
			if ( !raid.active_time ) {
				use_index = j;
				continue;
			}

			if ( vector3::sqr_distance( effect->world_pos, raid.position ) < _pow2( 30.f ) ) {
				raid.effects[ i ]++;
				raid.active_time = util::get_time<time_unit::seconds>();
				present = true;
				break;
			}

			top_index = j;
		}

		if ( !present ) {
			int index = use_index;

			// If we haven't found an empty slot, look for one now starting at the top index
			if ( index == -1 ) {
				for ( size_t k = top_index; k < _countof( raids ); k++ ) {
					raid& raid = raids[ k ];
					if ( raid.active_time )
						continue;

					index = k;
					break;
				}
			}

			if ( index != -1 ) {
				raid& raid = raids[ index ];

				raid.active_time = util::get_time<time_unit::seconds>();
				raid.position = effect->world_pos;
				raid.effects[ i ]++;

				rust::map_helper::grid_to_string( rust::map_helper::position_to_grid( effect->world_pos ), raid.grid, sizeof( raid.grid ) );

				if ( raid_visuals.notify ) {
					notifications::push( FMT( 128, S( "A raid has started in \x02\xFF\x01\x01\xFF""%s\x03 with \x02\xFF\x01\x01\xFF""%s\x03." ), raid.grid, raid_descriptors[ i ] ) );
				}
			}
		}

		return;
	}

	if ( events.enabled && events.notify ) {
		notifications::push( pooled_string->buffer );
	}
}

void client_update_pre_hook( rust::client* client ) {
	if ( !is_valid_ptr( client ) )
		return;

	// Update scroll delta here as this is the only hook we have that runs in the main menu
	gui::scroll_delta = unity::input::get_mouse_scroll_delta().y;

	rust::list_hash_set<rust::projectile*>* projectiles_instance_list = rust::list_component<rust::projectile>::static_fields_->instance_list;

	if ( is_valid_ptr( projectiles_instance_list ) ) {
		sys::buffer_list<rust::projectile*>* projectiles_buffer_list = projectiles_instance_list->vals;

		if ( is_valid_ptr( projectiles_buffer_list ) ) {
			sys::array<rust::projectile*>* projectiles_array = projectiles_buffer_list->buffer;

			if ( is_valid_ptr( projectiles_array ) ) {
				float time = unity::time::get_time();

				for ( int32_t i = 0; i < projectiles_buffer_list->count; i++ ) {
					rust::projectile* projectile = projectiles_array->buffer[ i ];
					if ( !is_valid_ptr( projectile ) )
						continue;

					if ( projectile->owner != local_player.entity )
						continue;

					// If this is a projectile we've skipped Projectile.Launch for, run it ourselves
					if ( projectile->monitor.u64 == 0xDEADBEEFCAFEBEEF ) {
						projectile->monitor.u64 = 0ull;

						float maximum_travel_time = 0.1f;

						while ( projectile->is_alive() ) {
							if ( projectile->initial_distance <= projectile->traveled_distance && projectile->traveled_time >= maximum_travel_time )
								break;

							features::on_projectile_update( projectile );
							projectile->update_velocity( 0.03125f );
						}

						projectile->launch_time = unity::time::get_fixed_time() - projectile->traveled_time;
					}

					if ( !projectile->is_alive() || ( time - projectile->launch_time < projectile->traveled_time + 0.03125f ) )
						continue;

					features::on_projectile_update( projectile );
				}
			}
		}
	}
}

void player_walk_movement_teleport_to_pre_hook( rust::player_walk_movement* player_walk_movement, vector3* position, rust::base_player* player ) {
	if ( !is_valid_ptr( player_walk_movement ) || !is_valid_ptr( position ) || !is_valid_ptr( player ) )
		return;

	if ( player != local_player.entity )
		return;

	rust::player_tick* last_sent_tick = local_player.entity->last_sent_tick;

	if ( is_valid_ptr( last_sent_tick ) ) {
		last_sent_tick->position = *position;
	}
}

void hook_handlers::network_client_create_networkable( _CONTEXT* context, void* user_data ) {
	static util::context_search search = util::context_search<rust::base_networkable*>( context,
		[]( rust::base_networkable* value ) {
			if ( !is_valid_ptr( value ) || !is_valid_ptr( value->cached_ptr ) )
				return false;

			// This must not be populated as we're hooking the creation of the networkable object
			if ( value->net )
				return false;

			if ( !value->as<rust::base_networkable>() )
				return false;

			unity::transform* transform = value->get_transform();
			if ( !is_valid_ptr( transform ) )
				return false;

			return true;
		}, true, 0x100 );

	if ( !search.resolved() )
		return;
	
	network_client_create_networkable_hook( search.get( context ) );
}

void hook_handlers::network_client_destroy_networkable( _CONTEXT* context, void* user_data ) {
	static util::context_search search = util::context_search<rust::base_networkable*>( context,
		[]( rust::base_networkable* value ) {
			if ( !is_valid_ptr( value ) )
				return false;

			return value->as<rust::base_networkable>() != nullptr;
		}, true, 0x100 );

	if ( !search.resolved() )
		return;

	network_client_destroy_networkable_hook( search.get( context ) );
}

// TODO: Clean up and put asset bundle loading in another place

bool init = false;

void hook_handlers::post_outline_manager_on_render_image( _CONTEXT* context, void* user_data ) {
	if ( !init ) {
		asset_bundle = unity::asset_bundle::load_from_file( L"C://assetbundle", 0u, 0ull );
		glow_manager::init( asset_bundle );
		init = true;
	}

	// Update entities
	entity_manager::update();

	glow_manager::update();
	glow_manager::on_render_image_hook( ( unity::render_texture* )context->Rdx, ( unity::render_texture* )context->R8 );
}

bool hook_handlers::pre_player_walk_movement_client_input( _CONTEXT* context, void* user_data ) {
	player_walk_movement_client_input_pre_hook( ( rust::player_walk_movement* )context->Rcx, ( rust::input_state* )context->Rdx, ( rust::model_state* )context->R8 );

	return true;
}

void hook_handlers::post_player_walk_movement_client_input( _CONTEXT* context, void* user_data ) {
	player_walk_movement_client_input_post_hook( ( rust::player_walk_movement* )context->Rcx, ( rust::input_state* )context->Rdx, ( rust::model_state* )context->R8 );
}

bool hook_handlers::pre_protobuf_player_tick_write_to_stream_delta( _CONTEXT* context, void* user_data ) {
	protobuf_player_tick_write_to_stream_delta_pre_hook( ( rust::player_tick* )context->Rcx, ( rust::buffer_stream* )context->Rdx, ( rust::player_tick* )context->R8 );

	return true;
}

bool hook_handlers::pre_protobuf_projectile_shoot_write_to_stream( _CONTEXT* context, void* user_data ) {
	if ( !local_player.held_entity )
		return true;

	if ( local_player.held_entity->as<rust::base_projectile>() ) {
		static util::context_search search = util::context_search<sys::list<rust::projectile*>*>( context,
			[]( sys::list<rust::projectile*>* value ) {
				if ( !is_valid_ptr( value ) )
					return false;

				// Check if the underlying array is valid
				sys::array<rust::projectile*>* items = value->items;
				if ( !is_valid_ptr( items ) || items->size <= 0 || items->size > 128 )
					return false;

				// Check if the first element of the array is a projectile
				rust::projectile* projectile = items->buffer[ 0 ];
				if ( !is_valid_ptr( projectile ) || !projectile->is<rust::projectile>() )
					return false;

				il2cpp_class* klass = value->klass;
				if ( !is_valid_ptr( klass ) )
					return false;

				// Protect against non null-terminated garbage
				char class_name[ 64 ] = {};
				memcpy( class_name, klass->name, sizeof( class_name ) - 1llu );

				// This is most likely redundant, but this only runs once, so it doesn't matter
				return util::hash( class_name ) == H( "List`1" );
			}, true, 0x100 );

		if ( !search.resolved() )
			return true;

		protobuf_projectile_shoot_write_to_stream_pre_hook( ( rust::projectile_shoot* )context->Rcx, search.get( context ), nullptr );
	}

	else if ( local_player.held_entity->as<rust::base_melee>() ) {
		static util::context_search search = util::context_search<rust::projectile*>( context,
			[]( rust::projectile* value ) {
				if ( !is_valid_ptr( value ) )
					return false;

				return value->is<rust::projectile>() != nullptr;
			}, true, 0x100 );

		if ( !search.resolved() )
			return true;

		protobuf_projectile_shoot_write_to_stream_pre_hook( ( rust::projectile_shoot* )context->Rcx, nullptr, search.get( context ) );
	}

	return true;
}

bool hook_handlers::pre_protobuf_player_projectile_update_write_to_stream( _CONTEXT* context, void* user_data ) {
	return true;
}

bool hook_handlers::pre_protobuf_player_projectile_attack_write_to_stream( _CONTEXT* context, void* user_data ) {
	protobuf_player_projectile_attack_write_to_stream_pre_hook( ( rust::player_projectile_attack* )context->Rcx );

	return true;
}

void hook_handlers::post_item_icon_try_to_move( _CONTEXT* context, void* user_data ) {
	item_icon_try_to_move_post_hook( ( rust::item_icon* )context->Rcx );
}

bool hook_handlers::pre_client_on_client_disconnected( _CONTEXT* context, void* user_data ) {
	client_on_client_disconnected_pre_hook( ( rust::client* )context->Rcx, ( sys::string* )context->Rdx );

	return true;
}

bool hook_handlers::pre_base_player_client_input( _CONTEXT* context, void* user_data ) {
	game_input.update();

	base_player_client_input_pre_hook( ( rust::base_player* )context->Rcx, ( rust::input_state* )context->Rdx );

	return true;
}

bool hook_handlers::pre_console_system_command_set( _CONTEXT* context, void* user_data ) {
	static util::context_search search = util::context_search<rust::console_system::arg*>( context,
		[]( rust::console_system::arg* value ) {
			if ( !is_valid_ptr( value ) )
				return false;

			return value->is<rust::console_system::arg>() != nullptr;
		}, true, 0x100 );

	if ( !search.resolved() )
		return true;

	return console_system_command_pre_hook( search.get( context ), ( uint64_t )user_data );
}

bool hook_handlers::pre_console_system_command_call( _CONTEXT* context, void* user_data ) {
	return console_system_command_pre_hook( ( rust::console_system::arg* )context->Rdx, ( uint64_t )user_data );
}

void hook_handlers::effect_library_setup_effect( _CONTEXT* context, void* user_data ) {
	static util::context_search search = util::context_search<rust::effect*>( context,
		[]( rust::effect* value ) {
			if ( !is_valid_ptr( value ) )
				return false;

			return value->is<rust::effect>() != nullptr;
		}, true, 0x100 );

	if ( !search.resolved() )
		return;

	effect_library_setup_effect_hook( search.get( context ) );
}

bool hook_handlers::pre_client_update( _CONTEXT* context, void* user_data ) {
	client_update_pre_hook( ( rust::client* )context->Rcx );

	return true;
}

bool hook_handlers::pre_player_walk_movement_teleport_to( _CONTEXT* context, void* user_data ) {
	player_walk_movement_teleport_to_pre_hook( ( rust::player_walk_movement* )context->Rcx, ( vector3* )context->Rdx, ( rust::base_player* )context->R8 );

	return true;
}