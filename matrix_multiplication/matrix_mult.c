#include "matrix_mult.h"

// Multiply A[m x n] * B[n x p] = C[m x p]
// A  1 2  B 5 6 9 
//    3 4    7 8 10
void mat_mult_generic(int32_t* A, int32_t* B, int32_t* C,
                      uint16_t m, uint16_t n, uint16_t p) {
    // TODO: Implement matrix multiplication
    for(int i = 0; i < m; i++) {
        // sum each row in matrix B
        for(int j = 0; j < p; j++) {
            /*
            A[col 0 row 0]*B[col 0 row 0] + B[col 1 row 0] + B[col 2 row 0]
            A[col 1 row 0]*B[col 0 row 1 ] + B[col 1 row 1] + B[col 2 row 1]
            A[col]
            
            
            */
        }
    }
}
