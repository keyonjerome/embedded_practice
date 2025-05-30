# 🔧 Problem: Event Queue for Interrupt-Driven System

Context:
You’re working on firmware for a real-time embedded system that processes events generated by hardware interrupts. Each event includes:

- A timestamp (e.g., uint32_t)
- An event type (enum of 3–5 values)
- An optional payload (up to 8 bytes)

Since events can arrive at unpredictable times and must be processed in order, you must implement a custom linked list that stores these events in a FIFO manner.

✅ Requirements
Create a struct to represent a single event node in the linked list.

Implement a basic singly-linked list with:

void queue_init(EventQueue* q)

bool queue_push(EventQueue* q, Event* new_event)

bool queue_pop(EventQueue* q, Event* out_event)

bool queue_is_empty(const EventQueue* q)

The list must be dynamically allocated (assume malloc and free are allowed for this exercise).

Handle memory safety properly:

Avoid memory leaks

Return false on allocation failure

Implement a test function in main() to:

Add 3 events

Remove 2

Add 1 more

Remove all and print them in order

