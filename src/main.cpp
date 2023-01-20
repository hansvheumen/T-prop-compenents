#include <Arduino.h>

int buttonState;
int previousButtonState = HIGH;
const int BUTTON = 8;
const int GREENLED = 5;

const int POTPIN = A0;
const int REDLED = 4;
int value;

const int UNKNOWN = 0;      // State: Not pressed, released or hold
const int PRESSED = 1;      // State: Button pressed
const int RELEASED = 2;     // State: Button released
const int PRESSED_HOLD = 3; // State: Button pressed and hold
int state = UNKNOWN;

void setup()
{
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(GREENLED, OUTPUT);
  pinMode(POTPIN, INPUT);
  pinMode(REDLED, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  buttonState = digitalRead(BUTTON);
  if(buttonState == LOW && previousButtonState == HIGH)
  {
    state = PRESSED;
  }
  else if(buttonState == HIGH && previousButtonState == LOW)
  {
    state = RELEASED;
  }
  else if(buttonState == LOW && previousButtonState == LOW)
  {
    state = PRESSED_HOLD;
  }
  else
  {
    state = UNKNOWN;
  }
  previousButtonState = buttonState;

  // ... For you to add a ‘small’ button handler that sets the ‘state’ variable,
  // and complete the sequence state pattern below.
  if (state == PRESSED)
  {
    Serial.println("PRESSED");
  }
  else if (state == RELEASED)
  {
    Serial.println("RELEASED");
  }
  else if (state == PRESSED_HOLD)
  {
    Serial.println("PRESSED_HOLD");
  }
}