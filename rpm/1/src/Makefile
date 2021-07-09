.PHONY: clean, mrproper
CC = gcc
CFLAGS = -g -Wall

all: mycat

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

mycat: myCat.o
	$(CC) $(CFLAGS) -o $@ $+

clean:
	rm -f *.o core.*

mrproper: clean
	rm -f out
