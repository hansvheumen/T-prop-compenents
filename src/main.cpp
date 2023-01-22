/*
 * Rich shield example
 * Adapted from Rich Shield Example Code
 * Fontys University of Applied Science
 * Name: LightSensor
 * Date: 07/01/2019
 * Author: Jaap Geurts <jaap.geurts@fontys.nl>
 * Version: 1.0
 */

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

int previousPercentage = -1;

void setup()
{
  Serial.begin(9600);
  display.off();

  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);

  pinMode(POTPIN, INPUT);
}

void loop()
{
  int value = analogRead(POTPIN);
  int percentage = map(value, 0, 1023, 0, 100);

  if (abs(percentage - previousPercentage) > 2)
  {

    if (abs(FULL_LEFT - percentage) < THRESHOLD)
    {
      digitalWrite(LED_YELLOW, HIGH);
    }
    else
    {
      digitalWrite(LED_YELLOW, LOW);
    }
    if (abs(FULL_RIGHT - percentage) < THRESHOLD)
    {
      digitalWrite(LED_GREEN, HIGH);
    }
    else
    {
      digitalWrite(LED_GREEN, LOW);
    }
    if (abs(HALF_WAY - percentage) < THRESHOLD)
    {
      digitalWrite(LED_BLUE, HIGH);
    }
    else
    {
      digitalWrite(LED_BLUE, LOW);
    }
    previousPercentage = percentage;
  }
}
