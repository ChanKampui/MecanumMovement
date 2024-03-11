#pragma once

#include <Arduino.h>

class Controller {
private:
  const uint8_t m_pin_Joystick_X;
  const uint8_t m_pin_Joystick_Y;
  const uint8_t m_pin_Joystick_Turn;


public:
  Controller(const uint8_t pin_Joystick_X, const uint8_t pin_Joystick_Y, const uint8_t pin_Joystick_Turn);
  int16_t MappedValue_X();
  int16_t MappedValue_Y();
  int16_t MappedValue_Turn();
};