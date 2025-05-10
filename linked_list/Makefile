# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

# Source and object files
SRCS = main.c event_queue.c
OBJS = $(SRCS:.c=.o)
TARGET = event_queue_test

# Default rule
all: $(TARGET)

# Link target
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
