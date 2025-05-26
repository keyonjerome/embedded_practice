#include "PWMController.hpp"
#include <iostream>
#include <iomanip>

constexpr uint8_t kNumChannels = 4;
constexpr uint32_t kTimerClockHz = 1000000; // 1 MHz
constexpr uint32_t kBaseAddr = 0x10000000;    // Simulated memory address

// Simulate memory-mapped registers with a static array
static uint32_t fake_register_block[kNumChannels * 4] = {0};

int main() {
    // Instantiate PWMController with fake register block
    PWMController pwm(reinterpret_cast<uintptr_t>(fake_register_block), kNumChannels, kTimerClockHz);

    std::cout << "Configuring PWM to 1kHz..." << std::endl;
    pwm.configure(1000); // Set to 1kHz (1000 Hz)

    std::cout << "Setting duty cycles..." << std::endl;
    pwm.setDutyCycle(0, 0.25f); // 25%
    pwm.setDutyCycle(1, 0.50f); // 50%
    pwm.setDutyCycle(2, 0.75f); // 75%
    pwm.setDutyCycle(3, 1.00f); // 100%

    std::cout << "Starting all channels..." << std::endl;
    for (int i = 0; i < kNumChannels; ++i) {
        pwm.start(i);
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nRegister Dump:\n";
    for (int i = 0; i < kNumChannels; ++i) {
        auto base = i * 4; // 4 x 32-bit registers per channel
        std::cout << "Channel " << i << ":\n";
        std::cout << "  CONTROL = " << fake_register_block[base + 0] << "\n";
        std::cout << "  PERIOD  = " << fake_register_block[base + 1] << "\n";
        std::cout << "  DUTY    = " << fake_register_block[base + 2] << "\n";
    }

    std::cout << "\nStopping channel 2...\n";
    pwm.stop(2);

    std::cout << "CONTROL register for channel 2 is now: "
              << fake_register_block[2 * 4 + 0] << "\n";

    return 0;
}
