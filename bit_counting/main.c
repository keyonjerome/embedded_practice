#include <stdint.h>
#include <stdio.h>

// Function prototype
uint8_t count_faults(uint32_t input_status) {

    // count number of bits
    uint32_t input = input_status;
    uint8_t count = 0;
    while(input) {
        // 1111 & (1110) -> 1110
        // 1110 & (0111) -> 0110 
        // count each bit individually; subtract 1 and see what bit was set 
        input &= (input-1);
        count++;
    }
}

uint32_t bitsSetTable[256]; // 

void initialize_bit_table() {
    for(int i = 0; i < 256; i++) {
        // 0: 0
        // 1: 1
        // 10: 1
        // 11: 2
        // 100: 1
      //  bitsSetTable[i] = bitsSetTable[i << 2]
    }

}

uint8_t count_faults_bit_table(uint32_t input_status) {

}



int main(void) {
    uint32_t test_status = 0b10110100010010000000000010101101;

    uint8_t fault_count = count_faults(test_status);
    printf("Number of faults: %u\n", fault_count);

    return 0;
}
