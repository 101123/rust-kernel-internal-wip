#pragma once

#define DEBUG

#define LOG( ... ) DbgPrintEx( DPFLTR_IHVDRIVER_ID, DPFLTR_ERROR_LEVEL, __VA_ARGS__ )

#include "sentian/api.h"

#include <cstdint>

namespace unity {
	class asset_bundle;
}

struct _KPROCESS;

inline sentian::driver_api* driver_api;

inline _KPROCESS* rust_process;
inline void* rust_pid;

inline uintptr_t game_assembly;
inline uintptr_t unity_player;

inline unity::asset_bundle* asset_bundle;

#define is_valid_ptr( x ) driver_api->is_valid_ptr( ( void* )x )