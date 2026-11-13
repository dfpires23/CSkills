#!/bin/bash

destino="ex2_1230414"

mkdir -p "$destino"

cat > "$destino/Makefile" << 'EOF'
CC=riscv32-linux-gcc
CFLAGS=-Wall -Wextra -fanalyzer -g
ARCHFLAGS=-march=rv32imd -mabi=ilp32d
LIBRV32=${HOME}/bin/bootlin/riscv32-buildroot-linux-gnu/sysroot

program.elf: main.o func1.o func2.o
	$(CC) $(CFLAGS) $(ARCHFLAGS) main.o func1.o func2.o -o program.elf

main.o: main.c
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c main.c

func1.o: func1.s func1.h
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c func1.s

func2.o: func2.s func2.h
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c func2.s

clean:
	rm -f *.o *.elf .*~ *~ .gdbinit

run: program.elf
	qemu-riscv32 -L $(LIBRV32) ./program.elf

debug: program.elf .gdbinit
	@echo "On other terminal window do:"
	@echo "riscv32-linux-gdb --tui ./program.elf"
	@echo "or just paste"
	@echo -n "cd $(CURDIR) ; riscv32-linux-gdb --tui ./program.elf" \
		| xclip -selection clipboard
	qemu-riscv32 -L $(LIBRV32) -g 1234 program.elf -S

define GDBINIT
target extended-remote localhost:1234
set sysroot ~/bin/bootlin/riscv32-buildroot-linux-gnu/sysroot
break main
continue

endef

export GDBINIT

.gdbinit:
	@echo "$$GDBINIT" >.gdbinit

EOF

cat > "$destino/main.c" << 'EOF'
#include "func2.h"
#include <stdio.h>
#define NCARS 5

int main(void) {
    unsigned int cars[NCARS] = {0xFFFFFFFF, 0xFFFAFFFA, 0x00000000, 0xFCFDEFAB,
                                0xFFFFFFFF};
    unsigned int *fill[NCARS];

    printf("Number=%d\n", func2(cars, NCARS, fill));

    return 0;
}

EOF

cat > "$destino/func1.s" << 'EOF'
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

EOF

cat > "$destino/func1.h" << 'EOF'
#ifndef FUNC1_H
#define FUNC1_H

int func1(unsigned int *);

#endif

EOF

cat > "$destino/func2.s" << 'EOF'
.section .text
.global func2

func2:
    addi sp, sp, -32
    sw ra, 28(sp)
    sw s0, 24(sp)
    sw s1, 20(sp)
    sw s2, 16(sp)
    sw s3, 12(sp)
    sw s4, 8(sp)

    mv s0, a0       # cars
    mv s1, a1       # n
    mv s2, a2       # fill
    li s3, 0        # i = 0
    li s4, 0        # count = 0

loop:
    bge s3, s1, end

    mv a0, s0
    call func1

    beqz a0, next

    sw s0, 0(s2)    # fill[count] = &cars[i]
    addi s2, s2, 4  # PrÃ³xima posiÃ§Ã£o de fill
    addi s4, s4, 1  # count++

next:
    addi s0, s0, 4  # PrÃ³ximo carro
    addi s3, s3, 1  # i++
    j loop

end:
    mv a0, s4       # return count

    lw s4, 8(sp)
    lw s3, 12(sp)
    lw s2, 16(sp)
    lw s1, 20(sp)
    lw s0, 24(sp)
    lw ra, 28(sp)
    addi sp, sp, 32

    ret

EOF

cat > "$destino/func2.h" << 'EOF'
#ifndef FUNC2_H
#define FUNC2_H

int func2(unsigned int *, int, unsigned int **);

#endif

EOF

echo "Setup complete -> $destino"
