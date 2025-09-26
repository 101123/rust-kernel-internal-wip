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

void features::weapon_modifier() {

}