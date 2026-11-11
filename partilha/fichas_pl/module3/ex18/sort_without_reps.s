.section .text
.global sort_without_reps

sort_without_reps:
    addi sp, sp, -16

    sw ra, 12(sp)
    sw s1, 8(sp)
    sw s2, 4(sp)

    mv s1, a1
    mv s2, a2

    call array_copy

    mv a0, s1
    mv a1, s2
    call array_sort

    mv a0, s1
    mv a1, s2
    call array_remove_duplicates

end:
    lw s2, 4(sp)
    lw s1, 8(sp)
    lw ra, 12(sp)

    addi sp, sp, 16
    ret
