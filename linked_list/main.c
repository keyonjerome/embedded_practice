#include "event_queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_EVENTS 100
#define MAX_PAYLOAD_SIZE 8

void print_event(const Event* e) {
    printf("Event timestamp: %u, type: %d, payload_len: %u, payload: ",
           e->timestamp, e->event, e->payload_length);
    for (int i = 0; i < e->payload_length; i++) {
        printf("%d ", e->payload[i]);
    }
    printf("\n");
}

int main() {
    EventQueue q;
    queue_init(&q);
    srand((unsigned int) time(NULL));

    // Check queue is empty initially
    if (!queue_is_empty(&q)) {
        printf("Error: queue should be empty after init\n");
        return 1;
    }

    // Push TOTAL_EVENTS events with random payloads
    for (int i = 0; i < TOTAL_EVENTS; i++) {
        Event e = {
            .timestamp = i,
            .event = rand() % 3, // Assuming 3 EventType values: 0, 1, 2
            .payload_length = rand() % (MAX_PAYLOAD_SIZE + 1)
        };

        for (int j = 0; j < e.payload_length; j++) {
            e.payload[j] = rand() % 256;
        }

        if (!queue_push(&q, &e)) {
            printf("Push failed at index %d\n", i);
            return 1;
        }
    }

    if (queue_is_empty(&q)) {
        printf("Error: queue should not be empty after pushes\n");
        return 1;
    }

    // Pop all events and print
    for (int i = 0; i < TOTAL_EVENTS; i++) {
        Event e;
        if (!queue_pop(&q, &e)) {
            printf("Pop failed at index %d\n", i);
            return 1;
        }
        print_event(&e);
    }

    // Confirm queue is empty after all pops
    if (!queue_is_empty(&q)) {
        printf("Error: queue should be empty after popping all events\n");
        return 1;
    }

    printf("All tests passed.\n");
    return 0;
}
