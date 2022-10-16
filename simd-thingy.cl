#include "simd-thingy.h"

static void mul_cl(ulong8* out, ulong8* x, ulong8* y) {
    *out = *x * *y;
}

void mul(ULong8_t* out, ULong8_t* x, ULong8_t* y) {
    mul_cl((ulong8*)out, (ulong8*)x, (ulong8*)y);
}