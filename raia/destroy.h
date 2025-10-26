#pragma once

#ifndef DESTROY_INLINE
#define DESTROY_INLINE __forceinline
#endif

namespace destroy {
	__declspec( noinline ) void* marker();
	__declspec( noinline ) void destroy( void* marker );
	__declspec( noinline ) void destroy_init();
	__declspec( noinline ) void nullsub();

	extern uint8_t init_begin;
	extern uint8_t init_end;
}

#pragma section( ".init$1", read, execute )
#pragma section( ".init$2", read, execute )
#pragma section( ".init$3", read, execute )
#pragma comment( linker, "/merge:.init=.text" )
#define INIT_API __declspec( code_seg( ".init$2" ) )

#define DESTROY_BEGIN void* __marker = destroy::marker();
#define DESTROY_END \
	destroy::destroy( __marker ); \
	destroy::nullsub();
#define DESTROY_INIT destroy::destroy_init();
