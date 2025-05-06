CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2

# Source files
SRCS = main.c stack.c
OBJS = $(SRCS:.c=.o)

# Executable name
TARGET = stack_test

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)


clean:
	rm -f $(OBJS) $(TARGET)
