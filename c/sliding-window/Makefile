.PHONY: clean, mrproper
CC = gcc
CFLAGS = -g -Wall

all: out

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

out: sliding-window.o
	$(CC) $(CFLAGS) -o $@ $+

clean:
	rm -f *.o core.*

mrproper: clean
	rm -f out
