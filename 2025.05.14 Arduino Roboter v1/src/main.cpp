#include <Arduino.h>
#include "driveControl.h"
#include "irCodeMotorTranslator.h"
#include "variablen.h"

void setup() 
{
  Serial.begin(9600);
  setupIrCMT();
  setupDC();
}

void loop() 
{
  irCodeMotorTranslator();
  driveControl(richtungl, richtungr);
  delay(1000);
}
