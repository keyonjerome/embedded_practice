#include <stdint.h>
#define REQUIRED_SAMPLES 0b11111111

uint8_t history = 0; // can be tweaked to be 8 bits, 32, 16, 64, etc. 


int debounce_button(uint8_t new_sample) {
    static uint8_t history = 0;
    history = ( history << 1 ) | (new_sample & 0x01);

    return history == REQUIRED_SAMPLES;
}

