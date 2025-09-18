#include "util.h"
#include "global.h"

#include "sentian/api.h"

#include "cheat/cheat.h"
#include <cstddef>

#include "cheat/sdk/sdk.h"
#include "cheat/entities.h"
#include "cheat/glow.h"

#include "render.h"

struct IDXGISwapChain;

namespace user_sdk {
#pragma pack( push, 1 )
	enum class command_id : uint8_t {
		get_key_states,
		set_wnd_proc_handler,
		set_d3d_render_handler,
		set_d3d_resize_handler,
		max
	};

	struct command {
		command_id id;
		void* data;
		uint32_t data_size;
		uint64_t return_value;
	};

	struct keystates {
		uint8_t data[ 64 ];
	};
#pragma pack( pop )

	void execute_command( command* cmd ) {
		sentian::driver_slot* slot = &driver_api->slots[ uint8_t( sentian::driver_slot_type::sockets ) ];
		if ( !slot->enabled || !slot->context )
			return;

		sentian::context_header header {
			.data = ( uint8_t* )cmd->data,
			.data_size = cmd->data_size,
			.arg1 = ( uint64_t )cmd->id,
		};

		cmd->return_value = slot->context( &header );
	}

	uint64_t set_d3d_resize_handler( void* handler ) {
		command cmd {
			.id = command_id::set_d3d_resize_handler,
			.data = handler,
			.data_size = sizeof( handler )
		};

		execute_command( &cmd );

		return cmd.return_value;
	}

	uint64_t set_d3d_render_handler( void* handler ) {
		command cmd {
			.id = command_id::set_d3d_render_handler,
			.data = handler,
			.data_size = sizeof( handler )
		};

		execute_command( &cmd );

		return cmd.return_value;
	}

	uint64_t set_wnd_proc_handler( void* handler ) {
		command cmd {
			.id = command_id::set_wnd_proc_handler,
			.data = handler,
			.data_size = sizeof( handler )
		};

		execute_command( &cmd );

		return cmd.return_value;
	}

	uint64_t get_key_states( keystates* keystates ) {
		command cmd {
			.id = command_id::get_key_states,
			.data = keystates,
			.data_size = sizeof( *keystates )
		};

		execute_command( &cmd );

		return cmd.return_value;
	}
}

bool cheat_init = false;

bool init_cheat() {
	// Resolve game dlls and populate classes in sdk
	if ( !bootstrap::init() )
		return false;

	// Resolve hooks
	if ( !hook_manager::init() )
		return false;
	
	// Initialize entity manager internal maps
	entity_manager::init();

	return true;
}

bool cheat_deinit = false;

// This function must be called after clearing the d3d handler otherwise the cheat unloads otherwise the hooks stay
void deinit_cheat() {
	hook_manager::remove_hooks();
	entity_manager::destroy();
	glow_manager::destroy();

	asset_bundle->unload( true );

	um::destroy_callers();
}

bool is_rust_process() {
	PEPROCESS current_process = PsGetCurrentProcess();
	return current_process == rust_process && PsGetProcessId( current_process ) == rust_pid;
}

bool on_unload( sentian::driver_slot* slot ) {
#ifdef DEBUG
	// If we haven't unloaded the cheat manually, we can clean up here, but we must be attached to the target process to do so
	//if ( !cheat_deinit ) {
	//	// Find the target process if it still exists
	//	PEPROCESS process = nullptr;
	//	if ( PsLookupProcessByProcessId( rust_pid, &process ) == STATUS_SUCCESS && process ) {
	//		// Attach to the target process and unload here
	//		KAPC_STATE apc_state = {};
	//		KeStackAttachProcess( process, &apc_state );

	//		deinit_cheat();

	//		KeUnstackDetachProcess( &apc_state );

	//		// Decrement reference count on process incremented by PsLookupProcessByProcessID
	//		ObDereferenceObject( process );
	//	}

	//	// For safety
	//	cheat_deinit = true;
	//}
#endif

	slot->enabled = false;

	util::sleep( 100 );

	return true;
}

bool is_exception_hook( CONTEXT* context, uint64_t find, uint64_t replace, uint64_t limit = 0x100 ) {
	bool match = false;

	// + 1 includes rip
	uint64_t* registers = ( uint64_t* )&context->Rax;
	constexpr size_t num_registers = ( ( offsetof( CONTEXT, Rip ) - offsetof( CONTEXT, Rax ) ) / sizeof( uint64_t ) ) + 1ull;

	for ( size_t i = 0; i < num_registers; i++ ) {
		uint64_t& reg = registers[ i ];

		if ( reg >= find && reg < ( find + limit ) ) {
			reg = replace + ( reg - find );
			match = true;
		}
	}

	return match;
}

void post_hook_impl( _CONTEXT* context ) {
	uint64_t integers[] = {
		context->Rcx,
		context->Rdx,
		context->R8,
		context->R9,
		*( uint64_t* )( context->Rsp + 0x8 ),
		*( uint64_t* )( context->Rsp + 0x10 ),
		*( uint64_t* )( context->Rsp + 0x18 ),
		*( uint64_t* )( context->Rsp + 0x20 )
	};

	float floats[] = {
		*( float* )&context->Xmm0,
		*( float* )&context->Xmm1,
		*( float* )&context->Xmm2,
		*( float* )&context->Xmm3
	};

	// Preserve return address
	uintptr_t retaddr = *( uintptr_t* )( context->Rsp );

	um::caller& caller = um::get_caller_for_thread();

	// Call the original, rip is correct from is_exception_hook call prior
	um::detail::run_usermode_call( caller.get_buffer(), context->Rip, integers, floats );

	// Set rip to return address
	context->Rip = retaddr;
}

bool on_exception( EXCEPTION_RECORD* exception_record, CONTEXT* context, uint8_t previous_mode ) {
	if ( is_rust_process() ) {
		for ( const hook& hook : hook_manager::hooks ) {
			if ( !hook.init )
				continue;

			if ( !is_exception_hook( context, hook.corrupt, hook.original ) )
				continue;

			if ( ( hook.flags & hook_flags::post_compatible ) == hook_flags::post_compatible ) {
				post_hook_impl( context );
			}

			hook.handler( context );
			return true;
		}
	}

	return false;
}

void render_handler( IDXGISwapChain* swap_chain ) {
	if ( !cheat_init ) {
		if ( !( cheat_init = init_cheat() ) ) {
			return;
		}
	}

	if ( !cheat_deinit ) {
		hook_manager::place_hooks();
		on_render( swap_chain );
		
		// Uses get key instead of get key down because we aren't in a game thread
		if ( unity::input::get_key( unity::key_code::f11 ) ) {
			user_sdk::set_d3d_render_handler( nullptr );
			deinit_cheat();

			cheat_deinit = true;
		}
	}
}

bool set_d3d_render_handler = false;
util::mutex syscall_mutex;

void on_syscall( sentian::syscall_frame* new_frame, sentian::syscall_frame* old_frame ) {
	if ( !set_d3d_render_handler ) {
		if ( !is_rust_process() )
			return;
		
		// Makes sure this only runs on a single thread
		if ( syscall_mutex.try_lock() ) {
			user_sdk::set_d3d_render_handler( render_handler );
			set_d3d_render_handler = true;

			syscall_mutex.unlock();
		}
	}
}

extern "C" int driver_main( sentian::driver_api* api, sentian::driver_allocation* allocation ) {
	if ( api->version != DRIVER_API_VERSION )
		return 1;

	util::process_info process_info = util::get_process_info( H( "RustClient.exe" ) );
	if ( !process_info.process )
		return 2;

	sentian::driver_slot* slot = &api->slots[ 1 ];

#ifdef DEBUG
	if ( !api->unload_slot( slot ) )
		return 3;
#else
	if ( slot->enabled )
		return 4;
#endif

	slot->enabled = true;
	slot->allocation = *allocation;
	slot->unload = ( sentian::unload_callback_t )on_unload;
	slot->trap = ( sentian::exception_callback_t )on_exception;
	slot->syscall = ( sentian::syscall_callback_t )on_syscall;

	driver_api = api;
	rust_process = process_info.process;
	rust_pid = process_info.process_id;

	return 0;
}