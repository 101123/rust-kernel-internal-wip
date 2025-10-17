#pragma once

#include "common.h"

class vector3 {
public:
	float x, y, z;

	vector3() : x( 0.f ), y( 0.f ), z( 0.f ) {};
	vector3( float _x, float _y, float _z ) : x( _x ), y( _y ), z( _z ) {};

	float* get_ptr() {
		return &x;
	}

	const float* get_ptr() const {
		return &x;
	}

	vector3 operator+( const vector3& value ) const {
		return vector3( x + value.x, y + value.y, z + value.z );
	}

	vector3& operator+=( const vector3& value ) {
		x += value.x; y += value.y; z += value.z; return *this; 
	}

	vector3 operator-( const vector3& value ) const {
		return vector3( x - value.x, y - value.y, z - value.z );
	}

	vector3& operator-=( const vector3& value ) {
		x -= value.x; y -= value.y; z -= value.z; return *this; 
	}

	vector3 operator*( float value ) const {
		return vector3( x * value, y * value, z * value );
	}

	vector3& operator*=( float value ) { 
		x *= value; y *= value; z *= value; return *this; 
	}

	vector3 operator*( const vector3& value ) {
		return vector3( x * value.x, y * value.y, z * value.z );
	}

	vector3 operator/( const float value ) const {
		return vector3( x / value, y / value, z / value );
	}

	vector3& operator/=( float value ) {
		x /= value; y /= value; z /= value; return *this;
	}

	bool operator==( const vector3 value ) {
		return x == value.x && y == value.y && z == value.z;
	}

	static vector3 cross( const vector3& lhs, const vector3& rhs ) {
		return vector3(
			lhs.y * rhs.z - lhs.z * rhs.y,
			lhs.z * rhs.x - lhs.x * rhs.z,
			lhs.x * rhs.y - lhs.y * rhs.x
		);
	}

	static float dot( const vector3& lhs, const vector3& rhs ) {
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	}

	static float sqr_magnitude( const vector3& vec ) {
		return dot( vec, vec );
	}

	static float magnitude( const vector3& vec ) {
		return sqrtf( dot( vec, vec ) );
	}

	static float distance( const vector3& lhs, const vector3& rhs ) {
		return magnitude( lhs - rhs );
	}

	static float sqr_distance( const vector3& lhs, const vector3& rhs ) {
		return sqr_magnitude( lhs - rhs );
	}

	static vector3 normalize( const vector3& vec ) {
		float length = magnitude( vec );
		if ( length == 0.f ) {
			return vector3();
		}

		return vec / magnitude( vec );
	}

	static float angle( const vector3& lhs, const vector3& rhs ) {
		return acosf( fminf( 1.0f, fmaxf( -1.0f, dot( lhs, rhs ) / ( magnitude( lhs ) * magnitude( rhs ) ) ) ) );
	}

	static vector3 lerp( const vector3& from, const vector3& to, float t ) {
		return to * t + from * ( 1.f - t );
	}

	static vector3 move_towards( const vector3& from, const vector3& to, float distance ) {
		vector3 delta = to - from;
		float sqr_delta = sqr_magnitude( delta );
		float sqr_distance = _pow2( distance );

		if ( sqr_delta > sqr_distance ) {
			float delta_magnitude = sqrtf( sqr_delta );

			if ( delta_magnitude > vector3::epsilon ) {
				return from + delta / delta_magnitude * distance;
			}

			else {
				return from;
			}
		}

		return to;
	}

	static vector3 slerp( const vector3& a, const vector3 b, float t );

	static const float epsilon;

	static const vector3 up;
	static const vector3 down;
	static const vector3 left;
	static const vector3 right;
	static const vector3 forward;
	static const vector3 back;
	static const vector3 zero;
};