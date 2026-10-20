CC=riscv32-linux-gcc
CFLAGS=-Wall -Wextra -fanalyzer -g
ARCHFLAGS=-march=rv32imd -mabi=ilp32d
LIBRV32=${HOME}/bin/bootlin/riscv32-buildroot-linux-gnu/sysroot

program.elf: main.o count_value.o cmp.o
	$(CC) $(CFLAGS) $(ARCHFLAGS) main.o count_value.o cmp.o -o program.elf

main.o: main.c
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c main.c

count_value.o: count_value.c
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c count_value.c

cmp.o: ../ex05/cmp.c
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c ../ex05/cmp.c

clean:
	rm -f *.o *.elf

run: program.elf
	qemu-riscv32 -L $(LIBRV32) ./program.elf

debug: program.elf
	@echo "On other terminal window do:"
	@echo "riscv32-linux-gdb -tui ./program.elf"
	qemu-riscv32 -L $(LIBRV32) -g 1234 program.elf -S
