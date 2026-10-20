#include "compress.h"
#include <stdio.h>

int main(void) {
    int vec_ints[] = {10, 20, 30, 40};
    long long vec_longs[2];

    compress(vec_ints, 4, vec_longs);

    for (int i = 0; i < 2; i++) {
        printf("%lld ", *(vec_longs + i));
    }
    printf("\n");

    return 0;
}
