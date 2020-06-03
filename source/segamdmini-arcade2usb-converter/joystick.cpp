/*
   joystick.cpp

   Joystick routines to handle arcade to usb conversion

   Version 1.1 (See CHANGELOG)
   Release date: 2019-04-19

   Written & released by M.F. Wieland (TSB)

    Licensed under the MIT License. See LICENSE file in the project root for full license information.
*/

#include "joystick.hpp"

#if defined(_USING_HID)

#define JOYSTICK_REPORT_ID 0x01

static const uint8_t _hidReportDescriptor[] PROGMEM = {
  0x05, 0x01,        /* Usage Page (Generic Desktop)  */
  0x09, 0x04,        /* Usage (Joystick)      */
  0xA1, 0x01,        /* Collection (Application)    */
  0xA1, 0x02,        /*   Collection (Logical)    */
  0x75, 0x08,        /*     Report Size (8)   */
  0x95, 0x05,        /*     Report Count (5)    */
  0x15, 0x00,        /*     Logical Minimum (0)   */
  0x26, 0xFF, 0x00,  /*     Logical Maximum (255)   */
  0x35, 0x00,        /*     Physical Minimum (0)    */
  0x46, 0xFF, 0x00,  /*     Physical Maximum (255)  */
  0x09, 0x30,        /*     Usage (Direction-X)     */
  0x09, 0x31,        /*     Usage (Direction-Y)      */
  0x09, 0x32,        /*     Usage (Direction-Z)     */
  0x09, 0x32,        /*     Usage (Direction-Z)     */
  0x09, 0x35,        /*     Usage (Rotate-Z)      */
  0x81, 0x02,        /*     Input (Variable)    */
  0x75, 0x04,        /*     Report Size (4)   */
  0x95, 0x01,        /*     Report Count (1)    */
  0x25, 0x07,        /*     Logical Maximum (7)   */
  0x46, 0x3B, 0x01,  /*     Physical Maximum (315)  */
  0x65, 0x14,        /*     Unit (Centimeter)   */
  0x09, 0x39,        /*     Usage (Hat switch)    */
  0x81, 0x42,        /*     Input (Variable)    */
  0x65, 0x00,        /*     Unit (None)     */
  0x75, 0x01,        /*     Report Size (1)   */
  0x95, 0x0C,        /*     Report Count (12)   */
  0x25, 0x01,        /*     Logical Maximum (1)   */
  0x45, 0x01,        /*     Physical Maximum (1)    */
  0x05, 0x09,        /*     Usage Page (Button)   */
  0x19, 0x01,        /*     Usage Minimum (0x01)    */
  0x29, 0x0C,        /*     Usage Maximum (0x0C)    */
  0x81, 0x02,        /*     Input (Variable)    */
  0x06, 0x00, 0xFF,  /*     Usage Page (Vendor Defined) */
  0x75, 0x01,        /*     Report Size (1)   */
  0x95, 0x08,        /*     Report Count (8)    */
  0x25, 0x01,        /*     Logical Maximum (1)   */
  0x45, 0x01,        /*     Physical Maximum (1)    */
  0x09, 0x01,        /*     Usage (0x01)      */
  0x81, 0x02,        /*     Input (Variable)    */
  0xC0,              /*   End Collection      */
  0xA1, 0x02,        /*   Collection (Logical)    */
  0x75, 0x08,        /*     Report Size (8)   */
  0x95, 0x07,        /*     Report Count (7)    */
  0x46, 0xFF, 0x00,  /*     Physical Maximum (255)  */
  0x26, 0xFF, 0x00,  /*     Logical Maximum (255)   */
  0x09, 0x02,        /*     Usage (0x02)      */
  0x91, 0x02,        /*     Output (Variable)   */
  0xC0,              /*   End Collection      */
  0xC0               /* End Collection      */
};

//================================================================================
//  Joystick
//================================================================================

Joystick_::Joystick_(void)
{
  static HIDSubDescriptor node(_hidReportDescriptor, sizeof(_hidReportDescriptor));
  HID().AppendDescriptor(&node);
}

void Joystick_::reset(void)
{
  //reset button state..
  _buttons = 0x0F;
  _start_button = 0x00;

  //reset x & y axis
  _x_axis = 0x7f;
  _y_axis = 0x7f;
}

void Joystick_::up()
{
  _y_axis = 0x0;
}

void Joystick_::right()
{
  _x_axis = 0xff;
}

void Joystick_::down()
{
  _y_axis = 0xff;
}

void Joystick_::left()
{
  _x_axis = 0x00;
}

void Joystick_::button_press(uint8_t b)
{
  _buttons = _buttons | b;
}

void Joystick_::start_press()
{
  _start_button = 0x10;
}

void Joystick_::usb_update()
{
  // only send usb data if needed..
  uint8_t m[8];
  m[0] = _x_axis;
  m[1] = _y_axis;
  m[2] = 0x0;
  m[3] = 0x0;
  m[4] = 0x0;
  m[5] = _buttons;
  m[6] = 0x0;
  m[7] = _start_button;

  HID().SendReport(JOYSTICK_REPORT_ID, m, sizeof(m));
}

Joystick_ Joystick;

#endif
