#include "ring_buffer.h"
#include <string.h>

void ring_buffer_init(RingBuffer* rb) {
    memset(rb->data,0,sizeof(rb->data));
    rb->head = 0;
    rb->tail = 0;
    rb->full = false;
}

bool ring_buffer_push(RingBuffer* rb, uint8_t byte) {
    
    if(ring_buffer_is_full(rb)) return false;

    rb->data[rb->head] = byte;
    rb->head = (rb->head+1) % RING_BUFFER_CAPACITY;
    rb->full = rb->head == rb->tail;
    return true;
}

bool ring_buffer_pop(RingBuffer* rb, uint8_t* out) {
    if(ring_buffer_is_empty(rb)) return false;

    *out = rb->data[rb->tail];
    rb->data[rb->tail] = 0;
    rb->tail = (rb->tail +1) % RING_BUFFER_CAPACITY;
    rb->full = false;
    return true;
}

bool ring_buffer_is_empty(const RingBuffer* rb) {
    return rb->head == rb->tail && (!rb->full);
}

bool ring_buffer_is_full(const RingBuffer* rb) {
    // Implement in your solution
    return rb->full;
}
