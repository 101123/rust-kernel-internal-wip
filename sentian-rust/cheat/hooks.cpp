#include "hooks.h"
#include "global.h"	
#include "cheat/cheat.h"
#include "cheat/sdk/sdk.h"
#include "nt.h"
#include "cheat/entities.h"
#include "cheat/glow.h"
#include "gui.h"

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
				location_ = resolved_location::registers;
				position_ = i;
				return;
			}
		}

		if ( stack ) {
			for ( size_t i = 0, n = depth / sizeof( T ); i < n; i++ ) {
				size_t offset = i * sizeof( T );
				T value = *( T* )( context->Rsp + offset );

				if ( callback( value ) ) {
					location_ = resolved_location::stack;
					position_ = offset;
					return;
				}
			}
		}

		location_ = resolved_location::unresolved;
		position_ = 0ull;
	}

	bool resolved() {
		return location_ != resolved_location::unresolved;
	}

	T get( _CONTEXT* context ) {
		if ( location_ == resolved_location::registers ) {
			uint64_t* registers = ( uint64_t* )&context->Rax;
			return ( T )registers[ position_ ];
		} 
		
		else if ( location_ == resolved_location::stack ) {
			return *( T* )( context->Rsp + position_ );
		}

		return T();
	}

private:
	resolved_location location_;
	size_t position_;
};

void network_client_create_networkable_hook( rust::base_networkable* networkable ) {
	if ( !is_valid_ptr( networkable ) || !is_valid_ptr( networkable->cached_ptr ) )
		return;

	cache_specifier specifier;
	if ( !entity_manager::belongs_in_cache( networkable, &specifier ) )
		return;

	entity_manager::add_to_cache( networkable, &specifier );
}

void network_client_destroy_networkable_hook( rust::base_networkable* networkable ) {
	if ( !is_valid_ptr( networkable ) || !is_valid_ptr( networkable->cached_ptr ) )
		return;

	cache_specifier specifier;
	if ( !entity_manager::belongs_in_cache( networkable, &specifier ) )
		return;

	entity_manager::remove_from_cache( networkable, &specifier );
}

void player_walk_movement_do_fixed_update_hook( rust::player_walk_movement* player_walk_movement, rust::model_state* model_state ) {
	if ( omnisprint ) {
		rust::base_player* owner = player_walk_movement->owner;
		if ( !owner )
			return;

		if ( !model_state->has_flag( rust::model_state::flag::ducked ) &&
			!model_state->has_flag( rust::model_state::flag::crawling ) ) {
			vector3 current_velocity = player_walk_movement->target_movement;

			if ( vector3::magnitude( current_velocity ) > 0.f ) {
				player_walk_movement->target_movement = vector3::normalize( current_velocity ) * owner->get_speed( 1.f, 0.f, 0.f );
				model_state->set_flag( rust::model_state::flag::sprinting, true );
			}
		}
	}
}

void protobuf_player_tick_write_to_stream_delta_hook( rust::player_tick* player_tick ) {
	if ( !is_valid_ptr( player_tick ) )
		return;

	rust::model_state* model_state = player_tick->model_state;
	if ( !is_valid_ptr( model_state ) )
		return;

	model_state->set_flag( rust::model_state::flag::sprinting, true );
}

void protobuf_projectile_shoot_write_to_stream_hook( sys::list<rust::projectile_shoot::projectile*>* server_projectiles_list, sys::list<rust::projectile*>* created_projectiles_list ) {
	if ( !is_valid_ptr( created_projectiles_list ) || !is_valid_ptr( created_projectiles_list->items ) )
		return;

	sys::array<rust::projectile_shoot::projectile*>* server_projectiles = server_projectiles_list->items;
	if ( !is_valid_ptr( server_projectiles ) )
		return;

	sys::array<rust::projectile*>* client_projectiles = created_projectiles_list->items;
	if ( !is_valid_ptr( server_projectiles ) )
		return;

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

void item_icon_try_to_move_hook( rust::item_icon* item_icon ) {
	if ( instant_loot ) {
		item_icon->run_timed_action();
	}
}

void client_on_client_disconnected_hook( rust::client* client, sys::string* reason ) {
	entity_manager::invalidate_cache();
	glow_manager::invalidate_cache();

	local_player = nullptr;
	target_player = nullptr;
}

void base_player_client_input_hook( rust::base_player* base_player, rust::input_state* state ) {
	local_player = base_player;
}

void hook_handlers::network_client_create_networkable( _CONTEXT* context ) {
	static context_search search = context_search<rust::base_networkable*>( context,
		[]( rust::base_networkable* value ) {
			if ( !is_valid_ptr( value ) )
				return false;

			if ( !value->as<rust::base_networkable>() )
				return false;

			unity::transform* transform = value->get_transform();
			if ( is_valid_ptr( transform ) ) {
				vector3 position = transform->get_position();

				char buffer[ 32 ] = {};
				snprintf( buffer, 32, "Start Position: %.2f %.2f %.2f\n", position.x, position.y, position.z );

				LOG( buffer );
			}

			// We don't want any entities with a valid networkable object as we're hooking the creation of it
			return !is_valid_ptr( value->net );
		}, true, 0x100 );

	if ( !search.resolved() )
		return;

	network_client_create_networkable_hook( search.get( context ) );
}

void hook_handlers::network_client_destroy_networkable( _CONTEXT* context ) {
	static context_search search = context_search<rust::base_networkable*>( context,
		[]( rust::base_networkable* value ) {
			if ( !is_valid_ptr( value ) )
				return false;

			return value->as<rust::base_networkable>() != nullptr;
		}, true, 0x100 );

	if ( !search.resolved() )
		return;

	network_client_destroy_networkable_hook( search.get( context ) );
}

// TODO: Clean up and put asset bundle loading in another place

bool init = false;

void hook_handlers::outline_manager_on_render_image( _CONTEXT* context ) {
	if ( !init ) {
		asset_bundle = unity::asset_bundle::load_from_file( L"C://assetbundle", 0u, 0ull );
		glow_manager::init( asset_bundle );
		init = true;
	}

	if ( unity::input::get_key_down( unity::key_code::end ) ) {
		gui::open = !gui::open;
	}

	// Update entities
	entity_manager::update();

	glow_manager::update();
	glow_manager::on_render_image_hook( ( unity::render_texture* )context->Rdx, ( unity::render_texture* )context->R8 );
}

void hook_handlers::player_walk_movement_do_fixed_update( _CONTEXT* context ) {
	player_walk_movement_do_fixed_update_hook( ( rust::player_walk_movement* )context->Rcx, ( rust::model_state* )context->Rdx );
}

void hook_handlers::protobuf_player_tick_write_to_stream_delta( _CONTEXT* context ) {
	protobuf_player_tick_write_to_stream_delta_hook( ( rust::player_tick* )context->Rcx );
}

void hook_handlers::protobuf_projectile_shoot_write_to_stream( _CONTEXT* context ) {
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
		// TODO: Improve this further
		static context_search search = context_search<sys::list<rust::projectile*>*>( context,
			[&]( sys::list<rust::projectile*>* value ) {
				if ( !is_valid_ptr( value ) || !is_valid_ptr( value->items ) )
					return false;

				il2cpp_class* klass = value->klass;
				if ( !is_valid_ptr( klass ) || !is_valid_ptr( klass->name ) )
					return false;

				// Protect against garbage
				char class_name[ 64 ] = {};
				memcpy( class_name, klass->name, sizeof( class_name ) - 1llu );

				// We've found a list, it may or not contain projectile objects
				return util::hash( class_name ) == H( "List`1" );
			}, true, 0x100 );

		if ( !search.resolved() )
			return;

		protobuf_projectile_shoot_write_to_stream_hook( projectile_shoot->projectiles, search.get( context ) );
	}

	else if ( held_entity->as<rust::base_melee>() ) {

	}
}

void hook_handlers::protobuf_player_projectile_update_write_to_stream( _CONTEXT* context ) {

}

void hook_handlers::protobuf_player_projectile_attack_write_to_stream( _CONTEXT* context ) {

}

void hook_handlers::item_icon_try_to_move( _CONTEXT* context ) {
	item_icon_try_to_move_hook( ( rust::item_icon* )context->Rcx );
}

void hook_handlers::client_on_client_disconnected( _CONTEXT* context ) {
	client_on_client_disconnected_hook( ( rust::client* )context->Rcx, ( sys::string* )context->Rdx );
}

void hook_handlers::base_player_client_input( _CONTEXT* context ) {
	base_player_client_input_hook( ( rust::base_player* )context->Rcx, ( rust::input_state* )context->Rdx );
}