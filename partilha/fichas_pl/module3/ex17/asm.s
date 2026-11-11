.section .text
	.global array_sort

array_sort:
    li t0, 0

outer_loop:
    addi t1, a1, -1
    bge t0, t1, end

    li t2, 0

inner_loop:
    addi t3, a1, -1
    sub t3, t3, t0

    bge t2, t3, next_outer

    slli t4, t2, 2
    add t4, a0, t4

    lw t5, 0(t4)
    lw t6, 4(t4)

    blt t5, t6, swap

continue:
    addi t2, t2, 1
    j inner_loop

swap:
    sw t6, 0(t4)
    sw t5, 4(t4)
    j continue

next_outer:
    addi t0, t0, 1
    j outer_loop

end:
    ret
