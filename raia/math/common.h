#pragma once

#define _pow2( x ) ( x * x )

#define _USE_MATH_DEFINES

#include <math.h>

namespace math {
    inline constexpr float rad2deg( float rad ) {
        return rad * ( 180.f / M_PI );
    }

    inline float lerp( float from, float to, float t ) {
        return to * t + from * ( 1.f - t );
    }
}