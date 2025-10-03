#include "hooks.h"
#include "global.h"	
#include "cheat/cheat.h"
#include "cheat/sdk/sdk.h"
#include "nt.h"
#include "cheat/entities.h"
#include "cheat/glow.h"
#include "gui.h"
#include "features.h"

#include <cstddef>

enum resolved_location {
	unresolved,
	registers,
	stack,
};

template <typename T>
class context_search {
public:
	static_assert( sizeof( T ) <= sizeof( uint64_t ) );

	context_search() = delete;

	template <typename C>
	context_search( _CONTEXT* context, C&& callback, bool stack, size_t depth ) {
		uint64_t* registers = ( uint64_t* )&context->Rax;
		constexpr size_t num_registers = ( offsetof( CONTEXT, Rip ) - offsetof( CONTEXT, Rax ) ) / sizeof( uint64_t );

		for ( size_t i = 0; i < num_registers; i++ ) {
			T value = ( T )registers[ i ];

			if ( callback( value ) ) {
				location_ = resolved_location::registers;
				position_ = i;
				return;
			}
		}

		if ( stack ) {
			for ( size_t i = 0, n = depth / sizeof( T ); i < n; i++ ) {
				size_t offset = i * sizeof( T );
				T value = *( T* )( context->Rsp + offset );

				if ( callback( value ) ) {
					location_ = resolved_location::stack;
					position_ = offset;
					return;
				}
			}
		}

		location_ = resolved_location::unresolved;
		position_ = 0ull;
	}

	bool resolved() {
		return location_ != resolved_location::unresolved;
	}

	T get( _CONTEXT* context ) {
		if ( location_ == resolved_location::registers ) {
			uint64_t* registers = ( uint64_t* )&context->Rax;
			return ( T )registers[ position_ ];
		} 
		
		else if ( location_ == resolved_location::stack ) {
			return *( T* )( context->Rsp + position_ );
		}

		return T();
	}

private:
	resolved_location location_;
	size_t position_;
};

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

void cache_held_entity( rust::item* held_item, rust::base_entity* held_entity ) {
	rust::item_definition* projectile_item_info = nullptr;
	float velocity_scale = 1.f, max_velocity_scale = 1.f;

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

	if ( !projectile_item_info || ( held_entity->prefab_id == held_weapon.prefab_id && projectile_item_info->item_id == held_weapon.item_id ) )
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
	held_weapon.item_id = projectile_item_info->item_id;
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

	if ( no_attack_restrictions ) {
		player_walk_movement->admin_cheat = previous_admin_cheat;
	}
}

void player_walk_movement_client_input_post_hook( rust::player_walk_movement* player_walk_movement, rust::input_state* input_state, rust::model_state* model_state ) {
	if ( !is_valid_ptr( player_walk_movement ) || !is_valid_ptr( input_state ) || !is_valid_ptr( model_state ) )
		return;

	if ( player_walk_movement->owner != local_player.entity )
		return;

	if ( model_state->has_flag( rust::model_state::flag::flying ) )
		return;

	if ( spider_man ) {
		player_walk_movement->ground_angle_new = 0.f;
	}

	if ( no_fall_damage ) {
		
	}

	if ( infinite_jump ) {
		float time = unity::time::get_time();

		player_walk_movement->ground_time = time + 0.2f;
		player_walk_movement->jump_time = time - 1.f;
		player_walk_movement->land_time = time - 0.4f;
	}

	if ( omnisprint ) {
		if ( !model_state->has_flag( rust::model_state::flag::ducked ) &&
			!model_state->has_flag( rust::model_state::flag::crawling ) &&
			model_state->water_level < 0.65f && !player_walk_movement->ladder ) {
			vector3 current_velocity = player_walk_movement->target_movement;

			if ( vector3::magnitude( current_velocity ) > 0.f ) {
				player_walk_movement->target_movement = vector3::normalize( current_velocity ) * local_player.entity->get_speed( 1.f, 0.f, 0.f );
				model_state->set_flag( rust::model_state::flag::sprinting, true );
			}
		}
	}
}

void protobuf_player_tick_write_to_stream_delta_pre_hook( rust::player_tick* player_tick ) {
	if ( !is_valid_ptr( player_tick ) )
		return;

	rust::model_state* model_state = player_tick->model_state;
	if ( !is_valid_ptr( model_state ) )
		return;

	model_state->set_flag( rust::model_state::flag::sprinting, true );
}

void protobuf_projectile_shoot_write_to_stream_pre_hook( rust::projectile_shoot* projectile_shoot, sys::list<rust::projectile*>* created_projectiles, rust::projectile* projectile ) {
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

	else if ( projectile && is_valid_ptr( projectile ) && projectile->is<rust::projectile>() ) {
		client_projectiles = &projectile;
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

		if ( aimbot.player_target ) {
			if ( aimbot.enabled && aimbot.type == aimbot_type::silent ) {
				vector3 direction = ( aimbot.player_target->second.bone_data.positions[ 1 ] - server_projectile->start_position );
				vector3 velocity = vector3::normalize( direction ) * held_weapon.velocity;

				server_projectile->start_velocity = velocity;
				client_projectile->initial_velocity = velocity;
				client_projectile->current_velocity = velocity;
			}
		}
	}
}

void protobuf_player_projectile_attack_write_to_stream_pre_hook( rust::player_projectile_attack* player_projectile_attack ) {
	if ( !is_valid_ptr( player_projectile_attack ) )
		return;

	rust::player_attack* attack = player_projectile_attack->player_attack;
	if ( !is_valid_ptr( attack ) )
		return;

	// TODO: Find a way to get the entity from the networkable id
	rust::base_networkable* hit_entity = nullptr;
	if ( !is_valid_ptr( hit_entity ) )
		return;

	if ( hit_override.enabled && hit_entity->is<rust::base_player>() ) {

	}

	else if ( patrol_heli_weakspots.enabled && hit_entity->is<rust::patrol_helicopter>() ) {

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

	// BasePlayer.CanAttack checks if adminCheat is true, and if so returns an early true. We set it here and then clear it before PlayerWalkMovement.ClientInput runs
	if ( no_attack_restrictions ) {
		rust::base_movement* movement = base_player->movement;

		if ( is_valid_ptr( movement ) ) {
			previous_admin_cheat = movement->admin_cheat;
			movement->admin_cheat = true;
		}
	}

	const std::pair<rust::base_player*, cached_player>* target = update_target();

	if ( local_player.held_entity ) {
		cache_held_entity( local_player.held_item, local_player.held_entity );

		if ( auto base_projectile = local_player.held_entity->as<rust::base_projectile>() ) {
			features::weapon_modifiers( base_projectile );

			if ( target ) {
				if ( aimbot.enabled && aimbot.type == aimbot_type::memory && game_input.get_async_key_state( 'C' ) ) {
					features::memory_aimbot( target );
				}
			}

			if ( auto compound_bow = base_projectile->is<rust::compound_bow_weapon>() ) {
				update_velocity_for_compound_bow( compound_bow );
			}
		}
	}

	features::graphics();
	features::bright_night();
}

void base_player_client_input_post_hook( rust::base_player* base_player, rust::input_state* state ) {

}

bool console_system_command_pre_hook( rust::console_system::arg* arg ) {
	if ( !is_valid_ptr( arg ) )
		return true;

	if ( block_server_commands && arg->option.is_from_server ) {
		return false;
	}

	return true;
}

void hook_handlers::network_client_create_networkable( _CONTEXT* context ) {
	static context_search search = context_search<rust::base_networkable*>( context,
		[]( rust::base_networkable* value ) {
			if ( !is_valid_ptr( value ) )
				return false;

			if ( !value->as<rust::base_networkable>() )
				return false;

			unity::transform* transform = value->get_transform();
			if ( !is_valid_ptr( transform ) )
				return false;

			// We don't want any entities with a valid networkable object as we're hooking the creation of it
			return !is_valid_ptr( value->net );
		}, true, 0x100 );

	if ( !search.resolved() )
		return;

	network_client_create_networkable_hook( search.get( context ) );
}

void hook_handlers::network_client_destroy_networkable( _CONTEXT* context ) {
	static context_search search = context_search<rust::base_networkable*>( context,
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

void hook_handlers::post_outline_manager_on_render_image( _CONTEXT* context ) {
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

bool hook_handlers::pre_player_walk_movement_client_input( _CONTEXT* context ) {
	player_walk_movement_client_input_pre_hook( ( rust::player_walk_movement* )context->Rcx, ( rust::input_state* )context->Rdx, ( rust::model_state* )context->R8 );

	return true;
}

void hook_handlers::post_player_walk_movement_client_input( _CONTEXT* context ) {
	player_walk_movement_client_input_post_hook( ( rust::player_walk_movement* )context->Rcx, ( rust::input_state* )context->Rdx, ( rust::model_state* )context->R8 );
}

bool hook_handlers::pre_protobuf_player_tick_write_to_stream_delta( _CONTEXT* context ) {
	protobuf_player_tick_write_to_stream_delta_pre_hook( ( rust::player_tick* )context->Rcx );

	return true;
}

bool hook_handlers::pre_protobuf_projectile_shoot_write_to_stream( _CONTEXT* context ) {
	if ( !local_player.held_entity )
		return true;

	if ( local_player.held_entity->as<rust::base_projectile>() ) {
		static context_search search = context_search<sys::list<rust::projectile*>*>( context,
			[&]( sys::list<rust::projectile*>* value ) {
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

				// This is most likely redundant, but this only runs once, so who cares?
				return util::hash( class_name ) == H( "List`1" );
			}, true, 0x100 );

		if ( !search.resolved() )
			return true;

		protobuf_projectile_shoot_write_to_stream_pre_hook( ( rust::projectile_shoot* )context->Rcx, search.get( context ), nullptr );
	}

	else if ( local_player.held_entity->as<rust::base_melee>() ) {
		static context_search search = context_search<rust::projectile*>( context,
			[&]( rust::projectile* value ) {
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

bool hook_handlers::pre_protobuf_player_projectile_update_write_to_stream( _CONTEXT* context ) {
	return true;
}

bool hook_handlers::pre_protobuf_player_projectile_attack_write_to_stream( _CONTEXT* context ) {
	protobuf_player_projectile_attack_write_to_stream_pre_hook( ( rust::player_projectile_attack* )context->Rcx );

	return true;
}

void hook_handlers::post_item_icon_try_to_move( _CONTEXT* context ) {
	item_icon_try_to_move_post_hook( ( rust::item_icon* )context->Rcx );
}

bool hook_handlers::pre_client_on_client_disconnected( _CONTEXT* context ) {
	client_on_client_disconnected_pre_hook( ( rust::client* )context->Rcx, ( sys::string* )context->Rdx );

	return true;
}

bool hook_handlers::pre_base_player_client_input( _CONTEXT* context ) {
	game_input.update();

	base_player_client_input_pre_hook( ( rust::base_player* )context->Rcx, ( rust::input_state* )context->Rdx );

	return true;
}

void hook_handlers::post_base_player_client_input( _CONTEXT* context ) {
	base_player_client_input_post_hook( ( rust::base_player* )context->Rcx, ( rust::input_state* )context->Rdx );
}

bool hook_handlers::pre_console_system_command_set( _CONTEXT* context ) {
	static context_search search = context_search<rust::console_system::arg*>( context,
		[&]( rust::console_system::arg* value ) {
			if ( !is_valid_ptr( value ) )
				return false;

			return value->is<rust::console_system::arg>() != nullptr;
		}, true, 0x100 );

	if ( !search.resolved() )
		return true;

	return console_system_command_pre_hook( search.get( context ) );
}

bool hook_handlers::pre_console_system_command_call( _CONTEXT* context ) {
	return console_system_command_pre_hook( ( rust::console_system::arg* )context->Rdx );
}