#include "asm.h"
#include <stdio.h>

int main(void) {
    int res;
    char op1[100];

    printf("Valor op1: ");
    scanf("%99s", op1);

    res = five_count(op1);

    printf("res = %d:0x%x\n", res, res);

    return 0;
}