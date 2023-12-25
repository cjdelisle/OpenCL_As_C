// SPDX-License-Identifier: MIT OR APACHE2
#include "simd-thingy.h"

#include "ide/Ide.h"

static void mul_cl(ulong8* out, ulong8* x, ulong8* y) {
    N(*out) = N(*x) * N(*y);
}

void mul(ULong8_t* out, ULong8_t* x, ULong8_t* y) {
    mul_cl((ulong8*)out, (ulong8*)x, (ulong8*)y);
}