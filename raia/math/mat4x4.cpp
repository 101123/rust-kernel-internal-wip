#include "mat4x4.h"

void quaternion_to_matrix( const quaternion& q, matrix4x4& m ) {
    float x = q.x * 2.f;
    float y = q.y * 2.f;
    float z = q.z * 2.f;
    float xx = q.x * x;
    float yy = q.y * y;
    float zz = q.z * z;
    float xy = q.x * y;
    float xz = q.x * z;
    float yz = q.y * z;
    float wx = q.w * x;
    float wy = q.w * y;
    float wz = q.w * z;

    m.data[ 0 ] = 1.f - ( yy + zz );
    m.data[ 1 ] = xy + wz;
    m.data[ 2 ] = xz - wy;
    m.data[ 3 ] = 0.f;

    m.data[ 4 ] = xy - wz;
    m.data[ 5 ] = 1.f - ( xx + zz );
    m.data[ 6 ] = yz + wx;
    m.data[ 7 ] = 0.f;

    m.data[ 8 ] = xz + wy;
    m.data[ 9 ] = yz - wx;
    m.data[ 10 ] = 1.f - ( xx + yy );
    m.data[ 11 ] = 0.f;

    m.data[ 12 ] = 0.f;
    m.data[ 13 ] = 0.f;
    m.data[ 14 ] = 0.f;
    m.data[ 15 ] = 1.f;
}

matrix4x4 matrix4x4::trs( const vector3& pos, const quaternion& q, const vector3& s ) {
    matrix4x4 m;
    quaternion_to_matrix( q, m );

    m.data[ 0 ] *= s[ 0 ];
    m.data[ 1 ] *= s[ 0 ];
    m.data[ 2 ] *= s[ 0 ];

    m.data[ 4 ] *= s[ 1 ];
    m.data[ 5 ] *= s[ 1 ];
    m.data[ 6 ] *= s[ 1 ];

    m.data[ 8 ] *= s[ 2 ];
    m.data[ 9 ] *= s[ 2 ];
    m.data[ 10 ] *= s[ 2 ];

    m.data[ 12 ] = pos[ 0 ];
    m.data[ 13 ] = pos[ 1 ];
    m.data[ 14 ] = pos[ 2 ];

    return m;
}