#pragma once

#include "sdk/declare.h"

#include <utility>

struct cached_player;

namespace features {
	void graphics();
	void bright_night();
	void weapon_modifiers( rust::base_projectile* weapon );
	void memory_aimbot( const std::pair<rust::base_player*, cached_player>* target );
	bool update_rocket_trajectory( rust::base_launcher* launcher );
	void looking_at( rust::base_player* local_player );
}