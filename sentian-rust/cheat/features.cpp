#include "features.h"
#include "sdk/sdk.h"
#include "vars.h"

void features::graphics() {
	
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
}