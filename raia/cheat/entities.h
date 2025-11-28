#pragma once

#define SNAPSHOT_COUNT 25

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
	char name[ 256 ];
};

struct cached_combat_entity : public cached_entity {
	int lifestate;
	float health;
	float max_health;
};

struct cached_belt_item {
	bool present;
	ID3D11ShaderResourceView* srv;
	int32_t item_id;
	float condition;
	float max_condition;
	int32_t amount;
	bool has_ammo;
	int32_t ammo_count;
	int32_t max_ammo_count;
	char name[ 256 ];
};

struct cached_bone_data {
	unity::transform* transforms[ 18 ];
	vector3 positions[ 18 ];
};

struct cached_position_snapshot {
	vector3 position;
	float time;
};

struct cached_velocity_data {
	cached_position_snapshot snapshots[ SNAPSHOT_COUNT ];
	int32_t index;
};

struct cached_player {
	bool init;
	bool scientist;
	rust::networkable_id net_id;
	uint64_t user_id;
	cached_bone_data bone_data;
	cached_velocity_data velocity_data;
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
	char name[ 256 ];
};

struct cached_building_block {
	unity::transform* transform;
	vector3 position;
};

template <typename K, typename V>
using entity_vector = const std::vector<std::pair<K, V>>&;

struct entity_collection {
	entity_vector<rust::base_entity*, cached_entity> entities;
	entity_vector<rust::base_entity*, cached_named_entity> named_entities;
	entity_vector<rust::base_combat_entity*, cached_combat_entity> combat_entities;
	entity_vector<rust::world_item*, cached_dropped_item> dropped_items;
	entity_vector<rust::base_player*, cached_player> players;
	entity_vector<rust::building_block*, cached_building_block> building_blocks;
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