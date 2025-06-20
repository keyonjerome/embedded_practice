#ifndef TAGGED_MALLOC_H
#define TAGGED_MALLOC_H

#include <stdint.h>
#include <stddef.h>

void* tagged_aligned_malloc(size_t size, size_t alignment, uint16_t tag);
void tagged_free(void* ptr, uint16_t expected_tag);

// Optional bonus features
uint16_t get_tag(void* ptr);
void debug_dump_allocations(void);

#endif // TAGGED_MALLOC_H
