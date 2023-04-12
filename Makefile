
CC := m68k-linux-gnu-gcc
SIZE := m68k-linux-gnu-size
OBJDUMP := m68k-linux-gnu-objdump
OBJCOPY := m68k-linux-gnu-objcopy

ODIR := obj
SDIR := src

CFLAGS := -m68000  -Wl,--build-id=none -ffreestanding -nostdlib -Wall -g


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
