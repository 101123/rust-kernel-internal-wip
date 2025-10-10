#include "mat4x4.h"

#include <unity_math/Matrix4x4.h>

matrix4x4 matrix4x4::trs( const vector3& pos, const quaternion& q, const vector3& s ) {
	Matrix4x4f matrix;
	matrix.SetTRS( *( const Vector3f* )&pos, *( const Quaternionf* )&q, *( const Vector3f* )&s );
	return *( matrix4x4* )&matrix;
}