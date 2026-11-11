#!/bin/bash

destino="ex2_1230414"

mkdir -p "$destino"

cat > "$destino/Makefile" << 'EOF'
# 1230414: Daniel Ferreira Pires: 2NC: Version 1.0

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
/*
 * 1230414: Daniel Ferreira Pires: 2NC: Version 1.0
 */

#include "func2.h"
#include <stdio.h>

int main(void) {
    int op1[] = {1, 2, 3, 4, 5, 6};
    int num = 6;

    int res = func2(op1, num);

    printf("res = %d:0x%x\n", res, res);

    return 0;
}

EOF

cat > "$destino/func1.s" << 'EOF'
/*
 * 1230414: Daniel Ferreira Pires: 2NC: Version 1.0
 */

.section .text
	.global func1

func1:
	li t0, 2
	rem a0, a0, t0
	
	bnez a0, false
	li a0, 1
	ret
	
false:
	li a0, 0
	ret
	
EOF

cat > "$destino/func1.h" << 'EOF'
/*
 * 1230414: Daniel Ferreira Pires: 2NC: Version 1.0
 */

#ifndef FUNC1_H
#define FUNC1_H

int func1(int);

#endif
EOF

cat > "$destino/func2.s" << 'EOF'
/*
 * 1230414: Daniel Ferreira Pires: 2NC: Version 1.0
 */

.section .text
	.global func2

func2:
    addi sp, sp, -32
    sw ra, 28(sp)
    sw s0, 24(sp)
    sw s1, 20(sp)
    sw s2, 16(sp)
    sw s3, 8(sp)

    mv s0, a0
    mv s1, zero
    mv s2, a1

loop:
    blez s2, end

    lw s3, 0(s0)
    mv a0, s3

    call func1

    beqz a0, next

    add s1, s1, s3

next:
    addi s0, s0, 4
    addi s2, s2, -1
    j loop

end:
    mv a0, s1

	lw s3, 12(sp)
    lw s2, 16(sp)
    lw s1, 20(sp)
    lw s0, 24(sp)
    lw ra, 28(sp)
    addi sp, sp, 32

    ret

EOF

cat > "$destino/func2.h" << 'EOF'
/*
 * 1230414: Daniel Ferreira Pires: 2NC: Version 1.0
 */

#ifndef FUNC2_H
#define FUNC2_H

int func2(int *, int);

#endif
EOF

echo "Setup complete -> $destino"
