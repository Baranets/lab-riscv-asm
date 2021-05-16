.PHONY: clean
dump_name=lab-riscv-asm.dump
executable_name=lab-riscv-asm.elf

default: $(dump_name) $(executable_name)

%.elf : %.c
	@riscv64-unknown-elf-gcc -march=rv32i -mabi=ilp32 $< -o $@

%.dump: %.elf
	@riscv64-unknown-elf-objdump -D $< > $@

clean:
	@rm -f $(dump_name)
	@rm -f $(executable_name)
	@rm -f lab-riscv-asm

c_build: 
	gcc lab-riscv-asm.c -o lab-riscv-asm