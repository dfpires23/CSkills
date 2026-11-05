.section .text
	.global compute

compute:
	mul t0, a0, a1
	mul t1, a0, a2
	sub a0, t0, t1
	div a0, a0, a3
	ret
