.section .text
	.global array_copy

array_copy:
loop:
    blez a2, end_copy

    lh t0, 0(a0)
    sh t0, 0(a1)

    addi a0, a0, 2
    addi a1, a1, 2
    addi a2, a2, -1

    j loop

end_copy:
    ret
