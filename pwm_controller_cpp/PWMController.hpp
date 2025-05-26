#ifndef PWM_CONTROLLER_HPP
#define PWM_CONTROLLER_HPP

#include <stdint.h>

struct __attribute__((packed)) PWMChannelRegisters {
    volatile uint32_t control; // 0x00
    volatile uint32_t period; // 0x04
    volatile uint32_t duty; // 0x08
    uint32_t _reserved; // pad to 16 bytes;
    // total size: 12 bytes
};


class PWMController {
public:
    PWMController(uint32_t base_address, uint8_t max_channels, uint32_t kTimerClockHz);
    
    void configure(uint32_t frequency_hz);
    void setDutyCycle(uint8_t channel, float duty);
    void start(uint8_t channel);
    void stop(uint8_t channel);

private:
    volatile PWMChannelRegisters* channels_;
    const uint8_t m_max_channels;
    const uint32_t m_kTimerClockHz;
    uint32_t m_current_frequency;
};




#endif // PWM_CONTROLLER_HPP
