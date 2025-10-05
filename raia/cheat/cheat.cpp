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
	{ nullptr, &rust::item_mod_projectile::type_object_, nullptr, ItemModProjectile_TypeDefinitionIndex },
	{ &rust::projectile::klass_, &rust::projectile::type_object_, nullptr, Projectile_TypeDefinitionIndex },
	{ &unity::behaviour::klass_, nullptr, nullptr, Behaviour_TypeDefinitionIndex },
	{ &unity::material::klass_ , &unity::material::type_object_, nullptr, Material_TypeDefinitionIndex },
	{ &rust::outline_manager::klass_, nullptr, nullptr, OutlineManager_TypeDefinitionIndex },
	{ &rust::held_entity::klass_, &rust::held_entity::type_object_, nullptr, HeldEntity_TypeDefinitionIndex },
	{ &rust::attack_entity::klass_, nullptr, nullptr, AttackEntity_TypeDefinitionIndex },
	{ &rust::base_melee::klass_, nullptr, nullptr, BaseMelee_TypeDefinitionIndex },
	{ &rust::base_projectile::klass_, nullptr, nullptr, BaseProjectile_TypeDefinitionIndex },
	{ &rust::bow_weapon::klass_, nullptr, nullptr, BowWeapon_TypeDefinitionIndex },
	{ &rust::crossbow_weapon::klass_, nullptr, nullptr, CrossbowWeapon_TypeDefinitionIndex },
	{ &rust::mini_crossbow::klass_, nullptr, nullptr, MiniCrossbow_TypeDefinitionIndex },
	{ &rust::flint_strike_weapon::klass_, nullptr, nullptr, FlintStrikeWeapon_TypeDefinitionIndex },
	{ &rust::spin_up_weapon::klass_, nullptr, nullptr, SpinUpWeapon_TypeDefinitionIndex },
	{ &rust::player_walk_movement::klass_, nullptr, nullptr, PlayerWalkMovement_TypeDefinitionIndex },
	{ &rust::player_projectile_update::klass_, nullptr, nullptr, ProtoBuf_PlayerProjectileUpdate_TypeDefinitionIndex },
	{ &rust::player_projectile_attack::klass_, nullptr, nullptr, ProtoBuf_PlayerProjectileAttack_TypeDefinitionIndex },
	{ &rust::projectile_shoot::klass_, nullptr, nullptr, ProtoBuf_ProjectileShoot_TypeDefinitionIndex },
	{ &rust::player_tick::klass_, nullptr, nullptr, PlayerTick_TypeDefinitionIndex },
	{ &rust::item_icon::klass_, nullptr, nullptr, ItemIcon_TypeDefinitionIndex },
	{ &rust::client::klass_, nullptr, nullptr, Client_TypeDefinitionIndex },
	{ &unity::game_object::klass_, nullptr, nullptr, GameObject_TypeDefinitionIndex },
	{ &rust::projectile_weapon_mod::klass_, nullptr, nullptr, ProjectileWeaponMod_TypeDefinitionIndex },
	{ &rust::base_launcher::klass_, nullptr, nullptr, BaseLauncher_TypeDefinitionIndex },
	{ nullptr, nullptr, &rust::game_physics::static_fields_, GamePhysics_Static_TypeDefinitionIndex },
	{ &rust::compound_bow_weapon::klass_, nullptr, nullptr, CompoundBowWeapon_TypeDefinitionIndex },
	{ &rust::console_system::arg::klass_, nullptr, nullptr, ConsoleSystem_Arg_TypeDefinitionIndex },
	{ &rust::patrol_helicopter::klass_, nullptr, nullptr, PatrolHelicopter_TypeDefinitionIndex },
	{ nullptr, nullptr, &rust::effect_network::static_fields_, EffectNetwork_Static_TypeDefinitionIndex },
	{ &rust::effect::klass_, nullptr, nullptr, Effect_TypeDefinitionIndex }
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

			if ( !is_valid_ptr( *class_lookup.type_object ) ) {
#ifdef DEBUG
				LOG( "Failed to resolve type object\n" );
#endif
				return false;
			}
		}

		uintptr_t* static_fields_lookup = ( uintptr_t* )class_lookup.static_fields;

		if ( static_fields_lookup ) {
			*static_fields_lookup = klass->static_fields;

			if ( !is_valid_ptr( *static_fields_lookup ) ) {
#ifdef DEBUG
				LOG( "Failed to resolve static fields\n" );
#endif

				return false;
			}
		}
	}

	/*for ( parent_class_lookup& parent_class_lookup : parent_class_lookups ) {
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
	}*/

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

	hook network_client_create_networkable_hook = {
		.init = false,
		.type = hook_type::method_info,
		.value = ( uintptr_t* )util::relative_32( facepunch_pool_get_networkable_method, 3 ),
		.original = 0ull,
		.corrupt = generate_corrupt_value(),
		.method_info = {
			.handler = hook_handlers::network_client_create_networkable
		}
	};

	uintptr_t facepunch_pool_free_networkable_method = util::find_pattern(
		game_assembly + Offsets::Network_Client::DestroyNetworkable, "\x48\x8D\x0D", 0x100 );

	if ( !is_valid_ptr( facepunch_pool_free_networkable_method ) )
		return false;

	hook network_client_destroy_networkable_hook = {
		.init = false,
		.type = hook_type::method_info,
		.value = ( uintptr_t* )util::relative_32( facepunch_pool_free_networkable_method, 3 ),
		.original = 0ull,
		.corrupt = generate_corrupt_value(),
		.method_info = {
			.handler = hook_handlers::network_client_destroy_networkable
		}
	};

	uintptr_t facepunch_pool_get_list_ieffect_method = util::find_pattern(
		game_assembly + Offsets::EffectLibrary::SetupEffect, "\x48\x8B\x1D\xCC\xCC\xCC\xCC\x4C\x39\x63\x38", 0x200 );

	if ( !is_valid_ptr( facepunch_pool_get_list_ieffect_method ) )
		return false;

	hook effect_library_setup_effect_hook = {
		.init = false,
		.type = hook_type::method_info,
		.value = ( uintptr_t* )util::relative_32( facepunch_pool_get_list_ieffect_method, 3 ),
		.original = 0ull,
		.corrupt = generate_corrupt_value(),
		.method_info = {
			.handler = hook_handlers::effect_library_setup_effect
		}
	};

	method_info* outline_manager_on_render_image_method = il2cpp_class_get_method_from_name( rust::outline_manager::klass_, S( "OnRenderImage" ), 2 );
	if ( !outline_manager_on_render_image_method )
		return false;

	hook outline_manager_on_render_image_hook = {
		.init = false,
		.type = hook_type::ptr_swap,
		.value = ( uintptr_t* )&outline_manager_on_render_image_method->method_ptr,
		.original = 0ull,
		.corrupt = 0ull,
		.ptr_swap = {
			.pre_handler = nullptr,
			.post_handler = hook_handlers::post_outline_manager_on_render_image
		}
	};

	hook player_walk_movement_client_input_hook = {
		.init = false,
		.type = hook_type::ptr_swap,
		.value = VFUNC( rust::player_walk_movement, Offsets::PlayerWalkMovement::ClientInput_vtableoff ),
		.original = 0ull,
		.corrupt = 0ull,
		.ptr_swap = {
			.pre_handler = hook_handlers::pre_player_walk_movement_client_input,
			.post_handler = hook_handlers::post_player_walk_movement_client_input
		}
	};

	hook protobuf_projectile_shoot_write_to_stream_hook = {
		.init = false,
		.type = hook_type::ptr_swap,
		.value = VFUNC( rust::projectile_shoot, Offsets::ProtoBuf_ProjectileShoot::WriteToStream_vtableoff ),
		.original = 0ull,
		.corrupt = 0ull,
		.ptr_swap = {
			.pre_handler = hook_handlers::pre_protobuf_projectile_shoot_write_to_stream,
			.post_handler = nullptr
		}
	};

	hook protobuf_player_projectile_attack_write_to_stream_hook = {
		.init = false,
		.type = hook_type::ptr_swap,
		.value = VFUNC( rust::player_projectile_attack, Offsets::ProtoBuf_PlayerProjectileAttack::WriteToStream_vtableoff ),
		.original = 0ull,
		.corrupt = 0ull,
		.ptr_swap = {
			.pre_handler = hook_handlers::pre_protobuf_player_projectile_attack_write_to_stream,
			.post_handler = nullptr
		}
	};

	hook item_icon_try_to_move_hook = {
		.init = false,
		.type = hook_type::ptr_swap,
		.value = VFUNC( rust::item_icon, Offsets::ItemIcon::TryToMove_vtableoff ),
		.original = 0ull,
		.corrupt = 0ull,
		.ptr_swap = {
			.pre_handler = nullptr,
			.post_handler = hook_handlers::post_item_icon_try_to_move
		}
	};

	hook protobuf_player_tick_write_to_stream_delta_hook = {
		.init = false,
		.type = hook_type::ptr_swap,
		.value = VFUNC( rust::player_tick, Offsets::PlayerTick::WriteToStreamDelta_vtableoff ),
		.original = 0ull,
		.corrupt = 0ull,
		.ptr_swap = {
			.pre_handler = hook_handlers::pre_protobuf_player_tick_write_to_stream_delta,
			.post_handler = nullptr
		}
	};

	hook client_on_client_disconnected_hook = {
		.init = false,
		.type = hook_type::ptr_swap,
		.value = VFUNC( rust::client, Offsets::Client::OnClientDisconnected_vtableoff ),
		.original = 0ull,
		.corrupt = 0ull,
		.ptr_swap = {
			.pre_handler = hook_handlers::pre_client_on_client_disconnected,
			.post_handler = nullptr
		}
	};

	hook base_player_client_input_hook = {
		.init = false,
		.type = hook_type::ptr_swap,
		.value = VFUNC( rust::base_player, Offsets::BasePlayer::ClientInput_vtableoff ),
		.original = 0ull,
		.corrupt = 0ull,
		.ptr_swap = {
			.pre_handler = hook_handlers::pre_base_player_client_input,
			.post_handler = nullptr
		}
	};

	enum command_hook_type {
		set,
		call
	};

	struct command_hook {
		const wchar_t* name;
		command_hook_type type;
	};

	const command_hook hooked_commands[] = {
		{ S( L"noclip" ), command_hook_type::call },
		{ S( L"debugcamera" ), command_hook_type::call },
		{ S( L"camlerp" ), command_hook_type::set },
		{ S( L"camlerptilt" ), command_hook_type::set },
		{ S( L"camlookspeed" ), command_hook_type::set },
		{ S( L"camspeed" ), command_hook_type::set },
	};

	for ( auto hooked_command : hooked_commands ) {
		// The subsequent find call requires an actual string object
		sys::string* name = sys::string::create( hooked_command.name );
		if ( !name )
			return false;

		rust::console_system::command* command = rust::console_system::index::client::find( name );
		if ( !is_valid_ptr( command ) )
			return false;

		sys::action* action = hooked_command.type == command_hook_type::set ? command->set_override : command->call;
		if ( !is_valid_ptr( action ) )
			return false;

		hook command_hook = {
			.init = false,
			.type = hook_type::ptr_swap,
			.value = ( uintptr_t* )action->_address_of_invoke_impl(),
			.original = 0ull,
			.corrupt = 0ull,
			.ptr_swap = {
				.pre_handler = hooked_command.type == command_hook_type::set ? 
					hook_handlers::pre_console_system_command_set : hook_handlers::pre_console_system_command_call,

				.post_handler = nullptr
			}
		};

		hook_manager::hooks.add( command_hook );
	}

	auto& hooks = hook_manager::hooks;

	hooks.add( network_client_create_networkable_hook );
	hooks.add( network_client_destroy_networkable_hook );
	hooks.add( effect_library_setup_effect_hook );
	hooks.add( outline_manager_on_render_image_hook );
	hooks.add( player_walk_movement_client_input_hook );
	hooks.add( protobuf_projectile_shoot_write_to_stream_hook );
	hooks.add( protobuf_player_projectile_attack_write_to_stream_hook );
	hooks.add( item_icon_try_to_move_hook );
	hooks.add( protobuf_player_tick_write_to_stream_delta_hook );
	hooks.add( client_on_client_disconnected_hook );
	hooks.add( base_player_client_input_hook );

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
			if ( hook.type == hook_type::ptr_swap && !hook.corrupt ) {
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