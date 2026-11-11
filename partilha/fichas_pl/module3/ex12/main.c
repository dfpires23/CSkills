#include "asm.h"
#include <stdio.h>

int main(void) {
    int vec[] = {10, 50, 25, 60, 80, 12};

    unsigned char res = vec_zero(vec, 6);
    printf("res = %hhu:0x%x\n", res, res);

    return 0;
}
