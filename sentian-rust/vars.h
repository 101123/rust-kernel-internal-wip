#pragma once

#include "util.h"
#include "renderer.h"
#include "vk.h"

namespace rust {
	class base_player;
	class base_projectile;
}

template <typename T>
struct cvar_t {
	static inline cvar_t* s_instances[ 256 ];
	static inline int s_count;

	cvar_t( const cvar_t& ) = delete;
	cvar_t( cvar_t&& ) = delete;
	void operator=( const cvar_t& ) = delete;
	void operator=( cvar_t& ) = delete;

	cvar_t( uint64_t hash, T value = 0 ) : hash( hash ), value( value ), default_value( value ) {
		s_instances[ s_count++ ] = this;
	}

	T* operator&() {
		return &value;
	}

	cvar_t* operator*() {
		return this;
	}

	operator T() const {
		return value;
	}

	T operator=( T new_value ) {
		return value = new_value;
	}

	uint64_t hash;
	T value;
	T default_value;
};

using cvar = cvar_t<bool>;
using cvar_i = cvar_t<int>;
using cvar_ui = cvar_t<unsigned int>;
using cvar_f = cvar_t<float>;

struct cvar_visual {
	cvar enabled;
	cvar_ui maximum_distance;
	cvar_ui color;
	const char* display_name;
};

#define WRAP_VISUAL( Name, Enabled, MaximumDistance, Color ) { \
    cvar( H( Name " Enabled" ), Enabled ), \
	cvar_ui( H( Name " Maximum Distance" ), MaximumDistance ), \
    cvar_ui( H( Name " Color" ), Color ), \
	Name } 

enum trigger_type {
	toggle,
	hold
};

struct cvar_bind {
	cvar enabled;
	cvar_ui trigger_type;
	cvar_ui key;
};

#define WRAP_BIND( Name, Enabled, TriggerType, Key ) { \
    cvar( H( Name " Enabled" ), Enabled ), \
	cvar_ui( H( Name " Trigger Type" ), TriggerType ), \
    cvar_ui( H( Name " Key" ), Key ) }

struct cvar_player_visuals {
	cvar enabled;
	cvar_ui visible_color;
	cvar_ui occluded_color;
	cvar bounding_box;
	cvar_ui bounding_box_color;
	cvar skeleton;
	cvar_ui skeleton_color;
	cvar name;
	cvar_ui name_color;
	cvar distance;
	cvar_ui distance_color;
	cvar held_item;
	cvar held_item_icon;
	cvar held_item_text;
	cvar_ui held_item_color;
	cvar belt;
	cvar_i belt_type;
	cvar_i belt_fov;
	cvar_i maximum_distance;
};

#define WRAP_PLAYER_CONFIGURATION( Name, Color ) { \
	cvar( H( Name " Enabled" ), true ), \
	cvar_ui( H( Name " Visible Color" ), Color ), \
	cvar_ui( H( Name " Occluded Color" ), Color ), \
	cvar( H( Name " Bounding Box" ), true ), \
	cvar_ui( H( Name " Bounding Box Color" ), Color ), \
	cvar( H( Name " Skeleton" ), true ), \
	cvar_ui( H( Name " Skeleton Color" ), Color ), \
	cvar( H( Name " Name" ), true ), \
	cvar_ui( H( Name " Name Color" ), Color ), \
	cvar( H( Name " Distance" ), true ), \
	cvar_ui( H( Name " Distance Color" ), Color ), \
	cvar( H( Name " Held Item" ), true ), \
	cvar( H( Name " Held Item Icon" ), true ), \
	cvar( H( Name " Held Item Text" ), true ), \
	cvar_ui( H( Name " Held Item Color" ), Color ), \
	cvar( H( Name " Belt" ), true ), \
	cvar_i( H( Name " Belt Type" ), 0 ), \
	cvar_i( H( Name " Belt FOV" ), 200 ), \
	cvar_i( H( Name " Maximum Distance" ), 500 ) }

inline cvar_player_visuals player_visuals = WRAP_PLAYER_CONFIGURATION( "Players", COL32( 255, 255, 255, 255 ) );
inline cvar_visual cvar_wounded = WRAP_VISUAL( "Wounded", true, 500, COL32( 255, 0, 0, 255 ) );
inline cvar_visual cvar_sleeper = WRAP_VISUAL( "Sleeper", false, 30, COL32( 255, 255, 255, 255 ) );
inline cvar_visual cvar_corpse = WRAP_VISUAL( "Corpse", true, 100, COL32( 255, 255, 255, 255 ) );

inline cvar_player_visuals scientist_visuals = WRAP_PLAYER_CONFIGURATION( "Scientists", COL32( 125, 195, 255, 255 ) );

inline cvar_visual stone_ore = WRAP_VISUAL( "Stone Ore", false, 500, COL32( 189, 195, 199, 255 ) );
inline cvar_visual metal_ore = WRAP_VISUAL( "Metal Ore", false, 500, COL32( 230, 126, 34, 255 ) );
inline cvar_visual sulfur_ore = WRAP_VISUAL( "Sulfur Ore", false, 500, COL32( 241, 196, 15, 255 ) );
inline cvar_visual wood_pile = WRAP_VISUAL( "Wood Pile", false, 500, COL32( 192, 57, 43, 255 ) );

inline cvar_visual hemp = WRAP_VISUAL( "Hemp", false, 500, COL32( 106, 176, 76, 255 ) );
inline cvar_visual mushroom = WRAP_VISUAL( "Mushroom", false, 500, COL32( 205, 97, 51, 255 ) );
inline cvar_visual pumpkin = WRAP_VISUAL( "Pumpkin", false, 500, COL32( 255, 121, 63, 255 ) );
inline cvar_visual corn = WRAP_VISUAL( "Corn", false, 500, COL32( 255, 218, 121, 255 ) );
inline cvar_visual potato = WRAP_VISUAL( "Potato", false, 500, COL32( 204, 142, 53, 255 ) );
inline cvar_visual stone = WRAP_VISUAL( "Stone", false, 500, COL32( 189, 195, 199, 255 ) );
inline cvar_visual metal = WRAP_VISUAL( "Metal", false, 500, COL32( 230, 126, 34, 255 ) );
inline cvar_visual sulfur = WRAP_VISUAL( "Sulfur", false, 500, COL32( 241, 196, 15, 255 ) );
inline cvar_visual wood = WRAP_VISUAL( "Wood", false, 500, COL32( 192, 57, 43, 255 ) );

inline cvar_visual vending_machine = WRAP_VISUAL( "Vending Machine", false, 500, COL32( 255, 255, 255, 255 ) );
inline cvar_visual wb1 = WRAP_VISUAL( "Tier 1 Workbench", false, 500, COL32( 255, 255, 255, 255 ) );
inline cvar_visual wb2 = WRAP_VISUAL( "Tier 2 Workbench", false, 500, COL32( 255, 255, 255, 255 ) );
inline cvar_visual wb3 = WRAP_VISUAL( "Tier 3 Workbench", false, 500, COL32( 255, 255, 255, 255 ) );
inline cvar_visual sleeping_bag = WRAP_VISUAL( "Sleeping Bag", false, 500, COL32( 255, 255, 255, 255 ) );
inline cvar_visual bed = WRAP_VISUAL( "Bed", false, 500, COL32( 255, 255, 255, 255 ) );

inline cvar_visual black_berry = WRAP_VISUAL( "Black Berry", false, 500, COL32( 106, 176, 76, 255 ) );
inline cvar_visual blue_berry = WRAP_VISUAL( "Blue Berry", false, 500, COL32( 205, 97, 51, 255 ) );
inline cvar_visual green_berry = WRAP_VISUAL( "Green Berry", false, 500, COL32( 255, 121, 63, 255 ) );
inline cvar_visual red_berry = WRAP_VISUAL( "Red Berry", false, 500, COL32( 255, 218, 121, 255 ) );
inline cvar_visual white_berry = WRAP_VISUAL( "White Berry", false, 500, COL32( 204, 142, 53, 255 ) );
inline cvar_visual yellow_berry = WRAP_VISUAL( "Yellow Berry", false, 500, COL32( 189, 195, 199, 255 ) );

inline cvar_visual rowboat = WRAP_VISUAL( "Rowboat", false, 500, COL32( 252, 66, 123, 255 ) );
inline cvar_visual rhib = WRAP_VISUAL( "Rhib", false, 500, COL32( 50, 255, 126, 255 ) );
inline cvar_visual minicopter = WRAP_VISUAL( "Minicopter", false, 500, COL32( 255, 77, 77, 255 ) );
inline cvar_visual scrap_helicopter = WRAP_VISUAL( "Scrap Helicopter", false, 500, COL32( 125, 95, 255, 255 ) );
inline cvar_visual attack_helicopter = WRAP_VISUAL( "Attack Helicopter", false, 500, COL32( 255, 255, 255, 255 ) );
inline cvar_visual tugboat = WRAP_VISUAL( "Tugboat", false, 500, COL32( 255, 255, 255, 255 ) );
inline cvar_visual submarine = WRAP_VISUAL( "Submarine", false, 500, COL32( 255, 255, 255, 255 ) );
inline cvar_visual hot_air_balloon = WRAP_VISUAL( "Hot Air Ballon", false, 500, COL32( 255, 255, 255, 255 ) );
inline cvar_visual diver_propulsion_vehicle = WRAP_VISUAL( "Diver Propulsion Vehicle", false, 500, COL32( 255, 255, 255, 255 ) );
inline cvar_visual patrol_helicopter = WRAP_VISUAL( "Patrol Helicopter", false, 500, COL32( 255, 56, 56, 255 ) );
inline cvar_visual bradley = WRAP_VISUAL( "Bradley", false, 500, COL32( 255, 56, 56, 255 ) );

inline cvar_visual bear = WRAP_VISUAL( "Bear", false, 500, COL32( 26, 188, 156, 255 ) );
inline cvar_visual boar = WRAP_VISUAL( "Boar", false, 500, COL32( 46, 204, 113, 255 ) );
inline cvar_visual chicken = WRAP_VISUAL( "Chicken", false, 500, COL32( 241, 196, 15, 255 ) );
inline cvar_visual horse = WRAP_VISUAL( "Horse", false, 500, COL32( 231, 76, 60, 255 ) );
inline cvar_visual stag = WRAP_VISUAL( "Stag", false, 500, COL32( 142, 68, 173, 255 ) );
inline cvar_visual wolf = WRAP_VISUAL( "Wolf", false, 500, COL32( 155, 89, 182, 255 ) );
inline cvar_visual shark = WRAP_VISUAL( "Shark", false, 500, COL32( 255, 255, 255, 255 ) );
inline cvar_visual bee_swarm = WRAP_VISUAL( "Bee Swarm", false, 500, COL32( 150, 90, 10, 255 ) );
inline cvar_visual tiger = WRAP_VISUAL( "Tiger", false, 500, COL32( 245, 150, 60, 255 ) );
inline cvar_visual panther = WRAP_VISUAL( "Panther", false, 500, COL32( 90, 70, 50, 255 ) );
inline cvar_visual crocodile = WRAP_VISUAL( "Crocodile", false, 500, COL32( 90, 160, 85, 255 ) );
inline cvar_visual snake = WRAP_VISUAL( "Snake", false, 500, COL32( 90, 200, 200, 255 ) );

inline cvar_visual cvar_tool_cupboard = WRAP_VISUAL( "Tool Cupboard", false, 500, COL32( 255, 255, 255, 255 ) );
inline cvar cvar_tool_cupboard_upkeep = cvar( H( "Tool Cupboard Upkeep" ), true );
inline cvar_visual cvar_backpack = WRAP_VISUAL( "Backpack", false, 500, COL32( 255, 255, 255, 255 ) );

inline cvar_visual red_barrel = WRAP_VISUAL( "Red Barrel", false, 500, COL32( 26, 188, 156, 255 ) );
inline cvar_visual blue_barrel = WRAP_VISUAL( "Blue Barrel", false, 500, COL32( 46, 204, 113, 255 ) );
inline cvar_visual oil_barrel = WRAP_VISUAL( "Oil Barrel", false, 500, COL32( 241, 196, 15, 255 ) );
inline cvar_visual diesel_barrel = WRAP_VISUAL( "Diesel Barrel", false, 500, COL32( 231, 76, 60, 255 ) );

inline cvar_visual minecart = WRAP_VISUAL( "Minecart", false, 500, COL32( 252, 66, 123, 255 ) );
inline cvar_visual vehicle_parts = WRAP_VISUAL( "Vehicle Parts", false, 500, COL32( 50, 255, 126, 255 ) );
inline cvar_visual tech_parts = WRAP_VISUAL( "Tech Parts", false, 500, COL32( 255, 77, 77, 255 ) );
inline cvar_visual food_crate = WRAP_VISUAL( "Food Crate", false, 500, COL32( 125, 95, 255, 255 ) );
inline cvar_visual medical_crate = WRAP_VISUAL( "Medical Crate", false, 500, COL32( 255, 255, 255, 255 ) );
inline cvar_visual tool_crate = WRAP_VISUAL( "Tool Crate", false, 500, COL32( 255, 255, 255, 255 ) );
inline cvar_visual ammo_crate = WRAP_VISUAL( "Ammo Crate", false, 500, COL32( 255, 255, 255, 255 ) );
inline cvar_visual fuel_crate = WRAP_VISUAL( "Fuel Crate", false, 500, COL32( 255, 255, 255, 255 ) );
inline cvar_visual basic_crate = WRAP_VISUAL( "Basic Crate", false, 500, COL32( 255, 255, 255, 255 ) );
inline cvar_visual normal_crate = WRAP_VISUAL( "Normal Crate", false, 500, COL32( 255, 56, 56, 255 ) );
inline cvar_visual underwater_crate = WRAP_VISUAL( "Underwater Crate", false, 500, COL32( 255, 56, 56, 255 ) );
inline cvar_visual military_crate = WRAP_VISUAL( "Military Crate", false, 500, COL32( 255, 56, 56, 255 ) );
inline cvar_visual elite_crate = WRAP_VISUAL( "Elite Crate", false, 500, COL32( 255, 56, 56, 255 ) );
inline cvar_visual bradley_crate = WRAP_VISUAL( "Bradley Crate", false, 500, COL32( 255, 56, 56, 255 ) );
inline cvar_visual heli_crate = WRAP_VISUAL( "Heli Crate", false, 500, COL32( 255, 56, 56, 255 ) );

inline cvar_visual hackable_crate = WRAP_VISUAL( "Hackable Crate", false, 500, COL32( 255, 56, 56, 255 ) );
inline cvar_visual supply_drop = WRAP_VISUAL( "Supply Drop", false, 500, COL32( 255, 56, 56, 255 ) );

inline cvar_visual shotgun_trap = WRAP_VISUAL( "Shotgun Trap", false, 500, COL32( 26, 188, 156, 255 ) );
inline cvar_visual flame_turret = WRAP_VISUAL( "Flame Turret", false, 500, COL32( 46, 204, 113, 255 ) );
inline cvar_visual auto_turret = WRAP_VISUAL( "Auto Turret", false, 500, COL32( 241, 196, 15, 255 ) );
inline cvar auto_turret_ignore_offline = cvar( H( "Auto Turret Ignore Offline" ), true );
inline cvar_visual sam_site = WRAP_VISUAL( "SAM Site", false, 500, COL32( 231, 76, 60, 255 ) );
inline cvar sam_site_ignore_offline = cvar( H( "SAM Site Ignore Offline" ), true );
inline cvar_visual land_mine = WRAP_VISUAL( "Land Mine", false, 500, COL32( 142, 68, 173, 255 ) );
inline cvar_visual bear_trap = WRAP_VISUAL( "Bear Trap", false, 500, COL32( 155, 89, 182, 255 ) );
inline cvar bear_trap_ignore_unarmed = cvar( H( "Bear Trap Ignored Unarmed" ), true );

inline cvar_visual dropped_weapon = WRAP_VISUAL( "Dropped Weapon", false, 500, COL32( 26, 188, 156, 255 ) );
inline cvar_visual dropped_construction = WRAP_VISUAL( "Dropped Construction", false, 500, COL32( 46, 204, 113, 255 ) );
inline cvar_visual dropped_items = WRAP_VISUAL( "Dropped Items", false, 500, COL32( 241, 196, 15, 255 ) );
inline cvar_visual dropped_resources = WRAP_VISUAL( "Dropped Resources", false, 500, COL32( 231, 76, 60, 255 ) );
inline cvar_visual dropped_attire = WRAP_VISUAL( "Dropped Attire", false, 500, COL32( 142, 68, 173, 255 ) );
inline cvar_visual dropped_tool = WRAP_VISUAL( "Dropped Tool", false, 500, COL32( 155, 89, 182, 255 ) );
inline cvar_visual dropped_medical = WRAP_VISUAL( "Dropped Medical", false, 500, COL32( 26, 188, 156, 255 ) );
inline cvar_visual dropped_food = WRAP_VISUAL( "Dropped Food", false, 500, COL32( 46, 204, 113, 255 ) );
inline cvar_visual dropped_ammunition = WRAP_VISUAL( "Dropped Ammunition", false, 500, COL32( 241, 196, 15, 255 ) );
inline cvar_visual dropped_traps = WRAP_VISUAL( "Dropped Traps", false, 500, COL32( 231, 76, 60, 255 ) );
inline cvar_visual dropped_misc = WRAP_VISUAL( "Dropped Misc", false, 500, COL32( 142, 68, 173, 255 ) );
inline cvar_visual dropped_component = WRAP_VISUAL( "Dropped Component", false, 500, COL32( 155, 89, 182, 255 ) );
inline cvar_visual dropped_electrical = WRAP_VISUAL( "Dropped Electrical", false, 500, COL32( 231, 76, 60, 255 ) );
inline cvar_visual dropped_fun = WRAP_VISUAL( "Dropped Fun", false, 500, COL32( 142, 68, 173, 255 ) );

#define DEFINE_CONTEXT( Name, Variables ) \
    struct Name##_context { \
        Variables \
    }; \
    inline Name##_context Name;

DEFINE_CONTEXT( local_player,
	rust::base_player* entity;
);

DEFINE_CONTEXT( weapon_data,
	struct {
		float projectile_velocity_scale;
		float aim_sway_scale;
		float recoil_scale;
		float sight_aim_cone_scale;
		float hip_aim_cone_scale;

		uint32_t hash;
	} mods;

	float velocity;
	float drag;
	float gravity_modifier;
	float initial_distance;

	uint32_t prefab_id;
	int item_id;
);

DEFINE_CONTEXT( recoil_modifier,
	cvar enabled = cvar( H( "Recoil Modifier" ), true );
	cvar_f yaw_scale = cvar_f( H( "Recoil Yaw Scale" ), 1.f );
	cvar_f pitch_scale = cvar_f( H( "Recoil Pitch Scale" ), 1.f );
);

DEFINE_CONTEXT( spread_modifier,
	cvar enabled = cvar( H( "Spread Modifier" ), true );
	cvar_f scale = cvar_f( H( "Spread Scale" ), 1.f );
);

DEFINE_CONTEXT( sway_modifier,
	cvar enabled = cvar( H( "Sway Modifier" ), true );
	cvar_f scale = cvar_f( H( "Sway Scale" ), 1.f );
);

DEFINE_CONTEXT( thick_bullet,
	cvar enabled = cvar( H( "Thick Bullet" ), false );
	cvar_f thickness = cvar_f( H( "Thickness" ), 1.f );
);

inline cvar force_automatic = cvar( H( "Force Automatic" ), false );

inline cvar instant_eoka = cvar( H( "Instant Eoka" ), false );

inline cvar instant_loot = cvar( H( "Instant Loot" ), true );

inline cvar no_attack_restrictions = cvar( H( "No Attack Restrictions" ), true );
inline bool previous_admin_cheat;

inline cvar spider_man = cvar( H( "Spider-Man" ), false );
inline cvar no_fall_damage = cvar( H( "No Fall Damage" ), false );
inline cvar infinite_jump = cvar( H( "Infinite Jump" ), false );
inline cvar omnisprint = cvar( H( "Omnisprint" ), false );
inline cvar on_ladder = cvar( H( "On Ladder" ), false );

inline cvar_bind override_night = WRAP_BIND( "Override Night", true, trigger_type::toggle, 'K' );
inline cvar_ui ambient_color = cvar_ui( H( "Ambient Color" ), COL32( 85, 50, 75, 255 ) );
inline cvar_f ambient_multiplier = cvar_f( H( "Ambient Multiplier" ), 2.f );
inline cvar_f ambient_saturation = cvar_f( H( "Ambient Saturation" ), 0.2f );

inline cvar_bind override_fov = WRAP_BIND( "Override FOV", true, trigger_type::toggle, 0 );
inline cvar_f fov = cvar_f( H( "FOV" ), 100.f );
inline float original_fov = -1.f;

inline cvar_bind zoom = WRAP_BIND( "Zoom", true, trigger_type::hold, 'X' );
inline cvar_f zoom_fov = cvar_f( H( "Zoom FOV" ), 40.f );


inline cvar chams = cvar( H( "Chams" ), true );
inline cvar_ui chams_type = cvar_ui( H( "Chams Type" ), 0 );
inline cvar_ui chams_color = cvar_ui( H( "Chams Color" ), COL32( 255, 255, 255, 255 ) );

inline cvar glow = cvar( H( "Glow" ), true );
inline cvar_ui glow_outline_color = cvar_ui( H( "Glow Outline Color" ), COL32( 255, 255, 255, 255 ) );
inline cvar_f glow_blur_scale = cvar_f( H( "Glow Blur Scale" ), 0.75f );
inline cvar_f glow_outline_scale = cvar_f( H( "Glow Outline Scale" ), 0.5f );