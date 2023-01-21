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
int value;
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
  value = analogRead(POTPIN);
  digitalWrite(REDLED, HIGH);
  delay(value);
  digitalWrite(REDLED, LOW);
  delay(value);

  int quarter = map(value, 0, 1023, 0, 3);
  Serial.println(quarter + 1);
}
