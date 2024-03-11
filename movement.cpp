#include "movement.h"
#include "controller.h"
#define PI 3.1415926

void Movement::mecaunumMovement(int16_t MappedValue_X, int16_t MappedValue_Y, int16_t MappedValue_Turn) {
  theta = atan2(MappedValue_Y, MappedValue_X);
  power = hypot(MappedValue_X, MappedValue_Y);

  sinAngle = sin(theta - (PI / 4));
  cosAngle = cos(theta - (PI / 4));
  max = max(abs(sinAngle), abs(cosAngle));

  motor[0] = power * cosAngle / max + MappedValue_Turn;
  motor[1] = power * sinAngle / max - MappedValue_Turn;
  motor[2] = power * sinAngle / max + MappedValue_Turn;
  motor[3] = power * cosAngle / max - MappedValue_Turn;
}
void Movement::showDirection(int16_t Turn) {
  if ((power + abs(Turn)) > 1) {  //Show DIR
    dir[0] /= power + abs(Turn);
    dir[1] /= power + abs(Turn);
    dir[2] /= power + abs(Turn);
    dir[3] /= power + abs(Turn);
  }
}