#include "hook.h"
#include "global.h"	
#include "cheat/cheat.h"
#include "cheat/sdk/sdk.h"
#include "nt.h"
#include "cheat/entities.h"
#include "cheat/glow.h"

#include <cstddef>

enum resolved_location {
	unresolved,
	registers,
	stack,
};

template <typename T>
class context_search {
public:
	static_assert( sizeof( T ) <= sizeof( uint64_t ) );

	context_search() = delete;

	template <typename C>
	context_search( _CONTEXT* context, C&& callback, bool stack, size_t depth ) {
		uint64_t* registers = ( uint64_t* )&context->Rax;
		constexpr size_t num_registers = ( offsetof( CONTEXT, Rip ) - offsetof( CONTEXT, Rax ) ) / sizeof( uint64_t );

		for ( size_t i = 0; i < num_registers; i++ ) {
			T value = ( T )registers[ i ];

			if ( callback( value ) ) {
				m_location = resolved_location::registers;
				m_offset = i;
				return;
			}
		}

		if ( stack ) {
			for ( size_t i = 0, n = depth / sizeof( T ); i < n; i++ ) {
				size_t offset = i * sizeof( T );
				T value = *( T* )( context->Rsp + offset );

				if ( callback( value ) ) {
					m_location = resolved_location::stack;
					m_offset = offset;
					return;
				}
			}
		}

		m_offset = 0;
		m_location = resolved_location::unresolved;
	}

	bool resolved() {
		return m_location != resolved_location::unresolved;
	}

	T get( _CONTEXT* context ) {
		if ( m_location == resolved_location::registers ) {
			uint64_t* registers = ( uint64_t* )&context->Rax;
			return ( T )registers[ m_offset ];
		} 
		
		else if ( m_location == resolved_location::stack ) {
			return *( T* )( context->Rsp + m_offset );
		}

		return T();
	}

private:
	resolved_location m_location;
	size_t m_offset;
};

void create_networkable_hook( rust::base_networkable* networkable ) {
	if ( !is_valid_ptr( networkable ) || !is_valid_ptr( networkable->cached_ptr ) )
		return;

	cache_specifier specifier;
	if ( !entity_manager::belongs_in_cache( networkable, &specifier ) )
		return;

	entity_manager::add_to_cache( networkable, &specifier );
}

void create_networkable_hook_handler( _CONTEXT* context ) {
	static context_search search = context_search<rust::base_networkable*>( context,
		[]( rust::base_networkable* value ) {
			if ( !is_valid_ptr( value ) )
				return false;

			return value->as<rust::base_networkable>() != nullptr;
		}, true, 0x100 );

	if ( !search.resolved() )
		return;

	create_networkable_hook( search.get( context ) );
}

void destroy_networkable_hook( rust::base_networkable* networkable ) {
	if ( !is_valid_ptr( networkable ) || !is_valid_ptr( networkable->cached_ptr ) )
		return;

	cache_specifier specifier;
	if ( !entity_manager::belongs_in_cache( networkable, &specifier ) )
		return;

	entity_manager::remove_from_cache( networkable, &specifier );
}

void destroy_networkable_hook_handler( _CONTEXT* context ) {
	static context_search search = context_search<rust::base_networkable*>( context,
		[]( rust::base_networkable* value ) {
			if ( !is_valid_ptr( value ) )
				return false;

			return value->as<rust::base_networkable>() != nullptr;
		}, true, 0x100 );

	if ( !search.resolved() )
		return;

	destroy_networkable_hook( search.get( context ) );
}

// TODO: Clean up and put asset bundle loading in another place

bool init = false;

void on_render_image_hook_handler( _CONTEXT* context ) {
	if ( !init ) {
		asset_bundle = unity::asset_bundle::load_from_file( L"C://assetbundle", 0u, 0ull );
		glow_manager::init( asset_bundle );
		init = true;
	}

	// Update entities
	entity_manager::update();

	glow_manager::on_render_image_hook( ( unity::render_texture* )context->Rdx, ( unity::render_texture* )context->R8 );
}

void movement_hook( rust::player_walk_movement* player_walk_movement, rust::model_state* model_state ) {
	// omnisprint
	{
		rust::base_player* owner = player_walk_movement->owner;
		if ( !owner )
			return;

		if ( !model_state->has_flag( rust::model_state::flag::ducked ) &&
			!model_state->has_flag( rust::model_state::flag::crawling ) ) {
			Vector3 current_velocity = player_walk_movement->target_movement;

			if ( Vector3::magnitude( current_velocity ) > 0.f ) {
				player_walk_movement->target_movement = Vector3::normalize( current_velocity ) * owner->get_speed( 1.f, 0.f, 0.f );
				model_state->set_flag( rust::model_state::flag::sprinting, true );
			}
		}
	}
}

void movement_hook_handler( _CONTEXT* context ) {
	// movement_hook( ( rust::player_walk_movement* )context->Rcx, ( rust::model_state* )context->Rdx );
}

void projectile_shoot_write_to_stream_hook( sys::list<rust::projectile_shoot::projectile*>* server_projectiles_list, sys::list<rust::projectile*>* created_projectiles_list ) {
	if ( !is_valid_ptr( created_projectiles_list ) || !is_valid_ptr( created_projectiles_list->items ) )
		return;

	sys::array<rust::projectile_shoot::projectile*>* server_projectiles = server_projectiles_list->items;
	if ( !is_valid_ptr( server_projectiles ) )
		return;

	sys::array<rust::projectile*>* client_projectiles = created_projectiles_list->items;
	if ( !is_valid_ptr( server_projectiles ) )
		return;

	LOG( "Projectile ct: %d\n", server_projectiles_list->size );

	// The list contains the actual count, not the underlying array
	for ( size_t i = 0; i < server_projectiles_list->size; i++ ) {
		rust::projectile_shoot::projectile* server_projectile = server_projectiles->buffer[ i ];
		if ( !is_valid_ptr( server_projectile ) )
			continue;

		rust::projectile* client_projectile = client_projectiles->buffer[ i ];
		if ( !is_valid_ptr( client_projectile ) )
			continue;

		LOG( "Server: %p, Client: %p\n", server_projectile, client_projectile );
	}
}

void projectile_shoot_write_to_stream_hook_handler( _CONTEXT* context ) {
	rust::projectile_shoot* projectile_shoot = ( rust::projectile_shoot* )context->Rcx;
	if ( !is_valid_ptr( projectile_shoot ) || !is_valid_ptr( projectile_shoot->projectiles ) )
		return;

	rust::base_player* local_player = rust::local_player::get_entity();
	if ( !is_valid_ptr( local_player ) )
		return;

	rust::held_entity* held_entity = local_player->get_held_entity();
	if ( !held_entity )
		return;

	if ( held_entity->as<rust::base_projectile>() ) {
		// TODO: Improve this to lessen chance of false positives
		static context_search search = context_search<sys::list<rust::projectile*>*>( context,
			[&]( sys::list<rust::projectile*>* value ) {
				if ( !is_valid_ptr( value ) || !is_valid_ptr( value->items ) )
					return false;

				return value->size == projectile_shoot->projectiles->size;
			}, true, 0x100 );

		if ( !search.resolved() )
			return;

		projectile_shoot_write_to_stream_hook( projectile_shoot->projectiles, search.get( context ) );
	}

	else if ( held_entity->as<rust::base_melee>() ) {
		
	}
}

void player_projectile_update_write_to_stream_hook_handler( _CONTEXT* context ) {

}

void player_projectile_attack_write_to_stream_hook_handler( _CONTEXT* context ) {

}

void item_icon_try_to_move_hook( rust::item_icon* item_icon ) {
	if ( !is_valid_ptr( item_icon ) )
		return;

	// Instant loot
	{
		item_icon->run_timed_action();
	}
}

void item_icon_try_to_move_hook_handler( _CONTEXT* context ) {
	item_icon_try_to_move_hook( ( rust::item_icon* )context->Rcx );
}