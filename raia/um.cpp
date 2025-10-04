#include "um.h"
#include "nt.h"
#include "util.h"
#include "global.h"

#include <stdio.h>

/**/

#pragma pack( push, 1 )

struct g_user_call_ctx {
	uint64_t padding01;

	uint64_t return_data;

	uint64_t arg1;
	uint64_t arg2;
	uint64_t arg3;
	uint64_t arg4;
	uint64_t arg5;
	uint64_t arg6;
	uint64_t arg7;
	uint64_t arg8;
	uint64_t arg9;
	uint64_t arg10;

	float farg1;
	float farg2;
	float farg3;
	float farg4;

	uint64_t ex_args1;
	uint64_t ex_args2;
	uint64_t ex_args3;
	uint64_t ex_args4;

	double float_ret;
	uint64_t value_ret;

	uint64_t address;
};

#pragma pack( pop )

void run_user_call( uint64_t ctx_buffer, uint64_t address, uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4,
	uint64_t arg5, uint64_t arg6, uint64_t arg7, uint64_t arg8, float farg1, float farg2, float farg3,
	float farg4 ) {

	g_user_call_ctx ctx{};

	ctx.address = address;
	ctx.return_data = uint64_t( ctx_buffer );
	ctx.arg1 = ( uint64_t )arg1;
	ctx.arg2 = ( uint64_t )arg2;
	ctx.arg3 = ( uint64_t )arg3;
	ctx.arg4 = ( uint64_t )arg4;
	ctx.arg5 = ( uint64_t )arg5;
	ctx.arg6 = ( uint64_t )arg6;
	ctx.arg7 = ( uint64_t )arg7;
	ctx.arg8 = ( uint64_t )arg8;

	ctx.farg1 = ( float )farg1;
	ctx.farg2 = ( float )farg2;
	ctx.farg3 = ( float )farg3;
	ctx.farg4 = ( float )farg4;

	PVOID return_buffer = 0;
	ULONG return_len = 0;

	KeUserModeCallback( 1337, &ctx, sizeof( ctx ), &return_buffer, &return_len );
}

/**/

namespace um {
	namespace detail {
		void run_usermode_call( uintptr_t buffer, uintptr_t target, uint64_t* integers, float* floats ) {
			run_user_call(
				buffer, target, 
				integers[ 0 ], integers[ 1 ], integers[ 2 ], integers[ 3 ], 
				integers[ 4 ], integers[ 5 ], integers[ 6 ], integers[ 7 ], 
				floats[ 0 ], floats[ 1 ], floats[ 2 ], floats[ 3 ] 
			);
		}
	}

	void* malloc( size_t size ) {
		void* base_address = nullptr;
		size_t region_size = size;
		if ( ZwAllocateVirtualMemory( NtCurrentProcess(), &base_address, 0, &region_size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE ) != STATUS_SUCCESS ) [[unlikely]]
			return nullptr;

		return base_address;
	}

	bool free( void* ptr, size_t size ) {
		return ZwFreeVirtualMemory( NtCurrentProcess(), &ptr, &size, MEM_DECOMMIT ) == STATUS_SUCCESS;
	}

	bool caller::initialize() {
		m_allocation = malloc( ALLOCATION_SIZE );
		if ( !m_allocation ) [[unlikely]]
			return false;

		m_buffer = ( uintptr_t )m_allocation;
		m_stack_base = m_buffer + ( ALLOCATION_SIZE / 2 );
		m_stack = m_stack_base;

		return m_initialized = true;
	}

	void caller::destroy() {
		free( m_allocation, ALLOCATION_SIZE );
	}

	// We should only be using two slots here, one for the game thread, and another for the render thread
	//
	static util::tls<caller, 16> callers;

#ifndef DEBUG
	caller& get_caller_for_thread() {
#else
	caller& get_caller_for_thread( const std::source_location& location ) {
#endif
		caller* caller = callers.get();
		if ( !caller ) [[unlikely]]
			__fastfail( 0 );

		// If caller hasn't been initialized yet, try to initialize it
		//
		if ( !caller->initialized() && !caller->initialize() )
			__fastfail( 0 );

#ifdef DEBUG
		caller->last_caller = location;
#endif

		return *caller;
	}

#ifdef DEBUG
	void print_last_callers() {
		for ( auto& [ _, caller ] : callers.get_objects() ) {
			const std::source_location& location = caller.last_caller;

			LOG( "%s (%d): %s", location.file_name(), location.line(), location.function_name() );
		}
	}
#endif

	void destroy_callers() {
		for ( auto& caller : callers.get_objects() ) {
			caller.object.destroy();
		}
	}
}