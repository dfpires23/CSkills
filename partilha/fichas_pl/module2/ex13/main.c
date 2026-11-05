#include <stdio.h>
#include "asm.h"

int main(void) {
	int op1, op2, op3, res;
	
	printf("Valor op1: ");
	scanf("%d", &op1);
	
	printf("Valor op2: ");
	scanf("%d", &op2);
	
	printf("Valor op3: ");
	scanf("%d", &op3);
	
	res = get_area(op1, op2, op3);
	printf("res = %d:0x%x\n", res, res);
	
	return 0;
}

