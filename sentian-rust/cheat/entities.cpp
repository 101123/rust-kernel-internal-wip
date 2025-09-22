#include "entities.h"
#include "cheat/sdk/sdk.h"
#include "util.h"
#include "glow.h"

#include <ankerl/unordered_dense.h>
#include <md5.h>

using player_map = ankerl::unordered_dense::map<rust::base_player*, cached_player>;
using entity_map = ankerl::unordered_dense::map<rust::base_entity*, cached_entity>;
using combat_entity_map = ankerl::unordered_dense::map<rust::base_combat_entity*, cached_combat_entity>;

struct cached_entities {
    entity_map m_resources;
    entity_map m_collectables;
    entity_map m_barrels;
    entity_map m_crates;
    entity_map m_supply_drops;
    entity_map m_deployables;

    combat_entity_map m_animals;
    combat_entity_map m_vehicles;
    combat_entity_map m_traps;

    player_map m_players;

    // Hackable Crate
    // Tool Cupboard
    // Dropped Items
    // Backpacks/Corpses

    util::array<entity_map*, 16> m_entity_maps;
    util::array<combat_entity_map*, 16> m_combat_entity_maps;

    cached_entities() {
        m_entity_maps.add( &m_resources );
        m_entity_maps.add( &m_collectables );
        m_entity_maps.add( &m_barrels );
        m_entity_maps.add( &m_crates );
        m_entity_maps.add( &m_supply_drops );
        m_entity_maps.add( &m_deployables );

        m_combat_entity_maps.add( &m_animals );
        m_combat_entity_maps.add( &m_vehicles );
        m_combat_entity_maps.add( &m_traps );
    }
};

static util::lazy_initializer<cached_entities> entity_cache;

void entity_manager::init() {
    entity_cache.construct();
}

void entity_manager::destroy() {
    cached_entities& entities = entity_cache.get();

    entity_map entities_temp;
    for ( auto& map : entities.m_entity_maps ) {
        map->swap( entities_temp );
    }

    combat_entity_map combat_entities_temp;
    for ( auto& map : entities.m_combat_entity_maps ) {
        map->swap( combat_entities_temp );
    }

    player_map players_temp;
    entities.m_players.swap( players_temp );
}

class entity_cacher {
public:
    entity_cacher( entity_map* entities ) : 
        m_cacher( entities, ( cacher::add_to_cache_t )add_to_cache, ( cacher::remove_from_cache_t )remove_from_cache ) {};

    operator cacher&() {
        return m_cacher;
    }

    static void add_to_cache( cacher* cacher, rust::base_entity* entity, cvar_visual* visual ) {
        unity::transform* transform = entity->get_transform();
        if ( !is_valid_ptr( transform ) )
            return;

        entity_map* storage = ( entity_map* )cacher->get_user_data();

        // This is most likely unnecessary
        if ( storage->contains( entity ) )
            return;

        storage->insert( { entity, cached_entity( entity, transform->get_position(), visual ) } );
    }

    static void remove_from_cache( cacher* cacher, rust::base_entity* entity, cvar_visual* visual ) {
        entity_map* storage = ( entity_map* )cacher->get_user_data();
        if ( !storage )
            return;

        auto iterator = storage->find( entity );
        if ( iterator == storage->end() )
            return;

        storage->erase( iterator );
    }

private:
    cacher m_cacher;
};

class combat_entity_cacher {
public:
    combat_entity_cacher( combat_entity_map* entities ) :
        m_cacher( entities, ( cacher::add_to_cache_t )add_to_cache, ( cacher::remove_from_cache_t )remove_from_cache ) {};

    operator cacher& ( ) {
        return m_cacher;
    }

    static void add_to_cache( cacher* cacher, rust::base_combat_entity* entity, cvar_visual* visual ) {
        unity::transform* transform = entity->get_transform();
        if ( !is_valid_ptr( transform ) )
            return;

        combat_entity_map* storage = ( combat_entity_map* )cacher->get_user_data();

        // This is most likely unnecessary
        if ( storage->contains( entity ) )
            return;

        storage->insert( { entity, cached_combat_entity( entity, transform->get_position(), visual, entity->lifestate, entity->health ) } );
    }

    static void remove_from_cache( cacher* cacher, rust::base_combat_entity* entity, cvar_visual* visual ) {
        combat_entity_map* storage = ( combat_entity_map* )cacher->get_user_data();
        if ( !storage )
            return;

        auto iterator = storage->find( entity );
        if ( iterator == storage->end() )
            return;

        storage->erase( iterator );
    }

private:
    cacher m_cacher;
};

inline int cached_bones[] = {
    rust::bones::neck,
    rust::bones::head,
    rust::bones::spine1, rust::bones::spine4,
    rust::bones::l_clavicle, rust::bones::r_clavicle,
    rust::bones::l_upperarm, rust::bones::r_upperarm,
    rust::bones::l_forearm, rust::bones::r_forearm,
    rust::bones::l_hand, rust::bones::r_hand,
    rust::bones::l_hip, rust::bones::r_hip,
    rust::bones::l_knee, rust::bones::r_knee,
    rust::bones::l_foot, rust::bones::r_foot
};

class player_cacher {
public:
    player_cacher( player_map* players ) :
        m_cacher( players, ( cacher::add_to_cache_t )add_to_cache, ( cacher::remove_from_cache_t )remove_from_cache ) {
    };

    operator cacher& ( ) {
        return m_cacher;
    }

    static void add_to_cache( cacher* cacher, rust::base_player* player, cvar_visual* visual ) {
        player_map* storage = ( player_map* )cacher->get_user_data();

        // This is most likely unnecessary
        if ( storage->contains( player ) )
            return;

        storage->insert( { player, {} } );
    }

    static void remove_from_cache( cacher* cacher, rust::base_player* player, cvar_visual* visual ) {
        player_map* storage = ( player_map* )cacher->get_user_data();
        if ( !storage )
            return;

        auto iterator = storage->find( player );
        if ( iterator == storage->end() )
            return;

        storage->erase( iterator );

        glow_manager::remove_player( player );
    }

private:
    cacher m_cacher;
};

constexpr uint32_t generate_prefab_id_from_path( const char* path ) {
	md5::Digest digest = md5::compute( path );
	return ( uint32_t )( ( int )( digest[ 0 ] ) | ( ( int )digest[ 1 ] << 8 ) | ( ( int )digest[ 2 ] << 16 ) | ( ( int )digest[ 3 ] << 24 ) );
}

#define PREFAB( prefab_path ) generate_prefab_id_from_path( prefab_path )

bool entity_manager::belongs_in_cache( rust::base_networkable* entity, cache_specifier* specifier ) {
    cached_entities& entities = entity_cache.get();

    if ( entity->klass == rust::base_player::s_klass || entity->klass == rust::scientist_npc::s_klass || 
        entity->klass == rust::tunnel_dweller::s_klass || entity->klass == rust::underwater_dweller::s_klass || 
        entity->klass == rust::scarecrow_npc::s_klass || entity->klass == rust::gingerbread_npc::s_klass ) {
        *specifier = cache_specifier( player_cacher( &entities.m_players ), nullptr );
        return true;
    }

    switch ( entity->prefab_id ) {
        case PREFAB( "assets/bundled/prefabs/autospawn/resource/ores/stone-ore.prefab" ):
        case PREFAB( "assets/bundled/prefabs/autospawn/resource/ores_sand/stone-ore.prefab" ):
        case PREFAB( "assets/bundled/prefabs/autospawn/resource/ores_snow/stone-ore.prefab" ):
        case PREFAB( "assets/bundled/prefabs/radtown/ore_stone.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_resources ), &stone_ore );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/resource/ores/metal-ore.prefab" ):
        case PREFAB( "assets/bundled/prefabs/autospawn/resource/ores_sand/metal-ore.prefab" ):
        case PREFAB( "assets/bundled/prefabs/autospawn/resource/ores_snow/metal-ore.prefab" ):
        case PREFAB( "assets/bundled/prefabs/radtown/ore_metal.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_resources ), &metal_ore );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/resource/ores/sulfur-ore.prefab" ):
        case PREFAB( "assets/bundled/prefabs/autospawn/resource/ores_sand/sulfur-ore.prefab" ):
        case PREFAB( "assets/bundled/prefabs/autospawn/resource/ores_snow/sulfur-ore.prefab" ):
        case PREFAB( "assets/bundled/prefabs/radtown/ore_sulfur.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_resources ), &sulfur_ore );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/resource/wood_log_pile/wood-pile.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_resources ), &wood_pile );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/hemp/hemp-collectable.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_collectables ), &hemp );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/mushrooms/mushroom-cluster-5.prefab" ):
        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/mushrooms/mushroom-cluster-6.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_collectables ), &mushroom );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/pumpkin/pumpkin-collectable.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_collectables ), &pumpkin );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/corn/corn-collectable.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_collectables ), &corn );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/potato/potato-collectable.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_collectables ), &potato );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/stone/stone-collectable.prefab" ):
        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/stone/halloween/halloween-stone-collectable.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_collectables ), &stone );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/stone/metal-collectable.prefab" ):
        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/stone/halloween/halloween-metal-collectable.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_collectables ), &metal );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/stone/sulfur-collectable.prefab" ):
        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/stone/halloween/halloween-sulfur-collectible.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_collectables ), &sulfur );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/wood/wood-collectable.prefab" ):
        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/stone/halloween/halloween-wood-collectable.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_collectables ), &wood );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/berry-black/berry-black-collectable.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_collectables ), &black_berry );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/berry-blue/berry-blue-collectable.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_collectables ), &blue_berry );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/berry-green/berry-green-collectable.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_collectables ), &green_berry );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/berry-red/berry-red-collectable.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_collectables ), &red_berry );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/berry-white/berry-white-collectable.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_collectables ), &white_berry );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/berry-yellow/berry-yellow-collectable.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_collectables ), &yellow_berry );
            return true;
        }

        case PREFAB( "assets/content/vehicles/boats/rowboat/rowboat.prefab" ): {
            *specifier = cache_specifier( combat_entity_cacher( &entities.m_vehicles ), &rowboat );
            return true;
        }

        case PREFAB( "assets/content/vehicles/boats/rhib/rhib.prefab" ): {
            *specifier = cache_specifier( combat_entity_cacher( &entities.m_vehicles ), &rhib );
            return true;
        }

        case PREFAB( "assets/content/vehicles/minicopter/minicopter.entity.prefab" ): {
            *specifier = cache_specifier( combat_entity_cacher( &entities.m_vehicles ), &minicopter );
            return true;
        }

        case PREFAB( "assets/content/vehicles/scrap heli carrier/scraptransporthelicopter.prefab" ): {
            *specifier = cache_specifier( combat_entity_cacher( &entities.m_vehicles ), &scrap_helicopter );
            return true;
        }

        case PREFAB( "assets/content/vehicles/attackhelicopter/attackhelicopter.entity.prefab" ): {
            *specifier = cache_specifier( combat_entity_cacher( &entities.m_vehicles ), &attack_helicopter );
            return true;
        }

        case PREFAB( "assets/content/vehicles/boats/tugboat/tugboat.prefab" ): {
            *specifier = cache_specifier( combat_entity_cacher( &entities.m_vehicles ), &tugboat );
            return true;
        }

        case PREFAB( "assets/content/vehicles/submarine/submarinesolo.entity.prefab" ): {
            *specifier = cache_specifier( combat_entity_cacher( &entities.m_vehicles ), &submarine );
            return true;
        }

        case PREFAB( "assets/content/vehicles/submarine/submarineduo.entity.prefab" ): {
            *specifier = cache_specifier( combat_entity_cacher( &entities.m_vehicles ), &submarine );
            return true;
        }

        case PREFAB( "assets/prefabs/deployable/hot air balloon/hotairballoon.prefab" ): {
            *specifier = cache_specifier( combat_entity_cacher( &entities.m_vehicles ), &hot_air_balloon );
            return true;
        }

        case PREFAB( "assets/content/vehicles/dpv/dpv.deployed.prefab" ): {
            *specifier = cache_specifier( combat_entity_cacher( &entities.m_vehicles ), &diver_propulsion_vehicle );
            return true;
        }

        case PREFAB( "assets/prefabs/npc/patrol helicopter/patrolhelicopter.prefab" ): {
            *specifier = cache_specifier( combat_entity_cacher( &entities.m_vehicles ), &patrol_helicopter );
            return true;
        }

        case PREFAB( "assets/prefabs/npc/m2bradley/bradleyapc.prefab" ): {
            *specifier = cache_specifier( combat_entity_cacher( &entities.m_vehicles ), &bradley );
            return true;
        }

        case PREFAB( "assets/rust.ai/agents/bear/bear.prefab" ):
        case PREFAB( "assets/rust.ai/agents/bear/polarbear.prefab" ): {
            *specifier = cache_specifier( combat_entity_cacher( &entities.m_animals ), &bear );
            return true;
        }

        case PREFAB( "assets/rust.ai/agents/boar/boar.prefab" ): {
            *specifier = cache_specifier( combat_entity_cacher( &entities.m_animals ), &boar );
            return true;
        }

        case PREFAB( "assets/rust.ai/agents/chicken/chicken.prefab" ): {
            *specifier = cache_specifier( combat_entity_cacher( &entities.m_animals ), &chicken );
            return true;
        }

        case PREFAB( "assets/content/vehicles/horse/ridablehorse.prefab" ): {
            *specifier = cache_specifier( combat_entity_cacher( &entities.m_animals ), &horse );
            return true;
        }

        case PREFAB( "assets/rust.ai/agents/stag/stag.prefab" ): {
            *specifier = cache_specifier( combat_entity_cacher( &entities.m_animals ), &stag );
            return true;
        }

        case PREFAB( "assets/rust.ai/agents/wolf/wolf2.prefab" ): {
            *specifier = cache_specifier( combat_entity_cacher( &entities.m_animals ), &wolf );
            return true;
        }

        case PREFAB( "assets/rust.ai/agents/fish/simpleshark.prefab" ): {
            *specifier = cache_specifier( combat_entity_cacher( &entities.m_animals ), &shark );
            return true;
        }

        case PREFAB( "assets/prefabs/npc/beeswarm/beeswarm.prefab" ):
        case PREFAB( "assets/prefabs/npc/beeswarm/beemasterswarm.prefab" ): {
            *specifier = cache_specifier( combat_entity_cacher( &entities.m_animals ), &bee_swarm );
            return true;
        }

        case PREFAB( "assets/rust.ai/agents/tiger/tiger.prefab" ): {
            *specifier = cache_specifier( combat_entity_cacher( &entities.m_animals ), &tiger );
            return true;
        }

        case PREFAB( "assets/rust.ai/agents/panther/panther.prefab" ): {
            *specifier = cache_specifier( combat_entity_cacher( &entities.m_animals ), &panther );
            return true;
        }

        case PREFAB( "assets/rust.ai/agents/crocodile/crocodile.prefab" ): {
            *specifier = cache_specifier( combat_entity_cacher( &entities.m_animals ), &crocodile );
            return true;
        }

        case PREFAB( "assets/rust.ai/agents/snake/snake.entity.prefab" ): {
            *specifier = cache_specifier( combat_entity_cacher( &entities.m_animals ), &snake );
            return true;
        }

        case PREFAB( "assets/prefabs/deployable/vendingmachine/vendingmachine.deployed.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_deployables ), &vending_machine );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/static/workbench1.static.prefab" ):
        case PREFAB( "assets/prefabs/deployable/tier 1 workbench/workbench1.deployed.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_deployables ), &wb1 );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/static/workbench2.static.prefab" ):
        case PREFAB( "assets/prefabs/deployable/tier 2 workbench/workbench2.deployed.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_deployables ), &wb2 );
            return true;
        }

        case PREFAB( "assets/prefabs/deployable/tier 3 workbench/workbench3.deployed.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_deployables ), &wb3 );
            return true;
        }

        case PREFAB( "assets/prefabs/deployable/sleeping bag/sleepingbag_leather_deployed.prefab" ):
        case PREFAB( "assets/prefabs/misc/summer_dlc/beach_towel/beachtowel.deployed.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_deployables ), &sleeping_bag );
            return true;
        }

        case PREFAB( "assets/prefabs/deployable/bed/bed_deployed.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_deployables ), &bed );
            return true;
        }

        case PREFAB( "assets/prefabs/deployable/tool cupboard/cupboard.tool.deployed.prefab" ):
        case PREFAB( "assets/prefabs/deployable/tool cupboard/retro/cupboard.tool.retro.deployed.prefab" ):
        case PREFAB( "assets/prefabs/deployable/tool cupboard/shockbyte/cupboard.tool.shockbyte.deployed.prefab" ): {
            return false;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/resource/loot/loot-barrel-1.prefab" ):
        case PREFAB( "assets/bundled/prefabs/radtown/loot_barrel_2.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_barrels ), &red_barrel );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/resource/loot/loot-barrel-2.prefab" ):
        case PREFAB( "assets/bundled/prefabs/radtown/loot_barrel_1.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_barrels ), &blue_barrel );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/radtown/oil_barrel.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_barrels ), &oil_barrel );
            return true;
        }

        case PREFAB( "assets/content/structures/excavator/prefabs/diesel_collectable.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_barrels ), &diesel_barrel );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/radtown/crate_basic.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_crates ), &basic_crate );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/radtown/underwater_labs/crate_ammunition.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_crates ), &ammo_crate );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/resource/loot/trash-pile-1.prefab" ):
        case PREFAB( "assets/bundled/prefabs/radtown/underwater_labs/crate_food_1.prefab" ):
        case PREFAB( "assets/bundled/prefabs/radtown/underwater_labs/crate_food_2.prefab" ):
        case PREFAB( "assets/bundled/prefabs/radtown/crate_normal_2_food.prefab" ):
        case PREFAB( "assets/bundled/prefabs/radtown/foodbox.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_crates ), &food_crate );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/radtown/underwater_labs/crate_fuel.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_crates ), &fuel_crate );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/radtown/underwater_labs/tech_parts_1.prefab" ):
        case PREFAB( "assets/bundled/prefabs/radtown/underwater_labs/tech_parts_2.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_crates ), &tech_parts );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/radtown/underwater_labs/vehicle_parts.prefab" ):
        case PREFAB( "assets/bundled/prefabs/radtown/vehicle_parts.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_crates ), &vehicle_parts );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/radtown/crate_normal_2.prefab" ):
        case PREFAB( "assets/bundled/prefabs/radtown/underwater_labs/crate_normal.prefab" ):
        case PREFAB( "assets/bundled/prefabs/radtown/underwater_labs/crate_normal_2.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_crates ), &normal_crate );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/radtown/crate_underwater_basic.prefab" ):
        case PREFAB( "assets/bundled/prefabs/radtown/crate_underwater_advanced.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_crates ), &underwater_crate );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/radtown/crate_normal_2_medical.prefab" ):
        case PREFAB( "assets/bundled/prefabs/radtown/underwater_labs/crate_medical.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_crates ), &medical_crate );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/radtown/crate_tools.prefab" ):
        case PREFAB( "assets/bundled/prefabs/radtown/underwater_labs/crate_tools.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_crates ), &tool_crate );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/radtown/crate_normal.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_crates ), &military_crate );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/radtown/crate_elite.prefab" ):
        case PREFAB( "assets/bundled/prefabs/radtown/underwater_labs/crate_elite.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_crates ), &elite_crate );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/radtown/minecart.prefab" ):
        case PREFAB( "assets/bundled/prefabs/radtown/crate_mine.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_crates ), &minecart );
            return true;
        }

        case PREFAB( "assets/prefabs/npc/m2bradley/bradley_crate.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_crates ), &bradley_crate );
            return true;
        }

        case PREFAB( "assets/prefabs/npc/patrol helicopter/heli_crate.prefab" ): {
            *specifier = cache_specifier( entity_cacher( &entities.m_crates ), &heli_crate );
            return true;
        }

        case PREFAB( "assets/prefabs/deployable/chinooklockedcrate/codelockedhackablecrate.prefab" ):
        case PREFAB( "assets/prefabs/deployable/chinooklockedcrate/codelockedhackablecrate_oilrig.prefab" ): {
            return false;
        }

        case PREFAB( "assets/prefabs/misc/supply drop/supply_drop.prefab" ):
        case PREFAB( "assets/prefabs/misc/xmas/sleigh/presentdrop.prefab" ): {
            return false;
        }

        case PREFAB( "assets/prefabs/deployable/single shot trap/guntrap.deployed.prefab" ): {
            *specifier = cache_specifier( combat_entity_cacher( &entities.m_traps ), &shotgun_trap );
            return true;
        }

        case PREFAB( "assets/prefabs/npc/flame turret/flameturret.deployed.prefab" ): {
            *specifier = cache_specifier( combat_entity_cacher( &entities.m_traps ), &flame_turret );
            return true;
        }

        case PREFAB( "assets/prefabs/deployable/landmine/landmine.prefab" ): {
            *specifier = cache_specifier( combat_entity_cacher( &entities.m_traps ), &land_mine );
            return true;
        }

        case PREFAB( "assets/prefabs/deployable/bear trap/beartrap.prefab" ): {
            *specifier = cache_specifier( combat_entity_cacher( &entities.m_traps ), &bear_trap );
            return true;
        }

        case PREFAB( "assets/prefabs/npc/sam_site_turret/sam_site_turret_deployed.prefab" ): {
            *specifier = cache_specifier( combat_entity_cacher( &entities.m_traps ), &sam_site );
            return true;
        }

        case PREFAB( "assets/prefabs/npc/autoturret/autoturret_deployed.prefab" ): {
            *specifier = cache_specifier( combat_entity_cacher( &entities.m_traps ), &auto_turret );
            return true;
        }

        case PREFAB( "assets/prefabs/misc/burlap sack/generic_world.prefab" ): {
            return false;
        }

        case PREFAB( "assets/prefabs/player/player_corpse.prefab" ):
        case PREFAB( "assets/prefabs/player/player_corpse_new.prefab" ): {
            return false;
        }

        case PREFAB( "assets/prefabs/misc/item drop/item_drop_backpack.prefab" ): {
            return false;
        }
    }

    return false;
}

void entity_manager::add_to_cache( rust::base_networkable* entity, cache_specifier* specifier ) {
    util::scoped_spinlock lock( &cache_lock );

    specifier->m_cacher.add_to_cache( entity, specifier->m_visual );
}

void entity_manager::remove_from_cache( rust::base_networkable* entity, cache_specifier* specifier ) {
    util::scoped_spinlock lock( &cache_lock );

    specifier->m_cacher.remove_from_cache( entity, specifier->m_visual );
}

void update_player_bones( cached_player& cached_player ) {
    auto& bone_data = cached_player.bone_data;

    for ( size_t i = 0; i < _countof( cached_bones ); i++ ) {
        bone_data.positions[ i ] = bone_data.transforms[ i ]->get_position();
    }
}

bool update_player_inventory( cached_player& cached_player ) {
    rust::item_container* belt = cached_player.inventory->container_belt;
    if ( !is_valid_ptr( belt ) )
        return false;

    sys::list<rust::item*>* items_list = belt->item_list;
    if ( !is_valid_ptr( items_list ) || !is_valid_ptr( items_list->items ) )
        return false;

    sys::array<rust::item*>* items = items_list->items;
    if ( !is_valid_ptr( items ) )
        return false;
    
    int active_item = -1;
    uint64_t active_item_id = cached_player.entity->cl_active_item;

    for ( size_t i = 0; i < 6; i++ ) {
        // The list contains the actual count, not the underlying array
        if ( i < items_list->size ) {
            // None of these pointers should ever be invalid, so fail if so
            rust::item* item = items->buffer[ i ];
            if ( !is_valid_ptr( item ) )
                return false;

            rust::item_definition* info = item->info;
            if ( !is_valid_ptr( info ) )
                return false;

            rust::phrase* display_name = info->display_name;
            if ( !is_valid_ptr( display_name ) )
                return false;

            sys::string* legacy_english = display_name->legacy_english;
            if ( !is_valid_ptr( legacy_english ) )
                return false;

            if ( item->uid == active_item_id ) {
                active_item = i;
            }

            cached_belt_item& belt_item = cached_player.belt_items[ i ];

            belt_item.present = true;
            belt_item.amount = item->amount;
            wcscpy_s( belt_item.name, _countof( belt_item.name ), legacy_english->buffer );
        }

        else {
            cached_belt_item& belt_item = cached_player.belt_items[ i ];

            belt_item.present = false;
        }
    }

    cached_player.active_item = active_item;

    return true;
}

bool init_player_if_needed( rust::base_player* player, cached_player& cached_player ) {
    // Check if we've already initialized this player
    if ( cached_player.init )
        return true;

    rust::player_eyes* eyes = player->get_eyes();
    if ( !is_valid_ptr( eyes ) )
        return false;

    rust::player_inventory* inventory = player->get_inventory();
    if ( !is_valid_ptr( inventory ) )
        return false;

    rust::model* model = player->model;
    if ( !is_valid_ptr( model ) )
        return false;

    sys::array<unity::transform*>* bone_transforms = model->bone_transforms;
    if ( !is_valid_ptr( bone_transforms ) )
        return false;

    // Make sure array is big enough to store desired transforms
    if ( bone_transforms->size <= rust::bones::r_hand )
        return false;

    for ( size_t i = 0; i < _countof( cached_bones ); i++ ) {
        unity::transform* transform = bone_transforms->buffer[ cached_bones[ i ] ];

        // If any transform is invalid, the player is not valid
        if ( !is_valid_ptr( transform ) )
            return false;

        cached_player.bone_data.transforms[ i ] = transform;
    }

    cached_player.entity = player;

    cached_player.scientist = true;

    cached_player.eyes = eyes;
    cached_player.inventory = inventory;

    const wchar_t* name = L"Scientist";

    if ( player->klass == rust::base_player::s_klass && is_valid_ptr( player->display_name ) ) {
        cached_player.scientist = false;
        name = player->display_name->buffer;
    } else if ( player->klass == rust::tunnel_dweller::s_klass ) {
        name = L"Tunnel Dweller";
    } else if ( player->klass == rust::underwater_dweller::s_klass ) {
        name = L"Underwater Dweller";
    } else if ( player->klass == rust::scarecrow_npc::s_klass ) {
        name = L"Scarecrow";
    } else if ( player->klass == rust::gingerbread_npc::s_klass ) {
        name = L"Gingerbread";
    }

    wcscpy_s( cached_player.name, _countof( cached_player.name ), name );

    glow_manager::add_player( player );

    return cached_player.init = true;
}

void update_players() {
    for ( auto& [ player, cached_player ] : entity_cache.get().m_players ) {
        if ( !init_player_if_needed( player, cached_player ) )
            continue;

        update_player_bones( cached_player );
        update_player_inventory( cached_player );
    }
}

void entity_manager::update() {
    util::scoped_spinlock lock( &cache_lock );

    update_players();
}

entity_collection entity_manager::get_entities() {
    cached_entities& entities = entity_cache.get();

    return entity_collection {
        .players = entities.m_players.values(),
        .resources = entities.m_resources.values()
    };
}