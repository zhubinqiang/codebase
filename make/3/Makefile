
SRC = ./src
INC = -I./include
LIBS = -L/usr/lib/x86_64-linux-gnu -lm
OBJS = main.o mathFunction.o multiplication-table.o
TARGET = main

# %.o: ${SRC}/%.c
# 	cc $(INC) -c $^


.PHONY: clean, mrproper
CC = gcc
CFLAGS = -g -Wall

all: $(TARGET)

%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $+ $(LIBS)

clean:
	rm -f *.o core.*

mrproper: clean
	rm -f $(TARGET)


