.section .text
.global func2

func2:
    addi sp, sp, -32
    sw ra, 28(sp)
    sw s0, 24(sp)
    sw s1, 20(sp)
    sw s2, 16(sp)
    sw s3, 12(sp)
    sw s4, 8(sp)

    mv s0, a0
    mv s1, a1
    mv s2, a2
    li s4, 0

loop:
    lb s3, 0(s0)
    beqz s3, end

    beqz s2, end

    mv a0, s3
    call func1

    beqz a0, next

    sb s3, 0(s1)

    addi s1, s1, 1
    addi s2, s2, -1
    addi s4, s4, 1

next:
    addi s0, s0, 1
    j loop

end:
    sb zero, 0(s1)
    mv a0, s4

    lw s4, 8(sp)
    lw s3, 12(sp)
    lw s2, 16(sp)
    lw s1, 20(sp)
    lw s0, 24(sp)
    lw ra, 28(sp)
    addi sp, sp, 32

    ret
