.PHONY: clean, mrproper
CC = gcc
CFLAGS = -g -Wall

all: out
	./out

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

out: ring-buffer.o
	$(CC) $(CFLAGS) -o $@ $+

clean:
	rm -f *.o core.*

mrproper: clean
	rm -f out
