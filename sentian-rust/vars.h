#pragma once

#include "util.h"

#include <cstdint>

#define COL32( r, g, b, a ) ( ( ( uint32_t )( a ) << 24 ) | ( ( uint32_t )( b ) << 16 ) | ( ( uint32_t ) ( g ) << 8 ) | ( ( uint32_t )( r ) << 0 ) )

#define COL32_WHITE COL32( 255, 255, 255, 255 )
#define COL32_BLACK COL32( 0, 0, 0, 255 )

#define COL32_RED COL32( 255, 0, 0, 255 )
#define COL32_GREEN COL32( 0, 255, 0, 255 )
#define COL32_BLUE COL32( 0, 255, 255, 255 )

template <typename T>
struct cvar_t {
	static inline cvar_t* s_instances[ 256 ];
	static inline int s_count;

	cvar_t( const cvar_t& ) = delete;
	cvar_t( cvar_t&& ) = delete;
	void operator=( const cvar_t& ) = delete;
	void operator=( cvar_t& ) = delete;

	cvar_t( uint64_t hash, T value = 0 ) : m_hash( hash ), m_value( value ), m_default_value( value ) {
		s_instances[ s_count++ ] = this;
	}

	T* operator&() {
		return &m_value;
	}

	cvar_t* operator*() {
		return this;
	}

	operator T() {
		return m_value;
	}

	T operator=( T value ) {
		return m_value = value;
	}

	uint64_t m_hash;
	T m_value;
	T m_default_value;
};

using cvar = cvar_t<bool>;
using cvar_i = cvar_t<int>;
using cvar_ui = cvar_t<unsigned int>;
using cvar_f = cvar_t<float>;

#define DEFINE_FEATURE( name, variables ) \
    struct name##feature { \
        variables \
    }; \
    inline name##feature name;

struct visual {
	cvar m_enabled;
	cvar_i m_maximum_distance;
	cvar_ui m_color;
	const char* m_display_name;
};

#define WRAP_VISUAL( name, enabled, maximum_distance, color ) { \
    cvar( H( name " Enabled" ), enabled ), \
	cvar_i( H( name " Maximum Distance" ), maximum_distance ), \
    cvar_ui( H( name " Color" ), color ), \
	name } 

struct player_visuals {
	cvar m_enabled;
	cvar m_box;
	cvar_ui m_box_color;
	cvar m_skeleton;
	cvar_ui m_skeleton_color;
	cvar m_name;
	cvar_ui m_name_color;
	cvar m_distance;
	cvar_ui m_distance_color;
	cvar m_held_item;
	cvar_i m_held_item_type;
	cvar_ui m_held_item_color;
	cvar m_belt;
	cvar_i m_belt_type;
	cvar_i m_belt_fov;
	cvar_i m_maximum_distance;
};

#define WRAP_PLAYER_VISUALS( name, color ) { \
	cvar( H( name " Enabled" ), true ), \
	cvar( H( name " Box" ), true ), \
	cvar_ui( H( name " Box Color" ), color ), \
	cvar( H( name " Skeleton" ), true ), \
	cvar_ui( H( name " Skeleton Color" ), color ), \
	cvar( H( name " Name" ), true ), \
	cvar_ui( H( name " Name Color" ), color ), \
	cvar( H( name " Distance" ), true ), \
	cvar_ui( H( name " Distance Color" ), color ), \
	cvar( H( name " Held Item" ), true ), \
	cvar_i( H( name " Held Item Type" ), 0 ), \
	cvar_ui( H( name " Held Item Color" ), color ), \
	cvar( H( name " Belt" ), true ), \
	cvar_i( H( name " Belt Type" ), 0 ), \
	cvar_i( H( name " Belt FOV" ), 200 ), \
	cvar_i( H( name " Maximum Distance" ), 500 ) }

inline player_visuals cvar_players = WRAP_PLAYER_VISUALS( "Players", COL32( 255, 255, 255, 255 ) );
inline visual cvar_wounded = WRAP_VISUAL( "Wounded", true, 500, COL32( 255, 0, 0, 255 ) );
inline visual cvar_sleeper = WRAP_VISUAL( "Sleeper", false, 30, COL32( 255, 255, 255, 255 ) );
inline visual cvar_corpse = WRAP_VISUAL( "Corpse", true, 100, COL32( 255, 255, 255, 255 ) );

inline player_visuals cvar_scientists = WRAP_PLAYER_VISUALS( "Scientists", COL32( 125, 195, 255, 255 ) );





inline visual cvar_stone_ore = WRAP_VISUAL( "Stone Ore", false, 500, COL32( 189, 195, 199, 255 ) );
inline visual cvar_metal_ore = WRAP_VISUAL( "Metal Ore", false, 500, COL32( 230, 126, 34, 255 ) );
inline visual cvar_sulfur_ore = WRAP_VISUAL( "Sulfur Ore", false, 500, COL32( 241, 196, 15, 255 ) );
inline visual cvar_wood_pile = WRAP_VISUAL( "Wood Pile", false, 500, COL32( 192, 57, 43, 255 ) );
inline cvar_i cvar_resources_maximum_distance = cvar_i( H( "Resources Maximum Distance" ), 500 );

inline visual cvar_hemp = WRAP_VISUAL( "Hemp", false, 500, COL32( 106, 176, 76, 255 ) );
inline visual cvar_mushroom = WRAP_VISUAL( "Mushroom", false, 500, COL32( 205, 97, 51, 255 ) );
inline visual cvar_pumpkin = WRAP_VISUAL( "Pumpkin", false, 500, COL32( 255, 121, 63, 255 ) );
inline visual cvar_corn = WRAP_VISUAL( "Corn", false, 500, COL32( 255, 218, 121, 255 ) );
inline visual cvar_potato = WRAP_VISUAL( "Potato", false, 500, COL32( 204, 142, 53, 255 ) );
inline visual cvar_stone = WRAP_VISUAL( "Stone", false, 500, COL32( 189, 195, 199, 255 ) );
inline visual cvar_metal = WRAP_VISUAL( "Metal", false, 500, COL32( 230, 126, 34, 255 ) );
inline visual cvar_sulfur = WRAP_VISUAL( "Sulfur", false, 500, COL32( 241, 196, 15, 255 ) );
inline visual cvar_wood = WRAP_VISUAL( "Wood", false, 500, COL32( 192, 57, 43, 255 ) );
inline cvar_i cvar_collectables_maximum_distance = cvar_i( H( "Collectables Maximum Distance" ), 500 );

inline visual cvar_vending_machine = WRAP_VISUAL( "Vending Machine", false, 500, COL32( 255, 255, 255, 255 ) );
inline visual cvar_wb1 = WRAP_VISUAL( "Tier 1 Workbench", false, 500, COL32( 255, 255, 255, 255 ) );
inline visual cvar_wb2 = WRAP_VISUAL( "Tier 2 Workbench", false, 500, COL32( 255, 255, 255, 255 ) );
inline visual cvar_wb3 = WRAP_VISUAL( "Tier 3 Workbench", false, 500, COL32( 255, 255, 255, 255 ) );
inline visual cvar_sleeping_bag = WRAP_VISUAL( "Sleeping Bag", false, 500, COL32( 255, 255, 255, 255 ) );
inline visual cvar_bed = WRAP_VISUAL( "Bed", false, 500, COL32( 255, 255, 255, 255 ) );
inline cvar_i cvar_deployables_maximum_distance = cvar_i( H( "Deployables Maximum Distance" ), 500 );

inline visual cvar_black_berry = WRAP_VISUAL( "Black Berry", false, 500, COL32( 106, 176, 76, 255 ) );
inline visual cvar_blue_berry = WRAP_VISUAL( "Blue Berry", false, 500, COL32( 205, 97, 51, 255 ) );
inline visual cvar_green_berry = WRAP_VISUAL( "Green Berry", false, 500, COL32( 255, 121, 63, 255 ) );
inline visual cvar_red_berry = WRAP_VISUAL( "Red Berry", false, 500, COL32( 255, 218, 121, 255 ) );
inline visual cvar_white_berry = WRAP_VISUAL( "White Berry", false, 500, COL32( 204, 142, 53, 255 ) );
inline visual cvar_yellow_berry = WRAP_VISUAL( "Yellow Berry", false, 500, COL32( 189, 195, 199, 255 ) );
inline cvar_i cvar_berries_maximum_distance = cvar_i( H( "Berries Maximum Distance" ), 500 );

inline visual cvar_rowboat = WRAP_VISUAL( "Rowboat", false, 500, COL32( 252, 66, 123, 255 ) );
inline visual cvar_rhib = WRAP_VISUAL( "Rhib", false, 500, COL32( 50, 255, 126, 255 ) );
inline visual cvar_minicopter = WRAP_VISUAL( "Minicopter", false, 500, COL32( 255, 77, 77, 255 ) );
inline visual cvar_scrap_helicopter = WRAP_VISUAL( "Scrap Helicopter", false, 500, COL32( 125, 95, 255, 255 ) );
inline visual cvar_attack_helicopter = WRAP_VISUAL( "Attack Helicopter", false, 500, COL32( 255, 255, 255, 255 ) );
inline visual cvar_tugboat = WRAP_VISUAL( "Tugboat", false, 500, COL32( 255, 255, 255, 255 ) );
inline visual cvar_submarine = WRAP_VISUAL( "Submarine", false, 500, COL32( 255, 255, 255, 255 ) );
inline visual cvar_hot_air_balloon = WRAP_VISUAL( "Hot Air Ballon", false, 500, COL32( 255, 255, 255, 255 ) );
inline visual cvar_diver_propulsion_vehicle = WRAP_VISUAL( "Diver Propulsion Vehicle", false, 500, COL32( 255, 255, 255, 255 ) );
inline visual cvar_patrol_helicopter = WRAP_VISUAL( "Patrol Helicopter", false, 500, COL32( 255, 56, 56, 255 ) );
inline visual cvar_bradley = WRAP_VISUAL( "Bradley", false, 500, COL32( 255, 56, 56, 255 ) );
inline cvar_i cvar_vehicles_maximum_distance = cvar_i( H( "Vehicles Maximum Distance" ), 500 );

inline visual cvar_bear = WRAP_VISUAL( "Bear", false, 500, COL32( 26, 188, 156, 255 ) );
inline visual cvar_boar = WRAP_VISUAL( "Boar", false, 500, COL32( 46, 204, 113, 255 ) );
inline visual cvar_chicken = WRAP_VISUAL( "Chicken", false, 500, COL32( 241, 196, 15, 255 ) );
inline visual cvar_horse = WRAP_VISUAL( "Horse", false, 500, COL32( 231, 76, 60, 255 ) );
inline visual cvar_stag = WRAP_VISUAL( "Stag", false, 500, COL32( 142, 68, 173, 255 ) );
inline visual cvar_wolf = WRAP_VISUAL( "Wolf", false, 500, COL32( 155, 89, 182, 255 ) );
inline visual cvar_shark = WRAP_VISUAL( "Shark", false, 500, COL32( 255, 255, 255, 255 ) );
inline visual cvar_bee_swarm = WRAP_VISUAL( "Bee Swarm", false, 500, COL32( 150, 90, 10, 255 ) );
inline visual cvar_tiger = WRAP_VISUAL( "Tiger", false, 500, COL32( 245, 150, 60, 255 ) );
inline visual cvar_panther = WRAP_VISUAL( "Panther", false, 500, COL32( 90, 70, 50, 255 ) );
inline visual cvar_crocodile = WRAP_VISUAL( "Crocodile", false, 500, COL32( 90, 160, 85, 255 ) );
inline visual cvar_snake = WRAP_VISUAL( "Snake", false, 500, COL32( 90, 200, 200, 255 ) );
inline cvar_i cvar_animals_maximum_distance = cvar_i( H( "Animals Maximum Distance" ), 500 );

inline visual cvar_tool_cupboard = WRAP_VISUAL( "Tool Cupboard", false, 500, COL32( 255, 255, 255, 255 ) );
inline cvar cvar_tool_cupboard_upkeep = cvar( H( "Tool Cupboard Upkeep" ), true );
inline visual cvar_backpack = WRAP_VISUAL( "Backpack", false, 500, COL32( 255, 255, 255, 255 ) );

inline visual cvar_red_barrel = WRAP_VISUAL( "Red Barrel", false, 500, COL32( 26, 188, 156, 255 ) );
inline visual cvar_blue_barrel = WRAP_VISUAL( "Blue Barrel", false, 500, COL32( 46, 204, 113, 255 ) );
inline visual cvar_oil_barrel = WRAP_VISUAL( "Oil Barrel", false, 500, COL32( 241, 196, 15, 255 ) );
inline visual cvar_diesel_barrel = WRAP_VISUAL( "Diesel Barrel", false, 500, COL32( 231, 76, 60, 255 ) );
inline cvar_i cvar_barrels_maximum_distance = cvar_i( H( "Barrels Maximum Distance" ), 500 );

inline visual cvar_minecart = WRAP_VISUAL( "Minecart", false, 500, COL32( 252, 66, 123, 255 ) );
inline visual cvar_vehicle_parts = WRAP_VISUAL( "Vehicle Parts", false, 500, COL32( 50, 255, 126, 255 ) );
inline visual cvar_tech_parts = WRAP_VISUAL( "Tech Parts", false, 500, COL32( 255, 77, 77, 255 ) );
inline visual cvar_food_crate = WRAP_VISUAL( "Food Crate", false, 500, COL32( 125, 95, 255, 255 ) );
inline visual cvar_medical_crate = WRAP_VISUAL( "Medical Crate", false, 500, COL32( 255, 255, 255, 255 ) );
inline visual cvar_tool_crate = WRAP_VISUAL( "Tool Crate", false, 500, COL32( 255, 255, 255, 255 ) );
inline visual cvar_ammo_crate = WRAP_VISUAL( "Ammo Crate", false, 500, COL32( 255, 255, 255, 255 ) );
inline visual cvar_fuel_crate = WRAP_VISUAL( "Fuel Crate", false, 500, COL32( 255, 255, 255, 255 ) );
inline visual cvar_basic_crate = WRAP_VISUAL( "Basic Crate", false, 500, COL32( 255, 255, 255, 255 ) );
inline visual cvar_normal_crate = WRAP_VISUAL( "Normal Crate", false, 500, COL32( 255, 56, 56, 255 ) );
inline visual cvar_underwater_crate = WRAP_VISUAL( "Underwater Crate", false, 500, COL32( 255, 56, 56, 255 ) );
inline visual cvar_military_crate = WRAP_VISUAL( "Military Crate", false, 500, COL32( 255, 56, 56, 255 ) );
inline visual cvar_elite_crate = WRAP_VISUAL( "Elite Crate", false, 500, COL32( 255, 56, 56, 255 ) );
inline visual cvar_bradley_crate = WRAP_VISUAL( "Bradley Crate", false, 500, COL32( 255, 56, 56, 255 ) );
inline visual cvar_heli_crate = WRAP_VISUAL( "Heli Crate", false, 500, COL32( 255, 56, 56, 255 ) );
inline cvar_i cvar_crates_maximum_distance = cvar_i( H( "Crates Maximum Distance" ), 500 );

inline visual cvar_hackable_crate = WRAP_VISUAL( "Hackable Crate", false, 500, COL32( 255, 56, 56, 255 ) );
inline visual cvar_supply_drop = WRAP_VISUAL( "Supply Drop", false, 500, COL32( 255, 56, 56, 255 ) );

inline visual cvar_shotgun_trap = WRAP_VISUAL( "Shotgun Trap", false, 500, COL32( 26, 188, 156, 255 ) );
inline visual cvar_flame_turret = WRAP_VISUAL( "Flame Turret", false, 500, COL32( 46, 204, 113, 255 ) );
inline visual cvar_auto_turret = WRAP_VISUAL( "Auto Turret", false, 500, COL32( 241, 196, 15, 255 ) );
inline cvar cvar_auto_turret_ignore_offline = cvar( H( "Auto Turret Ignore Offline" ), true );
inline visual cvar_sam_site = WRAP_VISUAL( "SAM Site", false, 500, COL32( 231, 76, 60, 255 ) );
inline cvar cvar_sam_site_ignore_offline = cvar( H( "SAM Site Ignore Offline" ), true );
inline visual cvar_land_mine = WRAP_VISUAL( "Land Mine", false, 500, COL32( 142, 68, 173, 255 ) );
inline visual cvar_bear_trap = WRAP_VISUAL( "Bear Trap", false, 500, COL32( 155, 89, 182, 255 ) );
inline cvar cvar_bear_trap_ignore_unarmed = cvar( H( "Bear Trap Ignored Unarmed" ), true );
inline cvar_i cvar_traps_maximum_distance = cvar_i( H( "Traps Maximum Distance" ), 500 );

inline visual cvar_dropped_weapon = WRAP_VISUAL( "Dropped Weapon", false, 500, COL32( 26, 188, 156, 255 ) );
inline visual cvar_dropped_construction = WRAP_VISUAL( "Dropped Construction", false, 500, COL32( 46, 204, 113, 255 ) );
inline visual cvar_dropped_items = WRAP_VISUAL( "Dropped Items", false, 500, COL32( 241, 196, 15, 255 ) );
inline visual cvar_dropped_resources = WRAP_VISUAL( "Dropped Resources", false, 500, COL32( 231, 76, 60, 255 ) );
inline visual cvar_dropped_attire = WRAP_VISUAL( "Dropped Attire", false, 500, COL32( 142, 68, 173, 255 ) );
inline visual cvar_dropped_tool = WRAP_VISUAL( "Dropped Tool", false, 500, COL32( 155, 89, 182, 255 ) );
inline visual cvar_dropped_medical = WRAP_VISUAL( "Dropped Medical", false, 500, COL32( 26, 188, 156, 255 ) );
inline visual cvar_dropped_food = WRAP_VISUAL( "Dropped Food", false, 500, COL32( 46, 204, 113, 255 ) );
inline visual cvar_dropped_ammunition = WRAP_VISUAL( "Dropped Ammunition", false, 500, COL32( 241, 196, 15, 255 ) );
inline visual cvar_dropped_traps = WRAP_VISUAL( "Dropped Traps", false, 500, COL32( 231, 76, 60, 255 ) );
inline visual cvar_dropped_misc = WRAP_VISUAL( "Dropped Misc", false, 500, COL32( 142, 68, 173, 255 ) );
inline visual cvar_dropped_component = WRAP_VISUAL( "Dropped Component", false, 500, COL32( 155, 89, 182, 255 ) );
inline visual cvar_dropped_electrical = WRAP_VISUAL( "Dropped Electrical", false, 500, COL32( 231, 76, 60, 255 ) );
inline visual cvar_dropped_fun = WRAP_VISUAL( "Dropped Fun", false, 500, COL32( 142, 68, 173, 255 ) );
inline cvar_i cvar_dropped_items_maximum_distance = cvar_i( H( "Dropped Items Maximum Distance" ), 500 );

inline cvar glow = cvar( H( "Glow" ), true );
inline cvar_ui glow_outline_color = cvar_ui( H( "Glow Outline Color" ), COL32( 255, 255, 255, 255 ) );
inline cvar_f glow_blur_scale = cvar_f( H( "Glow Blur Scale" ), 0.75f );
inline cvar_f glow_outline_scale = cvar_f( H( "Glow Outline Scale" ), 0.5f );