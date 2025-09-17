#pragma once

#include "global.h"
#include "nt.h"

#include <new>
#include <intrin.h>

#define ALLOCATION_SIZE 0x1000
#define STACK_SIZE ALLOCATION_SIZE / 2

namespace um {
	namespace detail {
		void run_usermode_call( uintptr_t buffer, uintptr_t target, uint64_t* integers, float* floats );
	}

	void* malloc( size_t size );
	bool free( void* ptr, size_t size );

	class caller {
	public:
		bool initialize();
		void destroy();

		bool initialized() { return m_initialized; };

		void* alloc( size_t size, size_t alignment = 1ull ) {
			uintptr_t aligned_address = ( m_stack + alignment - 1 ) & ~( alignment - 1 );
			if ( aligned_address + size > m_stack_base + STACK_SIZE ) {
				m_stack = m_stack_base;
			}

			else {
				m_stack = aligned_address;
			}

			uintptr_t location = m_stack;
			m_stack += size;
			return ( void* )location;
		}

		// Push object
		template <typename T, typename... Args>
		T* push( Args&&... args ) {
			return new ( alloc( sizeof( T ), alignof( T ) ) ) T( std::forward<Args>( args )... );
		}

		// Push array
		template <typename T>
		T* push_array( T* arr, size_t count ) {
			static_assert( std::is_trivial_v<T> );

			size_t size = count * sizeof( T );
			T* buffer = ( T* )alloc( size, alignof( T ) );
			memcpy( ( void* )buffer, arr, size );

			return ( T* )buffer;
		}

		// Push array of literals
		template <typename T, size_t N>
		T* push_array( const T( &arr )[ N ] ) {
			static_assert( std::is_trivial_v<T> );

			size_t size = N * sizeof( T );
			void* buffer = alloc( size, alignof( T ) );
			memcpy( buffer, arr, size );

			return ( T* )buffer;
		}

		// Helper function for strings
		const char* push_string( const char* string ) {
			char* buffer = ( char* )alloc( strlen( string ) + 1 );
			strcpy( buffer, string );
			return buffer;
		}

		template <typename Func, typename... Args>
		auto operator()( Func func, Args&&... args ) {
			// Validate function is able to be called with the given arguments.
			//
			static_assert( std::is_invocable_v<Func, Args...>,
				"Arguments do not match the function signature!" );

			using RetType = std::invoke_result_t<Func, Args...>;

			// Not initialized on purpose to worsen decompilation.
			//
			uint64_t integers[ 8 ];
			float floats[ 4 ];

			// Store arguments in correct indices in accordance with ABI.
			//
			size_t argument_index = 0ull;
			auto store_argument = [ & ]( auto&& arg ) {
				using Type = std::decay_t<decltype( arg )>;

				if constexpr ( std::is_same_v<Type, float> ) {
					floats[ argument_index++ ] = arg;
				}

				else if constexpr ( sizeof( Type ) <= sizeof( size_t ) ) {
					integers[ argument_index++ ] = ( uint64_t )arg;
				}
			};

			( store_argument( std::forward<Args>( args ) ), ... );
			
			// Call correct function caller based on the return type.
			//
			if constexpr ( std::is_same_v<RetType, float> ) {
				detail::run_usermode_call( m_buffer, ( uintptr_t )func, integers, floats );
				return *( RetType* )( m_buffer + 0x10 );
			}

			else {
				detail::run_usermode_call( m_buffer, ( uintptr_t )func, integers, floats );
				
				if constexpr ( !std::is_void_v<RetType> ) {
					return *( RetType* )( m_buffer + 0x20 );
				}
			}
		}

	private:
		// Whether caller is initialized.
		bool m_initialized;
		// Address of our usermode allocation.
		void* m_allocation;
		// Address to store context buffer, same as our usermode allocation address.
		uintptr_t m_buffer;
		// Base address of our stack
		uintptr_t m_stack_base;
		// Current stack address
		uintptr_t m_stack;
	};

	void destroy_callers();

	caller& get_caller_for_thread();
}