CC=riscv32-linux-gcc
CFLAGS=-Wall -Wextra -fanalyzer -g
ARCHFLAGS=-march=rv32imd -mabi=ilp32d
LIBRV32=${HOME}/bin/bootlin/riscv32-buildroot-linux-gnu/sysroot

program.elf: main.o sum_lower_triangular_matrix.o check_lower_triangular_matrix.o
	$(CC) $(CFLAGS) $(ARCHFLAGS) main.o sum_lower_triangular_matrix.o check_lower_triangular_matrix.o -o program.elf

main.o: main.c
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c main.c
	
sum_lower_triangular_matrix.o: sum_lower_triangular_matrix.c
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c sum_lower_triangular_matrix.c

check_lower_triangular_matrix.o: check_lower_triangular_matrix.c
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c check_lower_triangular_matrix.c

clean:
	rm -f *.o *.elf

run: program.elf
	qemu-riscv32 -L $(LIBRV32) ./program.elf

debug: program.elf
	@echo "On other terminal window do:"
	@echo "riscv32-linux-gdb -tui ./program.elf"
	qemu-riscv32 -L $(LIBRV32) -g 1234 program.elf -S
