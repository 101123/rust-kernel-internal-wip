#include "quat.h"
#include "mat3x3.h"

const quaternion quaternion::identity = quaternion( 0.f, 0.f, 0.f, 1.f );

void matrix_to_quaternion( const matrix3x3& rot, quaternion& q ) {
    float trace = rot.get( 0, 0 ) + rot.get( 1, 1 ) + rot.get( 2, 2 ), root;

    if ( trace > 0.f ) {
        // |w| > 1/2, may as well choose w > 1/2
        root = sqrtf( trace + 1.0f ); // 2w
        q.w = 0.5f * root;
        root = 0.5f / root; // 1/(4w)
        q.x = ( rot.get( 2, 1 ) - rot.get( 1, 2 ) ) * root;
        q.y = ( rot.get( 0, 2 ) - rot.get( 2, 0 ) ) * root;
        q.z = ( rot.get( 1, 0 ) - rot.get( 0, 1 ) ) * root;
    }

    else {
        // |w| <= 1/2
        int next[ 3 ] = { 1, 2, 0 };
        int i = 0;
        if ( rot.get( 1, 1 ) > rot.get( 0, 0 ) )
            i = 1;
        if ( rot.get( 2, 2 ) > rot.get( i, i ) )
            i = 2;
        int j = next[ i ];
        int k = next[ j ];

        root = sqrtf( rot.get( i, i ) - rot.get( j, j ) - rot.get( k, k ) + 1.0f );
        float* apk_quat[ 3 ] = { &q.x, &q.y, &q.z };
        *apk_quat[ i ] = 0.5f * root;
        root = 0.5f / root;
        q.w = ( rot.get( k, j ) - rot.get( j, k ) ) * root;
        *apk_quat[ j ] = ( rot.get( j, i ) + rot.get( i, j ) ) * root;
        *apk_quat[ k ] = ( rot.get( k, i ) + rot.get( i, k ) ) * root;
    }

    q = quaternion::normalize( q );
}

bool look_rotation_to_quaternion( const vector3& forward, const vector3& up, quaternion& result ) {
    matrix3x3 m;
    if ( !matrix3x3::look_rotation_to_matrix( forward, up, m ) )
        return false;

    matrix_to_quaternion( m, result );
    return true;
}

vector3 rotate_vector_by_quaternion( const quaternion& lhs, const vector3& rhs ) {
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
