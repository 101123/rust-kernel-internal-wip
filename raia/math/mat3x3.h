#pragma once

#include "vec3.h"

class matrix3x3 {
public:
	union {
		float data[ 3 * 3 ];
		vector3 vec[ 3 ];
	};

	matrix3x3() {};
	matrix3x3( vector3 a, vector3 b, vector3 c ) {
		vec[ 0 ] = a;
		vec[ 1 ] = b;
		vec[ 2 ] = c;
	}

	float& get( int row, int column ) { 
		return data[ row + ( column * 3 ) ]; 
	}

	const float& get( int row, int column ) const { 
		return data[ row + ( column * 3 ) ]; 
	}

	float operator[]( int index ) const {
		return data[ index ];
	}

	float& operator[]( int index ) {
		return data[ index ];
	}
};