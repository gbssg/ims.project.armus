#include <Arduino.h>
#include <variablen.h>
#include "driveControl.h"

#define TRIG_PIN 12
#define ECHO_PIN 13

long duration;
float distance;

void setupUS()
{
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}

void usDistanceCheck()
{
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    duration = pulseIn(ECHO_PIN, HIGH);

    distance = (duration * 0.0343) / 2;

    Serial.println(distance);

    if (distance < 10)
    {
        richtungl = -1;
        richtungr = -1;   
        lastCommandTime = millis();
        driveStateChanged = true;
    }
}
