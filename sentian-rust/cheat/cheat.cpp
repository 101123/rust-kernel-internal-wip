#include "cheat/cheat.h"
#include "global.h"
#include "sdk/sdk.h"
#include "cheat/hook/hook.h"
#include "util.h"
#include "cheat/entities.h"

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
	{ nullptr, nullptr, &rust::base_networkable::s_static_fields, BaseNetworkable_Static_TypeDefinitionIndex },
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
	{ &rust::player_tick::s_klass, nullptr, nullptr, PlayerTick_TypeDefinitionIndex }
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

bool resolve_hooks() {
	uintptr_t facepunch_pool_get_networkable_method = util::find_pattern(
		game_assembly + Offsets::Network_Client::CreateNetworkable, "\x48\x8D\x0D", 0x100 );

	if ( !is_valid_ptr( facepunch_pool_get_networkable_method ) )
		return false;

	hook create_networkable_hook {
		.init = false,
		.type = hook_type::method_info,
		.value = ( uintptr_t* )util::relative_32( facepunch_pool_get_networkable_method, 3 ),
		.original = 0ull,
		.corrupt = generate_corrupt_value(),
		.handler = create_networkable_hook_handler
	};

	uintptr_t facepunch_pool_free_networkable_method = util::find_pattern(
		game_assembly + Offsets::Network_Client::DestroyNetworkable, "\x48\x8D\x0D", 0x100 );

	if ( !is_valid_ptr( facepunch_pool_free_networkable_method ) )
		return false;

	hook destroy_networkable_hook {
		.init = false,
		.type = hook_type::method_info,
		.value = ( uintptr_t* )util::relative_32( facepunch_pool_free_networkable_method, 3 ),
		.original = 0ull,
		.corrupt = generate_corrupt_value(),
		.handler = destroy_networkable_hook_handler
	};

	method_info* outline_manager_on_render_image_method = il2cpp_class_get_method_from_name( rust::outline_manager::s_klass, "OnRenderImage", 2 );
	if ( !outline_manager_on_render_image_method )
		return false;

	hook on_render_image_hook {
		.init = false,
		.type = hook_type::vftable,
		.value = ( uintptr_t* )&outline_manager_on_render_image_method->method_ptr,
		.original = 0ull,
		.corrupt = generate_corrupt_value(),
		.handler = on_render_image_hook_handler
	};

	hook movement_hook {
		.init = false,
		.type = hook_type::vftable,
		.value = ( uintptr_t* )( ( uintptr_t )rust::player_walk_movement::s_klass + Offsets::PlayerWalkMovement::DoFixedUpdate_vtableoff ),
		.original = 0ull,
		.corrupt = generate_corrupt_value(),
		.handler = movement_hook_handler
	};

	hook projectile_shoot_hook {
		.init = false,
		.type = hook_type::vftable,
		.value = ( uintptr_t* )( ( uintptr_t )rust::projectile_shoot::s_klass + Offsets::IProto::WriteToStream_vtableoff ),
		.original = 0ull,
		.corrupt = generate_corrupt_value(),
		.handler = projectile_shoot_write_to_stream_hook_handler
	};

	auto& hooks = hook_manager::hooks;

	hooks.add( create_networkable_hook );
	hooks.add( destroy_networkable_hook );
	hooks.add( on_render_image_hook );
	//hooks.add( movement_hook );
	hooks.add( projectile_shoot_hook );

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
			if ( hook.type == hook_type::vftable ) {
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