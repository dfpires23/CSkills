#include "asm.h"
#include <stdio.h>

int main(void) {
    int num = 10;
    short op1[num];

    for (int i = 0; i < num; i++) {
        printf("Valor op1[%d]: ", i);
        scanf("%hd", &op1[i]);
    }

    vec_add_three(op1, num);

    printf("res: ");

    for (int i = 0; i < num; i++) {
        printf("%hd ", op1[i]);
    }

    printf("\n");

    return 0;
}