#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "tagged_malloc.h"

/*

malloc() returns an unaligned ptr
we need to bring this unaligned ptr to an aligned 32-whatever boundary
the tag is uint16_t, so we need to ask for (size + uint16_t) data, but then we need space for realignment

e.g:

return aligned ptr, we need to know how to get to the tag and the ptr to real data FROM the aligned ptr
easiest strat is to put those just before the aligned data, right?


tagged_aligned_malloc(1024,512,0x804)
{
    malloc(1024+sizeof(uint16_t)) -> 0x1048 -> this is not 512 aligned, it is 24 bytes off; we need to thus go up to the next 512 multiplier,
    which would be 1024+512=1536.

    attempt 2:

    data_size = sizeof(tag) + sizeof(ptr_to_real_data) + size 
                ^ however big the tag is ^ however big the ptr to the real data is ^ the actual data size
    
    we need data_size + (alignment-1) in the worst case, right?
    but do we always need alignment -1? if it fits exactly, we should be able to just take that much data
    no but we don't know where the beginning of the data segment will be until we ask for it, thus we need to ask for (alignment-1)
    
    ptr = malloc(data_size + (alignment-1));

    then we structure the memory like this
    | tag | ptr_to_real_data | ... space (if neeeded) | data
    
    ptr[0]
    ptr[1]
    ptr[(sizeof(tag))] = ptr_to_real_datal // e.g: if the tag is 2 bytes long, we move 2 bytes forward to write the ptr to real data
    ptr[ptr

    attempt 1:
    So how much memory do we actually need to ask for, to know for sure we will have enough space?
    In the worst case we are 1 exactly 1 ptr address away from the next alignment, and thus we would need
    (size+ sizeof(uint16_t) + (alignment-1))

    ((size+(alignment-1)+sizeof(uint16_t)) % alignment ) + (sizeof(uint16_t)+size)
    ^ how far out of alignment we could be in the worst case ^ the actual data size


}

*/
void* tagged_aligned_malloc(size_t size, size_t alignment, uint16_t tag) {



}

void tagged_free(void* ptr, uint16_t expected_tag) {

}

// Optional bonus features
uint16_t get_tag(void* ptr) {


}

void debug_dump_allocations(void) {

}