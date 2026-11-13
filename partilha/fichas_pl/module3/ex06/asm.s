.section .text
	.global encrypt

encrypt:
    li t0, 0

loop:
    lbu t1, 0(a0)
    beqz t1, end

    li t2, 'a'
    beq t1, t2, next

    li t2, ' '
    beq t1, t2, next

    addi t1, t1, 1
    sb t1, 0(a0)
    addi t0, t0, 1

next:
    addi a0, a0, 1
    j loop

end:
    mv a0, t0
    ret
