#!/bin/bash

read -p "Copiar para: " destino

mkdir -p "$destino"

cat > "$destino/Makefile" << 'EOF'
CC=riscv32-linux-gcc
CFLAGS=-Wall -Wextra -fanalyzer -g
ARCHFLAGS=-march=rv32imd -mabi=ilp32d
LIBRV32=${HOME}/bin/bootlin/riscv32-buildroot-linux-gnu/sysroot

program.elf: main.o
	$(CC) $(CFLAGS) $(ARCHFLAGS) main.o -o program.elf

main.o: main.c
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c main.c

clean:
	rm -f *.o *.elf

run: program.elf
	qemu-riscv32 -L $(LIBRV32) ./program.elf

debug: program.elf
	@echo "On other terminal window do:"
	@echo "riscv32-linux-gdb -tui ./program.elf"
	qemu-riscv32 -L $(LIBRV32) -g 1234 program.elf -S
EOF

cat > "$destino/main.c" << 'EOF'
#include <stdio.h>

int main(void) {
	printf("Hello, World!\n");
	return 0;
}
EOF

echo "Setup: Makefile e main.c -> $destino"
