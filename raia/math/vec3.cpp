#include "vec3.h"
#include "mat3x3.h"

const float vector3::epsilon = 0.00001f;

const vector3 vector3::up = vector3( 0.f, 1.f, 0.f );
const vector3 vector3::down = vector3( 0.f, -1.f, 0.f );
const vector3 vector3::left = vector3( -1.f, 0.f, 0.f );
const vector3 vector3::right = vector3( 1.f, 0.f, 0.f );
const vector3 vector3::forward = vector3( 0.f, 0.f, 1.f );
const vector3 vector3::back = vector3( 0.f, 0.f, -1.f );

//vector3 ortho_normal_vector_fast( const vector3& n ) {
//	if ( fabsf( n.z ) > 0.7071067811865475244008443621048490f ) {
//		float a = n.y * n.y + n.z * n.z;
//		float k = 1.f / sqrtf( a );
//		return vector3( 0.f, -n.z * k, n.y * k );
//	}
//
//	else {
//		float a = n.x * n.x + n.y * n.y;
//		float k = 1.f / sqrtf( a );
//		return vector3( -n.y * k, n.x * k, 0.f );
//	}
//}
//
//vector3 slerp( const vector3& lhs, const vector3& rhs, float t ) {
//	float lhs_mag = magnitude( lhs );
//	float rhs_mag = magnitude( rhs );
//	if ( lhs_mag < vector3::epsilon || rhs_mag < vector3::epsilon )
//		return lerp( lhs, rhs, t );
//
//	float lerped_mag = lerp( lhs_mag, rhs_mag, t );
//	float dir = dot( lhs, rhs ) / ( lhs_mag * rhs_mag );
//	if ( dir > 1.f - vector3::epsilon ) {
//		return lerp( lhs, rhs, t );
//	}
//
//	else if ( dir < -1.f + vector3::epsilon ) {
//		vector3 lhs_norm = lhs / lhs_mag;
//		vector3 axis = ortho_normal_vector_fast( lhs_norm );
//		matrix3x3 m;
//		m.set_axis_angle( axis, 3.14159265358979323846264338327950288419716939937510f * t );
//		vector3 slerped = m.multiply( lhs_norm );
//		slerped *= lerped_mag;
//		return slerped;
//	}
//
//	else {
//		vector3 axis = cross( lhs, rhs );
//		vector3 lhs_norm = lhs / lhs_mag;
//		axis = normalize( axis );
//		float angle = acosf( dir ) * t;
//		matrix3x3 m;
//		m.set_axis_angle( axis, angle );
//		vector3 slerped = m.multiply( lhs_norm );
//		slerped *= lerped_mag;
//		return slerped;
//	}
//}