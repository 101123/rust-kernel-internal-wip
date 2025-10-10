#pragma once

#include "quat.h"
#include "vec3.h"

class matrix4x4 {
public:
	float data[ 4 * 4 ];

	float operator[]( int index ) const {
		return data[ index ];
	}

	float& operator[]( int index ) {
		return data[ index ];
	}

	static matrix4x4 trs( const vector3& pos, const quaternion& q, const vector3& s );
};