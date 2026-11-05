.section .text
	.global is_greater

is_greater:
	ble a0, a1, no
	li a0, 1
	ret

no:
	li a0, 0
	ret
