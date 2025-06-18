#include <Arduino.h>
#include <IRremote.h>
#include "variablen.h"
// #include "lineFollower.h"

#define LEDPIN 9  

int letzerModusWechsel66 = millis();
int letzerModusWechsel74 = millis();

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
    Serial.print("                   ");
    Serial.println(IrReceiver.decodedIRData.command, DEC);
    IrReceiver.resume();

    driveStateChanged = true;
    lastCommandTime = millis();
    Serial.println(letzerModusWechsel66);

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
      // ir code for the * button the remote
      // have to change the system that tells eatch file on when to run
        if (millis() - letzerModusWechsel66 > 500)
        {
          sonarEnabled = false;
          motorEnabled = !motorEnabled; // ändert den Motorstatus
          digitalWrite(LEDPIN, !motorEnabled); 
          letzerModusWechsel66 = millis();
        }
        break;
      // case 74: // ir code for the "#" button on the remote : 74
      // if (millis() - letzerModusWechsel74 > 500)
      //   {
      //     stop();
      //     motorEnabled = false;
      //     sonarEnabled = !sonarEnabled; // ändert den Sonarstatus
      //     digitalWrite(LEDPIN, sonarEnabled); 
      //     letzerModusWechsel74 = millis();
      //   }
      //  break;
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
