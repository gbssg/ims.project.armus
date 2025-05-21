#include <Arduino.h>
#include <IRremote.h>
#include "variablen.h"

void setupIrCMT()
{
  IrReceiver.begin(3, ENABLE_LED_FEEDBACK);
}

void irCodeMotorTranslator() 
{
  if (IrReceiver.decode())
  {
    Serial.println(IrReceiver.decodedIRData.command, DEC);
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
      default:
        // Stop
        richtungl = 0;
        richtungr = 0;
        break;
    }

    if (IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT)
    {
      // Erkennt IR Signal Wiederholung
      driveStateChanged = true;
      Serial.println("Wiederholung vom IR Code");
      lastCommandTime = millis();
    }
  }
}
