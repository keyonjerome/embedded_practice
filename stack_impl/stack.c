#include "stack.h"

void stack_init(Stack* s) {
    if(s == NULL) return;
    s->top = -1;
}

bool stack_is_full(const Stack* s) {
    return (s->top == (STACK_CAPACITY-1));
}

bool stack_is_empty(const Stack* s) {
    return (s->top == -1);
}

bool stack_push(Stack* s, int val) {
    if(stack_is_full(s)) {
        return false;
    }
    s->top++;
    s->data[s->top]=val;
    return true;
}

bool stack_peek(Stack* s, int* out) {
    if(stack_is_empty(s)) return false;

    *out = s->data[s->top];
    return true;
}

bool stack_pop(Stack* s, int* out) {
    if(!stack_peek(s,out))  return false;
    s->data[s->top] = 0;
    s->top--;
    return true;
}


