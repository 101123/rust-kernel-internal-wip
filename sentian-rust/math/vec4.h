#pragma once

#include "vec3.h"

class Vector4 {
public:
	float x, y, z, w;

	Vector4() : x( 0.f ), y( 0.f ), z( 0.f ), w( 0.f ) {};
	Vector4( float _x, float _y, float _z, float _w ) : x( _x ), y( _y ), z( _z ), w( _w ) {};

	float* get_ptr() {
		return &x;
	}

	const float* get_ptr() const {
		return &x;
	}
};

inline Vector4 operator*( const Vector4& lhs, const Vector4& rhs ) {
	return Vector4( lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w );
}

inline Vector4 operator*( const Vector4& lhs, const float rhs ) {
	return Vector4( lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs );
}

inline Vector4 operator+( const Vector4& lhs, const Vector4& rhs ) {
	return Vector4( lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w );
}

inline Vector4 operator-( const Vector4& lhs, const Vector4& rhs ) {
	return Vector4( lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w );
}

inline Vector4 lerp( const Vector4& from, const Vector4& to, float t ) {
	return to * t + from * ( 1.f - t );
}

class Vector4i {
public:
	int x, y, z, w;

	Vector4i() : x( 0 ), y( 0 ), z( 0 ), w( 0 ) {};
	Vector4i( int _x, int _y, int _z, int _w ) : x( _x ), y( _y ), z( _z ), w( _w ) {};
};