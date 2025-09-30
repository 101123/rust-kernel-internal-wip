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

	vector3 operator/( const float value ) const {
		return vector3( x / value, y / value, z / value );
	}

	vector3& operator/=( float value ) {
		x /= value; y /= value; z /= value; return *this;
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
		return vec / magnitude( vec );
	}

	static float angle( const vector3& lhs, const vector3& rhs ) {
		return acosf( fminf( 1.0f, fmaxf( -1.0f, dot( lhs, rhs ) / ( magnitude( lhs ) * magnitude( rhs ) ) ) ) );
	}

	static vector3 lerp( const vector3& from, const vector3& to, float t ) {
		return to * t + from * ( 1.f - t );
	}

	static const float epsilon;
};

//vector3 ortho_normal_vector_fast( const vector3& n );
//vector3 slerp( const vector3& lhs, const vector3& rhs, float t );

