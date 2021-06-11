.PHONY: clean, mrproper, run
CC = gcc
CFLAGS = -g -Wall
LIBS = -lm

all: out

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

out: c-example.o
	$(CC) $(CFLAGS) -o $@ $+ $(LIBS)

clean:
	rm -f *.o core.*

mrproper: clean ## clean all
	rm -f out

run: all ## run binary
	./out

help: ## Prints help for targets with comments
	@cat $(MAKEFILE_LIST) | grep -E '^[a-zA-Z_-]+:.*?## .*$$' | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'


