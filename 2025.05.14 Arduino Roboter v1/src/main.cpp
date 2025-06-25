#include <Arduino.h>
#include "driveControl.h"
#include "irCodeMotorTranslator.h"
#include "usDistanceStop.h"
#include "lineFollower.h"
#include "sonar.h"

void setup() 
{
    Serial.begin(9600);
    setupIrCMT();
    setupDC();
    setupUS();
    setupLF();
    setupSonar();
}

void loop()
{
    irCodeMotorTranslator();
    usDistanceCheck();
    driveControl();
    lineFollower();
    sonar();
    delay(5);
}
