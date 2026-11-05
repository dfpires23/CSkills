.section .text
	.global six_packs

six_packs:
	li t0, 6
	div t1, a0, t0
	rem t2, a0, t0
	bnez t2, no
	mv a0, t1
	ret

no:
	addi a0, t1, 1
	ret
