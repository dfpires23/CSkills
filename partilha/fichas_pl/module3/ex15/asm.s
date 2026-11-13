.section .text
	.global sum_third_byte

sum_third_byte:
	li t0, 0

loop:
	blez a1, end
	
	lb t1, 2(a0)
	add t0, t0, t1
	
	addi a0, a0, 8
	addi a1, a1, -1
	
	j loop

end:
	mv a0, t0
	ret
