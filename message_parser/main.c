#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "parser.h"

void on_message_parsed(uint8_t command, const uint8_t* payload, uint8_t length) {
    printf("Parsed message:\n");
    printf("  Command: 0x%02X\n", command);
    printf("  Payload Length: %d\n", length);
    printf("  Payload:");
    for (uint8_t i = 0; i < length; i++) {
        printf(" 0x%02X", payload[i]);
    }
    printf("\n\n");
}

void run_test(const char* label, const uint8_t* data, size_t len) {
    printf("========== %s ==========\n", label);
    parser_init();
    for (size_t i = 0; i < len; ++i) {
        parser_process_byte(data[i]);
    }
    printf("\n");
}

int main(void) {
    // Test Case 1: Minimum valid message (command only)
    uint8_t msg_minimal[] = {0xAA, 0x01, 0x05, 0x01 ^ 0x05};
    run_test("Test 1: Minimal Valid Message", msg_minimal, sizeof(msg_minimal));

    // Test Case 2: Max payload (254 bytes)
    uint8_t msg_max_payload[1 + 1 + 1 + 254 + 1];
    msg_max_payload[0] = 0xAA;
    msg_max_payload[1] = 255;
    msg_max_payload[2] = 0x10;
    uint8_t checksum = 0xFF ^ 0x10;
    for (int i = 0; i < 254; i++) {
        msg_max_payload[3 + i] = i;
        checksum ^= i;
    }
    msg_max_payload[3 + 254] = checksum;
    run_test("Test 2: Max Payload", msg_max_payload, sizeof(msg_max_payload));

    // Test Case 3: Truncated message (missing checksum)
    uint8_t msg_truncated[] = {0xAA, 0x02, 0x01, 0xFF};  // Missing checksum
    run_test("Test 3: Truncated Message", msg_truncated, sizeof(msg_truncated));

    // Test Case 4: Noise before start byte
    uint8_t msg_noise[] = {0x13, 0x99, 0xFE, 0xAA, 0x01, 0x07, 0x01 ^ 0x07};
    run_test("Test 4: Noise Before Valid Message", msg_noise, sizeof(msg_noise));

    // Test Case 5: Bad checksum
    uint8_t msg_bad_checksum[] = {0xAA, 0x02, 0x02, 0x42, 0x99};  // Bad checksum
    run_test("Test 5: Bad Checksum", msg_bad_checksum, sizeof(msg_bad_checksum));

    // Test Case 6: Multiple valid messages in one stream
    uint8_t msg_multi[] = {
        0xAA, 0x02, 0x01, 0x02, 0x02 ^ 0x01 ^ 0x02,
        0xAA, 0x01, 0x03, 0x01 ^ 0x03
    };
    run_test("Test 6: Multiple Messages in One Stream", msg_multi, sizeof(msg_multi));

    return 0;
}
