#pragma once

#include "util.h"

struct _CONTEXT;

namespace hook_flags {
	enum : int {
		method_info = 1,
		vftable = 2,
		post = 4
	};
}

struct hook {
	bool init;
	int flags;
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