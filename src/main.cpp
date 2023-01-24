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
bool isDimming = false;
int percentage = 0;
const int DIMMING_INTERVAL = 5000;
const long BRIGHTENING_INTERVAL = 10000;

void setup()
{
  Serial.begin(9600);
  pinMode(LEDPIN, OUTPUT);
}

void pinAtBrighness(int pin, int percentage)
{
  int brightness = map(percentage, 0, 100, 0, 255);
  analogWrite(pin, brightness);
}

void loop()
{
  long current_time = millis() % (BRIGHTENING_INTERVAL + DIMMING_INTERVAL);
  isDimming = current_time > BRIGHTENING_INTERVAL;
  if (isDimming)
  {
    percentage = 100 * (BRIGHTENING_INTERVAL + DIMMING_INTERVAL - current_time) / DIMMING_INTERVAL;
  }
  else
  {
    percentage = 100 * current_time / BRIGHTENING_INTERVAL;
  }
  pinAtBrighness(LEDPIN, percentage);
}