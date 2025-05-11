CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: test_ring_buffer

test_ring_buffer: main.o ring_buffer.o
	$(CC) $(CFLAGS) -o test_ring_buffer main.o ring_buffer.o

main.o: main.c ring_buffer.h
	$(CC) $(CFLAGS) -c main.c

ring_buffer.o: ring_buffer.c ring_buffer.h
	$(CC) $(CFLAGS) -c ring_buffer.c

clean:
	rm -f *.o test_ring_buffer
