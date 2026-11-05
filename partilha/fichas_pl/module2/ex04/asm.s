.section .text
    .global three_halves

three_halves:
    li t0, 3
    mul t1, a0, t0
    li t0, 2
    div a0, t1, t0
    ret