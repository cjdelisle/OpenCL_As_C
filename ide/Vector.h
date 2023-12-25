// SPDX-License-Identifier: MIT OR APACHE2
#pragma once

#define __CBUILD__
#include "_kernel_c.h"

#define Vector_S01(type) \
    type s0; \
    type s1
#define Vector_S012(type) \
    Vector_S01(type); \
    type s2
#define Vector_S0123(type) \
    Vector_S012(type); \
    type s3
#define Vector_S01234567(type) \
    Vector_S0123(type); \
    type s4; \
    type s5; \
    type s6; \
    type s7
#define Vector_S0123456789abcdef(type) \
    Vector_S01234567(type); \
    type s8; \
    type s9; \
    type sa; \
    type sb; \
    type sc; \
    type sd; \
    type se; \
    type sf

#define Vector_2S0123(type) \
    type ## 2 s01; \
    type ## 2 s23
#define Vector_2S01234567(type) \
    Vector_2S0123(type); \
    type ## 2 s45; \
    type ## 2 s67
#define Vector_2S0123456789abcdef(type) \
    Vector_2S01234567(type); \
    type ## 2 s89; \
    type ## 2 sab; \
    type ## 2 scd; \
    type ## 2 sef

#define Vector_4S01234567(type) \
    type ## 4 s0123; \
    type ## 4 s4567
#define Vector_4S0123456789abcdef(type) \
    Vector_4S01234567(type) \
    type ## 4 s89ab; \
    type ## 4 scdef

#define Vector_8S0123456789abcdef(type) \

#define Vector_XY(type) \
    type x; \
    type y
#define Vector_XYZ(type) \
    Vector_XY(type); \
    type z
#define Vector_XYZW(type) \
    Vector_XYZ(type); \
    type w

#define Vector_MK_AB(type) \
    type a, type b
#define Vector_MK_ABC(type) \
    Vector_MK_AB(type), type c
#define Vector_MK_ABCD(type) \
    Vector_MK_ABC(type), type d
#define Vector_MK_ABCDEFGH(type) \
    Vector_MK_ABCD(type), type e, type f, type g, type h
#define Vector_MK_ABCDEFGHIJKLMNOP(type) \
    Vector_MK_ABCDEFGH(type), type i, type j, type k, type l, type m, type n, type o, type p

#define Vector_GET1(vec, index) ((vec).Vector_one)
#define Vector_GET2(vec, index) ((vec).Vector_two)
#define Vector_GET4(vec, index) ((vec).Vector_four)
#define Vector_GET8(vec, index) ((vec).Vector_eight)

#define Vector_MK_X2(type) \
    typedef type Vector_ ## type ## 2  __attribute__((__ext_vector_type__(2))); \
    typedef union { \
        type Vector_one; \
        struct { \
            type hi; \
            type lo; \
        }; \
        struct { \
            type even; \
            type odd; \
        }; \
        Vector_ ## type ## 2 num; \
    } type ## 2; \
    static inline type ## 2 Vector_mk ## type ## 2x1(Vector_MK_AB(type)) { \
        return (type ## 2) { }; \
    }

#define Vector_MK_X3(type) \
    Vector_MK_X2(type); \
    typedef type Vector_ ## type ## 3  __attribute__((__ext_vector_type__(3))); \
    typedef union { \
        type Vector_one; \
        type ## 2 Vector_two; \
        Vector_ ## type ## 3 num; \
    } type ## 3; \
    static inline type ## 3 Vector_mk ## type ## 3x1(Vector_MK_ABC(type)) { \
        return (type ## 3) { }; \
    }

#define Vector_MK_X4(type) \
    Vector_MK_X3(type); \
    typedef type Vector_ ## type ## 4  __attribute__((__ext_vector_type__(4))); \
    typedef union { \
        type Vector_one; \
        type ## 2 Vector_two; \
        struct { \
            type ## 2 hi; \
            type ## 2 lo; \
        }; \
        struct { \
            type ## 2 even; \
            type ## 2 odd; \
        }; \
        type ## 4 num; \
    } type ## 4; \
    static inline type ## 4 Vector_mk ## type ## 4x1(Vector_MK_ABCD(type)) { \
        return (type ## 4) { }; \
    } \
    static inline type ## 4 Vector_mk ## type ## 4x2(Vector_MK_AB(type ## 2)) { \
        return (type ## 4) { }; \
    }

#define Vector_MK_X8(type) \
    Vector_MK_X4(type); \
    typedef type Vector_ ## type ## 8  __attribute__((__ext_vector_type__(8))); \
    typedef union { \
        type Vector_one; \
        type ## 2 Vector_two; \
        type ## 4 Vector_four; \
        struct { \
            type ## 4 hi; \
            type ## 4 lo; \
        }; \
        struct { \
            type ## 4 even; \
            type ## 4 odd; \
        }; \
        Vector_ ## type ## 8 num; \
    } type ## 8; \
    static inline type ## 8 Vector_mk ## type ## 8x1(Vector_MK_ABCDEFGH(type)) { \
        return (type ## 8) { }; \
    } \
    static inline type ## 8 Vector_mk ## type ## 8x2(Vector_MK_ABCD(type ## 2)) { \
        return (type ## 8) { }; \
    } \
    static inline type ## 8 Vector_mk ## type ## 8x4(Vector_MK_AB(type ## 4)) { \
        return (type ## 8) { }; \
    }

#define Vector_MK_X16(type) \
    Vector_MK_X8(type); \
    typedef type Vector_ ## type ## 16  __attribute__((__ext_vector_type__(16))); \
    typedef union { \
        type Vector_one; \
        type ## 2 Vector_two; \
        type ## 4 Vector_four; \
        type ## 8 Vector_eight; \
        struct { \
            type ## 8 hi; \
            type ## 8 lo; \
        }; \
        struct { \
            type ## 8 even; \
            type ## 8 odd; \
        }; \
        Vector_ ## type ## 16 num; \
    } type ## 16; \
    static inline type ## 16 Vector_mk ## type ## 16x1(Vector_MK_ABCDEFGHIJKLMNOP(type)) { \
        return (type ## 16) { }; \
    } \
    static inline type ## 16 Vector_mk ## type ## 16x2(Vector_MK_ABCDEFGH(type ## 2)) { \
        return (type ## 16) { }; \
    } \
    static inline type ## 16 Vector_mk ## type ## 16x4(Vector_MK_ABCD(type ## 4)) { \
        return (type ## 16) { }; \
    } \
    static inline type ## 16 Vector_mk ## type ## 16x8(Vector_MK_AB(type ## 8)) { \
        return (type ## 16) { }; \
    }

Vector_MK_X16(char)
Vector_MK_X16(uchar);

Vector_MK_X16(short);
Vector_MK_X16(ushort);

Vector_MK_X16(int);
Vector_MK_X16(uint);

Vector_MK_X16(long);
Vector_MK_X16(ulong);

Vector_MK_X16(float);
Vector_MK_X16(double);

#ifdef __INTELLISENSE__
#define N(vec) ((vec).num)
#else
#define N(vec) (vec)
#endif

__attribute__((unused))
static void Vector_static_assertion() {
    #define Vector_static_assert(a) struct { int x[(a)]; }

    Vector_static_assert(sizeof(uchar) == 1);
    Vector_static_assert(sizeof(ushort) == 2);
    Vector_static_assert(sizeof(uint) == 4);
    Vector_static_assert(sizeof(ulong) == 8);

    Vector_static_assert(sizeof(char) == 1);
    Vector_static_assert(sizeof(short) == 2);
    Vector_static_assert(sizeof(int) == 4);
    Vector_static_assert(sizeof(long) == 8);

    {
        char2 x;
        char2 y;
        N(x) += N(y);
        Vector_static_assert(sizeof x == 2);
        Vector_static_assert(sizeof Vector_GET1(x, x) == 1);
        Vector_static_assert(sizeof x.hi == 1);
        Vector_static_assert(sizeof x.lo == 1);
    }

    {
        char3 x;
        Vector_static_assert(sizeof x == 2);
        // Vector_static_assert(sizeof x.x == 1);
        // Vector_static_assert(sizeof x.y == 1);
        // Vector_static_assert(sizeof x.z == 1);
        // Vector_static_assert(sizeof x.s0 == 1);
        // Vector_static_assert(sizeof x.s1 == 1);
        // Vector_static_assert(sizeof x.s2 == 1);
    }

    {
        char4 x;
        Vector_static_assert(sizeof x == 4);
        // Vector_static_assert(sizeof x.x == 1);
        // Vector_static_assert(sizeof x.y == 1);
        // Vector_static_assert(sizeof x.z == 1);
        // Vector_static_assert(sizeof x.w == 1);
        // Vector_static_assert(sizeof x.s0 == 1);
        // Vector_static_assert(sizeof x.s1 == 1);
        // Vector_static_assert(sizeof x.s2 == 1);
        // Vector_static_assert(sizeof x.s3 == 1);
        Vector_static_assert(sizeof x.hi == 2);
        Vector_static_assert(sizeof x.lo == 2);
        Vector_static_assert(sizeof x.even == 2);
        Vector_static_assert(sizeof x.odd == 2);
    }

    {
        char8 x;
        Vector_static_assert(sizeof x == 8);
        // Vector_static_assert(sizeof x.x == 1);
        // Vector_static_assert(sizeof x.y == 1);
        // Vector_static_assert(sizeof x.z == 1);
        // Vector_static_assert(sizeof x.w == 1);
        // Vector_static_assert(sizeof x.s0 == 1);
        // Vector_static_assert(sizeof x.s1 == 1);
        // Vector_static_assert(sizeof x.s2 == 1);
        // Vector_static_assert(sizeof x.s3 == 1);
        // Vector_static_assert(sizeof x.s4 == 1);
        // Vector_static_assert(sizeof x.s5 == 1);
        // Vector_static_assert(sizeof x.s6 == 1);
        // Vector_static_assert(sizeof x.s7 == 1);
        Vector_static_assert(sizeof x.hi == 4);
        Vector_static_assert(sizeof x.lo == 4);
        Vector_static_assert(sizeof x.even == 4);
        Vector_static_assert(sizeof x.odd == 4);
    }

    #undef Vector_static_assert
}