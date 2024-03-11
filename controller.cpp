#include "controller.h"

Controller::Controller(const uint8_t pin_Joystick_X, const uint8_t pin_Joystick_Y,
                       const uint8_t pin_Joystick_Turn)
  : m_pin_Joystick_X(pin_Joystick_X), m_pin_Joystick_Y(pin_Joystick_Y), m_pin_Joystick_Turn(pin_Joystick_Turn) {
  pinMode(m_pin_Joystick_X, INPUT);
  pinMode(m_pin_Joystick_Y, INPUT);
  pinMode(m_pin_Joystick_Turn, INPUT);
}

int16_t Controller::MappedValue_X() {
  return map(analogRead(m_pin_Joystick_X), 1023, 0, -255, 255);
}
int16_t Controller::MappedValue_Y() {
  return map(analogRead(m_pin_Joystick_Y), 0, 1023, -255, 255);
}
int16_t Controller::MappedValue_Turn() {
  return map(analogRead(m_pin_Joystick_Turn), 0, 1023, -255, 255);
}