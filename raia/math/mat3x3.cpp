#include "mat3x3.h"

void GetRotMatrixNormVec( float* out, const float* inVec, float radians )
{
    /* This function contributed by Erich Boleyn (erich@uruk.org) */
    /* This function used from the Mesa OpenGL code (matrix.c)  */
    float s, c;
    float vx, vy, vz, xx, yy, zz, xy, yz, zx, xs, ys, zs, one_c;

    s = sin( radians );
    c = cos( radians );

    vx = inVec[ 0 ];
    vy = inVec[ 1 ];
    vz = inVec[ 2 ];

#define M(row, col)  out[row*3 + col]
    /*
    *     Arbitrary axis rotation matrix.
    *
    *  This is composed of 5 matrices, Rz, Ry, T, Ry', Rz', multiplied
    *  like so:  Rz * Ry * T * Ry' * Rz'.  T is the final rotation
    *  (which is about the X-axis), and the two composite transforms
    *  Ry' * Rz' and Rz * Ry are (respectively) the rotations necessary
    *  from the arbitrary axis to the X-axis then back.  They are
    *  all elementary rotations.
    *
    *  Rz' is a rotation about the Z-axis, to bring the axis vector
    *  into the x-z plane.  Then Ry' is applied, rotating about the
    *  Y-axis to bring the axis vector parallel with the X-axis.  The
    *  rotation about the X-axis is then performed.  Ry and Rz are
    *  simply the respective inverse transforms to bring the arbitrary
    *  axis back to its original orientation.  The first transforms
    *  Rz' and Ry' are considered inverses, since the data from the
    *  arbitrary axis gives you info on how to get to it, not how
    *  to get away from it, and an inverse must be applied.
    *
    *  The basic calculation used is to recognize that the arbitrary
    *  axis vector (x, y, z), since it is of unit length, actually
    *  represents the sines and cosines of the angles to rotate the
    *  X-axis to the same orientation, with theta being the angle about
    *  Z and phi the angle about Y (in the order described above)
    *  as follows:
    *
    *  cos ( theta ) = x / sqrt ( 1 - z^2 )
    *  sin ( theta ) = y / sqrt ( 1 - z^2 )
    *
    *  cos ( phi ) = sqrt ( 1 - z^2 )
    *  sin ( phi ) = z
    *
    *  Note that cos ( phi ) can further be inserted to the above
    *  formulas:
    *
    *  cos ( theta ) = x / cos ( phi )
    *  sin ( theta ) = y / cos ( phi )
    *
    *  ...etc.  Because of those relations and the standard trigonometric
    *  relations, it is pssible to reduce the transforms down to what
    *  is used below.  It may be that any primary axis chosen will give the
    *  same results (modulo a sign convention) using thie method.
    *
    *  Particularly nice is to notice that all divisions that might
    *  have caused trouble when parallel to certain planes or
    *  axis go away with care paid to reducing the expressions.
    *  After checking, it does perform correctly under all cases, since
    *  in all the cases of division where the denominator would have
    *  been zero, the numerator would have been zero as well, giving
    *  the expected result.
    */

    xx = vx * vx;
    yy = vy * vy;
    zz = vz * vz;
    xy = vx * vy;
    yz = vy * vz;
    zx = vz * vx;
    xs = vx * s;
    ys = vy * s;
    zs = vz * s;
    one_c = 1.0F - c;

    M( 0, 0 ) = ( one_c * xx ) + c;
    M( 1, 0 ) = ( one_c * xy ) - zs;
    M( 2, 0 ) = ( one_c * zx ) + ys;

    M( 0, 1 ) = ( one_c * xy ) + zs;
    M( 1, 1 ) = ( one_c * yy ) + c;
    M( 2, 1 ) = ( one_c * yz ) - xs;

    M( 0, 2 ) = ( one_c * zx ) - ys;
    M( 1, 2 ) = ( one_c * yz ) + xs;
    M( 2, 2 ) = ( one_c * zz ) + c;

#undef M
}

bool compare_approximately( float f0, float f1, float epsilon = 0.000001f ) {
    return fabsf( f0 - f1 ) <= epsilon;
}

void matrix3x3::set_identity( matrix3x3& m ) {
    m.get( 0, 0 ) = 1.f; m.get( 0, 1 ) = 0.f; m.get( 0, 2 ) = 0.f;
    m.get( 1, 0 ) = 0.f; m.get( 1, 1 ) = 1.f; m.get( 1, 2 ) = 0.f;
    m.get( 2, 0 ) = 0.f; m.get( 2, 1 ) = 0.f; m.get( 2, 2 ) = 1.f;
}

void matrix3x3::set_basis( matrix3x3& m, const vector3& x, const vector3& y, const const vector3& z ) {
    m.get( 0, 0 ) = x[ 0 ]; m.get( 0, 1 ) = y[ 0 ]; m.get( 0, 2 ) = z[ 0 ];
    m.get( 1, 0 ) = x[ 1 ]; m.get( 1, 1 ) = y[ 1 ]; m.get( 1, 2 ) = z[ 1 ];
    m.get( 2, 0 ) = x[ 2 ]; m.get( 2, 1 ) = y[ 2 ]; m.get( 2, 2 ) = z[ 2 ];
}

void matrix3x3::set_axis_angle( matrix3x3& matrix, const vector3& rotation_axis, float radians ) {
    GetRotMatrixNormVec( matrix.data, rotation_axis.get_ptr(), radians );
}

vector3 matrix3x3::multiply( const matrix3x3& matrix, const vector3& v ) {
    vector3 result;
    result.x = matrix.data[ 0 ] * v.x + matrix.data[ 3 ] * v.y + matrix.data[ 6 ] * v.z;
    result.y = matrix.data[ 1 ] * v.x + matrix.data[ 4 ] * v.y + matrix.data[ 7 ] * v.z;
    result.z = matrix.data[ 2 ] * v.x + matrix.data[ 5 ] * v.y + matrix.data[ 8 ] * v.z;
    return result;
}

bool matrix3x3::look_rotation_to_matrix( const vector3& view, const vector3& up, matrix3x3& m ) {
    vector3 z = view;

    float mag = vector3::magnitude( z );
    if ( mag < vector3::epsilon ) {
        matrix3x3::set_identity( m );
        return false;
    }

    z /= mag;

    vector3 x = vector3::cross( up, z );
    mag = vector3::magnitude( x );
    if ( mag < vector3::epsilon ) {
        matrix3x3::set_identity( m );
        return false;
    }

    x /= mag;

    vector3 y( vector3::cross( z, x ) );
    if ( !compare_approximately( vector3::sqr_magnitude( y ), 1.f ) )
        return false;

    matrix3x3::set_basis( m, x, y, z );
    return true;
}