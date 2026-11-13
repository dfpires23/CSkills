.section .data
	.equ CONST, 20

.section .text
	.global sum2
	.global sum3

sum2:
	add a0, a0, a0
	add a0, a0, a1
	ret

sum3:
	add a0, a0, a0
	sub a0, a0, a1
	addi a0, a0, -CONST
	ret
