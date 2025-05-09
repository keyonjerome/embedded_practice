// sensor_packet.c
#include "sensor_packet.h"
#include <stdint.h>

uint32_t encode_packet(uint8_t sensor_type, uint8_t sensor_id, int16_t temperature, uint8_t humidity, uint8_t status_flags) {
    // TODO: Implement bit-packing
    return 0;
}

void decode_packet(uint32_t packet, uint8_t* sensor_type, uint8_t* sensor_id, int16_t* temperature, uint8_t* humidity, uint8_t* status_flags) {
    // TODO: Implement bit-unpacking
}