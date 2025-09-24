#include "cheat/cheat.h"
#include "cheat/hook.h"
#include "sdk/sdk.h"

struct class_lookup {
	il2cpp_class** klass;
	il2cpp_object** type_object;
	void* static_fields;
	uint64_t type_definition_index;
};

struct parent_lookup {
	il2cpp_class** start;
	il2cpp_class** klass;
	void* static_fields;
	int depth;
};

class_lookup class_lookups[] = {
	{ nullptr, nullptr, &rust::graphics::s_static_fields, ConVar_Graphics_Static_TypeDefinitionIndex },
	{ &rust::main_camera::s_klass, nullptr, &rust::main_camera::s_static_fields, MainCamera_TypeDefinitionIndex },
	{ &rust::base_networkable::s_klass, nullptr, nullptr, BaseNetworkable_TypeDefinitionIndex },
	{ &rust::base_player::s_klass, nullptr, nullptr, BasePlayer_TypeDefinitionIndex },
	{ &rust::scientist_npc::s_klass, nullptr, nullptr, ScientistNPC_TypeDefinitionIndex },
	{ &rust::tunnel_dweller::s_klass, nullptr, nullptr, TunnelDweller_TypeDefinitionIndex },
	{ &rust::underwater_dweller::s_klass, nullptr, nullptr, UnderwaterDweller_TypeDefinitionIndex },
	{ &rust::scarecrow_npc::s_klass, nullptr, nullptr, ScarecrowNPC_TypeDefinitionIndex },
	{ &rust::gingerbread_npc::s_klass, nullptr, nullptr, GingerbreadNPC_TypeDefinitionIndex },
	{ &rust::player_eyes::s_klass, &rust::player_eyes::s_type_object, nullptr, PlayerEyes_TypeDefinitionIndex },
	{ &rust::player_inventory::s_klass, &rust::player_inventory::s_type_object, nullptr, PlayerInventory_TypeDefinitionIndex },
	{ &unity::render_target_identifier::s_klass, nullptr, nullptr, RenderTargetIdentifier_TypeDefinitionIndex },
	{ &unity::command_buffer::s_klass, nullptr, nullptr, CommandBuffer_TypeDefinitionIndex },
	{ nullptr, &unity::shader::s_type_object, nullptr, Shader_TypeDefinitionIndex },
	{ nullptr, &unity::component::s_type_object, nullptr, Component_TypeDefinitionIndex },
	{ &unity::behaviour::s_klass, nullptr, nullptr, Behaviour_TypeDefinitionIndex },
	{ &unity::material::s_klass , &unity::material::s_type_object, nullptr, Material_TypeDefinitionIndex },
	{ &rust::outline_manager::s_klass, nullptr, nullptr, OutlineManager_TypeDefinitionIndex },
	{ &rust::held_entity::s_klass, &rust::held_entity::s_type_object, nullptr, HeldEntity_TypeDefinitionIndex },
	{ &rust::attack_entity::s_klass, nullptr, nullptr, AttackEntity_TypeDefinitionIndex },
	{ &rust::base_melee::s_klass, nullptr, nullptr, BaseMelee_TypeDefinitionIndex },
	{ &rust::base_projectile::s_klass, nullptr, nullptr, BaseProjectile_TypeDefinitionIndex },
	{ &rust::player_walk_movement::s_klass, nullptr, nullptr, PlayerWalkMovement_TypeDefinitionIndex },
	{ &rust::player_projectile_update::s_klass, nullptr, nullptr, ProtoBuf_PlayerProjectileUpdate_TypeDefinitionIndex },
	{ &rust::player_projectile_attack::s_klass, nullptr, nullptr, ProtoBuf_PlayerProjectileAttack_TypeDefinitionIndex },
	{ &rust::projectile_shoot::s_klass, nullptr, nullptr, ProtoBuf_ProjectileShoot_TypeDefinitionIndex },
	{ &rust::player_tick::s_klass, nullptr, nullptr, PlayerTick_TypeDefinitionIndex },
	{ &rust::item_icon::s_klass, nullptr, nullptr, ItemIcon_TypeDefinitionIndex },
	{ &rust::client::s_klass, nullptr, nullptr, Client_TypeDefinitionIndex }
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

#define VFUNC( klass, offset ) ( uintptr_t* )( ( uintptr_t )klass::s_klass + offset )

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

	method_info* outline_manager_on_render_image_method = il2cpp_class_get_method_from_name( rust::outline_manager::s_klass, "OnRenderImage", 2 );
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