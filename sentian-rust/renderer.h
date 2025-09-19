#pragma once

#include <cstdint>

#include "math/vec2.h"

struct IDXGISwapChain;

enum fonts {
	verdana,
	tahoma,
	small_fonts
};

namespace text_flags {
	enum : int {
		none = 0,
		centered = 1,
		drop_shadow = 2
	};
}

enum draw_flags {
	round_corners_top_left = 16,
	round_corners_top_right = 32,
	round_corners_bottom_left = 64,
	round_corners_bottom_right = 128,
	round_corners_none = 256,
	round_corners_top = round_corners_top_left | round_corners_top_right,
};

namespace renderer {
	bool init( IDXGISwapChain* swapchain );
	void destroy();

	void begin_frame();
	void end_frame();
	void draw_rect( float x, float y, float width, float height, float thickness, uint32_t color, float rounding = 0.f );
	void draw_filled_rect( float x, float y, float width, float height, uint32_t color, float rounding = 0.f );
	void draw_filled_rect_with_flags( float x, float y, float width, float height, uint32_t color, float rounding = 0.f, uint32_t flags = 0u );
	void draw_filled_rect_multi_color( float x, float y, float width, float height, uint32_t colors[ 4 ] );
	void draw_circle( float x, float y, float radius, float thickness, uint32_t color );
	void draw_filled_circle( float x, float y, float radius, uint32_t color );
	void draw_line( float x1, float y1, float x2, float y2, float thickness, uint32_t color );
	void draw_text( float x, float y, uint32_t font, uint32_t flags, uint32_t color, const char* text );
	void draw_text( float x, float y, uint32_t font, uint32_t flags, uint32_t color, const wchar_t* text );

	void push_clip_rect( float x, float y, float width, float height );
	void pop_clip_rect();

	Vector2 calc_text_size( uint32_t font, const char* text );
}