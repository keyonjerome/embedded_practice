#include <stdio.h>
#include "debounce.h"

int main() {
    uint8_t samples[] = {0, 1, 1, 1, 1, 1, 1, 1, 1};
    int num_samples = sizeof(samples) / sizeof(samples[0]);

    for (int i = 0; i < num_samples; i++) {
        int result = debounce_button(samples[i]);
        printf("Sample %d -> Input: %d -> Output: %d\n", i, samples[i], result);
    }

    return 0;
}