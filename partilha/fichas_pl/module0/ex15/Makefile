CC=riscv32-linux-gcc
CFLAGS=-Wall -Wextra -fanalyzer -g
ARCHFLAGS=-march=rv32imd -mabi=ilp32d
LIBRV32=${HOME}/bin/bootlin/riscv32-buildroot-linux-gnu/sysroot

program.elf: main.o count_words.o get_ascii_code.o count_char.o get_ascii_char.o
	$(CC) $(CFLAGS) $(ARCHFLAGS) main.o count_words.o get_ascii_code.o count_char.o get_ascii_char.o -o program.elf

main.o: main.c
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c main.c

count_words.o: count_words.c
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c count_words.c

get_ascii_code.o: ../ex07/get_ascii_code.c
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c ../ex07/get_ascii_code.c

count_char.o: ../ex13/count_char.c
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c ../ex13/count_char.c

get_ascii_char.o: ../ex08/get_ascii_char.c
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c ../ex08/get_ascii_char.c

clean:
	rm -f *.o *.elf

run: program.elf
	qemu-riscv32 -L $(LIBRV32) ./program.elf

debug: program.elf
	@echo "On other terminal window do:"
	@echo "riscv32-linux-gdb -tui ./program.elf"
	qemu-riscv32 -L $(LIBRV32) -g 1234 program.elf -S
