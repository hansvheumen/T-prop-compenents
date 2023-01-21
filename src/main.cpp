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

const int PIN_LDR = 16;
int min = 1023, max = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(PIN_LDR, INPUT);
}

void loop()
{
  int brightness = analogRead(PIN_LDR);
  if (brightness < min)
  {
    min = brightness; // new minimal brightness (darkness)
  }
  if (brightness > max)
  {
    max = brightness; // new maximal brightness (highlight)
  }
  Serial.print("dark = ");
  Serial.println(min);
  Serial.print("highlight = ");
  Serial.println(max);
  delay(5000);
}
