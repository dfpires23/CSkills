#include <stdio.h>
#include "asm.h"

int main(void) {
	int op1, res;
	
	printf("Valor op1: ");
	scanf("%d", &op1);
	
	res = six_packs(op1);
	printf("res = %d:0x%x\n", res, res);
	
	return 0;
}

