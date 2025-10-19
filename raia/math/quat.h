#pragma once

#include "common.h"
#include "vec3.h"
#include "mat3x3.h"

class quaternion {
public:
	float x, y, z, w;

	quaternion operator/( const float value ) const {
		return quaternion( x / value, y / value, z / value, w / value );
	}

	static float dot( const quaternion& lhs, const quaternion& rhs ) {
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
	}

	static float magnitude( const quaternion& quat ) {
		return sqrtf( dot( quat, quat ) );
	}

	static quaternion normalize( const quaternion& quat ) {
		return quat / magnitude( quat );
	}

	static const quaternion identity;
};

void matrix_to_quaternion( const matrix3x3& rot, quaternion& q );
bool look_rotation_to_quaternion( const vector3& forward, const vector3& up, quaternion& result );
vector3 rotate_vector_by_quaternion( const quaternion& lhs, const vector3& rhs );