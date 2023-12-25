// SPDX-License-Identifier: MIT OR APACHE2
#pragma once

#include "ide/Ide.h"

typedef struct {
    ulong x[8];
} ULong8_t;

void mul(ULong8_t* out, ULong8_t* x, ULong8_t* y);