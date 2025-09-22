#pragma once

#include "common.h"

class vector2 {
public:
	float x, y;

	vector2() : x( 0.f ), y( 0.f ) {};
	vector2( float _x, float _y ) : x( _x ), y( _y ) {};

	vector2& operator+=( const vector2& value ) {
		x += value.x; y += value.y; return *this;
	}

	vector2& operator-=( const vector2& value ) {
		x -= value.x; y -= value.y; return *this;
	}

	vector2& operator*=( float value ) {
		x *= value; y *= value; return *this;
	}

	vector2& operator/=( float value ) {
		x /= value; y /= value; return *this;
	}
};

inline vector2 operator+( const vector2& lhs, const vector2& rhs ) {
	return vector2( lhs.x + rhs.x, lhs.y + rhs.y );
}

inline vector2 operator-( const vector2& lhs, const vector2& rhs ) {
	return vector2( lhs.x - rhs.x, lhs.y - rhs.y );
}

inline vector2 operator*( const vector2& lhs, const float rhs ) {
	return vector2( lhs.x * rhs, lhs.y * rhs );
}

inline vector2 operator*( const float lhs, const vector2& rhs ) {
	return vector2( rhs.x * lhs, rhs.y * lhs );
}

inline vector2 operator*( const vector2& lhs, const vector2& rhs ) {
	return vector2( lhs.x * rhs.x, lhs.y * rhs.y );
}

inline vector2 operator/( const vector2& lhs, const float rhs ) {
	vector2 vec( lhs ); vec /= rhs; return vec;
}

inline float dot( const vector2& lhs, const vector2& rhs ) {
	return lhs.x * rhs.x + lhs.y * rhs.y;
}

inline float sqr_magnitude( const vector2& vec ) {
	return dot( vec, vec );
}

inline float magnitude( const vector2& vec ) {
	return sqrtf( dot( vec, vec ) );
}

inline float distance( const vector2& lhs, const vector2& rhs ) {
	return magnitude( lhs - rhs );
}

inline float sqr_distance( const vector2& lhs, const vector2& rhs ) {
	return sqr_magnitude( lhs - rhs );
}

inline vector2 normalize( const vector2& vec ) {
	return vec / magnitude( vec );
}

inline float angle( const vector2& lhs, const vector2& rhs ) {
	return acosf( fminf( 1.0f, fmaxf( -1.0f, dot( lhs, rhs ) / ( magnitude( lhs ) * magnitude( rhs ) ) ) ) );
}

inline vector2 lerp( const vector2& from, const vector2& to, float t ) {
	return to * t + from * ( 1.f - t );
}

class vector2i {
public:
	int x, y;

	vector2i() : x( 0 ), y( 0 ) {};
	vector2i( int _x, int _y ) : x( _x ), y( _y ) {};
};