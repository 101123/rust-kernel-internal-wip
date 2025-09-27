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

struct recoil_data {
	uint32_t prefab_id;
	float yaw_min;
	float yaw_max;
	float pitch_min;
	float pitch_max;
};

util::array<recoil_data, 64> weapon_recoil;

const recoil_data* get_recoil_data( rust::base_projectile* base_projectile ) {
	for ( const auto& recoil_data : weapon_recoil ) {
		if ( recoil_data.prefab_id == base_projectile->prefab_id ) {
			return &recoil_data;
		}
	}
	
	return nullptr;
}

void features::weapon_modifiers( rust::base_projectile* base_projectile ) {
	rust::recoil_properties* recoil = base_projectile->is<rust::flint_strike_weapon>() ?
		( ( rust::flint_strike_weapon* )base_projectile )->strike_recoil : base_projectile->recoil;

	if ( is_valid_ptr( recoil ) ) {
		recoil = is_valid_ptr( recoil->new_recoil_override ) ? recoil->new_recoil_override : recoil;

		const recoil_data* recoil_data = get_recoil_data( base_projectile );

		if ( !recoil_data ) {
			recoil_data = weapon_recoil.add( { base_projectile->prefab_id,
				recoil->recoil_yaw_min, recoil->recoil_yaw_max, recoil->recoil_pitch_min, recoil->recoil_pitch_max } );
		}

		// What the fuck?
		if ( !recoil_data )
			return;

		float yaw_modifier = weapon_data.mods.recoil_scale;
		float pitch_modifier = weapon_data.mods.recoil_scale;

		if ( recoil_modifier.enabled ) {
			yaw_modifier *= recoil_modifier.yaw_scale;
			pitch_modifier *= recoil_modifier.pitch_scale;
		}

		recoil->recoil_yaw_min = recoil_data->yaw_min * yaw_modifier;
		recoil->recoil_yaw_max = recoil_data->yaw_max * yaw_modifier;
		recoil->recoil_pitch_min = recoil_data->pitch_min * pitch_modifier;
		recoil->recoil_pitch_max = recoil_data->pitch_max * pitch_modifier;
	}

	// TODO: Bow spread comes from BaseProjectile.aimCone
	if ( base_projectile->is<rust::bow_weapon>() ) {

	}

	else {
		float sight_aim_cone_scale = weapon_data.mods.sight_aim_cone_scale;
		float hip_aim_cone_scale = weapon_data.mods.hip_aim_cone_scale;

		if ( spread_modifier.enabled ) {
			sight_aim_cone_scale *= spread_modifier.scale;
			hip_aim_cone_scale *= spread_modifier.scale;
		}

		base_projectile->sight_aim_cone_scale = sight_aim_cone_scale;
		base_projectile->hip_aim_cone_scale = hip_aim_cone_scale;
	}
}