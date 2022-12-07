prefix = /usr/local

CC = gcc
CFLAGS = -g -Wall

all: hithere.o
	$(CC) -o hithere hithere.o

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

install: pre_install
	install hithere $(DESTDIR)$(prefix)/bin
	install hithere.1 $(DESTDIR)$(prefix)/share/man/man1

pre_install:
	install -m755 -d $(DESTDIR)$(prefix)/bin
	install -m755 -d $(DESTDIR)$(prefix)/share/man/man1

clean:
	rm -f hithere *.o

.PHONY: clean

