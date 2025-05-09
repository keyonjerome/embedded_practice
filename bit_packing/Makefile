CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: main

main: main.o sensor_packet.o
	$(CC) $(CFLAGS) -o main main.o sensor_packet.o

main.o: main.c sensor_packet.h
	$(CC) $(CFLAGS) -c main.c

sensor_packet.o: sensor_packet.c sensor_packet.h
	$(CC) $(CFLAGS) -c sensor_packet.c

clean:
	rm -f *.o main