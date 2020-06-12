/*
   joystick.h

   Joystick routines to handle arcade to usb conversion

   Version 1.2 (See CHANGELOG)
   Release date: 2020-06-07

   Written & released by W.Bovelander (The Highlander)

    Licensed under the MIT License. See LICENSE file in the project root for full license information.
*/

#ifndef JOYSTICK_h
#define JOYSTICK_h

#include "HID.h"

// define output bits 
static const uint8_t A       = 0x4f; // 0100 1111
static const uint8_t B       = 0x2f; // 0010 1111
static const uint8_t START   = 0x20; // 0010 0000
static const uint8_t C       = 0x02; // 0000 0010

//================================================================================
//  Joystick
//================================================================================

class Joystick_
{
  private:
    uint8_t _buttons = 0x0F;
    uint8_t _start_button = 0x00;
    uint8_t _x_axis = 0x7F;
    uint8_t _y_axis = 0x7F;

  public:

    Joystick_(void);

    void buttons(uint8_t b);
    void reset(void);
    void up();
    void right();
    void down();
    void left();
    void button_press(uint8_t b);
    void start_press(uint8_t b);
    void usb_update();
};
extern Joystick_ Joystick;

#endif
