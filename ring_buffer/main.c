#include <stdio.h>
#include "ring_buffer.h"

int main(void) {
    RingBuffer rb;
    ring_buffer_init(&rb);

    printf("Pushing 16 values...\n");
    for (uint8_t i = 0; i < RING_BUFFER_CAPACITY; ++i) {
        if (!ring_buffer_push(&rb, i)) {
            printf("Failed to push %u\n", i);
        }
    }

    printf("Buffer full? %s\n", ring_buffer_is_full(&rb) ? "yes" : "no");

    printf("Trying to push to full buffer...\n");
    if (!ring_buffer_push(&rb, 100)) {
        printf("Correctly rejected extra push.\n");
    }

    printf("Popping values...\n");
    uint8_t val;
    while (ring_buffer_pop(&rb, &val)) {
        printf("Popped: %u\n", val);
    }

    printf("Buffer empty? %s\n", ring_buffer_is_empty(&rb) ? "yes" : "no");

    return 0;
}
