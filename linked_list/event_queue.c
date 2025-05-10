
#include "event_queue.h"
#include <stdlib.h>
#include <string.h>  // Optional for memcpy use

void queue_init(EventQueue* q) {
    // Initialize head and tail to null
    q->head = NULL;
    q->tail = NULL;
}

bool queue_push(EventQueue* q, const Event* new_event) {
    EventNode* n = malloc(sizeof(EventNode));
    
    if(n == NULL) return false;

    // copy over event data
    memcpy(&n->data,new_event,sizeof(Event));
    n->next = NULL;
    
    // empty LL
    if(q->head == NULL) {
        q->head = n;
        q->tail = n;
    }
    // non-empty LL
    else {
        q->tail->next = n;
        q->tail = n;
    }
    return true;
}

bool queue_pop(EventQueue* q, Event* out_event) {
    // If queue is empty, return false
    // Copy the event from head node into out_event
    // Free the head node and advance head pointer
    // If head becomes NULL, tail must also become NULL

    // if queue empty, return false
    if(queue_is_empty(q)) return false;

    EventNode* old_head = q->head; // hold the head of the queue temporarily
    memcpy(out_event,&q->head->data,sizeof(Event));
    q->head = q->head->next;    // advance the head of the queue
    
    // if only one item in queue
    if(q->head == NULL) {
        q->tail = NULL;
    }

    free(old_head);
    return true;
}

bool queue_is_empty(const EventQueue* q) {
    return q->head == NULL;
}
