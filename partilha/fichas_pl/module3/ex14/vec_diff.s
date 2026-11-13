.section .text
    .global vec_diff

vec_diff:
    addi sp, sp, -32
    sw ra, 28(sp)
    sw s0, 24(sp)
    sw s1, 20(sp)
    sw s2, 16(sp)
    sw s3, 12(sp)

    mv s0, a0
    mv s1, a1
    li s2, 0
    li s3, 0
    mv s4, s0

loop:
    bge s3, s1, end

    mv a0, s0
    mv a1, s1
    lw a2, 0(s4)

    call exists

    xori a0, a0, 1
    add s2, s2, a0

    addi s4, s4, 4
    addi s3, s3, 1
    j loop

end:
    mv a0, s2

    lw s3, 12(sp)
    lw s2, 16(sp)
    lw s1, 20(sp)
    lw s0, 24(sp)
    lw ra, 28(sp)
    addi sp, sp, 32

    ret
