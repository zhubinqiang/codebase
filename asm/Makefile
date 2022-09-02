.PHONY: clean, mrproper
ASM = yasm
CC = gcc
# CFLAGS = -g -Wall -no-pie
CFLAGS = -g -Wall

DEFAULT = 5.o

run: out
	./$<

%.o: %.asm
	$(ASM) -f elf64 -o $@ $<

# %.o: %.c
# 	$(CC) $(CFLAGS) -c -o $@ $<

out: $(DEFAULT)
	$(CC) $(CFLAGS) -o $@ $+

clean:
	rm -f *.o core.*

mrproper: clean
	rm -f out
