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
        unsigned __int64 _Options,
        char* _Buffer,
        size_t _BufferCount,
        char const* _Format,
        _locale_t _Locale,
        va_list _ArgList
    ) {
        return npf_vsnprintf( _Buffer, _BufferCount, _Format, _ArgList );
    }

    // This is needed because ntstrsafe.lib doesn't contain it for some reason
    extern const unsigned char __lookuptable_s[] = {
        /* ' ' */  0x06,
        /* '!' */  0x80,
        /* '"' */  0x80,
        /* '#' */  0x86,
        /* '$' */  0x80,
        /* '%' */  0x81,
        /* '&' */  0x80,
        /* ''' */  0x00,
        /* '(' */  0x00,
        /* ')' */  0x10,
        /* '*' */  0x03,
        /* '+' */  0x86,
        /* ',' */  0x80,
        /* '-' */  0x86,
        /* '.' */  0x82,
        /* '/' */  0x80,
        /* '0' */  0x14,
        /* '1' */  0x05,
        /* '2' */  0x05,
        /* '3' */  0x45,
        /* '4' */  0x45,
        /* '5' */  0x45,
        /* '6' */  0x85,
        /* '7' */  0x85,
        /* '8' */  0x85,
        /* '9' */  0x05,
        /* ':' */  0x00,
        /* ';' */  0x00,
        /* '<' */  0x30,
        /* '=' */  0x30,
        /* '>' */  0x80,
        /* '?' */  0x50,
        /* '@' */  0x80,
       #if defined (_SAFECRT_IMPL)
        /* 'A' */  0x80,       // Disable %A format
       #else  /* defined (_SAFECRT_IMPL) */
        /* 'A' */  0x88,
       #endif  /* defined (_SAFECRT_IMPL) */
        /* 'B' */  0x00,
        /* 'C' */  0x08,
        /* 'D' */  0x00,
        /* 'E' */  0x28,
        /* 'F' */  0x27,
        /* 'G' */  0x38,
        /* 'H' */  0x50,
        /* 'I' */  0x57,
        /* 'J' */  0x80,
        /* 'K' */  0x00,
        /* 'L' */  0x07,
        /* 'M' */  0x00,
        /* 'N' */  0x37,
        /* 'O' */  0x30,
        /* 'P' */  0x30,
        /* 'Q' */  0x50,
        /* 'R' */  0x50,
        /* 'S' */  0x88,
        /* 'T' */  0x00,
        /* 'U' */  0x00,
        /* 'V' */  0x00,
        /* 'W' */  0x20,
        /* 'X' */  0x28,
        /* 'Y' */  0x80,
        /* 'Z' */  0x88,
        /* '[' */  0x80,
        /* '\' */  0x80,
        /* ']' */  0x00,
        /* '^' */  0x00,
        /* '_' */  0x00,
        /* '`' */  0x60,
       #if defined (_SAFECRT_IMPL)
        /* 'a' */  0x60,       // Disable %a format
       #else  /* defined (_SAFECRT_IMPL) */
        /* 'a' */  0x68,
       #endif  /* defined (_SAFECRT_IMPL) */
        /* 'b' */  0x60,
        /* 'c' */  0x68,
        /* 'd' */  0x68,
        /* 'e' */  0x68,
        /* 'f' */  0x08,
        /* 'g' */  0x08,
        /* 'h' */  0x07,
        /* 'i' */  0x78,
        /* 'j' */  0x70,
        /* 'k' */  0x70,
        /* 'l' */  0x77,
        /* 'm' */  0x70,
        /* 'n' */  0x70,
        /* 'o' */  0x08,
        /* 'p' */  0x08,
        /* 'q' */  0x00,
        /* 'r' */  0x00,
        /* 's' */  0x08,
        /* 't' */  0x00,
        /* 'u' */  0x08,
        /* 'v' */  0x00,
        /* 'w' */  0x07,
        /* 'x' */  0x08
    };

    int _vswprintf_l(
        wchar_t* const _Buffer,
        wchar_t const* const _Format,
        _locale_t const _Locale,
        va_list _ArgList
    );

    int __stdio_common_vswprintf(
        unsigned __int64 _Options,
        wchar_t* _Buffer,
        size_t _BufferCount,
        wchar_t const* _Format,
        _locale_t _Locale,
        va_list _ArgList
    ) {
        return _vswprintf_l( _Buffer, _Format, _Locale, _ArgList );
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

    int main( void*, void* );
    int DriverEntry( void* DriverObject, void* RegistryPath ) {
        if ( _initterm_e( __xi_a, __xi_z ) != 0 )
            return 1;

        _initterm( __xc_a, __xc_z );
        return main( DriverObject, RegistryPath );
    }
}