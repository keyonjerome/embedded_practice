#ifndef EVENT_QUEUE_H
#define EVENT_QUEUE_H

#include <stdint.h>
#include <stdbool.h>

// === YOU MUST DEFINE THESE TYPES YOURSELF ===

// Define `Event`:
// - Timestamp (e.g., uint32_t)
// - Event type (an enum of at least 3 types)
// - Payload: up to 8 bytes of data (uint8_t array)
// - Payload length (uint8_t or similar)


typedef enum {
    EVENT_HIGH,
    EVENT_LOW,
    EVENT_MED
} EventType;

struct Event {
    uint32_t timestamp;
    EventType event;
    uint8_t payload[8];
    uint8_t payload_length;
};

struct EventNode {
    struct Event data;
    struct EventNode* next;
};

// Define `EventQueue`:
// - A FIFO queue to hold events
// - Backed by a singly linked list
// - Must support efficient push to tail and pop from head


struct EventQueue {
    struct EventNode* head;
    struct EventNode* tail;
};

typedef struct EventNode EventNode;
typedef struct Event Event;
typedef struct EventQueue EventQueue;

// === FUNCTION PROTOTYPES ===

void queue_init(EventQueue* q);
// Initializes the event queue

bool queue_push(EventQueue* q, const Event* new_event);
// Allocates and appends a new node to the queue
// Returns false if memory allocation fails

bool queue_pop(EventQueue* q, Event* out_event);
// Removes the oldest event from the queue and copies it to `out_event`
// Returns false if the queue is empty

bool queue_is_empty(const EventQueue* q);

#endif // EVENT_QUEUE_H
