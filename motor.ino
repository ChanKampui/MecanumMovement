#include "motor.h"
#include "controller.h"
#include "movement.h"

Motor wheelFL(43, 42, 9);
Motor wheelFR(35, 34, 12);
Motor wheelBL(29, 39, 5);
Motor wheelBR(36, 37, 8);

Movement mecannum;

Controller controller(A10, A11, A15);

void setup() {
  Serial.begin(115200);
}

void loop() {
  mecannum.mecaunumMovement(controller.MappedValue_X(), controller.MappedValue_Y(), controller.MappedValue_Turn());
  wheelFL.setSpeed(mecannum.speed_FL());
  wheelFR.setSpeed(mecannum.speed_FR());
  wheelBL.setSpeed(mecannum.speed_BL());
  wheelBR.setSpeed(mecannum.speed_BR());

  Serial.print(String(analogRead(A6)) + "\t" + String(analogRead(A5)) + "\t" + String(analogRead(A1)));
  Serial.println();
}
