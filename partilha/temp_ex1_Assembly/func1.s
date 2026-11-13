.section .text
.global func1

func1:
    lbu t0, 0(a0)       # Pressao do pneu 1
    lbu t1, 1(a0)       # Pressao do pneu 2
    lbu t2, 2(a0)       # Pressao do pneu 3
    lbu t3, 3(a0)       # Pressao do pneu 4

    li t4, 0xFE         # Limite de pressao

    bltu t0, t4, low    # Verifica pneu 1
    bltu t1, t4, low    # Verifica pneu 2
    bltu t2, t4, low    # Verifica pneu 3
    bltu t3, t4, low    # Verifica pneu 4

    li a0, 0            # Nenhum pneu com baixa pressao
    ret

low:
    li a0, 1            # Existe pneu com baixa pressao
    ret
