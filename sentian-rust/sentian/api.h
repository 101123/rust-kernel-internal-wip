#pragma once

#include <stdint.h>

#pragma pack( push, 1 )

#define DRIVER_API_VERSION 48

#define MAX_DRIVER_ALLOCATIONS 1024

#define DF_ENABLE_HANDLE_ESCALATION ( 1 << 0 )
#define DF_DISABLE_VA_COPY_PROTECTION ( 1 << 1 )
#define DF_DISABLE_HIDE_KERNEL_PATCHES ( 1 << 2 )
#define DF_DISABLE_HIDE_PAGE_TABLE_ENTRIES ( 1 << 3 )
#define DF_DISABLE_HIDE_PHYS_ADDRESS ( 1 << 4 )
#define DF_DISABLE_HIDE_EAC_KERNEL_PATCHES ( 1 << 5 )
#define DF_DISABLE_HIDE_WORKING_SET_WATCH ( 1 << 6 )
#define DF_DISABLE_HIDE_NMI_CALLBACKS ( 1 << 7 )
#define DF_DISABLE_HIDE_UNWINDS ( 1 << 8 )
#define DF_DISABLE_EARLY_IS_VALID_PTR ( 1 << 9 )
#define DF_DISABLE_HIDE_APC_CALLBACKS ( 1 << 10 )
#define DF_DISABLE_HIDE_SECURE_BOOT ( 1 << 11 )
#define DF_DISABLE_HIDE_TPM ( 1 << 12 )

#define DFE_ENABLE_PG_BYPASS ( 1 << 0 )

namespace sentian {
	enum class driver_slot_type : uint8_t {
		reserved0,
		spoofer,
		alloc,
		exec,
		renderer,
		watch,
		reserved1,
		mapper,
		sockets,
		max
	};

	enum class ntdll_dispatcher_type : uint8_t {
		ki_user_exception,
		ki_user_apc,
		ki_user_callback,
		max
	};

	enum class log_type : uint8_t {
		string = 0,
		data,
		max
	};

	enum class worker_type : uint8_t {
		regular,
		secure,
		max
	};

	struct syscall_frame {
		uint64_t rcx;
		uint64_t rdx;
		uint64_t r8;
		uint64_t r9;
		uint64_t r10;
	};

	struct guard_call_frame {
		uint64_t rax;
		uint64_t rcx;
		uint64_t rdx;
		uint64_t r8;
		uint64_t r9;
		uint64_t return_address;
	};

	struct usermode_allocation {
		bool valid;
		uint64_t pid;
		uint64_t address;
		uint32_t size;
	};

	struct callback_result {
		void* stack;
		uint64_t context;
		uint64_t result;
		bool skip_call : 1;
		bool post_call : 1;
	};

	struct context_header {
		uint8_t* data;
		uint32_t data_size;
		uint64_t arg1;
		uint64_t arg2;
		uint64_t arg3;
		uint64_t arg4;
		uint64_t arg5;
		uint64_t arg6;
		uint64_t arg7;
		uint64_t arg8;
	};

	struct log_entry {
		log_type type;
		uint16_t length;
		uint64_t timestamp;
		uint32_t pid;
		uint32_t tid;
		uint8_t data[ 1 ];
	};

	typedef bool ( *log_callback_t )( log_entry* log );

	typedef bool ( *unload_callback_t )( void* slot );
	typedef uint64_t( *context_callback_t )( context_header* context_header );
	typedef bool ( *exception_callback_t )( void* exception_record, void* context_record, uint8_t previous_mode );
	typedef void ( *syscall_callback_t )( syscall_frame* frame, syscall_frame* orig_frame );
	typedef bool ( *io_call_driver_callback_t )( callback_result* callback, void* device_object, void* irp );
	typedef bool ( *mm_get_physical_address_callback_t )( callback_result* callback, uint64_t va, uint64_t* phys );
	typedef bool ( *mm_copy_memory_callback_t )( callback_result* callback, uint64_t target_address, uint64_t source_address,
		uint64_t number_of_bytes, uint32_t flags, uint64_t* number_of_bytes_transferred );
	typedef bool ( *mi_map_contiguous_memory_callback_t )( callback_result* callback, uint64_t* phys, uint64_t* size );
	typedef bool ( *ki_process_nmi_callback_t )( callback_result* callback, void* trap_frame, void* exception_frame,
		bool* restore_rip );
	typedef bool ( *ki_deliver_apc_callback_t )( callback_result* callback, uint8_t processor_mode, void* exception_frame,
		void* trap_frame );
	typedef bool ( *ps_watch_working_set_callback_t )( callback_result* callback, uint32_t status, uint64_t rip,
		uint64_t fault_address );
	typedef bool ( *ob_reference_object_by_handle_callback_t )( callback_result* callback, void* handle, int32_t desired_access,
		void* object_type, uint8_t access_mode, uint32_t tag,
		void** object, void* handle_information,
		void* extra_handle_information );
	typedef bool ( *mm_access_fault_callback_t )( callback_result* callback, uint64_t fault_status, uint64_t virtual_address,
		uint8_t previous_mode, void* trap_frame, void* exception_frame );
	typedef bool ( *psp_exit_process_callback_t )( callback_result* callback, bool last_thread_exit, uint64_t process );
	typedef bool ( *rtl_virtual_unwind_callback_t )( callback_result* callback, uint32_t handler_type, uint64_t image_base,
		uint64_t control_pc, void* function_entry, void* context_record,
		void* handler_data, void* establisher_frame, void** exception_routine );
	typedef bool ( *ps_get_thread_win32_thread_callback_t )( callback_result* callback, uint64_t thread );
	typedef bool ( *etwp_reserve_trace_buffer_callback_t )( callback_result* callback, uint64_t logger_context,
		uint32_t required_size, uint64_t buffer_handle, uint64_t* time_stamp,
		uint32_t flags );
	typedef bool ( *nt_create_file_callback_t )( callback_result* callback, void** file_handle, uint32_t desired_access,
		void* object_attributes, void* io_status_block, void* allocation_size,
		uint32_t file_attributes, uint32_t share_access, uint32_t create_disposition,
		uint32_t create_options, void* ea_buffer, uint32_t ea_length );
	typedef bool ( *nt_open_file_callback_t )( callback_result* callback, void** file_handle, uint32_t desired_access,
		void* object_attributes, void* io_status_block, uint32_t share_access,
		uint32_t open_options );
	typedef bool ( *nt_read_file_callback_t )( callback_result* callback, void* file_handle, void* event, void* apc_routine,
		void* apc_context, void* io_status_block, uint8_t* buffer, uint32_t length,
		uint64_t* byte_offset, uint32_t* key );
	typedef bool ( *nt_query_system_information_callback_t )( callback_result* callback, uint32_t system_information_class,
		void* system_information, uint32_t system_information_length,
		uint32_t* return_length );
	typedef bool ( *nt_query_system_environment_value_ex_callback_t )( callback_result* callback, void* variable_name,
		void* vendor_guid, void* value, uint32_t* return_length,
		uint32_t* attributes );
	typedef bool ( *nt_query_value_key_callback_t )( callback_result* callback, void* key_handle, void* value_name,
		uint32_t key_value_information_class, void* key_value_information,
		uint32_t length, uint32_t* result_length );
	typedef bool ( *nt_query_virtual_memory_callback_t )( callback_result* callback, void* process_handle, void* base_address,
		uint32_t memory_information_class, void* memory_information,
		size_t memory_information_length, size_t* return_length );
	typedef bool ( *nt_read_virtual_memory_callback_t )( callback_result* callback, void* process_handle, void* base_address,
		void* buffer, size_t buffer_size, size_t* number_of_bytes_read );
	typedef bool ( *nt_protect_virtual_memory_callback_t )( callback_result* callback, void* process_handle, void** base_address,
		size_t* region_size, uint32_t new_protect, uint32_t* old_protect );

	struct driver_allocation {
		uint64_t image_base;
		uint32_t image_size;
		uint32_t function_table;
		uint16_t function_count;
	};

	struct driver_slot {
		bool enabled;
		driver_allocation allocation;
		context_callback_t context;
		unload_callback_t unload;
		exception_callback_t trap;
		syscall_callback_t syscall;
		exception_callback_t ntdll_dispatchers[ ( uint8_t )ntdll_dispatcher_type::max ];
		io_call_driver_callback_t io_call_driver;
		mm_get_physical_address_callback_t mm_get_physical_address;
		mm_copy_memory_callback_t mm_copy_memory;
		mi_map_contiguous_memory_callback_t mi_map_contiguous_memory;
		mm_access_fault_callback_t mm_access_fault;
		psp_exit_process_callback_t psp_exit_process;
		rtl_virtual_unwind_callback_t rtl_virtual_unwind;
		ki_process_nmi_callback_t ki_process_nmi;
		ki_deliver_apc_callback_t ki_deliver_apc;
		ps_watch_working_set_callback_t ps_watch_working_set;
		ob_reference_object_by_handle_callback_t ob_reference_object_by_handle;
		ps_get_thread_win32_thread_callback_t ps_get_thread_win32_thread;
		etwp_reserve_trace_buffer_callback_t etwp_reserve_trace_buffer;
		nt_create_file_callback_t nt_create_file;
		nt_open_file_callback_t nt_open_file;
		nt_read_file_callback_t nt_read_file;
		nt_query_system_information_callback_t nt_query_system_information;
		nt_query_system_environment_value_ex_callback_t nt_query_system_environment_value;
		nt_query_value_key_callback_t nt_query_value_key;
		nt_query_virtual_memory_callback_t nt_query_virtual_memory;
		nt_read_virtual_memory_callback_t nt_read_virtual_memory;
		nt_protect_virtual_memory_callback_t nt_protect_virtual_memory;
	};

	typedef bool ( *ke_ipi_generic_call_callback_t )( callback_result* callback, uint64_t* ipi_callback, uint64_t arg );
	typedef void ( *guard_call_callback_t )( guard_call_frame* frame, guard_call_frame* orig_frame );

	struct driver_slot_ext {
		bool enabled;
		ke_ipi_generic_call_callback_t ke_ipi_generic_call;
		guard_call_callback_t guard_call;
	};

	typedef void ( *worker_callback_t )( );
	typedef bool ( *workers_add_t )( worker_type worker_type, worker_callback_t callback );
	typedef void ( *workers_execute_t )( worker_type worker_type );

	struct driver_api_ext {
		uint64_t region_va;
		uint64_t region_pa;
		uint32_t region_size;
		uint32_t region_bl3_size;
		uint64_t secure_kernel;
		uint32_t secure_kernel_size;
		uint32_t debug_flags;
		workers_add_t workers_add;
		workers_execute_t workers_execute;
		driver_slot_ext slots[ ( uint8_t )driver_slot_type::max ];
	};

	typedef bool ( *is_valid_ptr_t )( void* address );
	typedef bool ( *is_within_memory_t )( uint64_t address, bool physical );
	typedef bool ( *is_within_kernel_t )( uint64_t address );
	typedef usermode_allocation* ( *find_alloc_t )( uint64_t pid, uint64_t address );
	typedef uint64_t( *find_syscall_t )( uint32_t hash );
	typedef uint32_t( *find_hash_t )( uint64_t address );
	typedef uint64_t( *find_export_t )( void* image_base, uint64_t hash );
	typedef void* ( *heap_alloc_t )( uint64_t size );
	typedef bool ( *heap_free_t )( void* address );
	typedef bool ( *insert_patch_t )( void* address, uint32_t size, void* data );
	typedef void* ( *trampoline_function_t )( void* address, uint32_t count );
	typedef void* ( *detour_function_t )( void* address, void* hook );
	typedef void* ( *redirect_function_t )( void* source, void* destination );
	typedef void* ( *breakpoint_function_t )( void* address, void* hook );
	typedef bool ( *add_log_t )( uint64_t timestamp, uint32_t pid, uint32_t tid, const char* message );
	typedef bool ( *add_data_log_t )( uint64_t timestamp, uint32_t pid, uint32_t tid, uint8_t* data, uint16_t size );
	typedef void ( *dump_logs_t )( log_callback_t callback );
	typedef bool ( *map_driver_t )( uint8_t* data, uint64_t argument );
	typedef bool ( *decrypt_payload_t )( uint8_t* data, bool use_guid, bool use_nonce );
	typedef bool ( *unload_slot_t )( driver_slot* slot );

	struct driver_api {
		uint8_t version;
		uint16_t port;
		driver_api_ext* ext;
		uint64_t kernel;
		uint32_t kernel_size;
		uint32_t kernel_version;
		uint32_t debug_flags;
		is_valid_ptr_t is_valid_ptr;
		is_within_memory_t is_within_memory;
		is_within_kernel_t is_within_kernel;
		find_alloc_t find_alloc;
		find_syscall_t find_syscall;
		find_hash_t find_hash;
		find_export_t find_export;
		heap_alloc_t heap_alloc;
		heap_free_t heap_free;
		insert_patch_t insert_patch;
		trampoline_function_t trampoline_function;
		detour_function_t detour_function;
		redirect_function_t redirect_function;
		breakpoint_function_t breakpoint_function;
		add_log_t add_log;
		add_data_log_t add_data_log;
		dump_logs_t dump_logs;
		map_driver_t map_driver;
		decrypt_payload_t decrypt_payload;
		unload_slot_t unload_slot;
		uint64_t ntdll_dispatchers[ ( uint8_t )ntdll_dispatcher_type::max ];
		driver_slot slots[ ( uint8_t )driver_slot_type::max ];
		usermode_allocation allocs[ MAX_DRIVER_ALLOCATIONS ];
	};
}

#pragma pack( pop )