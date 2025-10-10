#pragma once

#include <intrin.h>

typedef __m128 Simd128;

// Load / Save
#   define V4LoadUnaligned(base, offset)            _mm_loadu_ps((base)+(offset))
#   define V4StoreUnaligned(value, base, offset)    _mm_storeu_ps((base)+(offset), value)

// Math functions
#   define V4Add(v0, v1)        _mm_add_ps((v0), (v1))
#   define V4Mul(v0, v1)        _mm_mul_ps((v0), (v1))
#   define V4MulAdd(v0, v1, v2) _mm_add_ps(_mm_mul_ps((v0), (v1)), (v2))

// Shuffling / Permuting / Splatting / Merging
#   define V4Splat(v0, i)           _mm_shuffle_ps((v0), (v0), _MM_SHUFFLE(i,i,i,i))

// Attention! : these are done after PPC big-endian specs.
#   define V4MergeL(v0, v1)         _mm_unpackhi_ps((v0), (v1))
#   define V4MergeH(v0, v1)         _mm_unpacklo_ps((v0), (v1))