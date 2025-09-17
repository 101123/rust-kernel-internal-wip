#pragma once

#include "common.h"

class Vector2 {
public:
	float x, y;

	Vector2() : x( 0.f ), y( 0.f ) {};
	Vector2( float _x, float _y ) : x( _x ), y( _y ) {};

	Vector2& operator+=( const Vector2& value ) {
		x += value.x; y += value.y; return *this;
	}

	Vector2& operator-=( const Vector2& value ) {
		x -= value.x; y -= value.y; return *this;
	}

	Vector2& operator*=( float value ) {
		x *= value; y *= value; return *this;
	}

	Vector2& operator/=( float value ) {
		x /= value; y /= value; return *this;
	}
};

inline Vector2 operator+( const Vector2& lhs, const Vector2& rhs ) {
	return Vector2( lhs.x + rhs.x, lhs.y + rhs.y );
}

inline Vector2 operator-( const Vector2& lhs, const Vector2& rhs ) {
	return Vector2( lhs.x - rhs.x, lhs.y - rhs.y );
}

inline Vector2 operator*( const Vector2& lhs, const float rhs ) {
	return Vector2( lhs.x * rhs, lhs.y * rhs );
}

inline Vector2 operator*( const float lhs, const Vector2& rhs ) {
	return Vector2( rhs.x * lhs, rhs.y * lhs );
}

inline Vector2 operator*( const Vector2& lhs, const Vector2& rhs ) {
	return Vector2( lhs.x * rhs.x, lhs.y * rhs.y );
}

inline Vector2 operator/( const Vector2& lhs, const float rhs ) {
	Vector2 vec( lhs ); vec /= rhs; return vec;
}

inline float dot( const Vector2& lhs, const Vector2& rhs ) {
	return lhs.x * rhs.x + lhs.y * rhs.y;
}

inline float sqr_magnitude( const Vector2& vec ) {
	return dot( vec, vec );
}

inline float magnitude( const Vector2& vec ) {
	return sqrtf( dot( vec, vec ) );
}

inline float distance( const Vector2& lhs, const Vector2& rhs ) {
	return magnitude( lhs - rhs );
}

inline float sqr_distance( const Vector2& lhs, const Vector2& rhs ) {
	return sqr_magnitude( lhs - rhs );
}

inline Vector2 normalize( const Vector2& vec ) {
	return vec / magnitude( vec );
}

inline float angle( const Vector2& lhs, const Vector2& rhs ) {
	return acosf( fminf( 1.0f, fmaxf( -1.0f, dot( lhs, rhs ) / ( magnitude( lhs ) * magnitude( rhs ) ) ) ) );
}

inline Vector2 lerp( const Vector2& from, const Vector2& to, float t ) {
	return to * t + from * ( 1.f - t );
}

class Vector2i {
public:
	int x, y;

	Vector2i() : x( 0 ), y( 0 ) {};
	Vector2i( int _x, int _y ) : x( _x ), y( _y ) {};
};