.section .text
	.global big_sum

big_sum:
	add a0, a0, a2
	sltu t1, a0, a2
	add t0, a1, a3
	add a1, t0, t1
	ret
