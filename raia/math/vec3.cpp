#include "vec3.h"

#include <unity_math/Vector3.h>

const float vector3::epsilon = 0.00001f;

const vector3 vector3::up = vector3( 0.f, 1.f, 0.f );
const vector3 vector3::down = vector3( 0.f, -1.f, 0.f );
const vector3 vector3::left = vector3( -1.f, 0.f, 0.f );
const vector3 vector3::right = vector3( 1.f, 0.f, 0.f );
const vector3 vector3::forward = vector3( 0.f, 0.f, 1.f );
const vector3 vector3::back = vector3( 0.f, 0.f, -1.f );
const vector3 vector3::zero = vector3( 0.f, 0.f, 0.f );

vector3 vector3::slerp( const vector3& a, const vector3 b, float t ) {
	Vector3f value = Slerp( *( const Vector3f* )&a, *( const Vector3f* )&b, t );
	return *( vector3* )&value;
}