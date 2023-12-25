
.PHONY: clean, mrproper
CC = gcc
CFLAGS = -g -Wall

all: out

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

out: func_pointer.o
	$(CC) $(CFLAGS) -o $@ $+

clean:
	rm -f *.o core.*

mrproper: clean
	rm -f out
