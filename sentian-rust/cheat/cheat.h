#pragma once

#include "util.h"

struct _CONTEXT;

enum class hook_type : uint8_t {
	method_info,
	vftable
};

struct hook {
	bool init;
	hook_type type;
	uintptr_t* value;
	uintptr_t original;
	uint64_t corrupt;
	void( *handler )( _CONTEXT* );
};

namespace bootstrap {
	inline bool populated_classes = false;

	bool init();
}

namespace hook_manager {
	inline bool resolved_hooks = false;
	inline util::array<hook, 16llu> hooks;

	bool init();
	void place_hooks();
	void remove_hooks();
}