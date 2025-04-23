#include <Arduino.h>
#define TRIG_PIN 12
#define ECHO_PIN 13
#define D9 9
#define LEDPin D9

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LEDPin, OUTPUT);
}

void loop() {
  long duration;
  float distance;


  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
   
  duration = pulseIn(ECHO_PIN, HIGH);

  distance = (duration * 0.0343) / 2;

  Serial.println(distance);

  if (distance < 20)
  {
    digitalWrite(LEDPin, HIGH);
  }
  else
  {
    digitalWrite(LEDPin, LOW);
  }

  delay(500);
}
