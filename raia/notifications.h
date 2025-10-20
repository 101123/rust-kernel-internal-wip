#pragma once

#include <cstdint>

namespace notifications {
	void push( const char* message );
	void push( const wchar_t* message );
	void draw( float delta_time );
}