#include "util.h"
#include "global.h"

#include "sentian/api.h"

#include "cheat/cheat.h"
#include <cstddef>

#include "cheat/sdk/sdk.h"
#include "cheat/entities.h"
#include "cheat/glow.h"

#include "render.h"
#include "renderer.h"

#include "gui.h"

struct IDXGISwapChain;

bool cheat_init = false;

bool init_cheat() {
	// Resolve game dlls and populate classes in sdk
	if ( !bootstrap::init() ) {
#ifdef DEBUG
		LOG( "Bootstrap failed\n" );
#endif
		return false;
	}

	// Resolve hooks
	if ( !hook_manager::init() ) {
#ifdef DEBUG
		LOG( "Failed to resolve hooks" )
#endif
		return false;
	}
	
	// Initialize entity manager internal maps
	entity_manager::init();

	// Initialize gui draw list
	gui::init();

	return true;
}

bool cheat_deinit = false;

// This function must be called after clearing the d3d handler otherwise the cheat unloads otherwise the hooks stay
void deinit_cheat() {
	hook_manager::remove_hooks();
	entity_manager::destroy();
	glow_manager::destroy();

	// TODO: Fix bsod when calling this
	// renderer::destroy();

	gui::destroy();

	if ( asset_bundle ) {
		asset_bundle->unload( true );
	}

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

// This doesn't need to be thread-safe because Rust is single-threaded
CONTEXT previous_context;

bool on_exception( EXCEPTION_RECORD* exception_record, CONTEXT* context, uint8_t previous_mode ) {
	if ( is_rust_process() ) {
		for ( hook& hook : hook_manager::hooks ) {
			if ( !hook.init )
				continue;

			if ( hook.type == hook_type::method_info ) {
				if ( is_exception_hook( context, hook.corrupt, hook.original ) ) {
					hook.method_info.handler( context, hook.user_data );
					return true;
				}
			}

			else if ( hook.type == hook_type::ptr_swap ) {
				if ( context->Rip == hook.corrupt ) {
					// Check if we want to skip the original
					if ( hook.ptr_swap.pre_handler && !hook.ptr_swap.pre_handler( context, hook.user_data ) ) {
						uintptr_t retaddr = *( uintptr_t* )context->Rsp;

						// Emulate a ret
						context->Rsp += 0x8;
						context->Rip = retaddr;
					}

					else {
						// If we have a post hook
						if ( hook.ptr_swap.post_handler ) {
							uintptr_t* retaddr = ( uintptr_t* )context->Rsp;

							// Preserve the original return address
							hook.ptr_swap.retaddr = *retaddr;

							// Preserve the needed original arguments for the post hook
							previous_context.Rcx = context->Rcx;
							previous_context.Rdx = context->Rdx;
							previous_context.R8 = context->R8;
							previous_context.R9 = context->R9;

							// Corrupt the return address
							*retaddr = hook.ptr_swap.corrupt_retaddr;
						}

						context->Rip = hook.original;
					}

					return true;
				}

				// We've caught a post hook
				else if ( context->Rip == hook.ptr_swap.corrupt_retaddr ) {
					if ( hook.ptr_swap.post_handler ) {
						// Call the post hook with the original context we preserved
						hook.ptr_swap.post_handler( &previous_context, hook.user_data );
					}

					// Restore the return address we preserved
					context->Rip = hook.ptr_swap.retaddr;

					return true;
				}
			}
		}
	}

	return false;
}

void render_handler( IDXGISwapChain* swapchain ) {
	if ( !cheat_init ) {
		if ( !( cheat_init = init_cheat() ) ) {
			return;
		}
	}

	if ( !cheat_deinit ) {
		render_input.update();

		screen_width = unity::screen::get_width();
		screen_height = unity::screen::get_height();

		hook_manager::place_hooks();

		on_render( swapchain );

		if ( render_input.get_async_key_state( VK_F11 ) ) {
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

#ifdef DEBUG
bool on_exit_process( sentian::callback_result* callback, bool last_thread_exit, PEPROCESS process ) {
	if ( process == rust_process ) {
		um::print_last_callers();
	}

	return true;
}
#endif

int main( sentian::driver_api* api, sentian::driver_allocation* allocation ) {
	if ( api->version != DRIVER_API_VERSION )
		return 1;

	util::process_info process_info = util::get_process_info( H( "RustClient.exe" ) );
	if ( !process_info.process )
		return 2;

	sentian::driver_slot* slot = &api->slots[ 1 ];
	if ( !api->unload_slot( slot ) )
		return 3;

	slot->enabled = true;
	slot->allocation = *allocation;
	slot->unload = ( sentian::unload_callback_t )on_unload;
	slot->trap = ( sentian::exception_callback_t )on_exception;
	slot->syscall = ( sentian::syscall_callback_t )on_syscall;

#ifdef DEBUG
	slot->psp_exit_process = ( sentian::psp_exit_process_callback_t )on_exit_process;
#endif

	driver_api = api;
	rust_process = process_info.process;
	rust_pid = process_info.process_id;

	return 0;
}