.section .text
	.global test_even

test_even:
	li t0, 2
	rem a0, a0, t0
	
	bnez a0, false
	li a0, 1
	ret
	
false:
	li a0, 0
	ret
