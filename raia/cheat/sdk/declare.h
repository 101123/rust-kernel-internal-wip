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
	namespace network {
		class connection;
	}

	class base_networkable;
	class base_entity;
	class base_combat_entity;
	class item;
	class held_entity;
	class player_eyes;
	class base_player;
	class base_projectile;
	class base_launcher;
	class model;
	class networkable;
	class item_container;
	class player_inventory;
	class world_item;
	class projectile;
	class player_projectile_update;

	using networkable_id = uint64_t;
}

struct cached_entity;
struct cached_combat_entity;
struct cached_player;

struct IUnknown;
struct ID3D11ShaderResourceView;