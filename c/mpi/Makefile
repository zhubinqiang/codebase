
.PHONY: clean, mrproper
CC = mpicc
CFLAGS = -g -Wall

run: all
	mpiexec -n 2 ./out

all: out

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
out: sum_example.o
	$(CC) $(CFLAGS) -o $@ $+

clean:
	rm -f *.o core.*

mrproper: clean
	rm -f out

