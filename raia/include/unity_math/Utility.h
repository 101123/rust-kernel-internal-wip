#pragma once

#include "IntegerDefinitions.h"

#define SAFE_RELEASE(obj) { if (obj) { (obj)->Release(); (obj) = NULL; } else {} }

template<class T>
inline T clamp(const T&t, const T& t0, const T& t1)
{
    if (t < t0)
        return t0;
    else if (t > t1)
        return t1;
    else
        return t;
}

template<>
inline float clamp(const float&t, const float& t0, const float& t1)
{
    if (t < t0)
        return t0;
    else if (t > t1)
        return t1;
    else
        return t;
}

template<class T>
inline T clamp01(const T& t)
{
    if (t < 0)
        return 0;
    else if (t > 1)
        return 1;
    else
        return t;
}

template<>
inline float clamp01<float>(const float& t)
{
    if (t < 0.0F)
        return 0.0F;
    else if (t > 1.0F)
        return 1.0F;
    else
        return t;
}

template<class T>
static inline bool inRange(const T& value, const T& a, const T& b)
{
    return a <= value && value <= b;
}

// a good use of this is safe upcasting for type disambiguation. static_cast<> will work too, but it's too broad - it casts among "related types", which is often unsafe.
template<typename TTo, typename TFrom>
inline TTo implicit_cast(TFrom value)
{
    // a compile error here means that there is no automatic conversion TFrom -> TTo
    return value;
}

inline float SmoothStep(float from, float to, float t)
{
    t = clamp01(t);
    t = -2.0F * t * t * t + 3.0F * t * t;
    return to * t + from * (1.0f - t);
}

// Rounds value down.
// Note: base must be power of two value.
inline UInt32 RoundDown(UInt32 value, SInt32 base)
{
    return value & (-base);
}

// Rounds value up.
// Note: base must be power of two value.
inline UInt32 RoundUp(UInt32 value, SInt32 base)
{
    return (value + base - 1) & (-base);
}

inline UInt64 RoundUp64(UInt64 value, SInt64 base)
{
    return (value + base - 1) & (-base);
}

// Rounds value up.
// Note: multiple does not need to be a power of two value.
template<class DataType>
inline DataType RoundUpMultiple(DataType value, DataType multiple)
{
    return ((value + multiple - 1) / multiple) * multiple;
}

// Compare Less for circular value.
inline bool CircularLessThan(uint32_t a, uint32_t b) // a < b
{
    if (a != b)
        return (b - a) < (uint32_t(1) << (sizeof(uint32_t) * 8 - 1)); // 1 << 31 = 0x80000000
    else
        return false;
}

template<class T>
inline T* Stride(T* p, size_t offset)
{
    return reinterpret_cast<T*>((char*)p + offset);
}

template<typename T>
bool AreAllObjectsInArrayNonNull(T* const * objects, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (objects[i] == NULL)
            return false;
    }

    return true;
}

template<typename T>
inline void Swap(T& a, T& b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

// Euclid's algorithm:
// https://en.wikipedia.org/wiki/Euclidean_algorithm
inline UInt32 GreatestCommonDenominator(UInt32 a, UInt32 b)
{
    for (;;)
    {
        if (a == 0)
            return b;
        b %= a;
        if (b == 0)
            return a;
        a %= b;
    }

    return 0;
}

inline UInt32 LeastCommonMultiple(UInt32 a, UInt32 b)
{
    UInt32 temp = GreatestCommonDenominator(a, b);
    return temp ? (a / temp * b) : 0;
}

inline UInt32 Log10(const UInt32 value)
{
    if (value < 1000000)
    {
        if (value < 1000)
        {
            if (value < 10)
                return 0;

            return (value < 100) ? 1 : 2;
        }

        if (value < 10000)
            return 3;

        return (value < 100000) ? 4 : 5;
    }

    if (value < 100000000)
        return (value < 10000000) ? 6 : 7;

    return (value < 1000000000) ? 8 : 9;
}