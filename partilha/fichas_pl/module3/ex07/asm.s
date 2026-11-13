.section .text
    .global encrypt
    .global decrypt

encrypt:
    li t0, 0

loop_1:
    lbu t1, 0(a0)
    beqz t1, end_1

    li t2, 'a'
    beq t1, t2, next_1

    li t2, ' '
    beq t1, t2, next_1

    addi t1, t1, 1
    sb t1, 0(a0)
    addi t0, t0, 1

next_1:
    addi a0, a0, 1
    j loop_1

end_1:
    mv a0, t0
    ret


decrypt:
    li t0, 0

loop_2:
    lbu t1, 0(a0)
    beqz t1, end_2

    li t2, 'a'
    beq t1, t2, next_2

    li t2, ' '
    beq t1, t2, next_2

    addi t1, t1, -1
    sb t1, 0(a0)
    addi t0, t0, 1

next_2:
    addi a0, a0, 1
    j loop_2

end_2:
    mv a0, t0
    ret
