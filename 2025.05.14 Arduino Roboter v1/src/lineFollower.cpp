#include <Arduino.h>
#include "variablen.h"
#include "usDistanceStop.h"

#define pin_L 11
#define pin_M 7
#define pin_R 8

const int left_ctrl_forward = 2;
const int right_ctrl_forward = 4;

const int left_pwm = 5;
const int right_pwm = 6;

const int speedv = 155;
const int speedr = 100;

int val_L;
int val_M; 
int val_R;

int last_Turn = 1; // 1 = left, 2 = right. At the start defined as left so that it will turn in some direction if it never was on the line before

void left()
{
    digitalWrite(left_ctrl_forward, LOW);
    analogWrite(left_pwm, speedr);
    digitalWrite(right_ctrl_forward, HIGH);
    analogWrite(right_pwm, speedv);
    last_Turn = 1;
}

void right()
{
    digitalWrite(left_ctrl_forward, HIGH);
    analogWrite(left_pwm, speedv);
    digitalWrite(right_ctrl_forward, LOW);
    analogWrite(right_pwm, speedr);
    last_Turn = 2;
}

void front()
{
    digitalWrite(left_ctrl_forward, HIGH);
    analogWrite(left_pwm, speedv);
    digitalWrite(right_ctrl_forward, HIGH);
    analogWrite(right_pwm, speedv);
}

void stop()
{
    digitalWrite(left_ctrl_forward, LOW);
    analogWrite(left_pwm, 0);
    digitalWrite(right_ctrl_forward, LOW);
    analogWrite(right_pwm, 0);
}

void setupLF()    
{
    pinMode(pin_L, INPUT);
    pinMode(pin_M, INPUT);
    pinMode(pin_R, INPUT);
    pinMode(left_ctrl_forward, OUTPUT);
    pinMode(right_ctrl_forward, OUTPUT);
    pinMode(left_pwm, OUTPUT);
    pinMode(right_pwm, OUTPUT);

    Serial.println("Line follower setup complete");
}

void lineFollower()
{
    if (!motorEnabled && !sonarEnabled) // Ich verwende dieselbe Variable wie in driveControl weil linefollower und drivecontrol nicht gleichzeitig laufen sollen
    {
        val_L = digitalRead(pin_L);
        val_M = digitalRead(pin_M);
        val_R = digitalRead(pin_R);

        Serial.println(distance);
        
        if (distance >= 8)
        {
            if (val_L == 1 && val_R == 0)
            {
                left();
            }
            else if(val_L == 0 && val_R == 1)
            {
                right();
            }
            else if (val_L + val_M + val_R == 3) //wenn alle Sensoren auf der Linie sind, fährt er geradeaus
            {
                front();
            }
            else // wenn kein Sensor mehr auf der Linie ist, versucht er hiermit wieder die Linie zu finden
            {
                if (last_Turn == 1)
                {
                    left();
                }
                else if (last_Turn == 2)
                {
                    right();
                }
            }   
        }
        else
        {
            stop();
        }  
    }
}
