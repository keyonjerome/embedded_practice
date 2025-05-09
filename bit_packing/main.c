#include <stdio.h>
#include <stdint.h>
#include "sensor_packet.h"

void run_test(uint8_t type, uint8_t id, int16_t temp, uint8_t hum, uint8_t flags) {
    printf("\nTest case:\n");
    printf("  Type: %u, ID: %u, Temp: %d, Hum: %u, Flags: %u\n", type, id, temp, hum, flags);

    uint32_t packet = encode_packet(type, id, temp, hum, flags);
    printf("  Encoded packet: 0x%08X\n", packet);

    uint8_t d_type, d_id, d_hum, d_flags;
    int16_t d_temp;
    decode_packet(packet, &d_type, &d_id, &d_temp, &d_hum, &d_flags);

    printf("  Decoded:\n");
    printf("    Type: %u\n", d_type);
    printf("    ID: %u\n", d_id);
    printf("    Temp: %d\n", d_temp);
    printf("    Hum: %u\n", d_hum);
    printf("    Flags: %u\n", d_flags);
}

int main(void) {
    run_test(2, 45, -300, 75, 9);
    run_test(1, 63, 1023, 100, 15);
    run_test(3, 0, -2048, 0, 0);
    return 0;
}
