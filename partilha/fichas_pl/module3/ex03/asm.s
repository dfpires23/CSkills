.section .text
	.global str_copy_roman2

str_copy_roman2:
loop:
    lbu t0, 0(a0)
    beqz t0, end

    li t1, 'u'
    bne t0, t1, check_upper

    li t0, 'v'
    j copy

check_upper:
    li t1, 'U'
    bne t0, t1, copy

    li t0, 'V'

copy:
    sb t0, 0(a1)

    addi a0, a0, 1
    addi a1, a1, 1
    j loop

end:
    sb zero, 0(a1)
    ret
