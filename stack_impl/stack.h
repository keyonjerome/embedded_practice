#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define STACK_CAPACITY 16

typedef struct {
    int data[STACK_CAPACITY];
    int top; // index of top element
} Stack;

void stack_init(Stack* s);
bool stack_push(Stack* s, int value);
bool stack_pop(Stack* s, int* out);
bool stack_peek(Stack* s, int* out);
bool stack_is_empty(const Stack* s);
bool stack_is_full(const Stack* s);

#endif // STACK_H
