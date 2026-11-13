.section .text
	.global in_order

in_order:
	ble a0, a1, no
	ble a1, a2, no
	li a0, 1
	ret

no:
	li a0, 0
	ret
