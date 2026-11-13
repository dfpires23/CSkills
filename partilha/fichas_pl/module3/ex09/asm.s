.section .text
    .global vec_search

vec_search:
loop:
    blez a1, end

    lw t0, 0(a0)
    beq t0, a2, found

    addi a0, a0, 4
    addi a1, a1, -1
    j loop

found:
    ret

end:
    li a0, 0
    ret
