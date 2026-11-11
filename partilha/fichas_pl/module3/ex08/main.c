#include "vec_sum_even.h"
#include <stdio.h>

int main(void) {
    int op1[] = {1, 2, 3, 4, 5, 6};
    int num = 6;

    int res = vec_sum_even(op1, num);

    printf("res = %d:0x%x\n", res, res);

    return 0;
}
