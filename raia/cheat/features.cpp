#include "features.h"
#include "sdk/sdk.h"
#include "vars.h"
#include "entities.h"

void features::graphics() {
	if ( fov_modifier.enabled || fov_modifier.dirty ) {
		rust::convar::graphics::static_fields_->fov = fov_modifier.enabled ? ( float )fov_modifier.fov : 90.f;
		fov_modifier.dirty = fov_modifier.enabled;
	}
}

void features::bright_night() {
	rust::tod_sky* tod_sky = rust::tod_sky::get_instance();
	if ( !is_valid_ptr( tod_sky ) )
		return;

	rust::tod_night_parameters* night_parameters = tod_sky->night;
	if ( !is_valid_ptr( night_parameters ) )
		return;

	rust::tod_ambient_parameters* ambient_parameters = tod_sky->ambient;
	if ( !is_valid_ptr( ambient_parameters ) )
		return;

	night_parameters->ambient_multiplier = override_night.enabled ? ( float )ambient_multiplier : 0.f;
	ambient_parameters->saturation = override_night.enabled ? ( float )ambient_saturation : 1.f;

	if ( unity::gradient* gradient = night_parameters->ambient_color ) {
		unity::color color = override_night.enabled ? unity::color( ambient_color ) : unity::color( 0.f, 0.0343f, 0.099f, 1.f );

		std::initializer_list<unity::gradient_color_key> color_keys = { { color, 0.f }, { color, 1.f } };
		std::initializer_list<unity::gradient_alpha_key> alpha_keys = { { 1.f, 0.f }, { 1.f, 1.f } };

		gradient->set_keys( color_keys, alpha_keys );
	}
}

struct cached_weapon_data {
	uint32_t prefab_id;
	bool automatic;
	float aim_sway;
	float aim_cone;
	float yaw_min;
	float yaw_max;
	float pitch_min;
	float pitch_max;
};

util::array<cached_weapon_data, 64> weapon_data_cache;

const cached_weapon_data* get_weapon_data( rust::base_projectile* base_projectile ) {
	for ( const auto& weapon_data : weapon_data_cache ) {
		if ( weapon_data.prefab_id == base_projectile->prefab_id ) {
			return &weapon_data;
		}
	}
	
	return nullptr;
}

void features::weapon_modifiers( rust::base_projectile* weapon ) {
	rust::recoil_properties* recoil = weapon->is<rust::flint_strike_weapon>() ?
		( ( rust::flint_strike_weapon* )weapon )->strike_recoil : weapon->recoil;

	if ( !is_valid_ptr( recoil ) )
		return;

	recoil = is_valid_ptr( recoil->new_recoil_override ) ? recoil->new_recoil_override : recoil;

	const cached_weapon_data* weapon_data = get_weapon_data( weapon );

	if ( !weapon_data ) {
		weapon_data = weapon_data_cache.add( {
			weapon->prefab_id, weapon->automatic, weapon->aim_sway, weapon->aim_cone, recoil->recoil_yaw_min, recoil->recoil_yaw_max, recoil->recoil_pitch_min, recoil->recoil_pitch_max } );
	}

	// What the fuck?
	if ( !weapon_data )
		return;

	float yaw_scale = recoil_modifier.enabled ? recoil_modifier.yaw_scale.value : 1.f;
	float pitch_scale = recoil_modifier.enabled ? recoil_modifier.pitch_scale.value : 1.f;

	// Recoil properties are static values, so we can just multiply the default values by our scale
	recoil->recoil_yaw_min = weapon_data->yaw_min * yaw_scale;
	recoil->recoil_yaw_max = weapon_data->yaw_max * yaw_scale;
	recoil->recoil_pitch_min = weapon_data->pitch_min * pitch_scale;
	recoil->recoil_pitch_max = weapon_data->pitch_max * pitch_scale;

	// Bow spread is derived from BaseProjectile.aimCone, which is static so we can do the same thing
	if ( weapon->is<rust::bow_weapon>() || weapon->is<rust::compound_bow_weapon>() ) {
		weapon->aim_cone = weapon_data->aim_cone *
			( spread_modifier.enabled ? spread_modifier.scale.value : 1.f );
	}

	// BaseProjectile.sightAimConeScale/hipAimConeScale is the absolute spread scale derived from the attachments, and is dynamic, so to get the starting scale, you must calculate it 
	else {
		float sight_aim_cone_scale = held_weapon.mods.sight_aim_cone_scale;
		float hip_aim_cone_scale = held_weapon.mods.hip_aim_cone_scale;

		if ( spread_modifier.enabled ) {
			sight_aim_cone_scale *= spread_modifier.scale;
			hip_aim_cone_scale *= spread_modifier.scale;
		}

		// Don't multiply by default values as these are absolute
		weapon->sight_aim_cone_scale = sight_aim_cone_scale;
		weapon->hip_aim_cone_scale = hip_aim_cone_scale;
	}
	
	weapon->aim_sway = weapon_data->aim_sway *
		( sway_modifier.enabled ? sway_modifier.scale.value : 1.f );

	weapon->automatic = force_automatic ? true : weapon_data->automatic;

	// TODO: This must be reset as it persists until you fire
	if ( auto eoka_pistol = weapon->is<rust::flint_strike_weapon>() ) {
		if ( instant_eoka ) {
			eoka_pistol->did_spark_this_frame = true;
		}
	}

	if ( auto compound_bow = weapon->is<rust::compound_bow_weapon>() ) {
		if ( original_string_hold_duration_max == -1.f ) {
			original_string_hold_duration_max = compound_bow->string_hold_duration_max;
		}

		compound_bow->string_hold_duration_max = instant_compound_bow ? 0.f : original_string_hold_duration_max;
	}
}

bool features::update_rocket_trajectory( rust::base_launcher* launcher ) {
	rust::base_projectile::magazine* magazine = launcher->primary_magazine;
	if ( !is_valid_ptr( magazine ) )
		return false;

	rust::item_definition* ammo_type = magazine->ammo_type;
	if ( !is_valid_ptr( ammo_type ) )
		return false;

	float gravity_modifier, speed;

	switch ( ammo_type->item_id ) {
		case -742865266: // Rocket
			gravity_modifier = 0.25f;
			speed = 18.f;
			break;
		case -1841918730: // High Velocity Rocket
			gravity_modifier = 0.05f;
			speed = 40.f;
			break;
		case 1638322904: // Incendiary Rocket
			gravity_modifier = 0.25f;
			speed = 18.f;
			break;
		case -17123659: // Smoke Rocket
			gravity_modifier = 0.15f;
			speed = 30.f;
			break;
		default:
			return false;
	}

	vector3 current_position = local_player.eyes_position + local_player.body_forward;
	vector3 current_velocity = local_player.body_forward * speed;

	const float delta_time = 0.0625f;

	vector3 points[ 128 + 1 ];
	uint32_t num_points = 0u;

	for ( float time = 0.f; time < 8.f; time += delta_time ) {
		vector3 traveled_this_update = current_velocity * delta_time;

		unity::raycast_hit hit_info;
		if ( unity::physics::raycast( current_position, current_velocity, &hit_info, vector3::magnitude( traveled_this_update ), rust::server_projectile::mask, unity::query_trigger_interaction::ignore ) ) {
			// Include the hit point
			points[ num_points++ ] = hit_info.point;

			memcpy( draw_rocket_trajectory.points, points, sizeof( vector3 ) * num_points );
			draw_rocket_trajectory.num_points = num_points;
			draw_rocket_trajectory.travel_time = time;
			draw_rocket_trajectory.hit = true;

			return true;
		}

		points[ num_points++ ] = current_position;

		current_velocity += vector3( 0.f, -9.81f, 0.f ) * gravity_modifier * delta_time;
		current_position += traveled_this_update;
	}

	return false;
}

void features::looking_at( rust::base_player* local_player ) {
	rust::base_entity* looking_at_entity = local_player->looking_at_entity;
	if ( !is_valid_ptr( looking_at_entity ) )
		return;

	rust::buttons::con_button* use = rust::buttons::static_fields_->use;
	
	if ( is_valid_ptr( use ) && use->is_down ) {
		static util::timer<time_unit::milliseconds> timer( 0ull );

		if ( loot_without_untie && timer.has_elapsed( 25ull ) && looking_at_entity->is( H( "FreeableLootContainer" ) ) ) {
			looking_at_entity->server_rpc( S( L"RPC_OpenLoot" ) );
		}
	}
}

void features::drop_box() {
	if ( !auto_drop_box.enabled )
		return;

	static util::timer<time_unit::milliseconds> timer( 0ull );

	if ( ( game_input.get_async_key_state( 'V' ) & 0x1 ) && timer.has_elapsed( 50ull ) ) {
		rust::item_container* container00 = rust::loot_panel::get_container_00();
		if ( !is_valid_ptr( container00 ) )
			return;

		sys::list<rust::item*>* items_list = container00->item_list;
		if ( !is_valid_ptr( items_list ) )
			return;

		sys::array<rust::item*>* items = items_list->items;
		if ( !is_valid_ptr( items ) )
			return;

		for ( int32_t i = 0; i < items_list->size; i++ ) {
			rust::item* item = items->buffer[ i ];
			if ( !is_valid_ptr( item ) )
				continue;

			rust::local_player::item_command( item->uid, S( L"drop" ) );
		}
	}
}

void features::auto_upgrade_impl( rust::held_entity* held_entity ) {
	if ( !auto_upgrade.enabled )
		return;

	if ( util::get_time<time_unit::milliseconds>() < auto_upgrade.next_upgrade_time )
		return;

	if ( auto_upgrade.only_holding_hammer &&
		( !held_entity || ( !held_entity->is( H( "Hammer" ) ) && !held_entity->is( H( "Toolgun" ) ) ) ) )
		return;

	util::scoped_spinlock lock( &entity_manager::cache_lock );

	entity_collection entity_collection = entity_manager::get_entities();

	for ( auto [ building_block, cached_building_block ] : entity_collection.building_blocks ) {
		if ( building_block->grade >= auto_upgrade.to )
			continue;

		// If a from grade is specified, make sure the building grade matches
		if ( auto_upgrade.from != -1 && building_block->grade != auto_upgrade.from )
			continue;

		// Filter with a regular distance check first because replicating the actual distance check on the server is quite costly
		if ( vector3::distance( local_player.eyes_position, cached_building_block.position ) > 6.f )
			continue;

		if ( !building_block->can_afford_upgrade( auto_upgrade.to, 0ull, local_player.entity ) )
			break;

		// We could probably break early here to save some calls
		if ( !building_block->has_upgrade_privilege( auto_upgrade.to, 0ull, local_player.entity ) )
			continue;

		building_block->server_rpc( S( L"DoUpgradeToGrade" ), auto_upgrade.to.value, 0ull );

		auto_upgrade.next_upgrade_time = util::get_time<time_unit::milliseconds>() + 50ull;
	}
}