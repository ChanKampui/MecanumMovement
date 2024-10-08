#include "motor.h"

Motor::Motor(const uint8_t pin_inA, const uint8_t pin_inB,
             const uint8_t pin_PWM)
  : m_pin_inA(pin_inA), m_pin_inB(pin_inB), m_pin_PWM(pin_PWM) {
  pinMode(m_pin_inA, OUTPUT);
  pinMode(m_pin_inB, OUTPUT);
  pinMode(m_pin_PWM, OUTPUT);

  setSpeed(0);
}

void Motor::setSpeed(int16_t speed) {
  m_speed = constrain(speed, -255, 255);
  if (m_speed > 0) { //forward
    digitalWrite(m_pin_inA, HIGH);
    digitalWrite(m_pin_inB, LOW);
    analogWrite(m_pin_PWM, m_speed);
  } else if (m_speed < 0) { //backward
    digitalWrite(m_pin_inA, LOW);
    digitalWrite(m_pin_inB, HIGH);
    analogWrite(m_pin_PWM, -m_speed);
  } else { //stop
    digitalWrite(m_pin_inA, HIGH);
    digitalWrite(m_pin_inB, HIGH);
    analogWrite(m_pin_PWM, 0);
  }
}

int16_t Motor::getSpeed() const {
  return m_speed;
}


void Motor::brakeToVcc() {
  m_speed = 0;
  digitalWrite(m_pin_inA, HIGH);
  digitalWrite(m_pin_inB, HIGH);
  analogWrite(m_pin_PWM, 0);
}
