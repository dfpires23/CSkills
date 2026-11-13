.section .text
	.global vec_sum_even

vec_sum_even:
    addi sp, sp, -32
    sw ra, 28(sp)
    sw s0, 24(sp)
    sw s1, 20(sp)
    sw s2, 16(sp)
    sw s3, 8(sp)

    mv s0, a0
    mv s1, zero
    mv s2, a1

loop:
    blez s2, end

    lw s3, 0(s0)
    mv a0, s3

    call test_even

    beqz a0, next

    add s1, s1, s3

next:
    addi s0, s0, 4
    addi s2, s2, -1
    j loop

end:
    mv a0, s1

	lw s3, 12(sp)
    lw s2, 16(sp)
    lw s1, 20(sp)
    lw s0, 24(sp)
    lw ra, 28(sp)
    addi sp, sp, 32

    ret
