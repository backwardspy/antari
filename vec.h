#pragma once

#include <stdint.h>

typedef int64_t vt;

typedef union {
    struct
    {
        vt x, y;
    };
    vt v[2];
} vec2_t;

typedef union {
    struct
    {
        vt x, y, z;
    };
    struct
    {
        vt r, g, b;
    };

    vt v[3];
} vec3_t;

vec2_t vec2(vt x, vt y)
{
    vec2_t v;
    v.x = x;
    v.y = y;
    return v;
}

vec2_t vec2_add(vec2_t a, vec2_t b)
{
    return vec2(a.x + b.x, a.y + b.y);
}

vec2_t vec2_sub(vec2_t a, vec2_t b)
{
    return vec2(a.x - b.x, a.y - b.y);
}

vec2_t vec2_mul(vec2_t a, vt b)
{
    return vec2(a.x * b, a.y * b);
}

vec2_t vec2_div(vec2_t a, vt b)
{
    return vec2(a.x / b, a.y / b);
}

vt vec2_len2(vec2_t v)
{
    return v.x * v.x + v.y * v.y;
}

vt vec2_len(vec2_t v)
{
    return sqrt(vec2_len2(v));
}

vt vec2_dot(vec2_t a, vec2_t b)
{
    return a.x * b.x + a.y * b.y;
}

vec3_t vec3(vt x, vt y, vt z)
{
    vec3_t v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}

vec3_t vec3_add(vec3_t a, vec3_t b)
{
    return vec3(a.x + b.x, a.y + b.y, a.z + b.z);
}

vec3_t vec3_sub(vec3_t a, vec3_t b)
{
    return vec3(a.x - b.x, a.y - b.y, a.z - b.z);
}

vec3_t vec3_mul(vec3_t a, vt b)
{
    return vec3(a.x * b, a.y * b, a.z * b);
}

vec3_t vec3_div(vec3_t a, vt b)
{
    return vec3(a.x / b, a.y / b, a.z / b);
}

vt vec3_len2(vec3_t v)
{
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

vt vec3_len(vec3_t v)
{
    return sqrt(vec3_len2(v));
}

vt vec3_dot(vec3_t a, vec3_t b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

vec3_t vec3_cross(vec3_t a, vec3_t b)
{
    return vec3(
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x);
}
