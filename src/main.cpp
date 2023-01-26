#include <Arduino.h>
#include <OpenRichShield.h>
const int REDLED = 4;
const int BUTTON = 8;
bool toggle = false;
int lastButtonState = HIGH;

void setup()
{
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(REDLED, OUTPUT);
}

void loop()
{
  int buttonState;
  buttonState = digitalRead(BUTTON);
  if (buttonState != lastButtonState)
  {
    if (buttonState == LOW)
    {
      digitalWrite(REDLED, toggle);
      toggle = !toggle;
    }
    lastButtonState = buttonState;
  }
  delay(500);
}
