.section .data
	.equ A, 4
	.equ B, 3
	
.section .text
	.global needed_time

needed_time:
	li t0, A
	li t1, B
	sub t2, a1, a0
	li t3, 60
	
	bgtz t2, increase
	bltz t2, decrease
	
	li a0, 0
	ret

increase:
	mul a0, t2, t1
	mul a0, a0, t3
	ret
	
decrease:
	neg t2, t2
	mul a0, t2, t0
	mul a0, a0, t3
	ret
