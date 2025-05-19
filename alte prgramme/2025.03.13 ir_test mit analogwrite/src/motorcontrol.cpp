#include <Arduino.h>

int left_ctrl_forward = 2;
int right_ctrl_forward = 4;

int left_pwm = 5;
int right_pwm = 6;

int speedf = 105; 
int speedb = 150; 

void setup()
{
    pinMode(left_ctrl_forward, OUTPUT);
    pinMode(right_ctrl_forward, OUTPUT);
    pinMode(left_pwm, OUTPUT);
    pinMode(right_pwm, OUTPUT);
}


int mc(int valueL, int valueR)
{
    if (valueL == 1)
    {
        analogWrite(left_pwm, speedf);
        digitalWrite(left_ctrl_forward, HIGH);
    }
    else
    {
        analogWrite(left_pwm, speedb);
        digitalWrite(left_ctrl_forward, LOW);
    }

    if (valueR == 1)
    {
        analogWrite(right_pwm, speedf);
        digitalWrite(right_ctrl_forward, HIGH);
    }

    else
    {
        analogWrite(right_pwm, speedb);
        digitalWrite(right_ctrl_forward, LOW);
    }

}
