# 🧪 Embedded Systems C Interview Question: Message Protocol Parser

You are writing firmware for a microcontroller that communicates with a host system (e.g., a Raspberry Pi) via UART.

The host sends messages using a **custom binary protocol** defined as follows:

## 📦 Message Format

Each message sent from the host to the device has the structure:

`[START_BYTE][LENGTH][COMMAND][PAYLOAD][CHECKSUM]`


### Field Descriptions:

| Field       | Size (bytes) | Description                                                                 |
|-------------|--------------|-----------------------------------------------------------------------------|
| START_BYTE  | 1            | Always `0xAA`. Used to detect the start of a new message.                   |
| LENGTH      | 1            | Length of `[COMMAND][PAYLOAD]` in bytes. Value must be between 1 and 255.  |
| COMMAND     | 1            | Command ID (e.g., `0x01` = LED ON, `0x02` = LED OFF).                       |
| PAYLOAD     | 0–254        | Optional binary payload data. Length is `LENGTH - 1`.                       |
| CHECKSUM    | 1            | XOR of all bytes from `[LENGTH]` to the last byte of the payload.          |

### ✅ Example Message

`{0xAA, 0x03, 0x01, 0x05, 0x07, 0x03 ^ 0x01 ^ 0x05 ^ 0x07}`

START_BYTE: 0xAA

LENGTH: 3

COMMAND: `0x01`

PAYLOAD: `0x05, 0x07`

CHECKSUM: `0x03 ^ 0x01 ^ 0x05 ^ 0x07`

## 🧱 Requirements
Implement a stateful parser that reconstructs valid messages from incoming bytes.

You must implement the following functions:


- `void parser_init(void)`
- `void parser_process_byte(uint8_t byte)`
- `void on_message_parsed(uint8_t command, const uint8_t* payload, uint8_t length)`

## Functional Constraints
`parser_process_byte()` is called once per received byte.
`
When a valid message is fully received, `on_message_parsed()` must be called.

The parser must reset its internal state if:

A bad checksum is detected.

An unexpected `START_BYTE` appears mid-message.

An invalid `length` is encountered.

## Implementation Rules
Do not use dynamic memory allocation (malloc, calloc, etc).

Assume the platform has limited RAM and CPU.

Your parser must be robust and handle noisy input.