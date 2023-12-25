.PHONY: clean, mrproper
CC = gcc
CFLAGS = -g -Wall

all: out default_vendor_library libVendorA libVendorB

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

out: main.o
	$(CC) $(CFLAGS) -o $@ $+ -ldl

default_vendor_library: default_vendor_library.o
	$(CC) $(CFLAGS) -shared -fPIC -o $@.so $<

libVendorA: VendorA.o
	$(CC) $(CFLAGS) -shared -fPIC -o $@.so $<

libVendorB: VendorB.o
	$(CC) $(CFLAGS) -shared -fPIC -o $@.so $<

run: out default_vendor_library
	LD_LIBRARY_PATH=. ./out

runA: out libVendorA
	VENDOR_LIB=./libVendorA.so ./out

runB: out libVendorB
	VENDOR_LIB=./libVendorB.so ./out

clean:
	rm -f *.o core.*

mrproper: clean
	rm -f out *.so


