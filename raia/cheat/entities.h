#pragma once

#include "sdk/declare.h"

#include "math/vec3.h"
#include "vars.h"

#include <vector>

struct cache_specifier {
	const void** cache_functions;
	cvar_visual* visual;
	bool update;
};

struct cached_entity {
	int32_t flags;
	unity::transform* transform;
	vector3 position;
	cvar_visual* visual;
	bool update;
};

struct cached_named_entity : public cached_entity {
	uint64_t steam_id;
	wchar_t name[ 128 ];
};

struct cached_combat_entity : public cached_entity {
	int lifestate;
	float health;
	float max_health;
};

struct cached_belt_item {
	bool present;
	ID3D11ShaderResourceView* srv;
	float condition;
	float max_condition;
	int32_t amount;
	wchar_t name[ 128 ];
};

struct cached_bone_data {
	unity::transform* transforms[ 18 ];
	vector3 positions[ 18 ];
};

struct cached_player {
	bool init;
	bool scientist;
	uint64_t steam_id;
	cached_bone_data bone_data;
	char name[ 256 ];
	int32_t active_item_idx;
	int32_t active_item_id;
	cached_belt_item belt_items[ 6 ];
	rust::player_eyes* eyes;
	rust::player_inventory* inventory;
	ID3D11ShaderResourceView* avatar_srv;
	bool visible;
	uint64_t team_id;
	int32_t player_flags;
	int32_t lifestate;
};

struct cached_dropped_item {
	bool init;
	unity::transform* transform;
	vector3 position;
	int32_t amount;
	int32_t category;
	wchar_t name[ 128 ];
};

template <typename K, typename V>
using entity_vector = const std::vector<std::pair<K, V>>&;

struct entity_collection {
	entity_vector<rust::base_entity*, cached_entity> entities;
	entity_vector<rust::base_entity*, cached_named_entity> named_entities;
	entity_vector<rust::base_combat_entity*, cached_combat_entity> combat_entities;
	entity_vector<rust::world_item*, cached_dropped_item> dropped_items;
	entity_vector<rust::base_player*, cached_player> players;
};

namespace entity_manager {
	inline util::mutex cache_lock;

	void init();
	void destroy();

	bool belongs_in_cache( rust::base_networkable* entity, cache_specifier* specifier );
	void add_to_cache( rust::base_networkable* entity, cache_specifier* specifier );
	void remove_from_cache( rust::base_networkable* entity, cache_specifier* specifier );

	void update();
	void invalidate_cache();

	entity_collection get_entities();
}