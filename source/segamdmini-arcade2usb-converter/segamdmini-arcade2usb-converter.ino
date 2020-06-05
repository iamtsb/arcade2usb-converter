// Interface with a 3-button Sega Mega Drive Controller,
// Converts button presses to USB joystick output

#include "joystick.h"

// define the arduino input pin numbers
const int upPin = 2;        // UP
const int downPin = 4;      // DOWN
const int leftPin = 9;      // LEFT
const int rightPin = 10;     // RIGHT
const int abPin = 14;        // B on SELECT high, A on SELECT low.
const int selectPin = 7;    // SELECT
const int startcPin = 6;    // C on SELECT high, S on SELECT low.

void setup()
{
  pinMode(selectPin, OUTPUT);     // controlled by arduino
  pinMode(upPin, INPUT_PULLUP);
  pinMode(downPin, INPUT_PULLUP);
  pinMode(leftPin, INPUT_PULLUP);
  pinMode(rightPin, INPUT_PULLUP);
  pinMode(abPin, INPUT_PULLUP);
  pinMode(startcPin, INPUT_PULLUP);
}

void loop()
{
    Joystick.reset();

  // Start by putting SELECT HIGH.
  digitalWrite(selectPin, HIGH);
  delay(2);

  // UP-Button reading
  if (digitalRead(upPin) == LOW) {
    Joystick.up();
  }
    
  // DOWN-Button reading
  if (digitalRead(downPin) == LOW) {
    Joystick.down();
  }

  // LEFT-Button reading
  if (digitalRead(leftPin) == LOW) {
    Joystick.left();
  }

  // RIGHT-Button reading
  if (digitalRead(rightPin) == LOW) {
    Joystick.right();
  }

  // B-Button reading
  if (digitalRead(abPin) == LOW) {
    Joystick.button_press(B);
  }

  // C-Button reading
  if (digitalRead(startcPin) == LOW) {
    Joystick.start_press(C);
  }

  // Pull SELECT low
  digitalWrite(selectPin, LOW);
  delay(2);

  // Make all possible readings when SELECT HIGH:
  // START, A

  // A-Button reading
  if (digitalRead(abPin) == LOW) {
    Joystick.button_press(A);
  }

  // START-Button reading
  if (digitalRead(startcPin) == LOW) {
    Joystick.start_press(START);
  }

  // update usb data
  Joystick.usb_update();

  // delay 20 ms
  delay(10);
}
