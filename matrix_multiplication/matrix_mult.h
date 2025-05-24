#ifndef MATRIX_MULT_H
#define MATRIX_MULT_H

#include <stdint.h>

void mat_mult_generic(int32_t* A, int32_t* B, int32_t* C,
                      uint16_t m, uint16_t n, uint16_t p);

#endif // MATRIX_MULT_H
