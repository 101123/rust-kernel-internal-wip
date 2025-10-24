#pragma once

#include "sdk/declare.h"

namespace features {
	void graphics();
	void bright_night();
	void weapon_modifiers( rust::base_projectile* weapon );
	bool update_rocket_trajectory( rust::base_launcher* launcher );
	void looking_at( rust::base_player* local_player );
	void drop_box();
	void auto_upgrade_impl( rust::held_entity* held_entity );
}