#include <stdio.h>

#include "simd-thingy.h"

void printvec(ULong8_t* v) {
    printf("[");
    for (int i = 0; i < 8; i++) { printf("%lld,", v->x[i]); }
    printf("]\n");
}

int main() {
    ULong8_t x = { .x = { 0,1,2,3,4,5,6,7 } };
    ULong8_t y = { .x = { 8,9,10,11,12,13,14,15 } };
    ULong8_t z = {};
    printvec(&x);
    printf("TIMES\n");
    printvec(&y);
    printf("EQUALS\n");
    mul(&z, &x, &y);
    printvec(&z);
}