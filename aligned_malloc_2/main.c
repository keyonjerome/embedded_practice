#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "tagged_malloc.h"

int main() {
    void* ptr = tagged_aligned_malloc(64, 32, 0xBEEF);
    if (!ptr) {
        printf("Allocation failed!\n");
        return 1;
    }

    printf("Memory allocated at %p\n", ptr);
    
    // Optional: retrieve and print tag
    uint16_t tag = get_tag(ptr);
    printf("Retrieved tag: 0x%04X\n", tag);

    tagged_free(ptr, 0xBEEF);

    return 0;
}
