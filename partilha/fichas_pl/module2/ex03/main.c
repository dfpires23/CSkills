#include <stdio.h>
#include "asm.h"

int main(void) {
	int op1, op2, res2, res3;
	
	printf("Valor op1: ");
	scanf("%d", &op1);
	
	printf("Valor op2: ");
	scanf("%d", &op2);
	
	res2 = sum2(op1, op2);
	printf("res2 = %d:0x%x\n", res2, res2);
	
	res3 = sum3(op1, op2);
	printf("res3 = %d:0x%x\n", res3, res3);
	
	return 0;
}

