#ifndef SENSOR_PACKET_H
#define SENSOR_PACKET_H

#include <stdint.h>

uint32_t encode_packet(uint8_t sensor_type, uint8_t sensor_id, int16_t temperature, uint8_t humidity, uint8_t status_flags);
void decode_packet(uint32_t packet, uint8_t* sensor_type, uint8_t* sensor_id, int16_t* temperature, uint8_t* humidity, uint8_t* status_flags);

#endif // SENSOR_PACKET_H