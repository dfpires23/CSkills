CC=riscv32-linux-gcc
CFLAGS=-Wall -Wextra -fanalyzer -g
ARCHFLAGS=-march=rv32imd -mabi=ilp32d
LIBRV32=${HOME}/bin/bootlin/riscv32-buildroot-linux-gnu/sysroot

program.elf: main.o sort_without_reps.o array_copy.o array_sort.o array_remove_duplicates.o
	$(CC) $(CFLAGS) $(ARCHFLAGS) main.o sort_without_reps.o array_copy.o array_sort.o array_remove_duplicates.o -o program.elf

main.o: main.c
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c main.c

sort_without_reps.o: sort_without_reps.s sort_without_reps.h
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c sort_without_reps.s

array_copy.o: array_copy.s array_copy.h
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c array_copy.s

array_sort.o: array_sort.s array_sort.h
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c array_sort.s

array_remove_duplicates.o: array_remove_duplicates.s array_remove_duplicates.h
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c array_remove_duplicates.s

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

