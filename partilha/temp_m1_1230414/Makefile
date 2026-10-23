# 1230414: Daniel Ferreira Pires: 2NC: Version I

CC=riscv32-linux-gcc
CFLAGS=-Wall -Wextra -fanalyzer -g
ARCHFLAGS=-march=rv32imd -mabi=ilp32d
LIBRV32=${HOME}/bin/bootlin/riscv32-buildroot-linux-gnu/sysroot

program.elf: main.o func1.o func2.o
	$(CC) $(CFLAGS) $(ARCHFLAGS) main.o func1.o func2.o -o program.elf
	
main.o: main.c
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c main.c
	
func1.o: func1.c
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c func1.c
	
func2.o: func2.c
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c func2.c

clean:
	rm -f *.o *.elf
	
run: program.elf
	qemu-riscv32 -L $(LIBRV32) ./program.elf
