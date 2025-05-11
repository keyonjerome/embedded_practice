#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>
#include <stdbool.h>

#define RING_BUFFER_CAPACITY 16

typedef struct {
    uint8_t data[RING_BUFFER_CAPACITY];
    uint8_t head;
    uint8_t tail;
    bool full;
} RingBuffer;

void ring_buffer_init(RingBuffer* rb);
bool ring_buffer_push(RingBuffer* rb, uint8_t byte);
bool ring_buffer_pop(RingBuffer* rb, uint8_t* out);
bool ring_buffer_is_empty(const RingBuffer* rb);
bool ring_buffer_is_full(const RingBuffer* rb);

#endif // RING_BUFFER_H
