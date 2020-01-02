/*
joystick.h
 
Joystick routines to handle arcade to usb conversion
 
Version 1.1
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

#ifndef JOYSTICK_h
#define JOYSTICK_h

#include "HID.h"

//================================================================================
//  Joystick
//================================================================================

class Joystick_
{
private:
  uint16_t _buttons = 0x0;
  uint8_t _x_axis = 0x7F;
  uint8_t _y_axis = 0x7F;
  
public:
  
  Joystick_(void);

  void buttons(uint16_t b);
  void reset(void);
  void up();
  void right();
  void down();
  void left();
  void button_press(uint16_t b);
  void usb_update(); 
};
extern Joystick_ Joystick;

#endif
