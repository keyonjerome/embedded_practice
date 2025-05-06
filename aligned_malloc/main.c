#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
/*
Write a function in C that allocates a memory block of size bytes aligned to a specified alignment (which is a power of two),
similar to posix_memalign, but using malloc() internally.
*/

void* aligned_malloc(size_t size, size_t alignment);
void aligned_free(void* ptr);


void* aligned_malloc(size_t size, size_t alignment) {

    // malloc will return a word-aligned address, but not necessarily an
    // alignment-variable aligned address (e.g: if alignment is 128, we could get 0x64 when we should only
    // be getting multiples of 128

    /* We need to do a few things:
        1. "Overallocate" the amount of data; let's say we have an address 0x1001 (just out of line), and we want to start data at alignment x1004 (4-byte alignment).
            Thus, the most data we need to allocate in extra is alignment -1 bytes. We don't know how much we will need in advance of our malloc() call, so 
            We also need to allocate an extra sizeof(void*) bytes to store a pointer to the raw malloc'd data, which use for deallocation
        2. "Shift up" the final returned pointer by however much we need to in order to make it aligned
        3. Store the normal malloc() pointer right before the aligned data
    */
   
    // the max amount of extra we'll need is alignment -1 (see 0x1001 example). Then, we add in the size of the POINTER returned malloc(), which is just sizeof(void*).
    size_t extra = alignment - 1 + sizeof(void*); 

    void* raw = malloc(size + extra); // allocate all of our dat

    // If malloc fails, return null (safety)
    if(raw == NULL) return NULL;
    uintptr_t raw_addr = (uintptr_t)raw; // convert to a type where we can do maf
    // alignment buffer space | raw ptr | aligned memory
    uintptr_t misalignment = (raw_addr + sizeof(void*)) % alignment; // how far are we off from proper alignment? use a ptr type to work with ptr math
    // if misalignment == 0 ; the raw address + the size of the original malloc ptr lands us at a perfect alignment space. Thus, aligned address should be just that!
    // else, we add the misalignment to the adjusted address to get to the proper spot
    uintptr_t aligned_address = raw_addr + sizeof(void*);
    if(misalignment != 0) aligned_address = (raw_addr +sizeof(void*)) + (alignment-misalignment);

    void** raw_def = (void**) aligned_address;
    *(raw_def-1) = raw; // store the malloc ptr right before the aligned address, so we don't need to keep track of it anywhere else 

    // return the aligned address
    return (void*) aligned_address;
}

void aligned_free(void* ptr) {
    //free(*((void**) ptr) -1 );
    // Be so, so careful with this. The above doesn't work. The below does. Why? We need to make sure that before we do any pointer arithmetic, we convert to a 
    // void** type, or it won't work, as void* has no type defined--you can't do any pointer or size arithmetic on it.
    // So we convert it to void**. Great. Now, we can do pointer arithmetic, and we subtract 1 to get to the location of the 
    free(*(((void**) ptr) -1 ));

}


int main() {
    size_t size = 100;
    size_t alignment = 64;
    
    void* ptr = aligned_malloc(size, alignment);
    if (!ptr) {
        printf("Allocation failed\n");
        return 1;
    }

    if (((uintptr_t)ptr % alignment) != 0) {
        printf("Pointer is not aligned!\n");
    } else {
        printf("Success! Aligned pointer: %p\n", ptr);
    }

    aligned_free(ptr);
    return 0;
}
