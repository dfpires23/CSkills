.section .text
.global five_count

five_count:
    li t0, 0

loop:
    lbu t1, 0(a0)
    beqz t1, end

    li t2, '5'
    bne t1, t2, next
    addi t0, t0, 1

next:
    addi a0, a0, 1
    j loop

end:
    mv a0, t0
    ret
