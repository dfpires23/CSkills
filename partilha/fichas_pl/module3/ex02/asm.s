.section .text
	.global str_copy_roman

str_copy_roman:
loop:
    lbu t0, 0(a0)
    beqz t0, end

    li t1, 'u'
    bne t0, t1, copy

    li t0, 'v'

copy:
    sb t0, 0(a1)

    addi a0, a0, 1
    addi a1, a1, 1
    j loop

end:
    sb zero, 0(a1)
    ret
