#include <Arduino.h>

#define liniel 11
#define liniem 7
#define linier 8

const int left_ctrl_forward = 2;
const int right_ctrl_forward = 4;

const int left_pwm = 5;
const int right_pwm = 6;

const int speedv = 180; // original value: 105 
const int speedr = 190; //original value 150

void setup() 
{
    Serial.begin(9600);
    pinMode(liniel, INPUT);
    pinMode(liniem, INPUT);
    pinMode(linier, INPUT);
    pinMode(left_ctrl_forward, OUTPUT);
    pinMode(right_ctrl_forward, OUTPUT);
    pinMode(left_pwm, OUTPUT);
    pinMode(right_pwm, OUTPUT);
    Serial.println("Setup complete");
}

void loop() 
{
    Serial.print(digitalRead(liniel));
    Serial.print(digitalRead(liniem));
    Serial.print(digitalRead(linier));
    Serial.println();

    if (digitalRead(liniel) + digitalRead(liniem) + digitalRead(linier) == 3)
    {
        digitalWrite(left_ctrl_forward, HIGH);
        analogWrite(left_pwm, speedv);

        digitalWrite(right_ctrl_forward, HIGH);
        analogWrite(right_pwm, speedv);
    }
    else if (digitalRead(liniel) + digitalRead(liniem) == 2)
    {
        digitalWrite(right_ctrl_forward, HIGH);
        analogWrite(right_pwm, speedv);

        digitalWrite(left_ctrl_forward, LOW);
        analogWrite(left_pwm, speedr);
    }
    else if (digitalRead(linier) + digitalRead(liniem) == 2)
    {
        digitalWrite(right_ctrl_forward, LOW);
        analogWrite(right_pwm, speedr);

        digitalWrite(left_ctrl_forward, HIGH);
        analogWrite(left_pwm, speedv);
    }
    else
    {
        digitalWrite(left_ctrl_forward, LOW);
        analogWrite(left_pwm, 0);

        digitalWrite(right_ctrl_forward, HIGH);
        analogWrite(right_pwm, speedv);
    }






}

    // if (digitalRead(liniel) == 0)
    // {
    //     digitalWrite(left_ctrl_forward, HIGH);
    //     analogWrite(left_pwm, speedv);

    //     digitalWrite(right_ctrl_forward, LOW);
    //     analogWrite(right_pwm, 0);
    // }
    // else if (digitalRead(linier) == 0)
    // {
    //     digitalWrite(right_ctrl_forward, HIGH);
    //     analogWrite(right_pwm, speedv);

    //     digitalWrite(left_ctrl_forward, LOW);
    //     analogWrite(left_pwm, 0);
    // }
    // else
    // {
    //     digitalWrite(left_ctrl_forward, LOW);
    //     analogWrite(left_pwm, 0);

    //     digitalWrite(right_ctrl_forward, LOW);
    //     analogWrite(right_pwm, 0);
    // }




