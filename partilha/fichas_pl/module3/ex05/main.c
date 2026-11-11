#include "vec_avg.h"
#include <stdio.h>

int main(void) {
    short num = 3;
    int op1[num];
	int res;

    for (int i = 0; i < num; i++) {
        printf("Valor op1[%d]: ", i);
        scanf("%d", &op1[i]);
    }

    res = vec_avg(op1, num);

    printf("res = %d:0x%x\n", res, res);

    return 0;
}
