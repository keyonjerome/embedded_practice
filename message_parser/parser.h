#ifndef PARSER_H
#define PARSER_H

#include <stdint.h>
#include <stdbool.h>

void parser_init(void);
void parser_process_byte(uint8_t byte);
void on_message_parsed(uint8_t command, const uint8_t* payload, uint8_t length);

#endif // PARSER_H
