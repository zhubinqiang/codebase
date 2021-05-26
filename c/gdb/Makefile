.PHONY: clean, mrproper, sym
CC = gcc
CFLAGS = -ggdb3 -Wall

all: out

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

out: test.o hello.o
	$(CC) $(CFLAGS) -o $@ $+

clean:
	rm -f out *.o core.*

mrproper: clean
	rm -f out

## strip out
## objcopy --add-gnu-debuglink=out.debuginfo out
sym: out
	objcopy --only-keep-debug $^ ${^}.debuginfo


