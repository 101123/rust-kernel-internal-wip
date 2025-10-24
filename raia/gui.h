#pragma once

namespace gui {
	inline bool open = true;
	inline float scroll_delta = 0.f;

	void init();
	void destroy();

	void run();
}