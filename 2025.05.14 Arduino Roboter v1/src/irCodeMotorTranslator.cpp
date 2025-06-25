#include <Arduino.h>
#include <IRremote.h>
#include "variablen.h"

#define LEDPIN 9  

unsigned long letzerModusWechsel66 = millis();
unsigned long letzerModusWechsel74 = millis();

void setupIrCMT()
{
  IrReceiver.begin(3, ENABLE_LED_FEEDBACK);
  pinMode(LEDPIN, OUTPUT);
  digitalWrite(LEDPIN, LOW); 
}

void irCodeMotorTranslator() 
{
    if (IrReceiver.decode())
    {
        IrReceiver.resume();
        driveStateChanged = true;
        lastCommandTime = millis();

        switch (IrReceiver.decodedIRData.command) 
        {
        case 70:
            // Beide Seiten vorwärts
            richtungl = 1;
            richtungr = 1;
            break;
        case 67:
            // Linke Seite vorwärts, rechte Seite rückwärts (Rechtsdrehung)
            richtungl = 1;
            richtungr = -1;
            break;
        case 68:
            // Linke Seite rückwärts, rechte Seite vorwärts (Linksdrehung)
            richtungl = -1;
            richtungr = 1;
            break;
        case 21:
            // Beide Seiten rückwärts
            richtungl = -1;
            richtungr = -1;
            break;
        case 66:
            if (millis() - letzerModusWechsel66 >= 500)
            {
                sonarEnabled = false;
                motorEnabled = !motorEnabled; // ändert den Motorstatus
                digitalWrite(LEDPIN, !motorEnabled); 
                letzerModusWechsel66 = millis();
                Serial.println("66");
            }
            break;
        case 74:
        if (millis() - letzerModusWechsel74 >= 500)
            {
                motorEnabled = false;
                sonarEnabled = !sonarEnabled; // ändert den Sonarstatus
                digitalWrite(LEDPIN, LOW); 
                letzerModusWechsel74 = millis();
                Serial.println("74");
            }

            break;
        default:
            // Stop
            richtungl = 0;
            richtungr = 0;
            break;
        }

        if (IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT)
        {
        driveStateChanged = true;
        Serial.println("Wiederholung vom IR Code");
        }
    }
}
