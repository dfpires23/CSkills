.section .text
	.global frequencies

frequencies:
    li t0, 0

init:
    li t1, 21
    bge t0, t1, next_loop

    slli t2, t0, 2
    add t2, a2, t2
    sw zero, 0(t2)

    addi t0, t0, 1
    j init

next_loop:
    li t3, 0

loop:
    bge t3, a1, end

    lb t4, 0(a0)

    slli t5, t4, 2
    add t5, a2, t5

    lw t6, 0(t5)
    addi t6, t6, 1
    sw t6, 0(t5)

    addi a0, a0, 1
    addi t3, t3, 1
    j loop

end:
    ret
