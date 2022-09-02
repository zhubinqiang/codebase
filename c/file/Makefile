.PHONY: clean, mrproper, run
CC = gcc
CFLAGS = -g -Wall
LIBS = -lm
OUT = main


all: run

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

out: file-example.o
	$(CC) $(CFLAGS) -o $(OUT) $+
	# $(CC) $(CFLAGS) -o $(OUT) $+ $(LIBS)

clean:
	rm -f *.o core.*

mrproper: clean ## clean all
	rm -f $(OUT)

run: out ## run binary
	./$(OUT)

help: ## Prints help for targets with comments
	@cat $(MAKEFILE_LIST) | grep -E '^[a-zA-Z_-]+:.*?## .*$$' | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

