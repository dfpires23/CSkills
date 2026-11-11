#include "asm.h"
#include <stdio.h>

int main(void) {
    char op1[100];
	char op2[100];

    printf("Valor op1: ");
    scanf("%99s", op1);

    str_copy_roman(op1, op2);
	printf("res = %s\n", op2);

    return 0;
}