#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "parser.h"


int main(void) {
    parser_init();

    // Valid message: {START, LENGTH=3, CMD=0x01, PAYLOAD=0x05, 0x07, CHECKSUM}
    uint8_t test_msg[] = {0xAA, 0x03, 0x01, 0x05, 0x07, 0x03 ^ 0x01 ^ 0x05 ^ 0x07};

    printf("Sending valid message...\n");
    for (size_t i = 0; i < sizeof(test_msg); ++i) {
        parser_process_byte(test_msg[i]);
    }

    // Corrupted checksum
    uint8_t bad_checksum_msg[] = {0xAA, 0x01, 0x02, 0xFF};

    printf("\nSending message with bad checksum...\n");
    for (size_t i = 0; i < sizeof(bad_checksum_msg); ++i) {
        parser_process_byte(bad_checksum_msg[i]);
    }

    // Split message with noise in between
    uint8_t noisy[] = {0x00, 0xAA, 0x02, 0x09, 0xFF, 0x02 ^ 0x09 ^ 0xFF};

    printf("\nSending message with leading noise...\n");
    for (size_t i = 0; i < sizeof(noisy); ++i) {
        parser_process_byte(noisy[i]);
    }

    return 0;
}
