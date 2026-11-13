.section .text
	.global count_max

count_max:
    addi a1, a1, -2
    li t0, 0

loop:
    blez a1, end

    lw t1, 0(a0)
    lw t2, 4(a0)
    lw t3, 8(a0)

    bge t1, t2, next
    ble t2, t3, next

    addi t0, t0, 1

next:
    addi a0, a0, 4
    addi a1, a1, -1

    j loop

end:
    mv a0, t0
    ret
