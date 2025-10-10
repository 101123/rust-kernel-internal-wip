#pragma once

#include "common.h"
#include "vec3.h"

class quaternion {
public:
	float x, y, w, z;

	static const quaternion identity;
};

bool look_rotation_to_quaternion( const vector3& forward, const vector3& up, quaternion& result );
vector3 rotate_vector_by_quaternion( const quaternion& lhs, const vector3& rhs );