#pragma once

#include <cstdint>

#define FIELD( Type, Name, Offset ) \
    Type* _address_of_##Name() const { \
        return ( Type* )( ( uintptr_t )this + Offset ); \
    } \
    Type _get_##Name() const { \
        return *_address_of_##Name(); \
    } \
    void _set_##Name( Type value ) { \
        *_address_of_##Name() = value; \
    } \
    __declspec( property( get = _get_##Name, put = _set_##Name ) ) Type Name;

#define ENCRYPTED_VALUE( Type, Name, Offset, Decryption, Encryption ) \
    static Type decrypt_##Name( Type value ) { \
        uint32_t* values = ( uint32_t* )&value; \
        for ( size_t i = 0; i < ( sizeof( Type ) / sizeof( uint32_t ) ); i++ ) { \
            Decryption \
        }; \
        return value; \
    } \
    Type get_##Name() { \
        return decrypt_##Name( *( Type* )( ( uintptr_t )this + Offset ) ); \
    } \
    static Type encrypt_##Name( Type value ) { \
        uint32_t* values = ( uint32_t* )&value; \
        for ( size_t i = 0; i < ( sizeof( Type ) / sizeof( uint32_t ) ); i++ ) { \
            Encryption \
        }; \
        return value; \
    } \
    void set_##Name( Type value ) { \
        *( Type* )( ( uintptr_t )this + Offset ) = encrypt_##Name( value ); \
    } \
    __declspec( property( get = get_##Name, put = set_##Name ) ) Type Name;

#define HIDDEN_VALUE( Type, Name, Offset, HandleDecryption ) \
    static uintptr_t decrypt_##Name##_handle( uintptr_t handle ) { \
        uint32_t* values = ( uint32_t* )&handle; \
        for ( size_t i = 0; i < ( sizeof( uintptr_t ) / sizeof( uint32_t ) ); i++ ) { \
            HandleDecryption \
        }; \
        return handle; \
    } \
    Type get_##Name() { \
        uintptr_t hidden_value = *( uintptr_t* )( ( uintptr_t )this + Offset ); \
        if ( !is_valid_ptr( hidden_value ) ) \
            return nullptr; \
        uintptr_t decrypted_handle = decrypt_##Name##_handle( *( uintptr_t* )( hidden_value + Offsets::HiddenValue::_handle ) ); \
        return ( Type )il2cpp_gchandle_get_target( decrypted_handle ); \
    } \
    __declspec( property( get = get_##Name ) ) Type Name;
        
