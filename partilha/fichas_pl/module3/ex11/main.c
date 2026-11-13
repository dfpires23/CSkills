#include "asm.h"
#include <stdio.h>

int main(void) {
    int vec[] = {10, 5, 10, 60, 80, 12};

    int res = vec_greater12(vec, 6);
    printf("res = %d:0x%x\n", res, res);

    return 0;
}
