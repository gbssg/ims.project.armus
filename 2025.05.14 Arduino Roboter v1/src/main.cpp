#include <Arduino.h>
#include "driveControl.h"
#include "irCodeMotorTranslator.h"
#include "usDistanceStop.h"
#include "lineFollower.h"

void setup() 
{
    Serial.begin(9600);
    setupIrCMT();
    setupDC();
    setupUS();
    setupLF();
}

void loop()
{
    irCodeMotorTranslator();
    usDistanceCheck();
    driveControl();
    lineFollower();
    delay(5);
}
