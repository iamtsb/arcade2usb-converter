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
      // 0x85, JOYSTICK_REPORT_ID,
    
      0x75, 0x08,        /*     Report Size (8)   */
      0x95, 0x05,        /*     Report Count (5)    */
      0x15, 0x00,         /*    Logical minimum (0) */
      0x26, 0xFF, 0x00,  /*     Logical Maximum (255)   */
      0x35, 0x00,        /*     Physical Minimum (0)    */
      0x46, 0xFF, 0x00,  /*     Physical Maximum (255)  */
      0x09, 0x30,        /*     Usage (Direction-X)     */      
      0x09, 0x30,        /*     Usage (Direction-X)     */
      0x09, 0x30,        /*     Usage (Direction-X)     */      
      0x09, 0x30,        /*     Usage (Direction-X)     */      
      0x09, 0x31,        /*     Usage (Direction-Y)     */
      0x81, 0x02,        /*     Input (Data,Variable,Absolute,No Wrap,Linear,Preferred State,No Null Position)    */

      0x75, 0x04,        /*     Report Size (4)   */
      0x95, 0x01,        /*     Report Count (1)    */
      0x25, 0x07,        /*     Logical Maximum (7)   */
      0x46, 0x3B, 0x01,        /*     Physical Maximum (315)  */
      0x65, 0x14,        /*     Unit (20)   */          
      0x09, 0x00,         /*  Usage (undefined) */                              
      0x81, 0x42,          /* Input 66 (Data,Variable,Absolute,No Wrap,Linear,Preferred State,Null State) */

      0x65, 0x00,         /* Unit 0 */
      0x75, 0x01,          /* Report Size (1) */
      0x95, 0x0A,          /* Report Count (10) */
      0x25, 0x01,         /* Logical Maximum (1) */
      0x45, 0x01,         /* Physical Maximum (1) */
      0x05, 0x09,         /* Usage Page Buttons (9) */
      0x19, 0x01,          /* usage minimum 1 */
      0x29, 0x0A,          /* usage maximum 10 */
      0x81, 0x02,           /* Input 2 (Data,Variable,Absolute,No Wrap,Linear,Preferred State,No Null Position) */
       
      0x06, 0x00, 0xFF,          /* usage page (vendor specific) */
      0x75, 0x01,        /*     Report Size (1)   */
      0x95, 0x0A,        /*     Report Count (10)    */
      0x25, 0x01,        /*     Logical Maximum (1)   */
      0x45, 0x01,       /*     Physical Maximum (1)  */
      0x09, 0x01,        /* Usage (undefined) */
      0x81, 0x02,         /* Input 2 (Data,Variable,Absolute,No Wrap,Linear,Preferred State,No Null Position) */
    0xC0,

    0xA1, 0x02,        /*   Collection (Logical)    */
      0x75, 0x08,       /* report size (8) */
      0x95, 0x04,       /* report count (4) */
      0x46, 0xFF, 0x00,  /* Physical maximum (255) */
      0x26, 0xFF, 0x00,  /* Logical maximum (255) */
      0x09, 0x02,         /* Usage 2 (mouse) */
      0x91, 0x02,         /* Output 2 (Data,Variable,Absolute,No Wrap,Linear,Preferred State,No Null Position,Non Volatile) */
    0xC0,      
  0xC0               /* End Collection      */
};     

//================================================================================
//  Joystick
//================================================================================

Joystick_::Joystick_(void): PluggableUSBModule(1, 1, epType), protocol(HID_REPORT_PROTOCOL), idle(1)
{
//  static HIDSubDescriptor node(_hidReportDescriptor, sizeof(_hidReportDescriptor));
//  HID().AppendDescriptor(&node);

  epType[0] = EP_TYPE_INTERRUPT_IN;
  PluggableUSB().plug(this);
    
}

int Joystick_::getInterface(uint8_t* interfaceCount)
{
  *interfaceCount += 1; // uses 1
  HIDDescriptor hidInterface = {
    D_INTERFACE(pluggedInterface, 1, USB_DEVICE_CLASS_HUMAN_INTERFACE, HID_SUBCLASS_NONE, HID_PROTOCOL_NONE),
    D_HIDREPORT(sizeof(_hidReportDescriptor)),
    D_ENDPOINT(USB_ENDPOINT_IN(pluggedEndpoint), USB_ENDPOINT_TYPE_INTERRUPT, USB_EP_SIZE, 0x01)
  };
  return USB_SendControl(0, &hidInterface, sizeof(hidInterface));
}

int Joystick_::getDescriptor(USBSetup& setup)
{
  // Check if this is a HID Class Descriptor request
  if (setup.bmRequestType != REQUEST_DEVICETOHOST_STANDARD_INTERFACE) { return 0; }
  if (setup.wValueH != HID_REPORT_DESCRIPTOR_TYPE) { return 0; }

  // In a HID Class Descriptor wIndex cointains the interface number
  if (setup.wIndex != pluggedInterface) { return 0; }

  // Reset the protocol on reenumeration. Normally the host should not assume the state of the protocol
  // due to the USB specs, but Windows and Linux just assumes its in report mode.
  protocol = HID_REPORT_PROTOCOL;

  return USB_SendControl(TRANSFER_PGM, _hidReportDescriptor, sizeof(_hidReportDescriptor));
}

bool Joystick_::setup(USBSetup& setup)
{
  if (pluggedInterface != setup.wIndex) {
    return false;
  }

  uint8_t request = setup.bRequest;
  uint8_t requestType = setup.bmRequestType;

  if (requestType == REQUEST_DEVICETOHOST_CLASS_INTERFACE)
  {
    if (request == HID_GET_REPORT) {
      // TODO: HID_GetReport();
      return true;
    }
    if (request == HID_GET_PROTOCOL) {
      // TODO: Send8(protocol);
      return true;
    }
  }

  if (requestType == REQUEST_HOSTTODEVICE_CLASS_INTERFACE)
  {
    if (request == HID_SET_PROTOCOL) {
      protocol = setup.wValueL;
      return true;
    }
    if (request == HID_SET_IDLE) {
      idle = setup.wValueL;
      return true;
    }
    if (request == HID_SET_REPORT)
    {
    }
  }

  return false;
}

void Joystick_::SendReport(void* data, int length){
  USB_Send(pluggedEndpoint | TRANSFER_RELEASE, data, length);
}

void Joystick_::reset(void)
{
  // reset button state..
  _buttons = 0x0F;
  _start_button = 0x00;

  // reset x & y axis
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
  uint8_t m[8];

  m[0] = 0x01;
  m[1] = _x_axis;
  m[2] = _x_axis;
  m[3] = _x_axis;
  m[4] = _y_axis;
  m[5] = _buttons;
  m[6] = _start_button;
  m[7] = 0x00;

 USB_Send(pluggedEndpoint | TRANSFER_RELEASE, m, sizeof(m));
  // HID().SendReport(JOYSTICK_REPORT_ID, m, sizeof(m));
}

Joystick_ Joystick;

#endif
