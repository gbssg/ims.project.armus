#include <Arduino.h>
#include <IRremote.hpp>

#define IR_RECEIVE_PIN 3
#define LEDPIN 9

void setup() {
    Serial.begin(9600);
    pinMode(LEDPIN, OUTPUT);
    while (!Serial);
    
    Serial.println(F("IR to HEX Serial Output"));
    IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
    Serial.print(F("Ready to receive IR signals at pin 3"));
}

void loop() {
    if (IrReceiver.decode()) {
        Serial.print(F("DEC Data: "));
        Serial.print(IrReceiver.decodedIRData.command, DEC);
        Serial.println();
        IrReceiver.resume();
        if (IrReceiver.decodedIRData.command == 70) {
            digitalWrite(LEDPIN, HIGH);
        } else {
            digitalWrite(LEDPIN, LOW);
        }
    }
}