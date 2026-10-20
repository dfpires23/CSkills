#include "sum_integer_bytes.h"
#include <stdio.h>

int main(void) {
    unsigned int d = 0xAABBCCDD;

    printf("Sum=%d\n", sum_integer_bytes(&d));
    return 0;
}
