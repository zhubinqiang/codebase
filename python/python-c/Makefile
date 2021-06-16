
OBJS = sum.o
TARGET = sum
LIBS =

ifeq ($(OS), Windows_NT)
	SHARE =
else
	ifeq ($(shell uname), Darwin)
		SHARE = -shared -Wl,-install_name
	else
		SHARE = -shared -Wl,-soname
	endif
endif

.PHONY: clean, mrproper
CC = gcc
CFLAGS = -g -Wall

all: lib

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $+ $(LIBS)

lib: $(TARGET)
	$(CC) $(SHARE),$(TARGET) -o $(TARGET).so -fPIC $(OBJS)
	# $(CC) -shared -Wl,-soname,$(TARGET) -o $(TARGET).so -fPIC $(OBJS)

clean:
	rm -f *.o core.*

mrproper: clean
	rm -f out $(TARGET) $(TARGET).so

