// sensor_packet.c
#include "sensor_packet.h"
#include <stdint.h>

/*
[31:30] Sensor Type       (2 bits)
[29:24] Sensor ID         (6 bits)
[23:12] Temperature (C)   (12 bits, signed, two's complement)
[11:4]  Humidity (%)      (8 bits, unsigned)
[3:0]   Status Flags      (4 bits)
*/

typedef union {
    uint32_t raw_data;
    
    struct {
        uint8_t sensor_type : 2;
        uint8_t sensor_id : 6;
        int16_t temperature_celsius : 12;
        uint8_t humidity_percent : 8;
        uint8_t status: 4;
    };
} SensorPacket;




uint32_t encode_packet(uint8_t sensor_type, uint8_t sensor_id, int16_t temperature, uint8_t humidity, uint8_t status_flags) {
    
    // -------- | -------- | -------- | --111111 

    uint32_t result = 0;
    uint32_t sensor_type_shifted =  (((uint32_t) sensor_type & ((1 << 2)-1)) << 30 ); // 0b11000000
    uint32_t sensor_id_shifted =  (( (uint32_t) sensor_id & ((1 << 6)-1)) << 24);
    // Be incredibly careful with sign extension here.
    // In C, when you use a signed type like int16_t in an expression, it is first *promoted* to int (typically 32-bit).
    // If the original value is negative (e.g., -1), promotion extends the sign bit (e.g., 0xFFFF becomes 0xFFFFFFFF).
    //
    // Then, casting that to uint32_t *does not change the bits*. You now have 0xFFFFFFFF in a 32-bit unsigned value.
    //
    // If you then try to mask or truncate it back to 12 bits (e.g., & 0x0FFF), you've already lost the original pattern,
    // what you wanted was just the low 12 bits of the original two's complement value.
    //
    // ✅ The correct solution is to cast to uint16_t *before* promoting:
    // This ensures you're working with the raw bit pattern (e.g., 0x0FFF for -1) before widening to 32-bit.
    // this got me badly; i had a worse explanation here, and used genai to improve it
    uint32_t temperature_shifted = ( ( (uint32_t) ((uint16_t) temperature & ((1 << 12)-1))) << 12);
    uint32_t humidity_shifted = ( ( (uint32_t) humidity & ((1 << 8)-1)) << 4);
    uint32_t status_shifted = ( ((uint32_t) status_flags) & ((1 << 4)-1));
    
    result |= sensor_type_shifted | sensor_id_shifted | temperature_shifted | humidity_shifted | status_shifted;
    return result;
}

void decode_packet(uint32_t packet, uint8_t* sensor_type, uint8_t* sensor_id, int16_t* temperature, uint8_t* humidity, uint8_t* status_flags) {
    
    *sensor_type = (uint8_t) (packet >> 30);
    *sensor_id = (uint8_t) ((packet >> 24) & ((1 << 6) - 1 )); // mask off the first 2 bits
    // you need to manually do sign extension here, or you will lose the negative portion of the value.
    // if you just do uint16_t -> int16_t it will be incorrect.
    uint16_t temp_raw = ((uint16_t) ((packet >> 12) & ((1 << 12) - 1)));
    // we check 0x800 =0b0000100000000000->; the sign bit lives at that 12th bit. if it's 1, we know it's a negative number
    // if it's negative, we sign-extend it by OR-ing with 0xF000 (not a negation)
    *temperature = temp_raw & 0x800 ? (int16_t) (temp_raw | 0xF000) : (int16_t) temp_raw;

    *humidity =  (uint8_t) ((packet >> 4) & ((1 << 8) - 1));
    *status_flags = (uint8_t) (packet & ((1 << 4)-1));
}
void decode_packet_union(uint32_t packet, uint8_t* sensor_type, uint8_t* sensor_id, int16_t* temperature, uint8_t* humidity, uint8_t* status_flags) {
    SensorPacket data = {};
    data.raw_data = packet;
    *sensor_type = data.sensor_type;
    *sensor_id = data.sensor_id;
    *temperature = data.temperature_celsius;
    *humidity = data.humidity_percent;
    *status_flags = data.status;
}