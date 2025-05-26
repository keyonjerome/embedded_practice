CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic

all: main

main: main.o low_pass_filter.o
	$(CC) $(CFLAGS) -o main main.o low_pass_filter.o

main.o: main.c low_pass_filter.h
low_pass_filter.o: low_pass_filter.c low_pass_filter.h

clean:
	rm -f *.o main
