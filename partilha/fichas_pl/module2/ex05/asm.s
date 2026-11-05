.section .text
	.global parallel

parallel:
	mul t0, a0, a1
	add t1, a0, a1
	div a0, t0, t1
	ret
