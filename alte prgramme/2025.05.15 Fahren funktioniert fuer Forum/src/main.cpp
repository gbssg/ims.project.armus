#include <Arduino.h>
#include <IRremote.hpp>

#define IR_RECEIVE_PIN 3
// Für Ultraschallsensor
#define TRIG_PIN 12
#define ECHO_PIN 13

long duration;
float distance;

unsigned long startZeit = millis();
unsigned long aktuelleZeit = millis();
unsigned long echoZeit = millis();

int left_ctrl_forward = 2;
int right_ctrl_forward = 4;

int left_pwm = 5;
int right_pwm = 6;

int speed1 = 105; 
int speed2 = 150; 


void setup() 
{
  Serial.begin(9600);
  pinMode(IR_RECEIVE_PIN, INPUT);
  pinMode(left_ctrl_forward, OUTPUT);
  pinMode(right_ctrl_forward, OUTPUT);
  pinMode(left_pwm, OUTPUT);
  pinMode(right_pwm, OUTPUT);
  // Für Ultraschallsensor
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  

  while (!Serial);
  Serial.println(F("IR to HEX Serial Output"));
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  Serial.print(F("Ready to receive IR signals at pin 3"));
}

void loop()
{


  // duration = pulseIn(ECHO_PIN, HIGH);
  // distance = (duration * 0.0343) / 2;


  while (IrReceiver.decode())
  { 
    startZeit = millis();
    Serial.print(F("DEC Data: "));
    Serial.print(IrReceiver.decodedIRData.command, DEC);
    Serial.println();
    IrReceiver.resume();


    if (IrReceiver.decodedIRData.command == 70) 
    {
      // Beide Seiten vorwärts
      analogWrite(left_pwm, speed1);
      analogWrite(right_pwm, speed1);
      digitalWrite(left_ctrl_forward, HIGH);
      digitalWrite(right_ctrl_forward, HIGH);

      

    }

    else if (IrReceiver.decodedIRData.command == 67)
    {
      // Linke Seite vorwärts, rechte Seite rückwärts (Rechtsdrehung)
      digitalWrite(left_ctrl_forward, HIGH);
      digitalWrite(right_ctrl_forward, LOW);
      analogWrite(left_pwm, speed1);
      analogWrite(right_pwm, speed2);
    } 

    else if (IrReceiver.decodedIRData.command == 68)
    {
      // Linke Seite rückwärts, rechte Seite vorwärts (Linksdrehung)
      digitalWrite(left_ctrl_forward, LOW);
      digitalWrite(right_ctrl_forward, HIGH);
      analogWrite(left_pwm, speed2);
      analogWrite(right_pwm, speed1);
    }

    else if (IrReceiver.decodedIRData.command == 21)
    {
      // Beide Seiten rückwärts
      digitalWrite(left_ctrl_forward, LOW);
      digitalWrite(right_ctrl_forward, LOW);
      analogWrite(left_pwm, speed2);
      analogWrite(right_pwm, speed2);
    }



    
  }
  aktuelleZeit = millis();
  if (aktuelleZeit - startZeit > 200)
  {
    // Bei keinem Input stoppen
    analogWrite(left_pwm, 0);
    analogWrite(right_pwm, 0);
    digitalWrite(left_ctrl_forward, LOW);
    digitalWrite(right_ctrl_forward, LOW);
  }
}
