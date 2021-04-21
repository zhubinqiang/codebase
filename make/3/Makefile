
SRC = ./src
INC = -I./include
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
	$(CC) $(CFLAGS) $(INC) -o $@ $+

clean:
	rm -f *.o core.*

mrproper: clean
	rm -f $(EXE)



