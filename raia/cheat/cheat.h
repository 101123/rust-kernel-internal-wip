#pragma once

#include "util.h"

struct _CONTEXT;

namespace hook_type {
	enum : int {
		method_info = 1,
		ptr_swap = 2,
	};
}

struct hook {
	bool init;
	int type;
	uintptr_t* value;
	uintptr_t original;
	uint64_t corrupt;
	void* user_data;

	union {
		struct {
			void( *handler )( _CONTEXT*, void* );
		} method_info;

		struct {
			bool( *pre_handler )( _CONTEXT*, void* );
			void( *post_handler )( _CONTEXT*, void* );
			uintptr_t* ( *find_retaddr )( CONTEXT* );

			uint64_t corrupt_retaddr;
			uintptr_t retaddr;
		} ptr_swap;
	};
};

namespace bootstrap {
	inline bool populated_classes = false;

	bool init();
}

namespace hook_manager {
	inline bool resolved_hooks = false;
	inline util::array<hook, 32llu> hooks;

	bool init();
	void place_hooks();
	void remove_hooks();
}