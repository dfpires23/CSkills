.section .text
	.global time_sec

time_sec:
	li t0, 3600
	mul a0, a0, t0
	li t1, 60
	mul a1, a1, t1
	add a0, a0, a1
	add a0, a0, a2
	ret
