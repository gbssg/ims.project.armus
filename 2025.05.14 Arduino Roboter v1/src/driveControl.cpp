#include <Arduino.h>
#include "variablen.h"

int left_ctrl_forward = 2;
int right_ctrl_forward = 4;

int left_pwm = 5;
int right_pwm = 6;

int speedv = 105; 
int speedr = 150; 

void setupDC() 
{
    pinMode(left_ctrl_forward, OUTPUT);
    pinMode(right_ctrl_forward, OUTPUT);
    pinMode(left_pwm, OUTPUT);
    pinMode(right_pwm, OUTPUT);
}

void driveControl(int rl, int rr)
{
    Serial.println(millis() - aktuelleZeit);
    Serial.println(aktuelleZeit);
    if (millis() - aktuelleZeit > 200) 
    {
        rl = 0;
        rr = 0;
        update = true;
    }
    if (update)
    {
        
        switch (rl) 
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

        switch (rr) 
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
        update = false;
    }
}
