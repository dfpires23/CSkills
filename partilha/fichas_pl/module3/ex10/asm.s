.section .text
	.global str_cat

str_cat:
loop1:
    lbu t0, 0(a0)
    beqz t0, loop2
    sb t0, 0(a2)
    addi a0, a0, 1
    addi a2, a2, 1
    j loop1

loop2:
    lbu t0, 0(a1)
    sb t0, 0(a2)
    beqz t0, end
    addi a1, a1, 1
    addi a2, a2, 1
    j loop2

end:
    ret
