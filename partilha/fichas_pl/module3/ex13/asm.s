.section .text
	.global keep_positives

keep_positives:
	li t0, 0
	
loop:
	bge t0, a1, end
	lw t1, 0(a0)
	
	bgez t1, next
	
	sw t0, 0(a0)
	
next:
	addi a0, a0, 4
	addi t0, t0, 1
	
	j loop

end:
	ret
