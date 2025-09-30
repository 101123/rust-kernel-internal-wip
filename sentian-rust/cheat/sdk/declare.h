#pragma once

#include <cstdint>

namespace sys {
	class string;
}

namespace unity {
	class object;
	class game_object;
	class component;
	class behaviour;
	class transform;
	class texture;
}

namespace rust {
	class base_networkable;
	class base_entity;

	class item;
	class held_entity;

	class player_eyes;
	class base_player;

	class base_projectile;
	class base_launcher;

	class model;
	class networkable;
	class item_container;

	using networkable_id = uint64_t;
}