.PHONY: clean, mrproper
CC = gcc
CFLAGS = -g -Wall

SRC_DIR = src

all: main

%.o: src/%.c
	$(CC) $(CFLAGS) -I./include -c -o $@ $<

libone.a: add.o multitab.o
	ar -crv libone.a $^

libtwo.a: power.o pi.o
	ar -crv libtwo.a $^

main: main.c libone.a libtwo.a
	$(CC) $(CFLAGS) main.c -I./include -L. -lone -ltwo -o $@

run: main
	LD_LIBRARY_PATH=. ./main

clean:
	rm -f *.o core.* lib*.a

mrproper: clean
	rm -f main

