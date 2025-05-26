#include "PWMController.hpp"
#include <algorithm>
/*
BASE + 0x00 + 0x10 * channel → CONTROL
BASE + 0x04 + 0x10 * channel → PERIOD
BASE + 0x08 + 0x10 * channel → DUTY
*/

// TODO: Implement all methods in PWMController
PWMController::PWMController(uint32_t base_address,uint8_t max_channels, uint32_t kTimerClockHz) : m_max_channels(max_channels), m_kTimerClockHz(kTimerClockHz){
    channels_ = reinterpret_cast<volatile PWMChannelRegisters*>(base_address);
};

void PWMController::start(uint8_t channel) {
    if (channel >= m_max_channels) return;
    channels_[channel].control = 1;
};
void PWMController::stop(uint8_t channel) {
    if (channel >= m_max_channels) return; 
    channels_[channel].control = 0;
}

void PWMController::setDutyCycle(uint8_t channel, float duty) {
    uint32_t period = channels_[channel].period;
    duty = std::min(std::max(duty, 0.0f), 1.0f);
    channels_[channel].duty = static_cast<uint32_t>(duty*period);
}

void PWMController::configure(uint32_t frequency_hz) {
    
    if (frequency_hz == 0) return;
    m_current_frequency = frequency_hz;
    
    uint32_t ticks = m_kTimerClockHz / frequency_hz;
    for(int i = 0; i < m_max_channels; i++) {
            channels_[i].period = ticks;
    }
}