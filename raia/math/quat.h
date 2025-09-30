#include "common.h"
#include "vec3.h"

class quaternion {
public:
	float x, y, w, z;
};

inline vector3 rotate_vector_by_quaternion( const quaternion& lhs, const vector3& rhs ) {
    float x = lhs.x * 2.f;
    float y = lhs.y * 2.f;
    float z = lhs.z * 2.f;
    float xx = lhs.x * x;
    float yy = lhs.y * y;
    float zz = lhs.z * z;
    float xy = lhs.x * y;
    float xz = lhs.x * z;
    float yz = lhs.y * z;
    float wx = lhs.w * x;
    float wy = lhs.w * y;
    float wz = lhs.w * z;

    vector3 result;

    result.x = ( 1.f - ( yy + zz ) ) * rhs.x + ( xy - wz ) * rhs.y + ( xz + wy ) * rhs.z;
    result.y = ( xy + wz ) * rhs.x + ( 1.f - ( xx + zz ) ) * rhs.y + ( yz - wx ) * rhs.z;
    result.z = ( xz - wy ) * rhs.x + ( yz + wx ) * rhs.y + ( 1.f - ( xx + yy ) ) * rhs.z;

    return result;
}