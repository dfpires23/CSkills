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

    mv s0, a0       # cars
    mv s1, a1       # n
    mv s2, a2       # fill
    li s3, 0        # i = 0
    li s4, 0        # count = 0

loop:
    bge s3, s1, end

    mv a0, s0
    call func1

    beqz a0, next

    sw s0, 0(s2)    # fill[count] = &cars[i]
    addi s2, s2, 4  # PrÃ³xima posiÃ§Ã£o de fill
    addi s4, s4, 1  # count++

next:
    addi s0, s0, 4  # PrÃ³ximo carro
    addi s3, s3, 1  # i++
    j loop

end:
    mv a0, s4       # return count

    lw s4, 8(sp)
    lw s3, 12(sp)
    lw s2, 16(sp)
    lw s1, 20(sp)
    lw s0, 24(sp)
    lw ra, 28(sp)
    addi sp, sp, 32

    ret
