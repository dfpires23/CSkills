#!/bin/bash

read -p "Copy to: " destino

mkdir -p "$destino"

cat > "$destino/Makefile" << 'EOF'
CC=riscv32-linux-gcc
CFLAGS=-Wall -Wextra -fanalyzer -g
ARCHFLAGS=-march=rv32imd -mabi=ilp32d
LIBRV32=${HOME}/bin/bootlin/riscv32-buildroot-linux-gnu/sysroot

program.elf: main.o asm.o
	$(CC) $(CFLAGS) $(ARCHFLAGS) main.o asm.o -o program.elf

main.o: main.c
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c main.c

asm.o: asm.s asm.h
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c asm.s

clean:
	rm -f *.o *.elf .gdbinit

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
#include <stdio.h>
#include "asm.h"

int main(void) {
	int op1, op2, res;
	
	printf("Valor op1: ");
	scanf("%d", &op1);
	
	printf("Valor op2: ");
	scanf("%d", &op2);
	
	res = sum(op1, op2);
	printf("sum = %d:0x%x\n", res, res);
	
	return 0;
}

EOF

cat > "$destino/asm.s" << 'EOF'
	.section .text
	.global sum

sum:
	add a0, a0, a1
	ret
EOF

cat > "$destino/asm.h" << 'EOF'
#ifndef ASM_H
#define ASM_H

int sum(int, int);

#endif
EOF

echo "Setup complete -> $destino"
