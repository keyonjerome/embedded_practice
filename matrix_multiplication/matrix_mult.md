# Generic Matrix Multiplication in Embedded C

This project demonstrates how to implement generic matrix multiplication for use in embedded systems using C. The multiplication supports matrices of arbitrary valid sizes stored as flat arrays in row-major format.

## 📁 File Structure
.
├── main.c # Contains test cases and matrix print function
├── matrix_mult.c # Matrix multiplication implementation (to be completed)
├── matrix_mult.h # Header file with function declaration
├── Makefile # Build instructions
└── README.md # This documentation

## ✅ Problem Statement

Implement a function that multiplies two matrices `A` and `B`, producing result `C`:

- `A` is of size `m x n`
- `B` is of size `n x p`
- `C` will be of size `m x p`

All matrices are stored as **row-major flat arrays** of type `int32_t`.

### Function Prototype

```c
void mat_mult_generic(int32_t* A, int32_t* B, int32_t* C,
                      uint16_t m, uint16_t n, uint16_t p);
```

### ⚙️ Compilation
- To compile the project: `make`
- To clean the build artifacts: `make clean`

### 🚀 Run
After building, run the test executable:
`./test`
You should see the contents of matrices A, B, and the resulting matrix C printed to the terminal.

## 🧪 Sample Test Case
Multiplies: Matrix A (2x3):
```
1  2  3  
4  5  6  
```
Matrix B (3x2):
```
 7   8  
 9  10  
11  12  
```
Expected Matrix C (2x2):
```
 58  64  
139 154  
```
### 📌 Constraints
- No dynamic memory allocation (malloc, calloc, etc.).
- All buffers must be pre-allocated by the caller.
- Optimize for clarity and low memory usage, suitable for embedded systems.

### 🔧 TODO
- Implement the logic in matrix_mult.c
- Add additional tests if desired
- Optionally port to a microcontroller development environment (e.g., STM32, AVR)