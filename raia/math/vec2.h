#pragma once

#include "common.h"

class vector2 {
public:
	float x, y;

	vector2() : x( 0.f ), y( 0.f ) {};
	vector2( float _x, float _y ) : x( _x ), y( _y ) {};

	float* get_ptr() {
		return &x;
	}

	const float* get_ptr() const {
		return &x;
	}

	vector2 operator+( const vector2& value ) const {
		return vector2( x + value.x, y + value.y );
	}

	vector2& operator+=( const vector2& value ) {
		x += value.x; y += value.y; return *this;
	}

	vector2 operator-( const vector2& value ) const {
		return vector2( x - value.x, y - value.y );
	}

	vector2& operator-=( const vector2& value ) {
		x -= value.x; y -= value.y; return *this;
	}

	vector2 operator*( float value ) const {
		return vector2( x * value, y * value );
	}

	vector2& operator*=( float value ) {
		x *= value; y *= value; return *this;
	}

	vector2 operator/( const float value ) const {
		return vector2( x / value, y / value );
	}

	vector2& operator/=( float value ) {
		x /= value; y /= value; return *this;
	}

	static float dot( const vector2& lhs, const vector2& rhs ) {
		return lhs.x * rhs.x + lhs.y * rhs.y;
	}

	static float sqr_magnitude( const vector2& vec ) {
		return dot( vec, vec );
	}

	static float magnitude( const vector2& vec ) {
		return sqrtf( dot( vec, vec ) );
	}

	static float distance( const vector2& lhs, const vector2& rhs ) {
		return magnitude( lhs - rhs );
	}

	static float sqr_distance( const vector2& lhs, const vector2& rhs ) {
		return sqr_magnitude( lhs - rhs );
	}

	static vector2 normalize( const vector2& vec ) {
		return vec / magnitude( vec );
	}
};

class vector2i {
public:
	int x, y;

	vector2i() : x( 0 ), y( 0 ) {};
	vector2i( int _x, int _y ) : x( _x ), y( _y ) {};
};