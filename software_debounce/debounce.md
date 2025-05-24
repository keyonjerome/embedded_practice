# GPIO Debounce Challenge

## Problem Description

You are tasked with writing a software debounce function for a digital GPIO button.

Due to electrical noise, the button state fluctuates between 0 and 1 during transitions. You sample the GPIO every 5 ms using a timer. To reliably detect a stable press, you require **8 consecutive samples of the same value** before considering the button "pressed".

## Function Prototype

```c
int debounce_button(uint8_t new_sample);
```

*Parameters:*
- new_sample: The latest raw GPIO reading (either 0 or 1).

*Returns:*
- 1 if the last 8 samples are all 1 (stable press).
- 0 otherwise.

*Constraints:*
You may use static variables to preserve history.
Use efficient operations suitable for embedded systems.

## How to Build
`make`
## How to Run Tests
`./main`

## Example Output
```
Sample 0 -> Output: 0
Sample 1 -> Output: 0
...
Sample 7 -> Output: 1
```
