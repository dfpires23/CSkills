.section .text
    .global exists

exists:
    li t0, 0

loop:
    blez a1, end
    lw t1, 0(a0)

    bne t1, a2, next
    addi t0, t0, 1

	li t2, 2
    beq t0, t2, found

next:
    addi a0, a0, 4
    addi a1, a1, -1
    j loop

found:
    li a0, 1
    ret

end:
    li a0, 0
    ret
