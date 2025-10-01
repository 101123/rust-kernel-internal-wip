#pragma once

#include <cstdint>

#include "math/vec2.h"

#define COL32( r, g, b, a ) ( ( ( uint32_t )( a ) << 24 ) | ( ( uint32_t )( b ) << 16 ) | ( ( uint32_t ) ( g ) << 8 ) | ( ( uint32_t )( r ) << 0 ) )

#define COL32_RED COL32( 255, 0, 0, 255 )
#define COL32_GREEN COL32( 0, 255, 0, 255 )
#define COL32_BLUE COL32( 0, 255, 255, 255 )
#define COL32_WHITE COL32( 255, 255, 255, 255 )
#define COL32_BLACK COL32( 0, 0, 0, 255 )

#define TRUNC( x ) ( ( float )( int )( x ) )

struct IDXGISwapChain;
struct ID3D11ShaderResourceView;

enum fonts {
	verdana,
	small_fonts,
	icons
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
	void draw_image( ID3D11ShaderResourceView* srv, float x, float y, float width, float height );
	void draw_unity_image( ID3D11ShaderResourceView* srv, float x, float y, float width, float height, float rounding = 0.f );

	void push_clip_rect( float x, float y, float width, float height );
	void pop_clip_rect();

	vector2 calc_text_size( uint32_t font, const char* text );
	void wstr_to_utf8( const wchar_t* in, char* out, int out_size );
}