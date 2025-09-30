#include "features.h"
#include "sdk/sdk.h"
#include "vars.h"
#include "entities.h"

void features::graphics() {
	if ( fov_modifier.enabled || fov_modifier.dirty ) {
		rust::graphics::static_fields_->fov = fov_modifier.enabled ? ( float )fov_modifier.fov : 90.f;
		fov_modifier.dirty = fov_modifier.enabled;
	}
}

void features::bright_night() {
	auto static_fields = rust::singleton_component<rust::rust_camera>::static_fields_;
	if ( !static_fields )
		return;

	rust::rust_camera* rust_camera = static_fields->instance;
	if ( !is_valid_ptr( rust_camera ) )
		return;

	rust::tod_sky* tod_sky = rust::tod_sky::get_instance();
	if ( !is_valid_ptr( tod_sky ) )
		return;

	rust::tod_night_parameters* night_parameters = tod_sky->night;
	if ( !is_valid_ptr( night_parameters ) )
		return;

	rust::tod_ambient_parameters* ambient_parameters = tod_sky->ambient;
	if ( !is_valid_ptr( ambient_parameters ) )
		return;

	rust_camera->ambient_light_night = override_night.enabled ? ( float )ambient_multiplier : 0.f;
	rust_camera->ambient_light_multiplier = override_night.enabled ? 1.f : ( float )rust_camera->ambient_light_multiplier;
	ambient_parameters->saturation = ambient_saturation;

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
			weapon->prefab_id, weapon->automatic, weapon->aim_sway, weapon->aim_cone, recoil->recoil_yaw_min, recoil->recoil_yaw_max, recoil->recoil_pitch_min, recoil->recoil_pitch_max, } );
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
	if ( weapon->is<rust::bow_weapon>() ) {
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
	if ( instant_eoka && weapon->is<rust::flint_strike_weapon>() ) {
		( ( rust::flint_strike_weapon* )weapon )->did_spark_this_frame = true;
	}

	if ( weapon->is<rust::compound_bow_weapon>() ) {
		auto _weapon = ( rust::compound_bow_weapon* )weapon;

		if ( previous_string_hold_duration_max == -1.f ) {
			previous_string_hold_duration_max = _weapon->string_hold_duration_max;
		}

		_weapon->string_hold_duration_max = instant_compound_bow ? 0.f : previous_string_hold_duration_max;
	}
}

bool calc_angle( const vector3& src, const vector3& dst, vector3& result ) {
	vector3 direction = dst - src;
	if ( vector3::sqr_magnitude( direction ) < 0.001f )
		return false;

	result = vector3( 
		math::rad2deg( -asinf( direction.y / vector3::magnitude( direction ) ) ), 
		math::rad2deg( atan2f( direction.x, direction.z ) ), 
		0.f 
	);

	return true;
}

void features::memory_aimbot( const std::pair<rust::base_player*, cached_player>* target ) {
	rust::player_input* input = local_player.entity->input;
	if ( !is_valid_ptr( input ) )
		return;

	vector3 angle;
	if ( !calc_angle( local_player.eyes_position, target->second.bone_data.positions[ 1 ], angle ) )
		return;

	input->body_angles = vector2( angle.x, angle.y );
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