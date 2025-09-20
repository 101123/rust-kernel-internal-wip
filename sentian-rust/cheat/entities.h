#pragma once

#include "math/vec3.h"
#include "vars.h"

#include <vector>

namespace unity {
	class transform;
}

namespace rust {
	class base_networkable;
	class base_entity;
	class base_player;
	class player_eyes;
	class player_inventory;
}

class cacher {
public:
	using add_to_cache_t = void( * )( cacher*, rust::base_networkable*, cvar_visual* );
	using remove_from_cache_t = void( * )( cacher*, rust::base_networkable*, cvar_visual* );

	cacher() {};
	cacher( void* user_data, auto add_to_cache, auto remove_from_cache ) :
		m_user_data( user_data ), m_add_to_cache( add_to_cache ), m_remove_from_cache( remove_from_cache ) {};

	void* get_user_data() {
		return m_user_data;
	}

	void add_to_cache( rust::base_networkable* entity, cvar_visual* visual ) {
		m_add_to_cache( this, entity, visual );
	}

	void remove_from_cache( rust::base_networkable* entity, cvar_visual* visual ) {
		m_remove_from_cache( this, entity, visual );
	}

private:
	void* m_user_data;
	add_to_cache_t m_add_to_cache;
	remove_from_cache_t m_remove_from_cache;
};

struct cache_specifier {
	cacher m_cacher;
	cvar_visual* m_visual;
};

struct cached_entity {
	rust::base_entity* m_entity;
	Vector3 m_position;
	cvar_visual* m_visual;

	cached_entity( rust::base_entity* entity, Vector3 position, cvar_visual* visual ) :
		m_entity( entity ), m_position( position ), m_visual( visual ) {};
};

struct cached_combat_entity : public cached_entity {
	int m_lifestate;
	float m_health;

	cached_combat_entity( rust::base_entity* entity, Vector3 position, cvar_visual* visual, int lifestate, float health )
		: cached_entity( entity, position, visual ), m_lifestate( lifestate ), m_health( health ) {}
};

struct cached_belt_item {
	bool present;
	int amount;
	wchar_t name[ 128 ];
};

struct cached_bone_data {
	unity::transform* transforms[ 18 ];
	Vector3 positions[ 18 ];
};

struct cached_player {
	rust::base_player* entity;
	bool init;
	bool scientist;
	cached_bone_data bone_data;
	wchar_t name[ 128 ];
	int active_item;
	cached_belt_item belt_items[ 6 ];
	rust::player_eyes* eyes;
	rust::player_inventory* inventory;
};

template <typename K, typename V>
using entity_vector = const std::vector<std::pair<K, V>>&;

struct entity_collection {
	entity_vector<rust::base_player*, cached_player> players;
	entity_vector<rust::base_entity*, cached_entity> resources;
};

namespace entity_manager {
	inline util::mutex cache_lock;

	void init();
	void destroy();

	bool belongs_in_cache( rust::base_networkable* entity, cache_specifier* specifier );

	void add_to_cache( rust::base_networkable* entity, cache_specifier* specifier );
	void remove_from_cache( rust::base_networkable* entity, cache_specifier* specifier );

	void update();

	entity_collection get_entities();
}