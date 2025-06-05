#include <Arduino.h>

#define pin_L 11
#define pin_M 7
#define pin_R 8

const int left_ctrl_forward = 2;
const int right_ctrl_forward = 4;

const int left_pwm = 5;
const int right_pwm = 6;

const int speedv = 155; // original value: 105 
const int speedr = 100; //original value 150

int val_L;
int val_M;  
int val_R;

int last_Turn = 0; // 0 = start position, 1 = left, 2 = right

void setup() 
{
    Serial.begin(9600);
    pinMode(pin_L, INPUT);
    pinMode(pin_M, INPUT);
    pinMode(pin_R, INPUT);
    pinMode(left_ctrl_forward, OUTPUT);
    pinMode(right_ctrl_forward, OUTPUT);
    pinMode(left_pwm, OUTPUT);
    pinMode(right_pwm, OUTPUT);
    Serial.println("Setup complete");
    Serial.print(digitalRead(val_L));
    Serial.print(digitalRead(val_M));
    Serial.print(digitalRead(val_R));
}

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

void loop() 
{ 
    delay(10);
    val_L = digitalRead(pin_L);
    val_M = digitalRead(pin_M);
    val_R = digitalRead(pin_R);

    Serial.print(digitalRead(val_L));
    Serial.print(digitalRead(val_M));
    Serial.print(digitalRead(val_R));
    Serial.println();

    if (val_M == 1)
    {
        if (val_L == 1 && val_R == 0)
        {
            left();
        }
        else if(val_L == 0 && val_R == 1)
        {
            right();
        }
        else
        {
            front();
        }
    }
    else
    {
        if (val_L == 1 && val_R == 0)
        {
            left();
        }
        else if(val_L == 0 && val_R == 1)
        {
            right();
        }
        else
        {
            if (last_Turn == 1)
            {
                while (val_L + val_M + val_R < 1)
                {
                    val_L = digitalRead(pin_L);
                    val_M = digitalRead(pin_M);
                    val_R = digitalRead(pin_R);
                    left();
                }
            }
            else if (last_Turn == 2)
            {
                while (val_L + val_M + val_R < 1)
                {
                    val_L = digitalRead(pin_L);
                    val_M = digitalRead(pin_M);
                    val_R = digitalRead(pin_R);
                    right();
                }
            }
            else
            {
                stop();
            }
        }
    }
}
