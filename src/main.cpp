#include <Arduino.h>

int buttonState;
const int KEY1 = 8;
const int GREENLED = 5;


void setup()
{
  pinMode(KEY1, INPUT_PULLUP);
  pinMode(GREENLED, OUTPUT);
  Serial.begin(9600);
  
}

void loop()
{
  
  buttonState = digitalRead(KEY1);
  if (buttonState == LOW)
  {
    digitalWrite(GREENLED, HIGH);
    Serial.println("Button is pressed");
  }
  else
  {
    digitalWrite(GREENLED, LOW);
    Serial.println("Button is not pressed");
  }
}