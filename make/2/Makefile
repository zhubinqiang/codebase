
.PHONY: clean, mrproper
CC = gcc
CFLAGS = -g -Wall

all: out

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

out: main.o mathFunction.o multiplication-table.o
	$(CC) $(CFLAGS) -o $@ $+

clean:
	rm -f *.o core.*

mrproper: clean
	rm -f out


