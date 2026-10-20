CC=riscv32-linux-gcc
CFLAGS=-Wall -Wextra -fanalyzer -g
ARCHFLAGS=-march=rv32imd -mabi=ilp32d
LIBRV32=${HOME}/bin/bootlin/riscv32-buildroot-linux-gnu/sysroot

program.elf: main.o get_parts.o string_to_int.o get_ascii_code.o
	$(CC) $(CFLAGS) $(ARCHFLAGS) main.o get_parts.o string_to_int.o get_ascii_code.o -o program.elf

main.o: main.c
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c main.c

get_parts.o: get_parts.c
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c get_parts.c

string_to_int.o: ../ex11/string_to_int.c
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c ../ex11/string_to_int.c
	
get_ascii_code.o: ../ex07/get_ascii_code.c
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c ../ex07/get_ascii_code.c
	
clean:
	rm -f *.o *.elf

run: program.elf
	qemu-riscv32 -L $(LIBRV32) ./program.elf

debug: program.elf
	@echo "On other terminal window do:"
	@echo "riscv32-linux-gdb -tui ./program.elf"
	qemu-riscv32 -L $(LIBRV32) -g 1234 program.elf -S
