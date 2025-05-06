#include <stdio.h>
#include "stack.h"

/*
You are to implement a simple stack of integers with the following operations:

void stack_init(Stack* s)

bool stack_push(Stack* s, int value)

bool stack_pop(Stack* s, int* out)

bool stack_peek(Stack* s, int* out)

bool stack_is_empty(const Stack* s)

bool stack_is_full(const Stack* s)

💾 Constraints & Notes:
Max stack size is fixed at compile-time (#define STACK_CAPACITY 16)

Use static memory allocation only. No malloc().

Your stack should be implemented in stack.c and declared in stack.h.

The main test program should be in main.c, testing stack operations.

Return false if a push is attempted when full, or if pop/peek is done when empty.
*/

int main(void) {
    Stack s;
    stack_init(&s);

    for (int i = 0; i < STACK_CAPACITY; i++) {
        if (!stack_push(&s, i)) {
            printf("Push failed at %d\n", i);
        }
    }

    int val;
    if (stack_peek(&s, &val)) {
        printf("Top element: %d\n", val);
    }

    while (!stack_is_empty(&s)) {
        if (stack_pop(&s, &val)) {
            printf("Popped: %d\n", val);
        }
    }

    return 0;
}
