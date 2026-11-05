.section .text
	.global check_num

check_num:
    li t0, 2
    rem t1, a0, t0

    bltz a0, negative
    beqz t1, even_pos

    li a0, 4
    ret

even_pos:
    li a0, 3
    ret

negative:
    beqz t1, even_neg

    li a0, 2
    ret

even_neg:
    li a0, 1
    ret
