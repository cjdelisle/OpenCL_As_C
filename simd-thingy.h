#pragma once

#ifndef __OPENCL_C_VERSION__
#include <stdint.h>
typedef uint64_t ulong;
#endif

typedef struct {
    ulong x[8];
} ULong8_t;

void mul(ULong8_t* out, ULong8_t* x, ULong8_t* y);