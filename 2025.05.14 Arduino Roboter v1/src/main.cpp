#include <Arduino.h>
#include "driveControl.h"
#include "irCodeMotorTranslator.h"
#include "usDistanceStop.h"
#include "variablen.h"

void setup() 
{
  Serial.begin(9600);
  setupIrCMT();
  setupDC();
  setupUS();
}

void loop() 
{
  irCodeMotorTranslator();
  usDistanceCheck();
  driveControl(richtungl, richtungr);
  delay(5);
}
