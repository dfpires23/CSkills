.section .text
    .global func1

func1:
    lb t0, 1(a0)

    lhu t1, 2(a0)
    lhu t2, 4(a0)
    lhu t3, 6(a0)

    add t1, t1, t2
    add t1, t1, t3

    li t2, 1000
    mul t0, t0, t2

    bgtu t1, t0, maior

    li a0, 0
    ret

maior:
    li a0, 1
    ret
