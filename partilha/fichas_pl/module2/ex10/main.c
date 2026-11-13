#include <stdio.h>
#include "asm.h"

int main(void) {
	long long op1, op2, res;
	
	printf("Valor op1: ");
	scanf("%lld", &op1);
	
	printf("Valor op2: ");
	scanf("%lld", &op2);
	
	res = big_sum(op1, op2);
	printf("res = %lld:0x%llx\n", res, res);
	
	return 0;
}
