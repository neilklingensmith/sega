
CC := ~/x-tools/m68k-unknown-elf/bin/m68k-unknown-elf-gcc
SIZE := ~/x-tools/m68k-unknown-elf/bin/m68k-unknown-elf-size
OBJDUMP := ~/x-tools/m68k-unknown-elf/bin/m68k-unknown-elf-objdump
OBJCOPY := ~/x-tools/m68k-unknown-elf/bin/m68k-unknown-elf-objcopy

ODIR := obj
SDIR := src

CFLAGS := -m68000  -Wl,--build-id=none -ffreestanding -nostdlib -Wall -g
CFLAGS += -L~/x-tools/m68k-unknown-elf/lib/gcc/m68k-unknown-elf/12.2.0/

OBJS += \
        main.o \
        font.o \
        printfuncs.o \
        gfx.o \
        start.o \
        controller.o \
        rprintf.o \
        libc.o

OBJ = $(patsubst %,$(ODIR)/%,$(OBJS))



$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) -c -g -o $@ $^

$(ODIR)/%.o: $(SDIR)/%.s
	$(CC) $(CFLAGS) -c -o $@ $^


all: bin

bin: $(OBJ)
	$(CC)  $(CFLAGS) obj/* -Tsega.ld  -o sega.elf -lgcc
	ctags -R src/*
	$(SIZE) sega.elf
	cp sega.elf sega.img
	$(OBJCOPY) -Obinary sega.img

clean:
	rm -f obj/* sega.img sega.elf tags

disassemble:
	m68k-linux-gnu-objdump --source sega.elf

run:
	dgen -G 800x600 sega.img
