CC=riscv32-linux-gcc
CFLAGS=-Wall -Wextra -fanalyzer -g
ARCHFLAGS=-march=rv32imd -mabi=ilp32d
LIBRV32=${HOME}/bin/bootlin/riscv32-buildroot-linux-gnu/sysroot

program.elf: main.o fake_hash.o sum.o get_ascii_code.o
	$(CC) $(CFLAGS) $(ARCHFLAGS) main.o fake_hash.o sum.o get_ascii_code.o -o program.elf

main.o: main.c
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c main.c
	
fake_hash.o: fake_hash.c
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c fake_hash.c
	
sum.o: ../ex02/sum.c
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c ../ex02/sum.c
	
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
