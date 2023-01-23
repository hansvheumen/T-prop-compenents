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

const int LEDPIN = 5;
const int INTERVAL = 1000;
const int TEN_HZ = 10;
const int HUNDRED_HZ = 100;
int frequence = 1;
unsigned long previousTime = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(LEDPIN, OUTPUT);
}

void pinBlinkAtHz(int pin, int hz)
{
  int delayTime = 1000 / hz;
  digitalWrite(pin, HIGH);
  delay(delayTime);
  digitalWrite(pin, LOW);
  delay(delayTime);
}

void loop()
{
  unsigned long current_time = millis();
  if (current_time - previousTime >= INTERVAL)
  {
    previousTime = current_time;
    frequence++;
    Serial.println(frequence);
  }

  pinBlinkAtHz(LEDPIN, frequence);
}
