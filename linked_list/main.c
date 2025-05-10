#include "event_queue.h"
#include <stdio.h>

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

    // 1. Create and push 3 events
    for(int i = 0; i < 3; i++) {
        Event x = {
            .event = EVENT_HIGH,
            .payload = {i,i+1,i+2,i+3,i+4,i+5},
            .payload_length = 6,
            .timestamp = i
        };
        queue_push(&q,&x);
    };

    // 2. Pop 2 events and print them
    Event temp  = {};
    queue_pop(&q,&temp);
    printf("Event with timestamp %i : %i\r\n",temp.timestamp,temp.event);
    queue_pop(&q,&temp);
    printf("Event with timestamp %i : %i\r\n",temp.timestamp,temp.event);
    // 3. Push 1 more event
    Event push = {
        .event = EVENT_LOW,
        .payload = {-1,-1,-1,-1},
        .payload_length=4,
        .timestamp = 20
    };
    queue_push(&q,&push);
    // 4. Pop all remaining and print them
    while(!queue_is_empty(&q)) {
        Event temp  = {};
        queue_pop(&q,&temp);
        printf("Event with timestamp %i : %i\r\n",temp.timestamp,temp.event);
    }

    return 0;
}
