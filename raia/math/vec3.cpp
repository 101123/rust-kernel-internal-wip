#include "vec3.h"

const float vector3::epsilon = 0.00001f;

const vector3 vector3::up = vector3( 0.f, 1.f, 0.f );
const vector3 vector3::down = vector3( 0.f, -1.f, 0.f );
const vector3 vector3::left = vector3( -1.f, 0.f, 0.f );
const vector3 vector3::right = vector3( 1.f, 0.f, 0.f );
const vector3 vector3::forward = vector3( 0.f, 0.f, 1.f );
const vector3 vector3::back = vector3( 0.f, 0.f, -1.f );
const vector3 vector3::zero = vector3( 0.f, 0.f, 0.f );