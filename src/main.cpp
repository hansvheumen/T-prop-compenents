#include <Arduino.h>

const int BUTTON = 8;
const int GREENLED = 5;

const int POTPIN = A0;
const int REDLED = 4;

const int UNKNOWN = 0;      // State: Not pressed, released or hold
const int PRESSED = 1;      // State: Button pressed
const int RELEASED = 2;     // State: Button released
const int PRESSED_HOLD = 3; // State: Button pressed and hold
const int RELEASED_HOLD = 4; 

int state;
int buttonState;
int previousButtonState = HIGH;
bool isPrinted = false;

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
   
  if (buttonState == LOW && previousButtonState == HIGH)
  {
    state = PRESSED;
  }
  else if (buttonState == HIGH && previousButtonState == LOW)
  {
    state = RELEASED;
  }
  else if (buttonState == LOW && previousButtonState == LOW)
  {
    state = PRESSED_HOLD;
  }
  else if (buttonState == HIGH && previousButtonState == HIGH)
  {
    state = RELEASED_HOLD;
  }
  else
  {
    state = UNKNOWN;
  }

  // ... For you to add a ‘small’ button handler that sets the ‘state’ variable,
  // and complete the sequence state pattern below.
  if (buttonState != previousButtonState)
  {   
    if (state == PRESSED)
    {
      Serial.println("PRESSED");
    }
    else if (state == RELEASED)
    {
      Serial.println("RELEASED");
    }
    previousButtonState = buttonState;
    isPrinted = false;
  }
  else
  {
    if (!isPrinted)
    {       
      if (state == PRESSED_HOLD)
      {         
        Serial.println("PRESSED_HOLD");
      }
      else if (state == RELEASED_HOLD)
      {
        Serial.println("RELEASED_HOLD");
      }
      else
      {
        Serial.println("UNKNOWN");
      }
      isPrinted = true;
    }
  }
  delay(500);
}
