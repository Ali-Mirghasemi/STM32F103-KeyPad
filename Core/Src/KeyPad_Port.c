#include "KeyPad_Port.h"
#include "stm32f1xx.h"

const KeyPad_Driver KEYPAD_DRIVER = {
  KeyPad_initPin,
  KeyPad_readPin,
  KeyPad_writePin,
#if KEYPAD_USE_DEINIT
  KeyPad_deInitPin,
#endif
};

void KeyPad_initPin(const KeyPad_PinConfig* config, KeyPad_PinMode mode) {
  GPIO_InitTypeDef init = {0};
  
  switch (mode) {
    case KeyPad_PinMode_InputPullUp:
      init.Mode = GPIO_MODE_INPUT;
      init.Pull = GPIO_PULLUP;
      break;
    case KeyPad_PinMode_InputPullDown:
      init.Mode = GPIO_MODE_INPUT;
      init.Pull = GPIO_PULLDOWN;
      break;
    case KeyPad_PinMode_Output:
      init.Mode = GPIO_MODE_OUTPUT_PP;
      init.Pull = GPIO_NOPULL;
      break;
  }
  init.Speed = GPIO_SPEED_FREQ_HIGH;
  init.Pin = config->Pin;
  HAL_GPIO_Init((GPIO_TypeDef*) config->IO, &init); 
}
void KeyPad_deInitPin(const KeyPad_PinConfig* config) {
  HAL_GPIO_DeInit((GPIO_TypeDef*) config->IO, config->Pin);
}
uint8_t KeyPad_readPin(const KeyPad_PinConfig* config) {
  return HAL_GPIO_ReadPin((GPIO_TypeDef*) config->IO, config->Pin);
}
void KeyPad_writePin(const KeyPad_PinConfig* config, uint8_t value) {
  HAL_GPIO_WritePin((GPIO_TypeDef*) config->IO, config->Pin, (GPIO_PinState) value);
}



