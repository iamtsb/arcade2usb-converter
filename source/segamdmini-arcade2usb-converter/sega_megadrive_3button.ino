// Interface with a 3-button Sega Mega Drive Controller,
// Converts button presses to USB joystick output

#include "joystick.hpp"

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

  // UP-Button reading
  if (digitalRead(upPin) == LOW) {
    Serial.println("u");
    Joystick.up();
  }
    
  // DOWN-Button reading
  if (digitalRead(downPin) == LOW) {
    Serial.println("d");
    Joystick.down();
  }

  // LEFT-Button reading
  if (digitalRead(leftPin) == LOW) {
    Serial.println("l");    
    Joystick.left();
  }

  // RIGHT-Button reading
  if (digitalRead(rightPin) == LOW) {
    Serial.println("r");    
    Joystick.right();
  }

  // B-Button reading
  if (digitalRead(abPin) == LOW) {
    Serial.println("B");    
    Joystick.button_press(B);
  }

  // C-Button reading
  if (digitalRead(startcPin) == LOW) {
    Serial.println("C");    
    Joystick.button_press(C);
  }

  // Pull SELECT low
  digitalWrite(selectPin, LOW);

  // Make all possible readings when SELECT HIGH:
  // START, A

  // A-Button reading
  if (digitalRead(abPin) == LOW) {
    Serial.println("A");    
    Joystick.button_press(A);
  }

  // START-Button reading
  if (digitalRead(startcPin) == LOW) {
    Serial.println("START");    
    Joystick.start_press();
  }

  // update usb data
  Joystick.usb_update();

//  // delay 20 ms
//  delay(1);
}
