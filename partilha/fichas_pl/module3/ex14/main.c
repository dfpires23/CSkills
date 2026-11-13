#include "vec_diff.h"
#include <stdio.h>

int main(void) {
    int arr[] = {1, 5, 3, 5, 7};

    int res = vec_diff(arr, 5);
    printf("res = %d:0x%x\n", res, res);

    return 0;
}
