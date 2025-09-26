#include "cheat/cheat.h"
#include "cheat/hooks.h"
#include "sdk/sdk.h"

struct class_lookup {
	il2cpp_class** klass;
	il2cpp_object** type_object;
	void* static_fields;
	uint64_t type_definition_index;
};

struct parent_class_lookup {
	il2cpp_class** start;
	il2cpp_class** klass;
	void* static_fields;
	uint32_t depth;
};

class_lookup class_lookups[] = {
	{ nullptr, nullptr, &rust::graphics::static_fields_, ConVar_Graphics_Static_TypeDefinitionIndex },
	{ &rust::main_camera::klass_, nullptr, &rust::main_camera::static_fields_, MainCamera_TypeDefinitionIndex },
	{ &rust::base_networkable::klass_, nullptr, nullptr, BaseNetworkable_TypeDefinitionIndex },
	{ &rust::base_player::klass_, nullptr, nullptr, BasePlayer_TypeDefinitionIndex },
	{ &rust::scientist_npc::klass_, nullptr, nullptr, ScientistNPC_TypeDefinitionIndex },
	{ &rust::tunnel_dweller::klass_, nullptr, nullptr, TunnelDweller_TypeDefinitionIndex },
	{ &rust::underwater_dweller::klass_, nullptr, nullptr, UnderwaterDweller_TypeDefinitionIndex },
	{ &rust::scarecrow_npc::klass_, nullptr, nullptr, ScarecrowNPC_TypeDefinitionIndex },
	{ &rust::gingerbread_npc::klass_, nullptr, nullptr, GingerbreadNPC_TypeDefinitionIndex },
	{ &rust::player_eyes::klass_, &rust::player_eyes::type_object_, nullptr, PlayerEyes_TypeDefinitionIndex },
	{ &rust::player_inventory::klass_, &rust::player_inventory::type_object_, nullptr, PlayerInventory_TypeDefinitionIndex },
	{ &unity::render_target_identifier::klass_, nullptr, nullptr, RenderTargetIdentifier_TypeDefinitionIndex },
	{ &unity::command_buffer::klass_, nullptr, nullptr, CommandBuffer_TypeDefinitionIndex },
	{ nullptr, &unity::shader::type_object_, nullptr, Shader_TypeDefinitionIndex },
	{ nullptr, &unity::component::type_object_, nullptr, Component_TypeDefinitionIndex },
	{ &unity::behaviour::klass_, nullptr, nullptr, Behaviour_TypeDefinitionIndex },
	{ &unity::material::klass_ , &unity::material::type_object_, nullptr, Material_TypeDefinitionIndex },
	{ &rust::outline_manager::klass_, nullptr, nullptr, OutlineManager_TypeDefinitionIndex },
	{ &rust::held_entity::klass_, &rust::held_entity::type_object_, nullptr, HeldEntity_TypeDefinitionIndex },
	{ &rust::attack_entity::klass_, nullptr, nullptr, AttackEntity_TypeDefinitionIndex },
	{ &rust::base_melee::klass_, nullptr, nullptr, BaseMelee_TypeDefinitionIndex },
	{ &rust::base_projectile::klass_, nullptr, nullptr, BaseProjectile_TypeDefinitionIndex },
	{ &rust::player_walk_movement::klass_, nullptr, nullptr, PlayerWalkMovement_TypeDefinitionIndex },
	{ &rust::player_projectile_update::klass_, nullptr, nullptr, ProtoBuf_PlayerProjectileUpdate_TypeDefinitionIndex },
	{ &rust::player_projectile_attack::klass_, nullptr, nullptr, ProtoBuf_PlayerProjectileAttack_TypeDefinitionIndex },
	{ &rust::projectile_shoot::klass_, nullptr, nullptr, ProtoBuf_ProjectileShoot_TypeDefinitionIndex },
	{ &rust::player_tick::klass_, nullptr, nullptr, PlayerTick_TypeDefinitionIndex },
	{ &rust::item_icon::klass_, nullptr, nullptr, ItemIcon_TypeDefinitionIndex },
	{ &rust::client::klass_, nullptr, nullptr, Client_TypeDefinitionIndex }
};

parent_class_lookup parent_class_lookups[] = {
	{ &rust::main_camera::klass_, nullptr, &rust::singleton_component<rust::rust_camera>::static_fields_, 2u }
};

bool populate_classes() {
	static uintptr_t type_info_definition_table_address = util::relative_32(
		util::find_pattern_image( game_assembly, "\x48\xF7\xE1\x48\x8B\xCA\x48\xC1\xE9\x04\xBA\x08\x00\x00\x00" ) + 21, 3 );

	if ( !is_valid_ptr( type_info_definition_table_address ) )
		return false;

	il2cpp_class** type_info_definition_table = *( il2cpp_class*** )( type_info_definition_table_address );
	if ( !is_valid_ptr( type_info_definition_table ) )
		return false;

	for ( class_lookup& class_lookup : class_lookups ) {
		il2cpp_class* klass = *( il2cpp_class** )( &type_info_definition_table[ class_lookup.type_definition_index ] );
		if ( !is_valid_ptr( klass ) )
			return false;

		if ( class_lookup.klass ) {
			*class_lookup.klass = klass;
		}

		if ( class_lookup.type_object ) {
			*class_lookup.type_object = il2cpp_type_get_object( il2cpp_class_get_type( klass ) );
		}

		if ( class_lookup.static_fields ) {
			*( uintptr_t* )( class_lookup.static_fields ) = klass->static_fields;
		}
	}

	for ( parent_class_lookup& parent_class_lookup : parent_class_lookups ) {
		il2cpp_class* klass = *parent_class_lookup.start;

		while ( parent_class_lookup.depth-- ) {
			if ( !is_valid_ptr( klass ) )
				return false;

			klass = klass->parent;
		}

		if ( parent_class_lookup.klass ) {
			*parent_class_lookup.klass = klass;
		}

		if ( parent_class_lookup.static_fields ) {
			*( uintptr_t* )( parent_class_lookup.static_fields ) = klass->static_fields;
		}
	}

	return true;
}

bool bootstrap::init() {
	if ( !game_assembly ) {
		if ( !( game_assembly = util::get_process_module_info( rust_process, H( "GameAssembly.dll" ) ).base_address ) ) {
			return false;
		}
	}

	if ( !unity_player ) {
		if ( !( unity_player = util::get_process_module_info( rust_process, H( "UnityPlayer.dll" ) ).base_address ) ) {
			return false;
		}
	}

	if ( !populated_classes ) {
		if ( !( populated_classes = populate_classes() ) ) {
			return false;
		}
	}

	return true;
}

const uint64_t generate_corrupt_value() {
	static size_t count = 0ull;
	return 0xDEADCAFEBEEF0000ull + ( count++ << 16ull );
}

#define VFUNC( klass, offset ) ( uintptr_t* )( ( uintptr_t )klass::klass_ + offset )

bool resolve_hooks() {
	uintptr_t facepunch_pool_get_networkable_method = util::find_pattern(
		game_assembly + Offsets::Network_Client::CreateNetworkable, "\x48\x8D\x0D", 0x100 );

	if ( !is_valid_ptr( facepunch_pool_get_networkable_method ) )
		return false;

	hook network_client_create_networkable_hook {
		.init = false,
		.flags = hook_flags::method_info,
		.value = ( uintptr_t* )util::relative_32( facepunch_pool_get_networkable_method, 3 ),
		.original = 0ull,
		.corrupt = generate_corrupt_value(),
		.handler = hook_handlers::network_client_create_networkable
	};

	uintptr_t facepunch_pool_free_networkable_method = util::find_pattern(
		game_assembly + Offsets::Network_Client::DestroyNetworkable, "\x48\x8D\x0D", 0x100 );

	if ( !is_valid_ptr( facepunch_pool_free_networkable_method ) )
		return false;

	hook network_client_destroy_networkable_hook {
		.init = false,
		.flags = hook_flags::method_info,
		.value = ( uintptr_t* )util::relative_32( facepunch_pool_free_networkable_method, 3 ),
		.original = 0ull,
		.corrupt = generate_corrupt_value(),
		.handler = hook_handlers::network_client_destroy_networkable
	};

	method_info* outline_manager_on_render_image_method = il2cpp_class_get_method_from_name( rust::outline_manager::klass_, "OnRenderImage", 2 );
	if ( !outline_manager_on_render_image_method )
		return false;

	hook outline_manager_on_render_image_hook {
		.init = false,
		.flags = hook_flags::vftable | hook_flags::post,
		.value = ( uintptr_t* )&outline_manager_on_render_image_method->method_ptr,
		.original = 0ull,
		.corrupt = generate_corrupt_value(),
		.handler = hook_handlers::outline_manager_on_render_image
	};

	hook player_walk_movement_do_fixed_update_hook {
		.init = false,
		.flags = hook_flags::vftable,
		.value = VFUNC( rust::player_walk_movement, Offsets::PlayerWalkMovement::DoFixedUpdate_vtableoff ),
		.original = 0ull,
		.corrupt = generate_corrupt_value(),
		.handler = hook_handlers::player_walk_movement_do_fixed_update
	};

	hook protobuf_projectile_shoot_write_to_stream_hook {
		.init = false,
		.flags = hook_flags::vftable,
		.value = VFUNC( rust::projectile_shoot, Offsets::ProtoBuf_ProjectileShoot::WriteToStream_vtableoff ),
		.original = 0ull,
		.corrupt = generate_corrupt_value(),
		.handler = hook_handlers::protobuf_projectile_shoot_write_to_stream
	};

	hook item_icon_try_to_move_hook {
		.init = false,
		.flags = hook_flags::vftable | hook_flags::post,
		.value = VFUNC( rust::item_icon, Offsets::ItemIcon::TryToMove_vtableoff ),
		.original = 0ull,
		.corrupt = generate_corrupt_value(),
		.handler = hook_handlers::item_icon_try_to_move
	};

	hook protobuf_player_tick_write_to_stream_delta_hook {
		.init = false,
		.flags = hook_flags::vftable,
		.value = VFUNC( rust::player_tick, Offsets::PlayerTick::WriteToStreamDelta_vtableoff ),
		.original = 0ull,
		.corrupt = generate_corrupt_value(),
		.handler = hook_handlers::protobuf_player_tick_write_to_stream_delta
	};

	hook client_on_client_disconnected_hook {
		.init = false,
		.flags = hook_flags::vftable,
		.value = VFUNC( rust::client, Offsets::Client::OnClientDisconnected_vtableoff ),
		.original = 0ull,
		.corrupt = generate_corrupt_value(),
		.handler = hook_handlers::client_on_client_disconnected
	};

	auto& hooks = hook_manager::hooks;

	hooks.add( network_client_create_networkable_hook );
	hooks.add( network_client_destroy_networkable_hook );
	hooks.add( outline_manager_on_render_image_hook );
	hooks.add( player_walk_movement_do_fixed_update_hook );
	hooks.add( protobuf_projectile_shoot_write_to_stream_hook );
	hooks.add( item_icon_try_to_move_hook );
	hooks.add( protobuf_player_tick_write_to_stream_delta_hook );
	hooks.add( client_on_client_disconnected_hook );

	return true;
}

bool hook_manager::init() {
	// This must be called after classes are populated for vftable hooks
	if ( !bootstrap::populated_classes )
		return false;

	if ( resolved_hooks )
		return true;

	resolved_hooks = resolve_hooks();
}

void hook_manager::place_hooks() {
	if ( !resolved_hooks )
		return;

	for ( hook& hook : hooks ) {
		if ( !hook.init && is_valid_ptr( *hook.value ) ) {
			hook.original = *hook.value;

			// If it's a vftable hook, we set the corrupted value to the address of the function - 1 so that it lands on function padding (0xCC)
			if ( hook.flags & hook_flags::vftable ) {
				hook.corrupt = hook.original - 1;
			}

			hook.init = true;
		}

		else if ( hook.init ) {
			*hook.value = hook.corrupt;
		}
	}
}

void hook_manager::remove_hooks() {
	if ( !resolved_hooks )
		return;

	for ( hook& hook : hooks ) {
		if ( !hook.init )
			continue;

		*hook.value = hook.original;
	}
}