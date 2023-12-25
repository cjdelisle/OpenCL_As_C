// SPDX-License-Identifier: MIT OR APACHE2

#ifdef __OPENCL_C_VERSION__

#include "NativeCl.h"

#else

// tags which don't mean anything in C
#define __constant
#define __kernel
#define __global
#define __local
#define __private
#define __read_only
#define __write_only
#define __read_write

// size_t is explicitly defined in opencl, but nothing else from stdint.h
typedef __SIZE_TYPE__ size_t;
typedef char bool;
typedef int size_t;

// Assume we have 64 bit
#define cl_khr_int64
#define cl_khr_fp64

#include "Vector.h"

#endif