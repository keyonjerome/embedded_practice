# Sensor Packet Encoder/Decoder (Embedded C Practice)

## Problem Overview

You are implementing a communication protocol for a custom sensor. The sensor transmits compact 32-bit packets encoding its ID, type, temperature, humidity, and status flags. Your goal is to implement functions in C that encode and decode these packets using bit manipulation.

## Packet Structure (32 bits total)

```
[31:30] Sensor Type       (2 bits)
[29:24] Sensor ID         (6 bits)
[23:12] Temperature (C)   (12 bits, signed, two's complement)
[11:4]  Humidity (%)      (8 bits, unsigned)
[3:0]   Status Flags      (4 bits)
```

## Requirements

1. **Encoder Function:**
   ```c
   uint32_t encode_packet(uint8_t sensor_type, uint8_t sensor_id, int16_t temperature, uint8_t humidity, uint8_t status_flags);
   ```
   - Returns a packed 32-bit unsigned integer.
   - Inputs must be range-validated and masked appropriately.

2. **Decoder Function:**
   ```c
   void decode_packet(uint32_t packet, uint8_t* sensor_type, uint8_t* sensor_id, int16_t* temperature, uint8_t* humidity, uint8_t* status_flags);
   ```
   - Extracts values from the 32-bit packet using bit masking and shifting.
   - Handles sign extension for the 12-bit temperature.

## Additional Notes
- Avoid using `struct` packing or `union` tricks.
- Focus on raw bitwise operations: `<<`, `>>`, `&`, `|`.
- Add error checking and debug output as needed in `main.c`.

## Test Case Suggestion
```c
// Sample values to encode:
// sensor_type = 2, sensor_id = 45, temperature = -300, humidity = 75, status_flags = 9
```