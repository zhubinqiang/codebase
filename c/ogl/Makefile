.PHONY: clean, mrproper
CC = gcc
# CFLAGS = -g -Wall -L /usr/lib/x86_64-linux-gnu/ -l GL
CFLAGS = -g -Wall

all: out-finite-state-machine out-finite-state-machine-2 out-vbo

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

out-vbo: vbo.o
	$(CC) $(CFLAGS) -o $@ $+

out-finite-state-machine: finite-state-machine.o
	$(CC) $(CFLAGS) -o $@ $+

out-finite-state-machine-2: finite-state-machine-2.o
	$(CC) $(CFLAGS) -o $@ $+

clean:
	rm -f *.o core.*

mrproper: clean
	rm -f out out2

