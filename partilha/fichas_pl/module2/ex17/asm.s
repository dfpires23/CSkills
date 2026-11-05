.section .data
    .equ A, 3
    .equ B, 4

.section .text
    .global sigma

sigma:
    li t0, 1
    li t1, A
    mul t2, t1, t1
    mul t2, t2, t1
    li t3, 0
    li t4, B

loop:
    bgt t0, a0, end

    mul t5, t0, t0
    mul t5, t5, t2
    div t5, t5, t4
    add t3, t3, t5

    addi t0, t0, 1
    j loop

end:
    mv a0, t3
    ret