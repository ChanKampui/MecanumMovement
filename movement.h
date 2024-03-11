#pragma once
#include <Arduino.h>

//motor[0] wheelFL
//motor[1] wheelFR
//motor[2] wheelBL
//motor[3] wheelBR

class Movement {
private:
  double theta, power;
  double sinAngle, cosAngle, max;

  int motor[4];
  int dir[4];
public:
  void mecaunumMovement(int16_t MappedValue_X, int16_t MappedValue_Y, int16_t MappedValue_Turn);
  void showDirection(int16_t MappedValue_Turn);

  int16_t speed_FL() {
    return motor[0];
  }
  int16_t speed_FR() {
    return motor[1];
  }
  int16_t speed_BL() {
    return motor[2];
  }
  int16_t speed_BR() {
    return motor[3];
  }
};