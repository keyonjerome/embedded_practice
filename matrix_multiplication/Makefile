CC = gcc
CFLAGS = -Wall -Werror -std=c99

all: test

test: main.o matrix_mult.o
	$(CC) $(CFLAGS) -o test main.o matrix_mult.o

main.o: main.c matrix_mult.h
	$(CC) $(CFLAGS) -c main.c

matrix_mult.o: matrix_mult.c matrix_mult.h
	$(CC) $(CFLAGS) -c matrix_mult.c

clean:
	rm -f *.o test
