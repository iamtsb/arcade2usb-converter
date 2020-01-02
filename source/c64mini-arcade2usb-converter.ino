/*
c64mini-arcade2usb-converter.ino
 
C64 Mini Arcade Joystick to USB Converter.
 
Version 1.1 (See CHANGELOG)
Release date: 2019-04-19
 
Written & released by M.F. Wieland (TSB)
 
MIT License

Copyright (c) 2019 M.F. Wieland (TSB)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
 */

#include "joystick.h" 

// define buttons
const int pin_joystick_up = 2;
const int pin_joystick_down = 3;
const int pin_joystick_left = 4;
const int pin_joystick_right = 5;
const int pin_joystick_button1 = 6;

const int pin_joystick_button_menu = 7;
const int pin_joystick_button_a = 8;
const int pin_joystick_button_b = 9;
const int pin_joystick_button_c = 10;


int debounceDelay = 1; // debounce delay

void setup() {
  
  // setup input pins
  pinMode(pin_joystick_up, INPUT_PULLUP);       
  pinMode(pin_joystick_down, INPUT_PULLUP);       
  pinMode(pin_joystick_left, INPUT_PULLUP);       
  pinMode(pin_joystick_right, INPUT_PULLUP);       
  pinMode(pin_joystick_button1, INPUT_PULLUP);       
  pinMode(pin_joystick_button_menu, INPUT_PULLUP);       
  pinMode(pin_joystick_button_a, INPUT_PULLUP);       
  pinMode(pin_joystick_button_b, INPUT_PULLUP);       
  pinMode(pin_joystick_button_c, INPUT_PULLUP);       
}

void loop() {
  
  // Reset values for next loop..  
  Joystick.reset();
  
  // Button - Fire (1)
  if (digitalRead(pin_joystick_button1) == LOW) {
    
    Joystick.button_press(0x40); 
    // see documentation to use other device
  }
  
  // Button - Menu
  if (digitalRead(pin_joystick_button_menu) == LOW) {
    
    Joystick.button_press(0x0200);
    // see documentation to use other device
  }

  // Button - C
  if (digitalRead(pin_joystick_button_a) == LOW) {
    
    Joystick.button_press(0x0100);
    // see documentation to use other device
  }
  
  // Button - B (not in use at this moment)
  if (digitalRead(pin_joystick_button_b) == LOW) {
    
    Joystick.button_press(0x2);
    // see documentation to use other device
  }

  // Button - A
  if (digitalRead(pin_joystick_button_c) == LOW) {
    
    Joystick.button_press(0x4);
    // see documentation to use other device
  }

  // Button - Up
  if (digitalRead(pin_joystick_up) == LOW) {
    
    Joystick.up();  
  }
  
  // Button - Right
  if (digitalRead(pin_joystick_right) == LOW) {
    Joystick.right();
  }
  
  // Button - Down
  if (digitalRead(pin_joystick_down) == LOW) {
    
    Joystick.down();
  }
  
  // Button - Left
  if (digitalRead(pin_joystick_left) == LOW) {

    Joystick.left();
  }
  
  // update joystick actions
  Joystick.usb_update();
  
  delay(debounceDelay);
}
