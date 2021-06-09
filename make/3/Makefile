
SRC = ./src
INC = -I./include
LIBS = -L/usr/lib/x86_64-linux-gnu -lm
EXE = out

# %.o: ${SRC}/%.c
# 	cc $(INC) -c $^


.PHONY: clean, mrproper
CC = gcc
CFLAGS = -g -Wall

all: $(EXE)

%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(EXE): main.o mathFunction.o multiplication-table.o
	$(CC) $(CFLAGS) -o $@ $+ $(LIBS)

clean:
	rm -f *.o core.*

mrproper: clean
	rm -f $(EXE)



