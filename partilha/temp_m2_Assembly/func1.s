.section .text
.global func1

func1:
    li t0, 'A'
    li t1, 'Z'

    blt a0, t0, low
    bgt a0, t1, low

    li a0, 1
    ret

low:
    li a0, 0
    ret
