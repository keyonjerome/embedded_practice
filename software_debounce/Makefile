CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic

all: main

main: main.o debounce.o
	$(CC) $(CFLAGS) -o main main.o debounce.o

main.o: main.c debounce.h
debounce.o: debounce.c debounce.h

clean:
	rm -f *.o main
