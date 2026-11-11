.section .text
	.global vec_greater12

vec_greater12:
	li t0, 0
	
loop:
	blez a1, end
	lw t1, 0(a0)
	
	li t2, 12
	ble t1, t2, next
	
	addi t0, t0, 1
	
next:
	addi a0, a0, 4
	addi a1, a1, -1
	
	j loop

end:
	mv a0, t0
	ret
