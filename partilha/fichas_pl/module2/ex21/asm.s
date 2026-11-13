.section .text
	.global f
	.global f2
	.global f3
	.global f4

f:
	bne a0, a1, else_f
	
	sub t0, a0, a1
	addi t0, t0, 1
	mv a0, t0
	ret

else_f:
	add t0, a0, a1
	addi t0, t0, -1
	mv a0, t0
	ret

f2:
	ble a0, a1, else_f2
	
	addi a0, a0, -1
	mul a0, a0, a1
	ret

else_f2:
	addi a1, a1, 1
	mul a0, a0, a1
	ret
	
f3:
	blt a0, a1, else_f3
	
	mul t0, a0, a1
	addi t1, a0, 1
	div a0, t1, t0
	ret
	
else_f3:
	add t0, a0, a1
	addi t1, t0, 2
	div a0, t1, t0
	ret
	
f4:
    add t0, a0, a1
    
	li t1, 10
    bge t0, t1, else_f4

    mul t2, a0, a0
    li t1, 4
    mul a0, t2, t1
    ret

else_f4:
    mul t0, a1, a1
    li t1, 3
    div a0, t0, t1
    ret
