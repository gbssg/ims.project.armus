#include <Arduino.h>
#include "variablen.h"

const int left_ctrl_forward = 2;
const int right_ctrl_forward = 4;

const int left_pwm = 5;
const int right_pwm = 6;

const int speedv = 105; 
const int speedr = 150; 

void setupDC() 
{
    pinMode(left_ctrl_forward, OUTPUT);
    pinMode(right_ctrl_forward, OUTPUT);
    pinMode(left_pwm, OUTPUT);
    pinMode(right_pwm, OUTPUT);
    driveStateChanged = true;
    motorEnabled = true;
}

void driveControl()
{
    if (millis() - lastCommandTime > 200) 
    {
        richtungl = 0;
        richtungr = 0;
        driveStateChanged = true;
    }
    if (sonarEnabled)
    {
        digitalWrite(left_ctrl_forward, LOW);
        analogWrite(left_pwm, 0);
        digitalWrite(right_ctrl_forward, LOW);
        analogWrite(right_pwm, 0);
    }

    if (motorEnabled  && driveStateChanged  && !sonarEnabled)
    {

        switch (richtungl) 
        {
            case 1:
                digitalWrite(left_ctrl_forward, HIGH);
                analogWrite(left_pwm, speedv);
                break;
            case -1:
                digitalWrite(left_ctrl_forward, LOW);
                analogWrite(left_pwm, speedr);
                break;
            case 0:
                digitalWrite(left_ctrl_forward, LOW);
                analogWrite(left_pwm, 0);
                break;
        }

        switch (richtungr) 
        {
            case 1:
                digitalWrite(right_ctrl_forward, HIGH);
                analogWrite(right_pwm, speedv);
                break;
            case -1:
                digitalWrite(right_ctrl_forward, LOW);
                analogWrite(right_pwm, speedr);
                break;
            case 0:
                digitalWrite(right_ctrl_forward, LOW);
                analogWrite(right_pwm, 0);
                break;
        }

        driveStateChanged = false;

    }
}
