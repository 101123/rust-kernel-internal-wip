#pragma once

#include "vec3.h"

class Matrix3x3 {
public:
	union {
		float data[ 3 * 3 ];
		Vector3 vec[ 3 ];
	};

	Matrix3x3() {};
	Matrix3x3( Vector3 a, Vector3 b, Vector3 c ) {
		vec[ 0 ] = a;
		vec[ 1 ] = b;
		vec[ 2 ] = c;
	}

	float& get( int row, int column ) { 
		return data[ row + ( column * 3 ) ]; 
	}

	const float& get( int row, int column ) const { 
		return data[ row + ( column * 3 ) ]; 
	}

	float operator[]( int index ) const {
		return data[ index ];
	}

	float& operator[]( int index ) {
		return data[ index ];
	}

	Vector3 multiply( const Vector3& v ) const {
		Vector3 res;
		res.x = data[ 0 ] * v.x + data[ 3 ] * v.y + data[ 6 ] * v.z;
		res.y = data[ 1 ] * v.x + data[ 4 ] * v.y + data[ 7 ] * v.z;
		res.z = data[ 2 ] * v.x + data[ 5 ] * v.y + data[ 8 ] * v.z;
		return res;
	}

	Matrix3x3& set_axis_angle( const Vector3& rotation_axis, float radians );
};