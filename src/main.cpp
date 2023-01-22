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

float previousHuminity = -1;

void setup()
{
  Serial.begin(9600);

  dht.begin();
}

void loop()
{

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (humidity != previousHuminity)
  {
    previousHuminity = humidity;
    display.show(humidity);
    Serial.println(humidity);
    delay(1000);
  }
  else
  {
    display.show(-1);
    delay(500);
    display.clear();
    delay(500);
  }
}
