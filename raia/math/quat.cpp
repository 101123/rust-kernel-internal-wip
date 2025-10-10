#include "quat.h"

#include <unity_math/Quaternion.h>

const quaternion quaternion::identity = quaternion( 0.f, 0.f, 0.f, 1.f );

bool look_rotation_to_quaternion( const vector3& forward, const vector3& up, quaternion& result ) {
	return LookRotationToQuaternion( *( const Vector3f* )&forward, *( const Vector3f* )&up, ( Quaternionf* )&result );
}

vector3 rotate_vector_by_quaternion( const quaternion& lhs, const vector3& rhs ) {
	Vector3f result = RotateVectorByQuat( *( const Quaternionf* )&lhs, *( const Vector3f* )&rhs );
	return *( vector3* )&result;
}
