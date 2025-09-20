#pragma once

#include "global.h"

#include "cheat/sdk/offsets.h"
#include "cheat/sdk/field_types.h"

#include "util.h"
#include "um.h"

struct method_info {
	void* method_ptr;
	// ...
};

class il2cpp_type {

};

class il2cpp_class {
public:
	FIELD( const char*, name, Offsets::Il2CppClass::name );
	FIELD( const char*, namespaze, Offsets::Il2CppClass::namespaze );
	FIELD( il2cpp_class*, parent, Offsets::Il2CppClass::parent );
	FIELD( uintptr_t, static_fields, Offsets::Il2CppClass::static_fields );
};

class il2cpp_object {
public:
	FIELD( il2cpp_class*, klass, Offsets::Il2CppObject::klass );

	template <typename T>
	T* as() {
		il2cpp_class* current = klass;

		while ( is_valid_ptr( current ) ) {
			if ( current == T::s_klass ) {
				return ( T* )this;
			}

			current = current->parent;
		}

		return nullptr;
	}
};

struct handle_data {
	uint32_t* bitmap;
	void** entries;
	uint32_t size;
	uint8_t type;
	uint32_t slot_hint : 24;
	uint16_t* domain_ids;
};

inline il2cpp_object* il2cpp_gchandle_get_target( uint32_t gchandle ) {
	uint32_t slot = gchandle >> 3;
	uint32_t type = ( gchandle & 7 ) - 1;
	if ( type > 3 )
		return nullptr;

	handle_data* gc_handles = ( handle_data* )( game_assembly + Offsets::GameAssembly::gc_handles );
	handle_data* handles = &gc_handles[ type ];

	if ( slot < handles->size && ( handles->bitmap[ slot / 32 ] & ( 1 << ( slot % 32 ) ) ) ) {
		if ( handles->type > 1 ) {
			return ( il2cpp_object* )handles->entries[ slot ];
		}
	}

	return nullptr;
}

inline method_info* il2cpp_class_get_method_from_name( il2cpp_class* klass, const char* name, int args_count ) {
	static method_info* ( *il2cpp_class_get_method_from_name )( il2cpp_class*, const char*, int ) =
		( decltype( il2cpp_class_get_method_from_name ) )( driver_api->find_export( ( void* )game_assembly, H( "il2cpp_class_get_method_from_name" ) ) );

	um::caller& caller = um::get_caller_for_thread();

	const char* name_ = caller.push_string( name );

	return caller( il2cpp_class_get_method_from_name, klass, name_, args_count );
}

inline il2cpp_class* il2cpp_class_from_system_type( il2cpp_object* type ) {
	static il2cpp_class* ( *il2cpp_class_from_system_type )( il2cpp_object* ) =
		( decltype( il2cpp_class_from_system_type ) )( driver_api->find_export( ( void* )game_assembly, H( "il2cpp_class_from_system_type" ) ) );

	um::caller& caller = um::get_caller_for_thread();

	return caller( il2cpp_class_from_system_type, type );
}

inline il2cpp_type* il2cpp_class_get_type( il2cpp_class* klass ) {
	return ( il2cpp_type* )( ( uintptr_t )klass + Offsets::Il2CppClass::byval_arg );
}

inline uint32_t il2cpp_gchandle_new( il2cpp_object* obj, bool pinned ) {
	static uint32_t ( *il2cpp_gchandle_new )( il2cpp_object*, bool ) =
		( decltype( il2cpp_gchandle_new ) )( driver_api->find_export( ( void* )game_assembly, H( "il2cpp_gchandle_new" ) ) );

	um::caller& caller = um::get_caller_for_thread();

	return caller( il2cpp_gchandle_new, obj, pinned );
}

inline il2cpp_object* il2cpp_object_new( il2cpp_class* klass ) {
	static il2cpp_object* ( *il2cpp_object_new )( il2cpp_class* ) =
		( decltype( il2cpp_object_new ) )( driver_api->find_export( ( void* )game_assembly, H( "il2cpp_object_new" ) ) );

	um::caller& caller = um::get_caller_for_thread();

	return caller( il2cpp_object_new, klass );
}

inline il2cpp_object* il2cpp_type_get_object( il2cpp_type* type ) {
	static il2cpp_object*( *il2cpp_type_get_object )( il2cpp_type* ) =
		( decltype( il2cpp_type_get_object ) )( driver_api->find_export( ( void* )game_assembly, H( "il2cpp_type_get_object" ) ) );

	um::caller& caller = um::get_caller_for_thread();

	return caller( il2cpp_type_get_object, type );
}