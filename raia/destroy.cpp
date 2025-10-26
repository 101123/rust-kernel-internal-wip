#include <stdint.h>
#include <intrin.h>

#include <destroy.h>

namespace destroy {
	__declspec( allocate( ".init$1" ) ) uint8_t init_begin;
	__declspec( allocate( ".init$3" ) ) uint8_t init_end;

	DESTROY_INLINE void destroy_internal( uint8_t* begin, uint8_t* end ) {
		uint64_t seed = ( uint64_t ) _AddressOfReturnAddress();

		while ( begin != end ) {
			seed ^= seed << 13;
			seed ^= seed >> 7;
			seed ^= seed << 17;

			*begin = seed & 0xFF;
			begin++;
		}
	}

#pragma optimize( "", off )
	void* marker() {
		return _ReturnAddress();
	}

	void destroy( void* marker ) {
		uint8_t* begin = ( ( uint8_t* ) marker ) - 5;
		uint8_t* end = ( uint8_t* ) _ReturnAddress();

		destroy_internal( begin, end );
	}

	void destroy_init() {
		DESTROY_BEGIN

		destroy_internal( &init_begin, &init_end );

		DESTROY_END
	}

	void nullsub() {};
#pragma optimize( "", on )
}
