CC=riscv32-linux-gcc
CFLAGS=-Wall -Wextra -fanalyzer -g
ARCHFLAGS=-march=rv32imd -mabi=ilp32d
LIBRV32=${HOME}/bin/bootlin/riscv32-buildroot-linux-gnu/sysroot

program.elf: main.o func1.o file2.o
	$(CC) $(CFLAGS) $(ARCHFLAGS) main.o func1.o file2.o -o program.elf

main.o: main.c
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c main.c

func1.o: func1.s func1.h
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c func1.s

file2.o: file2.s file2.h
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c file2.s

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

