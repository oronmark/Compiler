CC=gcc
CFLAGS=-O -g -Wall 
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: example

example: example.o
	$(CC) $(CFLAGS) -o $@ $^

example.o: example.c cisc.h

clean:
	rm -f *.o example
