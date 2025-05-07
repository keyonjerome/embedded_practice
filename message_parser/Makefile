CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
OBJS = main.o parser.o
TARGET = test_parser
all: test_parser

test_parser: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

main.o: main.c parser.h
parser.o: parser.c parser.h

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f *.o test_parser
