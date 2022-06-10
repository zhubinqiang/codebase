
.PHONY: clean, mrproper
CC = gcc
CFLAGS = -g -Wall

NOW = $(shell date)

all: out

%.o: %.c
	@ echo ${NOW}
	$(CC) $(CFLAGS) -c -o $@ $<

out: main.o mathFunction.o multiplication-table.o
	$(CC) $(CFLAGS) -o $@ $+

clean:
	rm -f *.o core.*

mrproper: clean
	rm -f out


