.section .text
	.global steps

steps:
	mv t0, a0
	li t1, 3
	mul a0, a0, t1
	addi a0, a0, 6
	div a0, a0, t1
	addi a0, a0, 12
	sub a0, a0, t0
	li t2, 4
	sub a0, a0, t2
	ret
