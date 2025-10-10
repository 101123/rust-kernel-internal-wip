#include "entities.h"
#include "cheat/sdk/sdk.h"
#include "util.h"
#include "glow.h"
#include "dx.h"

#include <ankerl/unordered_dense.h>

using entity_map = ankerl::unordered_dense::map<rust::base_entity*, cached_entity>;
using named_entity_map = ankerl::unordered_dense::map<rust::base_entity*, cached_named_entity>;
using combat_entity_map = ankerl::unordered_dense::map<rust::base_combat_entity*, cached_combat_entity>;
using dropped_item_map = ankerl::unordered_dense::map<rust::world_item*, cached_dropped_item>;
using player_map = ankerl::unordered_dense::map<rust::base_player*, cached_player>;

struct cached_entities {
    entity_map entities;
    named_entity_map named_entities;
    combat_entity_map combat_entities;
    dropped_item_map dropped_items;
    player_map players;

    // Hackable Crate
    // Tool Cupboard
};

static util::lazy_initializer<cached_entities> entity_cache;

void entity_manager::init() {
    entity_cache.construct();
}

// We need to validate the objects vftable because it may become invalidated even without us releasing our reference
void safe_release_impl( IUnknown* object ) {
    if ( !is_valid_ptr( object ) )
        return;

    void** vftable = *( void*** )( object );
    if ( !is_valid_ptr( vftable ) )
        return;

    object->Release();
}

#define SAFE_RELEASE( Object ) if ( Object ) { safe_release_impl( Object ); Object = nullptr; }

void entity_manager::destroy() {
    util::scoped_spinlock lock( &cache_lock );

    cached_entities& entities = entity_cache.get();

    entity_map temp_entity_map;
    entities.entities.swap( temp_entity_map );

    named_entity_map temp_named_entity_map;
    entities.named_entities.swap( temp_named_entity_map );

    combat_entity_map temp_combat_entity_map;
    entities.combat_entities.swap( temp_combat_entity_map );

    dropped_item_map temp_dropped_item_map;
    entities.dropped_items.swap( temp_dropped_item_map );

    for ( auto& [ _, cached_player ] : entities.players ) {
        SAFE_RELEASE( cached_player.avatar_srv );
    }

    player_map temp_player_map;
    entities.players.swap( temp_player_map );
}

namespace entity_cacher {
    void add_to_cache( rust::base_entity* entity, cache_specifier* specifier ) {
        unity::transform* transform = entity->get_transform();
        if ( !is_valid_ptr( transform ) )
            return;

        entity_map& entities = entity_cache.get().entities;
        if ( entities.contains( entity ) )
            return;

        entities.insert( { entity, 
            cached_entity {
                entity->flags,
                transform,
                transform->get_position(),
                specifier->visual,
                specifier->update 
            } } 
        );
    }

    void remove_from_cache( rust::base_entity* entity, cache_specifier* specifier ) {
        entity_map& entities = entity_cache.get().entities;

        auto iterator = entities.find( entity );
        if ( iterator == entities.end() )
            return;

        entities.erase( iterator );
    }

    const void* cache_functions[] = {
        add_to_cache,
        remove_from_cache
    };
}

namespace named_entity_cacher {
    void add_to_cache( rust::base_entity* entity, cache_specifier* specifier ) {
        unity::transform* transform = entity->get_transform();
        if ( !is_valid_ptr( transform ) )
            return;

        named_entity_map& named_entities = entity_cache.get().named_entities;
        if ( named_entities.contains( entity ) )
            return;

        named_entities.insert( { entity, 
            cached_named_entity {
                cached_entity {
                    entity->flags,
                    transform,
                    transform->get_position(),
                    specifier->visual,
                    specifier->update
                }
            } }
        );
    }

    void remove_from_cache( rust::base_entity* entity, cache_specifier* specifier ) {
        named_entity_map& named_entities = entity_cache.get().named_entities;

        auto iterator = named_entities.find( entity );
        if ( iterator == named_entities.end() )
            return;

        named_entities.erase( iterator );
    }

    const void* cache_functions[] = {
        add_to_cache,
        remove_from_cache
    };
}

namespace combat_entity_cacher {
    void add_to_cache( rust::base_combat_entity* combat_entity, cache_specifier* specifier ) {
        unity::transform* transform = combat_entity->get_transform();
        if ( !is_valid_ptr( transform ) )
            return;

        combat_entity_map& combat_entities = entity_cache.get().combat_entities;
        if ( combat_entities.contains( combat_entity ) )
            return;

        combat_entities.insert( { combat_entity,
            cached_combat_entity {
                cached_entity { 
                    combat_entity->flags,
                    transform,
                    transform->get_position(),
                    specifier->visual,
                    specifier->update
                },

                combat_entity->lifestate,
                combat_entity->health,
                combat_entity->max_health
            } }
        );
    }

    void remove_from_cache( rust::base_combat_entity* entity, cache_specifier* specifier ) {
        combat_entity_map& combat_entities = entity_cache.get().combat_entities;

        auto iterator = combat_entities.find( entity );
        if ( iterator == combat_entities.end() )
            return;

        combat_entities.erase( iterator );
    }

    const void* cache_functions[] = {
        add_to_cache,
        remove_from_cache
    };
}

namespace dropped_item_cacher {
    void add_to_cache( rust::world_item* world_item, cache_specifier* specifier ) {
        unity::transform* transform = world_item->get_transform();
        if ( !is_valid_ptr( transform ) )
            return;

        dropped_item_map& dropped_items = entity_cache.get().dropped_items;
        if ( dropped_items.contains( world_item ) )
            return;

        dropped_items.insert( { world_item, 
            cached_dropped_item { 
                false, 
                transform, 
                transform->get_position() 
            } } 
        );
    }

    void remove_from_cache( rust::world_item* world_item, cache_specifier* specifier ) {
        dropped_item_map& dropped_items = entity_cache.get().dropped_items;

        auto iterator = dropped_items.find( world_item );
        if ( iterator == dropped_items.end() )
            return;

        dropped_items.erase( iterator );
    }

    const void* cache_functions[] = {
        add_to_cache,
        remove_from_cache
    };
}

namespace player_cacher {
    void add_to_cache( rust::base_player* player, cache_specifier* specifier ) {
        player_map& players = entity_cache.get().players;
        if ( players.contains( player ) )
            return;

        // The player isn't fully constructed here, so we can't cache anything
        players.insert( { player, {} } );
    }

    void remove_from_cache( rust::base_player* player, cache_specifier* specifier ) {
        player_map& players = entity_cache.get().players;

        auto iterator = players.find( player );
        if ( iterator == players.end() )
            return;

        auto& [ _, cached_player ] = *iterator;

        SAFE_RELEASE( cached_player.avatar_srv );

        if ( aimbot.player_target && player == aimbot.player_target->first ) {
            aimbot.player_target = nullptr;
        }

        glow_manager::remove_player( player );

        players.erase( iterator );
    }

    const void* cache_functions[] = {
        add_to_cache,
        remove_from_cache
    };
}

const void** get_entity_cacher() {
    return entity_cacher::cache_functions;
}

const void** get_named_entity_cacher() {
    return named_entity_cacher::cache_functions;
}

const void** get_combat_entity_cacher() {
    return combat_entity_cacher::cache_functions;
}

const void** get_dropped_item_cacher() {
    return dropped_item_cacher::cache_functions;
}

const void** get_player_cacher() {
    return player_cacher::cache_functions;
}

#define PREFAB( prefab_path ) unity::string_ex::manifest_hash( prefab_path )

bool entity_manager::belongs_in_cache( rust::base_networkable* entity, cache_specifier* specifier ) {
    if ( entity->klass == rust::base_player::klass_ || entity->klass == rust::scientist_npc::klass_ || 
        entity->klass == rust::tunnel_dweller::klass_ || entity->klass == rust::underwater_dweller::klass_ || 
        entity->klass == rust::scarecrow_npc::klass_ || entity->klass == rust::gingerbread_npc::klass_ ) {
        *specifier = cache_specifier( get_player_cacher(), nullptr, true );
        return true;
    }

    switch ( entity->prefab_id ) {
        case PREFAB( "assets/bundled/prefabs/autospawn/resource/ores/stone-ore.prefab" ):
        case PREFAB( "assets/bundled/prefabs/autospawn/resource/ores_sand/stone-ore.prefab" ):
        case PREFAB( "assets/bundled/prefabs/autospawn/resource/ores_snow/stone-ore.prefab" ):
        case PREFAB( "assets/bundled/prefabs/radtown/ore_stone.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &stone_ore, false );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/resource/ores/metal-ore.prefab" ):
        case PREFAB( "assets/bundled/prefabs/autospawn/resource/ores_sand/metal-ore.prefab" ):
        case PREFAB( "assets/bundled/prefabs/autospawn/resource/ores_snow/metal-ore.prefab" ):
        case PREFAB( "assets/bundled/prefabs/radtown/ore_metal.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &metal_ore, false );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/resource/ores/sulfur-ore.prefab" ):
        case PREFAB( "assets/bundled/prefabs/autospawn/resource/ores_sand/sulfur-ore.prefab" ):
        case PREFAB( "assets/bundled/prefabs/autospawn/resource/ores_snow/sulfur-ore.prefab" ):
        case PREFAB( "assets/bundled/prefabs/radtown/ore_sulfur.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &sulfur_ore, false );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/resource/wood_log_pile/wood-pile.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &wood_pile, false );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/hemp/hemp-collectable.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &hemp, false );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/mushrooms/mushroom-cluster-5.prefab" ):
        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/mushrooms/mushroom-cluster-6.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &mushroom, false );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/pumpkin/pumpkin-collectable.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &pumpkin, false );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/corn/corn-collectable.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &corn, false );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/potato/potato-collectable.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &potato, false );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/stone/stone-collectable.prefab" ):
        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/stone/halloween/halloween-stone-collectable.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &stone, false );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/stone/metal-collectable.prefab" ):
        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/stone/halloween/halloween-metal-collectable.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &metal, false );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/stone/sulfur-collectable.prefab" ):
        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/stone/halloween/halloween-sulfur-collectible.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &sulfur, false );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/wood/wood-collectable.prefab" ):
        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/stone/halloween/halloween-wood-collectable.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &wood, false );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/berry-black/berry-black-collectable.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &black_berry, false );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/berry-blue/berry-blue-collectable.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &blue_berry, false );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/berry-green/berry-green-collectable.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &green_berry, false );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/berry-red/berry-red-collectable.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &red_berry, false );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/berry-white/berry-white-collectable.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &white_berry, false );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/collectable/berry-yellow/berry-yellow-collectable.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &yellow_berry, false );
            return true;
        }

        case PREFAB( "assets/content/vehicles/boats/rowboat/rowboat.prefab" ): {
            *specifier = cache_specifier( get_combat_entity_cacher(), &rowboat, true );
            return true;
        }

        case PREFAB( "assets/content/vehicles/boats/rhib/rhib.prefab" ): {
            *specifier = cache_specifier( get_combat_entity_cacher(), &rhib, true );
            return true;
        }

        case PREFAB( "assets/content/vehicles/minicopter/minicopter.entity.prefab" ): {
            *specifier = cache_specifier( get_combat_entity_cacher(), &minicopter, true );
            return true;
        }

        case PREFAB( "assets/content/vehicles/scrap heli carrier/scraptransporthelicopter.prefab" ): {
            *specifier = cache_specifier( get_combat_entity_cacher(), &scrap_helicopter, true );
            return true;
        }

        case PREFAB( "assets/content/vehicles/attackhelicopter/attackhelicopter.entity.prefab" ): {
            *specifier = cache_specifier( get_combat_entity_cacher(), &attack_helicopter, true );
            return true;
        }

        case PREFAB( "assets/content/vehicles/boats/tugboat/tugboat.prefab" ): {
            *specifier = cache_specifier( get_combat_entity_cacher(), &tugboat, true );
            return true;
        }

        case PREFAB( "assets/content/vehicles/submarine/submarinesolo.entity.prefab" ): {
            *specifier = cache_specifier( get_combat_entity_cacher(), &submarine, true );
            return true;
        }

        case PREFAB( "assets/content/vehicles/submarine/submarineduo.entity.prefab" ): {
            *specifier = cache_specifier( get_combat_entity_cacher(), &submarine, true );
            return true;
        }

        case PREFAB( "assets/prefabs/deployable/hot air balloon/hotairballoon.prefab" ): {
            *specifier = cache_specifier( get_combat_entity_cacher(), &hot_air_balloon, true );
            return true;
        }

        case PREFAB( "assets/content/vehicles/dpv/dpv.deployed.prefab" ): {
            *specifier = cache_specifier( get_combat_entity_cacher(), &diver_propulsion_vehicle, true );
            return true;
        }

        case PREFAB( "assets/prefabs/npc/patrol helicopter/patrolhelicopter.prefab" ): {
            *specifier = cache_specifier( get_combat_entity_cacher(), &patrol_helicopter, true );
            return true;
        }

        case PREFAB( "assets/prefabs/npc/m2bradley/bradleyapc.prefab" ): {
            *specifier = cache_specifier( get_combat_entity_cacher(), &bradley, true );
            return true;
        }

        case PREFAB( "assets/rust.ai/agents/bear/bear.prefab" ):
        case PREFAB( "assets/rust.ai/agents/bear/polarbear.prefab" ): {
            *specifier = cache_specifier( get_combat_entity_cacher(), &bear, true );
            return true;
        }

        case PREFAB( "assets/rust.ai/agents/boar/boar.prefab" ): {
            *specifier = cache_specifier( get_combat_entity_cacher(), &boar, true );
            return true;
        }

        case PREFAB( "assets/rust.ai/agents/chicken/chicken.prefab" ): {
            *specifier = cache_specifier( get_combat_entity_cacher(), &chicken, true );
            return true;
        }

        case PREFAB( "assets/content/vehicles/horse/ridablehorse.prefab" ): {
            *specifier = cache_specifier( get_combat_entity_cacher(), &horse, true );
            return true;
        }

        case PREFAB( "assets/rust.ai/agents/stag/stag.prefab" ): {
            *specifier = cache_specifier( get_combat_entity_cacher(), &stag, true );
            return true;
        }

        case PREFAB( "assets/rust.ai/agents/wolf/wolf2.prefab" ): {
            *specifier = cache_specifier( get_combat_entity_cacher(), &wolf, true );
            return true;
        }

        case PREFAB( "assets/rust.ai/agents/fish/simpleshark.prefab" ): {
            *specifier = cache_specifier( get_combat_entity_cacher(), &shark, true );
            return true;
        }

        case PREFAB( "assets/prefabs/npc/beeswarm/beeswarm.prefab" ):
        case PREFAB( "assets/prefabs/npc/beeswarm/beemasterswarm.prefab" ): {
            *specifier = cache_specifier( get_combat_entity_cacher(), &bee_swarm, true );
            return true;
        }

        case PREFAB( "assets/rust.ai/agents/tiger/tiger.prefab" ): {
            *specifier = cache_specifier( get_combat_entity_cacher(), &tiger, true );
            return true;
        }

        case PREFAB( "assets/rust.ai/agents/panther/panther.prefab" ): {
            *specifier = cache_specifier( get_combat_entity_cacher(), &panther, true );
            return true;
        }

        case PREFAB( "assets/rust.ai/agents/crocodile/crocodile.prefab" ): {
            *specifier = cache_specifier( get_combat_entity_cacher(), &crocodile, true );
            return true;
        }

        case PREFAB( "assets/rust.ai/agents/snake/snake.entity.prefab" ): {
            *specifier = cache_specifier( get_combat_entity_cacher(), &snake, true );
            return true;
        }

        case PREFAB( "assets/prefabs/deployable/vendingmachine/vendingmachine.deployed.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &vending_machine, false );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/static/workbench1.static.prefab" ):
        case PREFAB( "assets/prefabs/deployable/tier 1 workbench/workbench1.deployed.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &wb1, false );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/static/workbench2.static.prefab" ):
        case PREFAB( "assets/prefabs/deployable/tier 2 workbench/workbench2.deployed.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &wb2, false );
            return true;
        }

        case PREFAB( "assets/prefabs/deployable/tier 3 workbench/workbench3.deployed.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &wb3, false );
            return true;
        }

        case PREFAB( "assets/prefabs/deployable/sleeping bag/sleepingbag_leather_deployed.prefab" ):
        case PREFAB( "assets/prefabs/misc/summer_dlc/beach_towel/beachtowel.deployed.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &sleeping_bag, false );
            return true;
        }

        case PREFAB( "assets/prefabs/deployable/bed/bed_deployed.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &bed, false );
            return true;
        }

        case PREFAB( "assets/prefabs/deployable/tool cupboard/cupboard.tool.deployed.prefab" ):
        case PREFAB( "assets/prefabs/deployable/tool cupboard/retro/cupboard.tool.retro.deployed.prefab" ):
        case PREFAB( "assets/prefabs/deployable/tool cupboard/shockbyte/cupboard.tool.shockbyte.deployed.prefab" ): {
            return false;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/resource/loot/loot-barrel-1.prefab" ):
        case PREFAB( "assets/bundled/prefabs/radtown/loot_barrel_2.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &red_barrel, false );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/resource/loot/loot-barrel-2.prefab" ):
        case PREFAB( "assets/bundled/prefabs/radtown/loot_barrel_1.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &blue_barrel, false );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/radtown/oil_barrel.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &oil_barrel, false );
            return true;
        }

        case PREFAB( "assets/content/structures/excavator/prefabs/diesel_collectable.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &diesel_barrel, false );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/radtown/crate_basic.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &basic_crate, false );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/radtown/underwater_labs/crate_ammunition.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &ammo_crate, false );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/autospawn/resource/loot/trash-pile-1.prefab" ):
        case PREFAB( "assets/bundled/prefabs/radtown/underwater_labs/crate_food_1.prefab" ):
        case PREFAB( "assets/bundled/prefabs/radtown/underwater_labs/crate_food_2.prefab" ):
        case PREFAB( "assets/bundled/prefabs/radtown/crate_normal_2_food.prefab" ):
        case PREFAB( "assets/bundled/prefabs/radtown/foodbox.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &food_crate, false );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/radtown/underwater_labs/crate_fuel.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &fuel_crate, false );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/radtown/underwater_labs/tech_parts_1.prefab" ):
        case PREFAB( "assets/bundled/prefabs/radtown/underwater_labs/tech_parts_2.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &tech_parts, false );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/radtown/underwater_labs/vehicle_parts.prefab" ):
        case PREFAB( "assets/bundled/prefabs/radtown/vehicle_parts.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &vehicle_parts, false );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/radtown/crate_normal_2.prefab" ):
        case PREFAB( "assets/bundled/prefabs/radtown/underwater_labs/crate_normal.prefab" ):
        case PREFAB( "assets/bundled/prefabs/radtown/underwater_labs/crate_normal_2.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &normal_crate, false );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/radtown/crate_underwater_basic.prefab" ):
        case PREFAB( "assets/bundled/prefabs/radtown/crate_underwater_advanced.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &underwater_crate, false );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/radtown/crate_normal_2_medical.prefab" ):
        case PREFAB( "assets/bundled/prefabs/radtown/underwater_labs/crate_medical.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &medical_crate, false );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/radtown/crate_tools.prefab" ):
        case PREFAB( "assets/bundled/prefabs/radtown/underwater_labs/crate_tools.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &tool_crate, false );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/radtown/crate_normal.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &military_crate, false );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/radtown/crate_elite.prefab" ):
        case PREFAB( "assets/bundled/prefabs/radtown/underwater_labs/crate_elite.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &elite_crate, false );
            return true;
        }

        case PREFAB( "assets/bundled/prefabs/radtown/minecart.prefab" ):
        case PREFAB( "assets/bundled/prefabs/radtown/crate_mine.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &minecart, false );
            return true;
        }

        case PREFAB( "assets/prefabs/npc/m2bradley/bradley_crate.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &bradley_crate, true );
            return true;
        }

        case PREFAB( "assets/prefabs/npc/patrol helicopter/heli_crate.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &heli_crate, true );
            return true;
        }

        case PREFAB( "assets/prefabs/deployable/chinooklockedcrate/codelockedhackablecrate.prefab" ):
        case PREFAB( "assets/prefabs/deployable/chinooklockedcrate/codelockedhackablecrate_oilrig.prefab" ): {
            return false;
        }

        case PREFAB( "assets/prefabs/misc/supply drop/supply_drop.prefab" ):
        case PREFAB( "assets/prefabs/misc/xmas/sleigh/presentdrop.prefab" ): {
            *specifier = cache_specifier( get_entity_cacher(), &supply_drop, true );
            return true;
        }

        case PREFAB( "assets/prefabs/deployable/single shot trap/guntrap.deployed.prefab" ): {
            *specifier = cache_specifier( get_combat_entity_cacher(), &shotgun_trap, false );
            return true;
        }

        case PREFAB( "assets/prefabs/npc/flame turret/flameturret.deployed.prefab" ): {
            *specifier = cache_specifier( get_combat_entity_cacher(), &flame_turret, false );
            return true;
        }

        case PREFAB( "assets/prefabs/deployable/landmine/landmine.prefab" ): {
            *specifier = cache_specifier( get_combat_entity_cacher(), &land_mine, false );
            return true;
        }

        case PREFAB( "assets/prefabs/deployable/bear trap/beartrap.prefab" ): {
            *specifier = cache_specifier( get_combat_entity_cacher(), &bear_trap, false );
            return true;
        }

        case PREFAB( "assets/prefabs/npc/sam_site_turret/sam_site_turret_deployed.prefab" ): {
            *specifier = cache_specifier( get_combat_entity_cacher(), &sam_site, false );
            return true;
        }

        case PREFAB( "assets/prefabs/npc/autoturret/autoturret_deployed.prefab" ): {
            *specifier = cache_specifier( get_combat_entity_cacher(), &auto_turret, false );
            return true;
        }

        case PREFAB( "assets/prefabs/misc/burlap sack/generic_world.prefab" ): {
            *specifier = cache_specifier( get_dropped_item_cacher(), nullptr, true );
            return true;
        }

        case PREFAB( "assets/prefabs/player/player_corpse.prefab" ):
        case PREFAB( "assets/prefabs/player/player_corpse_new.prefab" ): {
            *specifier = cache_specifier( get_named_entity_cacher(), &player_corpse, true );
            return true;
        }

        case PREFAB( "assets/prefabs/misc/item drop/item_drop_backpack.prefab" ): {
            *specifier = cache_specifier( get_named_entity_cacher(), &backpack, false );
            return true;
        }
    }

    return false;
}

void entity_manager::add_to_cache( rust::base_networkable* entity, cache_specifier* specifier ) {
    util::scoped_spinlock lock( &cache_lock );

    void( *add_to_cache )( rust::base_networkable*, cache_specifier* ) = 
        ( decltype( add_to_cache ) )( specifier->cache_functions[ 0 ] );

    add_to_cache( entity, specifier );
}

void entity_manager::remove_from_cache( rust::base_networkable* entity, cache_specifier* specifier ) {
    util::scoped_spinlock lock( &cache_lock );

    void( *remove_from_cache )( rust::base_networkable*, cache_specifier* ) =
        ( decltype( remove_from_cache ) )( specifier->cache_functions[ 1 ] );

    remove_from_cache( entity, specifier );
}

void cache_named_entity( rust::base_entity* named_entity, cached_named_entity& cached_named_entity ) {
    uint64_t steam_id = 0ull;
    sys::string* player_name = nullptr;

    if ( auto player_corpse = named_entity->is<rust::player_corpse>() ) {
        steam_id = player_corpse->player_steam_id;
        player_name = player_corpse->player_name;
    }

    else if ( auto dropped_item_container = named_entity->is<rust::dropped_item_container>() ) {
        steam_id = dropped_item_container->player_steam_id;
        player_name = dropped_item_container->player_name;
    }

    cached_named_entity.steam_id = steam_id;

    if ( cached_named_entity.name[ 0 ] == L'\0' && is_valid_ptr( player_name ) ) {
        wcscpy_s( cached_named_entity.name, _countof( cached_named_entity.name ), player_name->buffer );
    }
}

bool cache_dropped_item( rust::world_item* world_item, cached_dropped_item& cached_dropped_item ) {
    if ( cached_dropped_item.init )
        return true;

    rust::item* item = world_item->item;
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

    cached_dropped_item.amount = item->amount;
    cached_dropped_item.category = info->category;
    wcscpy_s( cached_dropped_item.name, _countof( cached_dropped_item.name ), legacy_english->buffer );

    return cached_dropped_item.init = true;
}

const int cached_bones[] = {
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

bool cache_player( rust::base_player* player, cached_player& cached_player ) {
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

    cached_player.scientist = !player->is<rust::base_player>();
    cached_player.steam_id = player->get_user_id();
    cached_player.eyes = eyes;
    cached_player.inventory = inventory;

    if ( !cached_player.scientist && is_valid_ptr( player->display_name ) ) {
        renderer::wstr_to_utf8( player->display_name->buffer, cached_player.name, sizeof( cached_player.name ) );
    }

    else {
        const char* name = S( "Scientist" );

        if ( player->is<rust::tunnel_dweller>() ) {
            name = S( "Tunnel Dweller" );
        } else if ( player->is<rust::underwater_dweller>() ) {
            name = S( "Underwater Dweller" );
        } else if ( player->is<rust::scarecrow_npc>() ) {
            name = S( "Scarecrow" );
        } else if ( player->is<rust::gingerbread_npc>() ) {
            name = S( "Gingerbread" );
        }

        strcpy_s( cached_player.name, sizeof( cached_player.name ), name );
    }

    glow_manager::add_player( player );

    return cached_player.init = true;
}

bool should_update_player( const cached_player& cached_player ) {
    return true;
}

void update_player_bones( cached_player& cached_player ) {
    auto& bone_data = cached_player.bone_data;

    for ( size_t i = 0; i < _countof( cached_bones ); i++ ) {
        bone_data.positions[ i ] = bone_data.transforms[ i ]->get_position();
    }
}

bool update_player_inventory( rust::base_player* player, cached_player& cached_player ) {
    rust::item_container* belt = cached_player.inventory->container_belt;
    if ( !is_valid_ptr( belt ) )
        return false;

    sys::list<rust::item*>* items_list = belt->item_list;
    if ( !is_valid_ptr( items_list ) || !is_valid_ptr( items_list->items ) )
        return false;

    sys::array<rust::item*>* items = items_list->items;
    if ( !is_valid_ptr( items ) )
        return false;
    
    int active_item_idx = -1, active_item_id = -1;
    uint64_t active_item_uid = player->cl_active_item;

    for ( size_t i = 0; i < 6; i++ ) {
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

            unity::sprite* icon_sprite = info->icon_sprite;
            if ( !is_valid_ptr( icon_sprite ) )
                return false;

            unity::texture2d* icon_texture = icon_sprite->get_texture();
            if ( !is_valid_ptr( icon_texture ) )
                return false;

            ID3D11ShaderResourceView* icon_srv = icon_texture->get_srv();
            if ( !is_valid_ptr( icon_srv ) )
                return false;

            sys::string* legacy_english = display_name->legacy_english;
            if ( !is_valid_ptr( legacy_english ) )
                return false;

            if ( item->uid == active_item_uid ) {
                active_item_idx = i;
                active_item_id = info->item_id;
            }

            cached_belt_item& belt_item = cached_player.belt_items[ i ];

            belt_item.present = true;
            belt_item.srv = icon_srv;
            belt_item.amount = item->amount;
            wcscpy_s( belt_item.name, _countof( belt_item.name ), legacy_english->buffer );
        }

        else {
            cached_belt_item& belt_item = cached_player.belt_items[ i ];

            belt_item.present = false;
        }
    }

    cached_player.active_item_idx = active_item_idx;
    cached_player.active_item_id = active_item_id;

    return true;
}

void update_player_visibility( rust::base_player* player, cached_player& cached_player ) {
    const cvar_player_visuals& visuals =
        cached_player.scientist ? scientist_visuals : player_visuals;

    if ( !visuals.visible_check )
        return;

    const vector3& origin = camera.position;
    vector3 direction = cached_player.bone_data.positions[ 1 ] - camera.position;

    cached_player.visible = !rust::game_physics::trace(
        unity::ray( origin, direction ), 0.f, nullptr, vector3::magnitude( direction ), 1218519297, unity::query_trigger_interaction::ignore, local_player.entity );
}

void update_player_avatar( rust::base_player* player, cached_player& cached_player ) {
    if ( cached_player.avatar_srv || cached_player.scientist || 
        !( cached_player.steam_id > 76561197960265728 && cached_player.steam_id < 76561202255233023 ) )
        return;

    unity::texture* avatar_texture = rust::steam_client_wrapper::get_avatar_texture( cached_player.steam_id );

    if ( is_valid_ptr( avatar_texture ) ) {
        ID3D11ShaderResourceView* srv = avatar_texture->get_srv();

        if ( is_valid_ptr( srv ) ) {
            // Increase reference count for the srv so it doesn't get freed while we're using it
            srv->AddRef();

            cached_player.avatar_srv = srv;
        }
    }
}

void entity_manager::update() {
    util::scoped_spinlock lock( &cache_lock );

    cached_entities& cached_entities = entity_cache.get();

    for ( auto& [ entity, cached_entity ] : cached_entities.entities ) {
        cached_entity.flags = entity->flags;

        if ( !entity->parent_entity && !cached_entity.update )
            continue;

        cached_entity.position = cached_entity.transform->get_position();
    }

    for ( auto& [ named_entity, cached_named_entity ] : cached_entities.named_entities ) {
        cached_named_entity.flags = named_entity->flags;

        cache_named_entity( named_entity, cached_named_entity );

        if ( !named_entity->parent_entity && !cached_named_entity.update )
            continue;

        cached_named_entity.position = cached_named_entity.transform->get_position();
    }

    for ( auto& [ combat_entity, cached_combat_entity ] : cached_entities.combat_entities ) {
        cached_combat_entity.flags = combat_entity->flags;
        cached_combat_entity.lifestate = combat_entity->lifestate;
        cached_combat_entity.health = combat_entity->health;
        cached_combat_entity.max_health = combat_entity->max_health;

        if ( !combat_entity->parent_entity && !cached_combat_entity.update )
            continue;

        cached_combat_entity.position = cached_combat_entity.transform->get_position();
    }

    for ( auto& [ dropped_item, cached_dropped_item ] : cached_entities.dropped_items ) {
        if ( !cache_dropped_item( dropped_item, cached_dropped_item ) )
            continue;

        cached_dropped_item.position = cached_dropped_item.transform->get_position();
    }

    for ( auto& [ player, cached_player ] : cached_entities.players ) {
        if ( !cache_player( player, cached_player ) )
            continue;

        cached_player.team_id = player->current_team;
        cached_player.player_flags = player->player_flags;
        cached_player.lifestate = player->lifestate;

        update_player_bones( cached_player );
        update_player_inventory( player, cached_player );
        update_player_visibility( player, cached_player );
        update_player_avatar( player, cached_player );
    }
}

void entity_manager::invalidate_cache() {
    util::scoped_spinlock lock( &cache_lock );

    cached_entities& cached_entities = entity_cache.get();

    cached_entities.entities.clear();
    cached_entities.combat_entities.clear();
    cached_entities.dropped_items.clear();

    for ( auto& [ _, cached_player ] : cached_entities.players ) {
        SAFE_RELEASE( cached_player.avatar_srv );
    }

    cached_entities.players.clear();
}

entity_collection entity_manager::get_entities() {
    cached_entities& cached_entities = entity_cache.get();

    return entity_collection {
        .entities = cached_entities.entities.values(),
        .named_entities = cached_entities.named_entities.values(),
        .combat_entities = cached_entities.combat_entities.values(),
        .dropped_items = cached_entities.dropped_items.values(),
        .players = cached_entities.players.values()
    };
}