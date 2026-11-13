.section .text
    .global vec_sum

vec_sum:
    li t0, 0

loop:
    blez a1, end
    lw t1, 0(a0)
    add t0, t0, t1
    addi a0, a0, 4
    addi a1, a1, -1
    j loop

end:
    mv a0, t0
    ret
