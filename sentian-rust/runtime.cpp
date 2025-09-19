#pragma once

#include "nt.h"

#define NANOPRINTF_IMPLEMENTATION
#define NANOPRINTF_USE_FIELD_WIDTH_FORMAT_SPECIFIERS 1
#define NANOPRINTF_USE_PRECISION_FORMAT_SPECIFIERS 1
#define NANOPRINTF_USE_FLOAT_FORMAT_SPECIFIERS 1
#define NANOPRINTF_USE_LARGE_FORMAT_SPECIFIERS 1
#define NANOPRINTF_USE_BINARY_FORMAT_SPECIFIERS 0
#define NANOPRINTF_USE_WRITEBACK_FORMAT_SPECIFIERS 0
#include <nanoprintf.h>

#include <exception>

extern "C" {
    void* malloc( size_t _Size ) {
        return ExAllocatePool( PagedPool, _Size );
    }

    void free( void* _Block ) {
        ExFreePool( _Block );
    }

    int __stdio_common_vsprintf(
        unsigned __int64 const options,
        char* const buffer,
        size_t const buffer_count,
        char const* const format,
        _locale_t const locale,
        va_list const arglist
    ) {
        return npf_vsnprintf( buffer, buffer_count, format, arglist );
    }
}

//
// xthrow.cpp  
//
namespace std {
    void _Xbad_alloc() {
        __fastfail( 0 );
    }

    void _Xinvalid_argument( const char* _Message ) {
        __fastfail( 0 );
    }

    void _Xlength_error( const char* _Message ) {
        __fastfail( 0 );
    }

    void _Xout_of_range( const char* _Message ) {
        __fastfail( 0 );
    }

    void _Xoverflow_error( const char* _Message ) {
        __fastfail( 0 );
    }

    void _Xruntime_error( const char* _Message ) {
        __fastfail( 0 );
    }

    void _Xbad_function_call() {
        __fastfail( 0 );
    }

    void _Xregex_error( const int _Code ) {
        __fastfail( 0 );
    }

    void _Xlen_string() {
        __fastfail( 0 );
    }

    void _Xlength() {
        __fastfail( 0 );
    }

    void _Xrange() {
        __fastfail( 0 );
    }
}

//
// throw_bad_alloc.cpp
//
void __cdecl __scrt_throw_std_bad_alloc() {
    __fastfail( 0 );
}

void __cdecl __scrt_throw_std_bad_array_new_length() {
    __fastfail( 0 );
}

//
//
//
void* operator new( size_t size ) {
    return malloc( size );
}

void* operator new( size_t size, std::nothrow_t const& ) {
    return malloc( size );
}

void* operator new[]( size_t size ) {
    return malloc( size );
}

void operator delete( void* ptr ) {
    free( ptr );
}

void operator delete[]( void* ptr ) {
    free( ptr );
}

void operator delete( void* ptr, size_t size ) {
    free( ptr );
}

void operator delete[]( void* ptr, size_t size ) {
    free( ptr );
}

//
// exception
//
std::_Prhand std::_Raise_handler = nullptr;

//
// invalid_parameter.cpp
//
void _invalid_parameter_noinfo( void ) {
    __fastfail( 0 );
}

void _invalid_parameter_noinfo_noreturn( void ) {
    __fastfail( 0 );
}

//
//
//
void _invoke_watson(
    _In_opt_z_ wchar_t const* _Expression,
    _In_opt_z_ wchar_t const* _FunctionName,
    _In_opt_z_ wchar_t const* _FileName,
    _In_       unsigned int _LineNo,
    _In_       uintptr_t _Reserved ) {
    __fastfail( 0 );
}

//
// Global initializers
//
typedef void( *_PVFV )( void );
typedef int( *_PIFV )( void );
typedef void( *_PVFI )( int );

void _initterm( _PVFV* const _First, _PVFV* const _Last ) {
    for ( _PVFV* it = _First; it != _Last; ++it ) {
        if ( *it == nullptr )
            continue;

        ( **it )( );
    }
}

int _initterm_e( _PIFV* const _First, _PIFV* const _Last ) {
    for ( _PIFV* it = _First; it != _First; ++it ) {
        if ( *it == nullptr )
            continue;

        int const result = ( **it )( );
        if ( result != 0 ) {
            return result;
        }
    }

    return 0;
}

extern "C" {
#pragma comment( linker, "/merge:.CRT=.rdata" )

#pragma section( ".CRT$XIA", long, read )
#pragma section( ".CRT$XIZ", long, read )
#pragma section( ".CRT$XCA", long, read )
#pragma section( ".CRT$XCZ", long, read )
#pragma section( ".CRT$XPA", long, read )
#pragma section( ".CRT$XPZ", long, read )
#pragma section( ".CRT$XTA", long, read )
#pragma section( ".CRT$XTZ", long, read )

    __declspec( allocate( ".CRT$XIA" ) ) _PIFV __xi_a[] = { nullptr };
    __declspec( allocate( ".CRT$XIZ" ) ) _PIFV __xi_z[] = { nullptr };
    __declspec( allocate( ".CRT$XCA" ) ) _PVFV __xc_a[] = { nullptr };
    __declspec( allocate( ".CRT$XCZ" ) ) _PVFV __xc_z[] = { nullptr };
    __declspec( allocate( ".CRT$XPA" ) ) _PVFV __xp_a[] = { nullptr };
    __declspec( allocate( ".CRT$XPZ" ) ) _PVFV __xp_z[] = { nullptr };
    __declspec( allocate( ".CRT$XTA" ) ) _PVFV __xt_a[] = { nullptr };
    __declspec( allocate( ".CRT$XTZ" ) ) _PVFV __xt_z[] = { nullptr };

    int driver_main( void*, void* );
    int DriverEntry( void* DriverObject, void* RegistryPath ) {
        if ( _initterm_e( __xi_a, __xi_z ) != 0 )
            return 1;

        _initterm( __xc_a, __xc_z );
        return driver_main( DriverObject, RegistryPath );
    }
}