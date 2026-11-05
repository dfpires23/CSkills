.section .text
	.global new_salary

new_salary:
	li t0, 10
	beq a1, t0, manager
	
	li t0, 11
	beq a1, t0, engineer
	
	li t0, 12
	beq a1, t0, technician
	
	addi a0, a0, 250
	ret

manager:	
	addi a0, a0, 500
	ret

engineer:	
	addi a0, a0, 400
	ret

technician:	
	addi a0, a0, 300
	ret
