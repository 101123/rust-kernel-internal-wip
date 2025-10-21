#pragma once

#include "nt.h"

#include <type_traits>
#include <cstdarg>
#include <cstdio>

enum time_unit {
	nanoseconds = 1,
	microseconds = 10,
	milliseconds = 10000,
	seconds = 10000000
};

namespace util {
	namespace detail {
		inline bool compare_pattern( uint8_t* data, uint8_t* pattern, const char* mask ) {
			for ( ; *mask; ++data, ++pattern, ++mask ) {
				if ( *mask == 'x' && *data != *pattern ) {
					return false;
				}
			}

			return *mask == '\0';
		}

		inline bool copy_unicode_string( const UNICODE_STRING* unicode_string, wchar_t* buffer, size_t length ) {
			if ( !unicode_string || !unicode_string->Buffer )
				return false;

			size_t unicode_string_length = unicode_string->Length / sizeof( wchar_t );
			if ( unicode_string_length >= length )  
				return false;

			memcpy( buffer, unicode_string->Buffer, unicode_string->Length );
			buffer[ unicode_string_length ] = L'\0';
			return true;
		}

		inline uint8_t format_buffer[ 1024 ];
	}

	template <typename T, size_t N>
	class array {
	public:
		array() : count_( 0ull ) {};

		size_t size() const { return count_; }
		size_t capacity() const { return N; }

		T& operator[]( size_t index ) { return buffer_[ index ]; }
		const T& operator[]( size_t index ) const { return buffer_[ index ]; }

		T* begin() { return buffer_; }
		const T* begin() const { return buffer_; }

		T* end() { return buffer_ + count_; }
		const T* end() const { return buffer_ + count_; }

		T* add( T item ) {
			if ( count_ < N ) {
				size_t index = count_++;
				buffer_[ index ] = item;
				return &buffer_[ index ];
			}

			return nullptr;
		}

	private:
		T buffer_[ N ];
		size_t count_;
	};

	class mutex {
	public:
		void lock() {
			while ( true ) {
				if ( m_lock == 0 && _InterlockedExchange8( &m_lock, 1 ) == 0 )
					break;

				_mm_pause();
			}
		}

		bool try_lock() {
			return ( m_lock == 0 && _InterlockedExchange8( &m_lock, 1 ) == 0 );
		}

		void unlock() {
			m_lock = 0;
		}

	private:
		char m_lock;
	};

	class scoped_spinlock {
	public:
		scoped_spinlock() = delete;
		scoped_spinlock( mutex* mutex ) : m_mutex( mutex ) {
			m_mutex->lock();
		}

		~scoped_spinlock() {
			m_mutex->unlock();
		}

	private:
		mutex* m_mutex;
	};

	inline uintptr_t find_pattern( uintptr_t base, const char* pattern, const char* mask, size_t size ) {
		for ( int32_t i = 0, len = strlen( mask ); i < size - len; i++ ) {
			uint8_t* address = &( ( uint8_t* )base )[ i ];

			if ( detail::compare_pattern( address, ( uint8_t* )pattern, mask ) ) {
				return ( uintptr_t )address;
			}
		}

		return 0ull;
	}

	inline uintptr_t relative_32( uintptr_t instruction, int offset ) {
		int relative = *( int* )( instruction + offset );
		return instruction + relative + offset + sizeof( int );
	}

	inline constexpr uint64_t hash( const char* str ) {
		uint64_t hash = 0xCBF29CE484222325ull;

		while ( *str ) {
			hash = ( hash ^ uint32_t( ( *str >= 'A' && *str <= 'Z' ) ? *str - ( 'A' - 'a' ) : *str ) ) *
				0x100000001B3ull;
			str++;
		}

		return hash;
	}

	inline consteval uint64_t hash_const( const char* str ) {
		return hash( str );
	}

	inline constexpr uint64_t hash_w( const wchar_t* str ) {
		uint64_t hash = 0xCBF29CE484222325ull;

		while ( *str ) {
			hash = ( hash ^ uint32_t( ( *str >= L'A' && *str <= L'Z' ) ? *str - ( L'A' - L'a' ) : *str ) & 0xFF ) *
				0x100000001B3ull;
			str++;
		}

		return hash;
	}

	inline consteval uint64_t hash_w_const( const wchar_t* str ) {
		return hash_w( str );
	}

	template <typename T, size_t N>
	class tls {
	public:
		struct pair {
			HANDLE thread_id;
			T object;
		};

		T* get() {
			HANDLE current_thread_id = PsGetCurrentThreadId();

			for ( size_t i = 0; i < N; i++ ) {
				if ( m_objects[ i ].thread_id == current_thread_id ) {
					return &m_objects[ i ].object;
				}
			}

			util::scoped_spinlock lock( &m_mutex );

			if ( pair* pair = m_objects.add( { current_thread_id, T() } ) ) {
				return &pair->object;
			}

			return nullptr;
		}

		util::array<pair, N>& get_objects() {
			return m_objects;
		}

	private:
		util::array<pair, N> m_objects;
		util::mutex m_mutex;
	};

#define _max( x, y ) ( x > y ? x : y )

	inline uintptr_t find_pattern_image( uintptr_t image, const char* pattern, const char* mask ) {
		IMAGE_DOS_HEADER dos_header = *( IMAGE_DOS_HEADER* )( image );
		IMAGE_NT_HEADERS nt_headers = *( IMAGE_NT_HEADERS* )( image + dos_header.e_lfanew );

		uintptr_t section_base = image + dos_header.e_lfanew + FIELD_OFFSET( IMAGE_NT_HEADERS, OptionalHeader ) +
			nt_headers.FileHeader.SizeOfOptionalHeader;

		for ( size_t i = 0; i < nt_headers.FileHeader.NumberOfSections; i++ ) {
			IMAGE_SECTION_HEADER section =
				*( IMAGE_SECTION_HEADER* )( section_base + ( i * sizeof( IMAGE_SECTION_HEADER ) ) );

			if ( ( section.Characteristics & IMAGE_SCN_MEM_EXECUTE ) == 0 ||
				( section.Characteristics & IMAGE_SCN_MEM_DISCARDABLE ) != 0 ) {
				continue;
			}

			uintptr_t result = util::find_pattern( 
				image + section.VirtualAddress, pattern, mask, _max( section.SizeOfRawData, section.Misc.VirtualSize ) );

			if ( result ) {
				return result;
			}
		}

		return 0;
	}

	inline void sleep( int ms ) {
		int value = ms * -10000;

		LARGE_INTEGER interval {
			.QuadPart = value
		};

		KeDelayExecutionThread( KernelMode, false, &interval );
	}

	inline KLDR_DATA_TABLE_ENTRY* get_system_module( uint64_t hash ) {
		if ( IsListEmpty( PsLoadedModuleList ) )
			return nullptr;

		for ( LIST_ENTRY* list_entry = PsLoadedModuleList->Flink; list_entry != PsLoadedModuleList; list_entry = list_entry->Flink ) {
			KLDR_DATA_TABLE_ENTRY* entry = CONTAINING_RECORD( list_entry, KLDR_DATA_TABLE_ENTRY, InLoadOrderLinks );
			if ( !entry )
				continue;

			wchar_t buffer[ 256 ];
			if ( !detail::copy_unicode_string( &entry->BaseDllName, buffer, 256 ) )
				continue;

			if ( util::hash_w( buffer ) == hash ) {
				return entry;
			}
		}

		return nullptr;
	}

	struct process_info {
		PEPROCESS process;
		HANDLE process_id;
	};

	inline process_info get_process_info( uint64_t hash ) {
		SYSTEM_PROCESS_INFORMATION* system_process_information = nullptr;
		ULONG length = 0u;
		if ( ZwQuerySystemInformation( SYSTEM_INFORMATION_CLASS::SystemProcessInformation, system_process_information, 0u, &length ) != STATUS_INFO_LENGTH_MISMATCH )
			return process_info();

		system_process_information = ( SYSTEM_PROCESS_INFORMATION* )ExAllocatePool( POOL_TYPE::NonPagedPoolNx, ( SIZE_T )length * 2ull );
		if ( !system_process_information )
			return process_info();

		if ( ZwQuerySystemInformation( SYSTEM_INFORMATION_CLASS::SystemProcessInformation, system_process_information, length * 2u, nullptr ) != STATUS_SUCCESS )
			return process_info();

		process_info process_info = {};

		SYSTEM_PROCESS_INFORMATION* entry = system_process_information;
		while ( !process_info.process ) {
			PEPROCESS process = nullptr;
			if ( PsLookupProcessByProcessId( entry->UniqueProcessId, &process ) == STATUS_SUCCESS ) {
				UNICODE_STRING* image_file_name = nullptr;
				if ( SeLocateProcessImageName( process, &image_file_name ) == STATUS_SUCCESS ) {
					wchar_t buffer[ 256 ];
					if ( detail::copy_unicode_string( image_file_name, buffer, 256 ) ) {
						wchar_t* file_name_start = wcsrchr( buffer, L'\\' );
						if ( file_name_start ) {
							if ( util::hash_w( file_name_start + 1 ) == hash ) {
								process_info = {
									.process = process,
									.process_id = PsGetProcessId( process )
								};
							}
						}
					}

					ExFreePool( image_file_name );
				}

				ObDereferenceObject( process );
			}

			if ( entry->NextEntryOffset == 0u )
				break;

			entry = ( SYSTEM_PROCESS_INFORMATION* )( ( uintptr_t )entry + entry->NextEntryOffset );
		}

		ExFreePool( system_process_information );
		return process_info;
	}

	struct process_module_info {
		LDR_DATA_TABLE_ENTRY* ldr_entry;
		uintptr_t base_address;
	};

	inline process_module_info get_process_module_info( PEPROCESS process, uint64_t hash ) {
		if ( PsGetCurrentProcess() != process )
			return process_module_info();

		PEB* peb = PsGetProcessPeb( process );
		if ( !peb )
			return process_module_info();

		PPEB_LDR_DATA ldr = peb->Ldr;
		if ( !ldr || !ldr->Initialized )
			return process_module_info();

		process_module_info module_info = {};

		for ( LIST_ENTRY* list_entry = ldr->InLoadOrderModuleList.Flink; list_entry != &ldr->InLoadOrderModuleList; list_entry = list_entry->Flink ) {
			LDR_DATA_TABLE_ENTRY* entry = CONTAINING_RECORD( list_entry, LDR_DATA_TABLE_ENTRY, InLoadOrderLinks );
			if ( !entry )
				continue;

			wchar_t buffer[ 256 ];
			if ( !detail::copy_unicode_string( &entry->BaseDllName, buffer, 256 ) )
				continue;

			if ( util::hash_w( buffer ) == hash ) {
				module_info = {
					.ldr_entry = entry,
					.base_address = ( uintptr_t )entry->DllBase
				};

				return module_info;
			}
		}

		return process_module_info();
	}

	inline constexpr uint32_t ms_hash( const char* const str, const uint32_t value ) {
		return ( str[ 0 ] == '\0' ) ? value : ms_hash( &str[ 1 ],
			( 1025 * ( value + str[ 0 ] ) >> 6 ) ^ 1025 * ( value + str[ 0 ] ) );
	}

	inline constexpr uint32_t ms_hash( const char* const str ) {
		return ms_hash( &str[ 2 ], 0 );
	}

	template <typename T>
	class lazy_initializer {
	public:
		T& get() {
			return *( T* )m_storage;
		}

		template <typename... Args>
		void construct( Args&&... args ) {
			new ( ( void* )m_storage ) T( std::forward<Args>( args )... );
		}

		void destruct() {
			get().~T();
		}

	private:
		alignas( T ) uint8_t m_storage[ sizeof( T ) ];
	};

	inline uint32_t random( uint32_t seed = 0x811C9DC5 ) {
		return RtlRandomEx( ( PULONG )&seed );
	}

	template <typename T, size_t N> 
	struct string {
		T buffer[ N ];

		operator const T* ( ) {
			return buffer;
		}
	};

	template <size_t N>
	inline string<char, N> format_string( const char* format, ... ) {
		string<char, N> formatted;

		va_list args;
		va_start( args, format );
		vsprintf( formatted.buffer, format, args );
		va_end( args );

		return formatted;
	}

	template <size_t N>
	inline string<wchar_t, N> format_string( const wchar_t* format, ... ) {
		string<wchar_t, N> formatted;

		va_list args;
		va_start( args, format );
		vswprintf( formatted.buffer, format, args );
		va_end( args );

		return formatted;
	}

	template <uint64_t unit = time_unit::nanoseconds>
	inline uint64_t get_time() {
		return ( *( volatile uint64_t* )( 0xFFFFF78000000008 ) / unit );
	}

	template <uint64_t unit>
	class timer {
	public:
		timer( uint64_t start_time = get_time<unit>() ) :
			previous_time_( start_time ) {}

		uint64_t get_elapsed() {
			return get_time<unit>() - previous_time_;
		}

		bool has_elapsed( uint64_t time ) {
			if ( get_elapsed() > ( time * unit ) ) {
				previous_time_ = get_time<unit>();
				return true;
			}

			return false;
		}

		uint64_t get_delta_time() {
			uint64_t delta_time = get_time<unit>() - previous_time_;
			previous_time_ = get_time<unit>();
			return delta_time;
		}

	private:
		uint64_t previous_time_;
	};

	enum resolved_location {
		unresolved,
		registers,
		stack,
	};

	template <typename T>
	class context_search {
	public:
		static_assert( sizeof( T ) <= sizeof( uint64_t ) );

		context_search() = delete;

		template <typename C>
		context_search( _CONTEXT* context, C&& callback, bool stack, size_t depth ) {
			uint64_t* registers = ( uint64_t* )&context->Rax;
			constexpr size_t num_registers = ( offsetof( CONTEXT, Rip ) - offsetof( CONTEXT, Rax ) ) / sizeof( uint64_t );

			for ( size_t i = 0; i < num_registers; i++ ) {
				T value = ( T )registers[ i ];

				if ( callback( value ) ) {
					value_ = value;
					location_ = resolved_location::registers;
					position_ = i;
					return;
				}
			}

			if ( stack ) {
				for ( size_t i = 0, n = depth / sizeof( T ); i < n; i++ ) {
					size_t offset = i * sizeof( T );
					T value = *( T* )( context->Rsp + offset );

					if ( callback( value ) ) {
						value_ = value;
						location_ = resolved_location::stack;
						position_ = offset;
						return;
					}
				}
			}

			location_ = resolved_location::unresolved;
			position_ = 0ull;
		}

		bool resolved() {
			return location_ != resolved_location::unresolved;
		}

		T get_value() {
			return value_;
		}

		T* ptr_to( _CONTEXT* context ) {
			if ( location_ == resolved_location::registers ) {
				uint64_t* registers = ( uint64_t* )&context->Rax;
				return ( T* )&registers[ position_ ];
			}

			else if ( location_ == resolved_location::stack ) {
				return ( T* )( context->Rsp + position_ );
			}

			return nullptr;
		}

		T get( _CONTEXT* context ) {
			if ( auto ptr = ptr_to( context ) ) {
				return *ptr;
			}

			return T();
		}

	private:
		T value_;
		resolved_location location_;
		size_t position_;
	};

	template <typename T>
	class com_ptr {
	public:
		com_ptr() :
			object_( nullptr ) {};

		~com_ptr() {
			if ( object_ ) {
				object_->Release();
			}
		}

		com_ptr( const com_ptr& ) = delete;
		com_ptr& operator=( const com_ptr& other ) = delete;

		com_ptr( com_ptr&& other ) {
			object_ = other.object_;
			other.object_ = nullptr;
		}

		com_ptr& operator=( com_ptr&& other ) {
			if ( &other != this ) {
				if ( object_ ) {
					object_->Release();
				}

				object_ = other.object_;
				other.object_ = nullptr;
			}

			return *this;
		}

		T* get() {
			return object_;
		}

		T** ptr_to() {
			return &object_;
		}

	private:
		T* object_;
	};

	template <typename T, size_t N>
	class fifo_queue {
	public:
		fifo_queue() :
			count_( 0ull ), head_( 0ull ), tail_( 0ull ) {};

		size_t size() const { return count_; }
		size_t capacity() const { return N; }

		bool push( const T& item ) {
			if ( count_ == N )
				return false;

			buffer_[ tail_ ] = item;
			tail_ = ( tail_ + 1llu ) % N;
			count_++;
			return true;
		}

		template <typename... Args>
		bool emplace_push( Args&&... args ) {
			if ( count_ == N )
				return false;

			new ( &buffer_[ tail_ ] ) T( std::forward<Args>( args )... );
			tail_ = ( tail_ + 1llu ) % N;
			count_++;
			return true;
		}

		bool pop( T& item ) {
			if ( count_ == 0ull )
				return false;

			item = buffer_[ head_ ];
			head_ = ( head_ + 1llu ) % N;
			count_--;
			return true;
		}

		void pop() {
			if ( count_ > 0ull ) {
				head_ = ( head_ + 1llu ) % N;
				count_--;
			}
		}
			
		template <typename C>
		void for_each( C&& callback ) {
			for ( size_t i = 0; i < count_; i++ ) {
				callback( buffer_[ ( head_ + i ) % N ], i );
			}
		}

	private:
		T buffer_[ N ];
		size_t count_;
		size_t head_;
		size_t tail_;
	};
}

#define H( String ) util::hash_const( String )
#define HW( String ) util::hash_w_const( String )
#define MS_H( String ) util::ms_hash( String ) 
#define FMT( Size, Format, ... ) util::format_string<Size>( Format, __VA_ARGS__ )