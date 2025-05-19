#include <Arduino.h>
#include <IRremote.hpp>

#define IR_RECEIVE_PIN 3

#define TRIG_PIN 12
#define ECHO_PIN 13

unsigned long startZeit = millis();


void setup() 
{
  Serial.begin(9600);
  pinMode(IR_RECEIVE_PIN, INPUT);

  while (!Serial);
  Serial.println(F("IR to HEX Serial Output"));
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  Serial.print(F("Ready to receive IR signals at pin 3"));
}

void loop() 
{
  startZeit = millis();
  for(int i = 0; i < 5; i++)
  {
    while (IrReceiver.decode())
    { 
    Serial.print(F("DEC Data: "));
    Serial.print(IrReceiver.decodedIRData.command);
    Serial.println();
    IrReceiver.resume();
    Serial.println(IrReceiver.decodedIRData.command, HEX);

    if (IrReceiver.decodedIRData.command == 70) 
    {
      Serial.println("vv");
      Serial.println("test");

    }

    int differenz = millis() - startZeit;
    Serial.print(F("Differenz: "));
    Serial.println(differenz);
    }
  }

  delay(100);

  Serial.println("test2");
  
  
}
