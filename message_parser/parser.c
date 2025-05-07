#include "parser.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
/*

### Field Descriptions:

| Field       | Size (bytes) | Description                                                                 |
|-------------|--------------|-----------------------------------------------------------------------------|
| START_BYTE  | 1            | Always `0xAA`. Used to detect the start of a new message.                   |
| LENGTH      | 1            | Length of `[COMMAND][PAYLOAD]` in bytes. Value must be between 1 and 255.  |
| COMMAND     | 1            | Command ID (e.g., `0x01` = LED ON, `0x02` = LED OFF).                       |
| PAYLOAD     | 0–254        | Optional binary payload data. Length is `LENGTH - 1`.                       |
| CHECKSUM    | 1            | XOR of all bytes from `[LENGTH]` to the last byte of the payload.          |
*/

/*
// how to get a pointer to a struct you're currently creating. not that we need it for this, but good to know
typedef struct _msg_state MessageStateMachine;

//
struct _msg_state {
    MessageStateMachine* x;
};
*/

#define START_BYTE 0xAA

enum MessageState {INIT,WAITING,IN_PROGRESS,COMPLETE};
enum MessageFieldState {START,LENGTH,COMMAND,PAYLOAD,CHECKSUM};


typedef struct _msg {
    uint8_t length;
    uint8_t cmd;
    uint8_t payload[255];
    uint8_t checksum;
    uint8_t running_checksum;
} Message;


uint8_t parser_state = WAITING;
uint8_t msg_field_state = START;
uint8_t length_index = 0;
Message current_msg = {};

void parser_init(void) {
    parser_state = WAITING;

}
void parser_process_byte(uint8_t byte) {

    switch(parser_state) {
        case INIT:
            // should not be getting data while uninitialized; error behaviour
            break;
        case WAITING:
            if(byte == START_BYTE) {
                parser_state = IN_PROGRESS;
                msg_field_state = LENGTH;
                length_index = 0;
                current_msg.running_checksum = 0;
                printf("Moving to in progress state\n");
            }
            // ignore non-start bytes
            break;

        case IN_PROGRESS:
            switch(msg_field_state) {
                case LENGTH:
                    if (byte < 1) {
                        printf("Invalid length.\r\n");
                        break;
                    }
                    current_msg.running_checksum ^= byte;
                    current_msg.length = byte;
                    msg_field_state = COMMAND;
                    printf("Length: %i \r\n",current_msg.length);
                    break;
                case COMMAND:
                    current_msg.running_checksum ^= byte;
                    current_msg.cmd = byte;
                    // This is an edge case I didn't consider when writing this the first time.
                    if (current_msg.length == 1) {
                        // No payload; go directly to checksum
                        msg_field_state = CHECKSUM;
                    } else {
                        msg_field_state = PAYLOAD;
                    }
                    length_index = 0;
                    printf("Command: %i \r\n",current_msg.cmd);
                    break;
                case PAYLOAD:
                    current_msg.running_checksum ^= byte;
                    current_msg.payload[length_index] = byte;
                    length_index++;
                    if(length_index == current_msg.length-1) msg_field_state = CHECKSUM;
                    break;
                case CHECKSUM:
                
                    current_msg.checksum = byte;
                    if(current_msg.checksum == current_msg.running_checksum) {
                        on_message_parsed(current_msg.cmd,current_msg.payload,current_msg.length-1);
                    }
                    else {
                        // otherwise, reject message
                        printf("Message rejected\n");
                    }
                    printf("Checksum processed.\r\n");
                    parser_state = WAITING;
                    msg_field_state = START;
                    length_index = 0;
                    memset(&current_msg, 0, sizeof(current_msg));
                    break;
            }

            break;
        default:
            break;
    }

}