#include <Arduino.h>
#include <IRremote.hpp>

#define IR_RECEIVE_PIN 3
#define SDA_Pin  A4
#define SCL_Pin  A5

unsigned long startZeit = millis();
unsigned long akuelleZeit = millis();

int left_ctrl = 2;
int left_pwm = 1;
int right_ctrl = 4;
int right_pwm = 1;

void setup() 
{
  Serial.begin(9600);
  pinMode(IR_RECEIVE_PIN,INPUT);  pinMode(left_ctrl,OUTPUT);
  pinMode(left_pwm,OUTPUT);
  pinMode(right_ctrl,OUTPUT);
  pinMode(right_pwm,OUTPUT);
  while (!Serial);
    Serial.println(F("IR to HEX Serial Output"));
    IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
    Serial.print(F("Ready to receive IR signals at pin 3"));
}
void loop() 
{
  
  while (IrReceiver.decode())
  { 
    startZeit = millis();
    Serial.print(F("DEC Data: "));
    Serial.print(IrReceiver.decodedIRData.command, DEC);
    int pinZustand = analogRead(IR_RECEIVE_PIN);
    Serial.println(pinZustand);
    Serial.println();
    IrReceiver.resume();

    if (IrReceiver.decodedIRData.command == 70) 
    {
      digitalWrite(left_ctrl, HIGH);
      digitalWrite(right_ctrl, HIGH);
    } 
    else if (IrReceiver.decodedIRData.command == 67)
    {
      digitalWrite(left_ctrl, HIGH);
      digitalWrite(right_ctrl, LOW);
    } 
    else if (IrReceiver.decodedIRData.command == 68)
    {
      digitalWrite(left_ctrl, LOW);
      digitalWrite(right_ctrl, HIGH);
    } 
    else 
    {
      digitalWrite(left_ctrl, LOW);
      digitalWrite(right_ctrl, LOW);
    }
  }
  akuelleZeit = millis();
  if (akuelleZeit - startZeit > 100)
  {
    digitalWrite(left_ctrl, LOW);
    digitalWrite(right_ctrl, LOW);
  }
}
