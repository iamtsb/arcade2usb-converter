/*
   joystick.cpp

   Joystick routines to handle arcade to usb conversion

   Version 1.2 (See CHANGELOG)
   Release date: 2020-06-07

   Written & released by W.Bovelander (The Highlander)

    Licensed under the MIT License. See LICENSE file in the project root for full license information.
*/

#include "joystick.h"

#if defined(_USING_HID)

#define JOYSTICK_REPORT_ID 0x01

static const uint8_t _hidReportDescriptor[] PROGMEM = {
  0x05, 0x01,        /* Usage Page (Generic Desktop)  */
  0x09, 0x04,        /* Usage (Joystick)      */
  0xA1, 0x01,        /* Collection (Application)    */
    0xA1, 0x02,        /*   Collection (Logical)    */
      0x85, JOYSTICK_REPORT_ID,
    
      0x75, 0x08,        /*     Report Size (8)   */
      0x95, 0x04,        /*     Report Count (4)    */
      0x26, 0xFF, 0x00,  /*     Logical Maximum (255)   */
      0x35, 0x00,        /*     Physical Minimum (0)    */
      0x46, 0xFF, 0x00,  /*     Physical Maximum (255)  */
      0x09, 0x01,        /*     Usage (vendor specific)      */
      0x09, 0x01,        /*     Usage (vendor specific)     */
      0x09, 0x30,        /*     Usage (Direction-X)     */      
      0x09, 0x31,        /*     Usage (Direction-Y)     */
      0x81, 0x02,        /*     Input (Variable)    */

      0x65, 0x00,        /*     Unit (None)   */
      0x75, 0x01,        /*     Report Size (1)   */
      0x95, 0x10,        /*     Report Count (16)    */
      0x25, 0x01,        /*     Logical Maximum (1)   */
      0x45, 0x01,        /*     Physical Maximum (1)  */
      0x05, 0x09,         /*  Usage Page (Buttons) */
      0x19, 0x01,          /* Usage_Minimum button 1 */
      0x29, 0x10,          /* Usage_Maximum button 16 */                              
      0x81, 0x02,          /* Input 2 (Data,Variable,Absolute,No Wrap,Linear,Preferred State,No Null Position) */
      
      0x06, 0x00, 0xFF,          /* usage page (vendor specific) */
      0x75, 0x01,        /*     Report Size (1)   */
      0x95, 0x08,        /*     Report Count (8)    */
      0x25, 0x01,        /*     Logical Maximum (1)   */
      0x45, 0x01,       /*     Physical Maximum (1)  */
      0x09, 0x02,        /* Usage (vendor usage 2) */
      0x81, 0x02,         /* Input 2 (Data,Variable,Absolute,No Wrap,Linear,Preferred State,No Null Position) */

      0xC0,
  0xC0               /* End Collection      */
};      

//================================================================================
//  Joystick
//================================================================================

Joystick_::Joystick_(void)
{
  static HIDSubDescriptor node(_hidReportDescriptor, sizeof(_hidReportDescriptor));
  HID().AppendDescriptor(&node);

  uint8_t m_clean[7];
  m_clean[0] = 0x7f;
  m_clean[1] = 0x7f;
  m_clean[2] = 0x7f;
  m_clean[3] = 0x7f;
  m_clean[4] = 0x0f;
  m_clean[5] = 0x00;
  m_clean[6] = 0x00;
  HID().SendReport(JOYSTICK_REPORT_ID, m_clean, sizeof(m_clean));
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

void Joystick_::start_press(uint8_t b)
{
  _start_button = _start_button | b;
}

void Joystick_::usb_update()
{
  // only send usb data if needed..
  uint8_t m[7];

  m[0] = 0x7f;
  m[1] = 0x7f;
  m[2] = _x_axis;
  m[3] = _y_axis;
  m[4] = _buttons;
  m[5] = _start_button;
  m[6] = 0x00;

  HID().SendReport(JOYSTICK_REPORT_ID, m, sizeof(m));
}

Joystick_ Joystick;

#endif
