#include <Arduino.h>
#include <OpenRichShield.h>

const int POTPIN = A0;
const int THRESHOLD = 5;
const int FULL_LEFT = 0;
const int FULL_RIGHT = 100;
const int HALF_WAY = 50;

const int LED_RED = 4;
const int LED_GREEN = 5;
const int LED_BLUE = 6;
const int LED_YELLOW = 7;

const int PIN_RED = 7;
const int PIN_GREEN = 6;
const int PIN_BLUE = 5;

void setup()
{
  Serial.begin(9600);
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
}

void setColor(int redValue, int greenValue, int blueValue)
{
  analogWrite(PIN_RED, redValue);
  analogWrite(PIN_GREEN, greenValue);
  analogWrite(PIN_BLUE, blueValue);
}
void loop()
{
  setColor(255, 0, 0); // Red Color
  delay(1000);
  setColor(0, 255, 0); // Green Color
  delay(1000);
  setColor(0, 0, 255); // Blue Color
  delay(1000);
  setColor(255, 255, 255); // White Color
  delay(1000);
  setColor(170, 0, 255); // Purple Color
  delay(1000);
}