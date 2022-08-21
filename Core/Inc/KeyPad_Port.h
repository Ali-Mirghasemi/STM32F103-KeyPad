#ifndef _KEYPAD_PORT_H_
#define _KEYPAD_PORT_H_

#include "KeyPad.h"

void KeyPad_initPin(const KeyPad_PinConfig* config, KeyPad_PinMode mode);
void KeyPad_deInitPin(const KeyPad_PinConfig* config);
uint8_t KeyPad_readPin(const KeyPad_PinConfig* config);
void KeyPad_writePin(const KeyPad_PinConfig* config, uint8_t value);

extern const KeyPad_Driver KEYPAD_DRIVER;

#endif // _KEYPAD_PORT_H_
