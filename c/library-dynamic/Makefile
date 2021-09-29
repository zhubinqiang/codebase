.PHONY: clean, mrproper
CC = gcc
CFLAGS = -g -Wall

SRC_DIR = src

all: main

%.o: src/%.c
	$(CC) $(CFLAGS) -I./include -c -o $@ $<

libone.so: add.o multitab.o
	$(CC)  -I./include -fPIC -shared -o libone.so $^

libtwo.so: power.o pi.o
	$(CC)  -I./include -fPIC -shared -Wl,-soname,libtwo.so.2 -o libtwo.so.2.1 $^
	ln -sf libtwo.so.2.1 libtwo.so.2
	ln -sf libtwo.so.2 libtwo.so

main: main.c libone.so libtwo.so
	$(CC) $(CFLAGS) main.c -I./include -L. -lone -ltwo -o $@

run: main
	LD_LIBRARY_PATH=. ./main

clean:
	rm -f *.o core.* lib*.so lib*.so*

mrproper: clean
	rm -f main

