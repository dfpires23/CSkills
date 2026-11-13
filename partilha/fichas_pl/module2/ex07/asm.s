.section .text
	.global my_remainder

my_remainder:
	add a0, a0, a1
	rem a0, a0, a2
	ret
