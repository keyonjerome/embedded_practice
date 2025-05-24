#include <stdio.h>
#include <stdint.h>
#include "matrix_mult.h"

void print_matrix(int32_t* M, uint16_t rows, uint16_t cols) {
    for (uint16_t i = 0; i < rows; ++i) {
        for (uint16_t j = 0; j < cols; ++j) {
            printf("%4d ", M[i * cols + j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int32_t A[6] = {1, 2, 3,
                   4, 5, 6}; // 2x3
    int32_t B[6] = {7,  8,
                    9, 10,
                   11, 12}; // 3x2
    int32_t C[4] = {0};     // 2x2 result

    mat_mult_generic(A, B, C, 2, 3, 2);

    printf("Matrix A (2x3):\n");
    print_matrix(A, 2, 3);

    printf("Matrix B (3x2):\n");
    print_matrix(B, 3, 2);

    printf("Matrix C = A * B (2x2):\n");
    print_matrix(C, 2, 2);

    return 0;
}
