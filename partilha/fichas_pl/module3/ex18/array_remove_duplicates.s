.section .text
    .global array_remove_duplicates

array_remove_duplicates:
    blez a1, empty_array

    li t0, 0
    li t1, 1

remove_loop:
    bge t1, a1, remove_end

    slli t2, t0, 1
    add t2, a0, t2

    slli t3, t1, 1
    add t3, a0, t3

    lh t4, 0(t2)
    lh t5, 0(t3)

    beq t4, t5, skip_duplicate

    addi t0, t0, 1

    slli t2, t0, 1
    add t2, a0, t2

    sh t5, 0(t2)

skip_duplicate:
    addi t1, t1, 1
    j remove_loop

remove_end:
    addi a0, t0, 1
    ret

empty_array:
    li a0, 0
    ret
