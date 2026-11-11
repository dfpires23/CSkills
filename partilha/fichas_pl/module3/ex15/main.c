#include "asm.h"
#include <stdio.h>

int main(void) {
    long long arr[] = {0x123456789ABCDEF0, 0x1122334455667788};
    int num = 2;
    int res;

    res = sum_third_byte(arr, num);

    printf("res = %d: 0x%x\n", res, res);

    return 0;
}