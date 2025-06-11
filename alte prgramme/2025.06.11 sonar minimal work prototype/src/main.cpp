#include <Arduino.h>
#include <Servo.h>

#define TRIG_PIN 12
#define ECHO_PIN 13
#define LEDPin 9
#define PIN_SERVO A3

Servo servo;

long duration;
float distance;

String sonar1 [10];
String sonar2 [10];
String sonar3 [10];
String sonar4 [10];
String sonar5 [10];
String sonar6 [10];
String sonar7 [10];
String sonar8 [10];
String sonar9 [10];
String sonarA [10];

void clearArrays()
{
  for (int a = 0; a < 10; a++)
  {
    sonar1[a] = "O";
    sonar2[a] = "O";
    sonar3[a] = "O";
    sonar4[a] = "O";
    sonar5[a] = "O";
    sonar6[a] = "O";
    sonar7[a] = "o";
    sonar8[a] = "O";
    sonar9[a] = "O";
    sonarA[a] = "O";
  }
}

void USRead()
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration * 0.0343) / 2;
  Serial.println(distance);
}

void displayArrays()
{
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println(sonar1[] + sonar2[0] + sonar3[0] + sonar4[0] + sonar5[0] + sonar6[0] + sonar7[0] + sonar8[0] + sonar9[0] + sonarA[]);
}


void setup()
{
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LEDPin, OUTPUT);
  servo.attach(PIN_SERVO);
  servo.write(90);
}

void loop()
{

}
