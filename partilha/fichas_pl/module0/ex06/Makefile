CC=riscv32-linux-gcc
CFLAGS=-Wall -Wextra -fanalyzer -g
ARCHFLAGS=-march=rv32imd -mabi=ilp32d
LIBRV32=${HOME}/bin/bootlin/riscv32-buildroot-linux-gnu/sysroot

program.elf: main.o cmp.o get_greater_digit.o
	$(CC) $(CFLAGS) $(ARCHFLAGS) main.o cmp.o get_greater_digit.o -o program.elf

main.o: main.c
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c main.c

get_greater_digit.o: get_greater_digit.c
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c get_greater_digit.c

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
