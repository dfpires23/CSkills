.section .text
	.global swap

swap:
loop:
	blez a2, end
	
	lb t0, 0(a0)
	lb t1, 0(a1)
	
	sb t1, 0(a0)
	sb t0, 0(a1)
	
	addi a0, a0, 1
	addi a1, a1, 1
	addi a2, a2, -1
	
	j loop

end:
	ret
