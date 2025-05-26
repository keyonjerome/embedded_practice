#ifndef LOW_PASS_FILTER_H
#define LOW_PASS_FILTER_H

#include <stdint.h>




// Q1.15 fixed-point type
typedef int16_t q1_15;
#define FIXED_POINT_SCALE (1 << 15)
#define LOW_PASS_FILTER_ALPHA ((q1_15) (0.01f *FIXED_POINT_SCALE))

// Q1.15 helpers
q1_15 to_fixed(float f);
float to_float(q1_15 q);

/**
 * Initialize or reset the low-pass filter state.
 */
void low_pass_filter_reset(void);

/**
 * Apply a low-pass filter to the new sample.
 * 
 * @param x_n The new input sample (Q1.15 fixed-point)
 * @return The filtered output sample (Q1.15 fixed-point)
 */
q1_15 low_pass_filter(q1_15 x_n);

#endif // LOW_PASS_FILTER_H
