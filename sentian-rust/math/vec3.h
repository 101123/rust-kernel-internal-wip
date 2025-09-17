#pragma once

#include "common.h"

class Vector3 {
public:
	float x, y, z;

	Vector3() : x( 0.f ), y( 0.f ), z( 0.f ) {};
	Vector3( float _x, float _y, float _z ) : x( _x ), y( _y ), z( _z ) {};

	float* get_ptr() {
		return &x;
	}

	const float* get_ptr() const {
		return &x;
	}

	Vector3 operator+( const Vector3& value ) const {
		return Vector3( x + value.x, y + value.y, z + value.z );
	}

	Vector3& operator+=( const Vector3& value ) {
		x += value.x; y += value.y; z += value.z; return *this; 
	}

	Vector3 operator-( const Vector3& value ) const {
		return Vector3( x - value.x, y - value.y, z - value.z );
	}

	Vector3& operator-=( const Vector3& value ) {
		x -= value.x; y -= value.y; z -= value.z; return *this; 
	}

	Vector3 operator*( float value ) const {
		return Vector3( x * value, y * value, z * value );
	}

	Vector3& operator*=( float value ) { 
		x *= value; y *= value; z *= value; return *this; 
	}

	Vector3 operator/( const float value ) const {
		return Vector3( x / value, y / value, z / value );
	}

	Vector3& operator/=( float value ) {
		x /= value; y /= value; z /= value; return *this;
	}

	static Vector3 cross( const Vector3& lhs, const Vector3& rhs ) {
		return Vector3(
			lhs.y * rhs.z - lhs.z * rhs.y,
			lhs.z * rhs.x - lhs.x * rhs.z,
			lhs.x * rhs.y - lhs.y * rhs.x
		);
	}

	static float dot( const Vector3& lhs, const Vector3& rhs ) {
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	}

	static float sqr_magnitude( const Vector3& vec ) {
		return dot( vec, vec );
	}

	static float magnitude( const Vector3& vec ) {
		return sqrtf( dot( vec, vec ) );
	}

	static float distance( const Vector3& lhs, const Vector3& rhs ) {
		return magnitude( lhs - rhs );
	}

	static float sqr_distance( const Vector3& lhs, const Vector3& rhs ) {
		return sqr_magnitude( lhs - rhs );
	}

	static Vector3 normalize( const Vector3& vec ) {
		return vec / magnitude( vec );
	}

	static float angle( const Vector3& lhs, const Vector3& rhs ) {
		return acosf( fminf( 1.0f, fmaxf( -1.0f, dot( lhs, rhs ) / ( magnitude( lhs ) * magnitude( rhs ) ) ) ) );
	}

	static Vector3 lerp( const Vector3& from, const Vector3& to, float t ) {
		return to * t + from * ( 1.f - t );
	}

	static const float epsilon;
};

//Vector3 ortho_normal_vector_fast( const Vector3& n );
//Vector3 slerp( const Vector3& lhs, const Vector3& rhs, float t );

