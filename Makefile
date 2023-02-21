CC=gcc
CFLAGS=-I.
DEPS = collector.h
OBJ = collector.o driver.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)