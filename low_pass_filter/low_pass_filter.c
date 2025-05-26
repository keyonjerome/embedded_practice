//low_pass_filter.c
#include "low_pass_filter.h"

static q1_15 prev = 0;

// Helper to convert float to Q1.15
q1_15 to_fixed(float f) {
    return (q1_15)(f * FIXED_POINT_SCALE);
}

// Helper to convert Q1.15 to float
float to_float(q1_15 q) {
    return (float)q / FIXED_POINT_SCALE;
}

void low_pass_filter_reset(void) {
    prev = 0;
}

/**
 * Apply a low-pass filter to the new sample.
 * 
 * @param x_n The new input sample (Q1.15 fixed-point)
 * @return The filtered output sample (Q1.15 fixed-point)
 */
q1_15 low_pass_filter(q1_15 x_n) {

    const q1_15 alpha = LOW_PASS_FILTER_ALPHA; 
    int32_t term_1 = (int32_t) alpha*x_n;
    int32_t term_2 = (int32_t) (FIXED_POINT_SCALE-alpha)*prev;

    q1_15 signal =  (q1_15) ((term_1+term_2) >> 15);
    prev = signal;
    return signal;
}