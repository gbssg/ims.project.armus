#include <Arduino.h>
#include <Servo.h>

#define TRIG_PIN 12
#define ECHO_PIN 13
#define LEDPin 9
#define PIN_SERVO A3

Servo servo;

long duration;
int distance;

int lastServoPosition;


char sonarData [10][20];

void clearArray()
{
  for (int a = 0; a < 10; a++)
  {
    for (int b = 0; b < 20; b++)
    {
      sonarData[a][b] = 'O';
    }
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
  if (distance % 2 != 0)
  {
    distance = distance + 1;
  }
  if (distance > 40)
  {
    distance = 38; // Limits the distance to 40 cm
  }


}

void displayArrays()
{
  Serial.println("    " + String(sonarData[2][19]) + "          " + String(sonarData[3][19]) + "         " + String(sonarData[4][19]) + "     " + String(sonarData[5][19]) + "         " + String(sonarData[6][19]) + "          " + String(sonarData[7][19]) + "    ");
  Serial.println("     " + String(sonarData[2][18]) + "          " + String(sonarData[3][18]) + "        " + String(sonarData[4][18]) + "     " + String(sonarData[5][18]) + "        " + String(sonarData[6][18]) + "          " + String(sonarData[7][18]) + "     ");
  Serial.println("      " + String(sonarData[2][17]) + "         " + String(sonarData[3][17]) + "        " + String(sonarData[4][17]) + "     " + String(sonarData[5][17]) + "        " + String(sonarData[6][17]) + "         " + String(sonarData[7][17]) + "      ");
  Serial.println("       " + String(sonarData[2][16]) + "         " + String(sonarData[3][16]) + "       " + String(sonarData[4][16]) + "     " + String(sonarData[5][16]) + "       " + String(sonarData[6][16]) + "         " + String(sonarData[7][16]) + "      ");
  Serial.println("        " + String(sonarData[2][15]) + "        " + String(sonarData[3][15]) + "       " + String(sonarData[4][15]) + "     " + String(sonarData[5][15]) + "       " + String(sonarData[6][15]) + "        " + String(sonarData[7][15]) + "       ");
  Serial.println("         " + String(sonarData[2][14]) + "        " + String(sonarData[3][14]) + "      " + String(sonarData[4][14]) + "     " + String(sonarData[5][14]) + "      " + String(sonarData[6][14]) + "        " + String(sonarData[7][14]) + "        ");
  Serial.println("          " + String(sonarData[2][13]) + "       " + String(sonarData[3][13]) + "      " + String(sonarData[4][13]) + "     " + String(sonarData[5][13]) + "      " + String(sonarData[6][13]) + "       " + String(sonarData[7][13]) + "         ");
  Serial.println("           " + String(sonarData[2][12]) + "       " + String(sonarData[3][12]) + "      " + String(sonarData[4][12]) + "   " + String(sonarData[5][12]) + "      " + String(sonarData[6][12]) + "       " + String(sonarData[7][12]) + "          ");
  Serial.println("            " + String(sonarData[2][11]) + "      " + String(sonarData[3][11]) + "      " + String(sonarData[4][11]) + "   " + String(sonarData[5][11]) + "      " + String(sonarData[6][11]) + "      " + String(sonarData[7][11]) + "           ");
  Serial.println("  " + String(sonarData[1][19]) + String(sonarData[1][18]) + "         " + String(sonarData[2][10]) + "      " + String(sonarData[3][10]) + "     " + String(sonarData[4][10]) + "   " + String(sonarData[5][10]) + "     " + String(sonarData[6][10]) + "      " + String(sonarData[7][10]) + "         " + String(sonarData[8][18]) + String(sonarData[8][19]));
  Serial.println("    " + String(sonarData[1][17]) + String(sonarData[1][16]) + "        " + String(sonarData[2][9]) + "     " + String(sonarData[3][9]) + "     " + String(sonarData[4][9]) + "   " + String(sonarData[5][9]) + "     " + String(sonarData[6][9]) + "     " + String(sonarData[7][9]) + "        " + String(sonarData[8][16]) + String(sonarData[8][17]));
  Serial.println("      " + String(sonarData[1][15]) + String(sonarData[1][14]) + "       " + String(sonarData[2][8]) + "     " + String(sonarData[3][8]) + "    " + String(sonarData[4][8]) + "   " + String(sonarData[5][8]) + "    " + String(sonarData[6][8]) + "     " + String(sonarData[7][8]) + "       " + String(sonarData[8][14]) + String(sonarData[8][15]));
  Serial.println("        " + String(sonarData[1][13]) + String(sonarData[1][12]) + "      " + String(sonarData[2][7]) + "    " + String(sonarData[3][7]) + "    " + String(sonarData[4][7]) + "   " + String(sonarData[5][7]) + "    " + String(sonarData[6][7]) + "    " + String(sonarData[7][7]) + "      " + String(sonarData[8][12]) + String(sonarData[8][13]));
  Serial.println("          " + String(sonarData[1][11]) + String(sonarData[1][10]) + "     " + String(sonarData[2][6]) + "    " + String(sonarData[3][6]) + "   " + String(sonarData[4][6]) + "   " + String(sonarData[5][6]) + "   " + String(sonarData[6][6]) + "    " + String(sonarData[7][6]) + "     " + String(sonarData[8][10]) + String(sonarData[8][11]));
  Serial.println("            " + String(sonarData[1][9]) + String(sonarData[1][8]) + "    " + String(sonarData[2][5]) + "   " + String(sonarData[3][5]) + "   " + String(sonarData[4][5]) + "   " + String(sonarData[5][5]) + "   " + String(sonarData[6][5]) + "   " + String(sonarData[7][5]) + "    " + String(sonarData[8][8]) + String(sonarData[8][9]));
  Serial.println("              " + String(sonarData[1][7]) + String(sonarData[1][6]) + "   " + String(sonarData[2][4]) + "   " + String(sonarData[3][4]) + "   " + String(sonarData[4][4]) + " " + String(sonarData[5][4]) + "   " + String(sonarData[6][4]) + "   " + String(sonarData[7][4]) + "   " + String(sonarData[8][6]) + String(sonarData[8][7]));
  Serial.println("                " + String(sonarData[1][5]) + String(sonarData[1][4]) + "  " + String(sonarData[2][3]) + "  " + String(sonarData[3][3]) + "   " +String(sonarData[4][3]) + " " + String(sonarData[5][3]) + "   " + String(sonarData[6][3]) + "  " + String(sonarData[7][3]) + "  " + String(sonarData[8][4]) + String(sonarData[8][5]));
  Serial.println("                  " + String(sonarData[1][3]) + String(sonarData[1][2]) + " " + String(sonarData[2][2]) + "  " + String(sonarData[3][2]) + "  " + String(sonarData[4][2]) + " " + String(sonarData[5][2]) + "  " + String(sonarData[6][2]) + "  " + String(sonarData[7][2]) + " " + String(sonarData[8][2]) + String(sonarData[8][3]));
  Serial.println("                    " + String(sonarData[1][1]) + " " + String(sonarData[2][1]) + " " + String(sonarData[3][1]) + "  " + String(sonarData[4][1]) + " " + String(sonarData[5][1]) + "  " + String(sonarData[6][1]) + " " + String(sonarData[7][1]) + " " + String(sonarData[8][1]));
  Serial.println(String(sonarData[0][19]) + String(sonarData[0][18]) + String(sonarData[0][17]) + String(sonarData[0][16]) + String(sonarData[0][15]) + String(sonarData[0][14]) + String(sonarData[0][13]) + String(sonarData[0][12]) + String(sonarData[0][11]) + String(sonarData[0][10]) + String(sonarData[0][9]) + String(sonarData[0][8]) + String(sonarData[0][7]) + String(sonarData[0][6]) + String(sonarData[0][5]) + String(sonarData[0][4]) + String(sonarData[0][3]) + String(sonarData[0][2]) + String(sonarData[0][1]) + String(sonarData[0][0]) + " " + String(sonarData[1][0]) + " " + String(sonarData[2][0]) + " " + String(sonarData[3][0]) + " " + String(sonarData[4][0]) + " " + String(sonarData[5][0]) + " " + String(sonarData[6][0]) + " " + String(sonarData[7][0]) + " " + String(sonarData[8][0]) + " " +String(sonarData[9][0]) + String(sonarData[9][1]) + String(sonarData[9][2]) + String(sonarData[9][3]) + String(sonarData[9][4]) + String(sonarData[9][5]) + String(sonarData[9][6]) + String(sonarData[9][7]) + String(sonarData[9][8]) + String(sonarData[9][9]) + String(sonarData[9][10]) + String(sonarData[9][11]) + String(sonarData[9][12]) + String(sonarData[9][13]) + String(sonarData[9][14]) + String(sonarData[9][15]) + String(sonarData[9][16]) + String(sonarData[9][17]) + String(sonarData[9][18]) + String(sonarData[9][19]));
}

void setup()
{
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LEDPin, OUTPUT);
  servo.attach(PIN_SERVO);
  
  Serial.println("Starting Ultrasonic Sensor Array");
  delay(100);
  clearArray();
  displayArrays();
  
}

void loop()
{
  lastServoPosition = 0;
  servo.write(0);
  Serial.println(lastServoPosition);
  clearArray();
  for (int i = 10; i > 0; i --)
  {
    USRead();
    sonarData[i][distance / 2 -1 ] = 'X';
    sonarData[i][distance / 2] = 'X';
    sonarData[i][distance / 2 + 1] = 'X';
    displayArrays();
    Serial.println(lastServoPosition);
    lastServoPosition += 18;
    Serial.println(lastServoPosition);
    servo.write(lastServoPosition);
    delay(2000);
  }
  delay(2000);
}
