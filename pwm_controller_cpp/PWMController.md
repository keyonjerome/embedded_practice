# Embedded C++ Challenge: PWMController Design

## Objective

Implement a C++ class called `PWMController` that configures and controls PWM output channels on a memory-mapped microcontroller peripheral.

## Requirements

- Must support:
  - Configuring a global PWM frequency
  - Setting a duty cycle per channel (0.0–1.0)
  - Starting/stopping individual channels
- Memory-mapped register layout:
```
BASE + 0x00 + 0x10 * channel → CONTROL
BASE + 0x04 + 0x10 * channel → PERIOD
BASE + 0x08 + 0x10 * channel → DUTY
```
- Support up to 4 channels
- No dynamic memory or STL containers
- No exceptions or RTTI

## Files

- `PWMController.hpp` – Class declaration
- `PWMController.cpp` – Class implementation
- `main.cpp` – Test harness (use dummy register emulation if needed)

## How to Build

```make```
## How to Run
```./pwm_test```
## Bonus (Optional)
How would you add interrupt handling?
How could you extend this to support multiple PWM peripherals?