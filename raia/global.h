#pragma once

#define DEBUG
#define EAC_LOGS

#ifdef DEBUG
#define S( String ) String

#define DESTROY_BEGIN 
#define DESTROY_END

#ifdef EAC_LOGS
#define LOG( Message ) driver_api->add_log( 0, 0, 0, Message );
#else
#define LOG( Format, ... ) DbgPrintEx( DPFLTR_IHVDRIVER_ID, DPFLTR_ERROR_LEVEL, Format, __VA_ARGS__ );
#endif

#define LOG2( Format, ... ) { char _[ 256 ]; snprintf( _, sizeof( _ ), Format, __VA_ARGS__ ); DbgPrintEx( DPFLTR_IHVDRIVER_ID, DPFLTR_ERROR_LEVEL, "%s", _ ); }
#else
#include "xorstr.hpp"
#include "destroy.h"

#define S( String ) xorstr_( String )
#define LOG( Message ) 
#endif

#include "sentian/api.h"

namespace unity {
	class asset_bundle;
}

namespace rust {
	class base_player;
}

struct _KPROCESS;

inline _KPROCESS* rust_process;
inline void* rust_pid;

inline uintptr_t game_assembly;
inline uintptr_t unity_player;

inline unity::asset_bundle* asset_bundle;

inline int screen_width;
inline int screen_height;

inline input game_input;
inline input render_input;