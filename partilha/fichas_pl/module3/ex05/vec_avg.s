.section .text
	.global vec_avg

vec_avg:
    addi sp, sp, -16
    sw ra, 12(sp)
    sw a1, 8(sp)

    call vec_sum

    lw t0, 8(sp)
    div a0, a0, t0

    lw ra, 12(sp)
    addi sp, sp, 16
    ret
