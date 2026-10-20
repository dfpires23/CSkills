CC=riscv32-linux-gcc
CFLAGS=-Wall -Wextra -fanalyzer -g
ARCHFLAGS=-march=rv32imd -mabi=ilp32d
LIBRV32=${HOME}/bin/bootlin/riscv32-buildroot-linux-gnu/sysroot

program.elf: main.o find_pattern.o cmp.o size_string.o
	$(CC) $(CFLAGS) $(ARCHFLAGS) main.o find_pattern.o cmp.o size_string.o -o program.elf

main.o: main.c
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c main.c
	
find_pattern.o: find_pattern.c
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c find_pattern.c
	
cmp.o: ../ex05/cmp.c
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c ../ex05/cmp.c
	
size_string.o: ../ex10/size_string.c
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c ../ex10/size_string.c

clean:
	rm -f *.o *.elf

run: program.elf
	qemu-riscv32 -L $(LIBRV32) ./program.elf

debug: program.elf
	@echo "On other terminal window do:"
	@echo "riscv32-linux-gdb -tui ./program.elf"
	qemu-riscv32 -L $(LIBRV32) -g 1234 program.elf -S
