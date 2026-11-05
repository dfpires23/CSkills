.section .text
	.global is_multiple

is_multiple:
	rem t0, a0, a1
	bnez t0, no
	li a0, 1
	ret

no:
	li a0, 0
	ret
