#pragma once

#define DEBUG

#define LOG( ... ) DbgPrintEx( DPFLTR_IHVDRIVER_ID, DPFLTR_ERROR_LEVEL, __VA_ARGS__ )

#include "sentian/api.h"

#include <cstdint>

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

inline rust::base_player* local_player;
inline rust::base_player* target_player;

inline unity::asset_bundle* asset_bundle;

inline input game_input;
inline input render_input;