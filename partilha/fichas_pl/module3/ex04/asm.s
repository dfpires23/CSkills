.section .text
	.global vec_add_three

vec_add_three:
loop:
    blez a1, end

    lh t0, 0(a0)
    addi t0, t0, 3
    sh t0, 0(a0)

    addi a0, a0, 2
    addi a1, a1, -1
    j loop

end:
    ret
