#include <stdio.h>
#include "low_pass_filter.h"


int main() {
    low_pass_filter_reset();

    // Simulated noisy input signal
    float input_signal[] = {1.0, 1.1, 1.5, 3.0, 1.2, 1.0, 0.9, 0.95, 1.0};
    int len = sizeof(input_signal) / sizeof(input_signal[0]);

    printf("Input\tFiltered\n");
    for (int i = 0; i < len; i++) {
        q1_15 input_fixed = to_fixed(input_signal[i]);
        q1_15 output_fixed = low_pass_filter(input_fixed);
        printf("%.2f\t%.4f\n", input_signal[i], to_float(output_fixed));
    }

    return 0;
}
