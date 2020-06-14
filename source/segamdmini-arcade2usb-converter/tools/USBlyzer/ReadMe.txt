
                                             May 15, 2016
                                             USBlyzer 2.2


       Thank you for your interest in USBlyzer!


 OVERVIEW

   USBlyzer is an easy to use software USB protocol analyzer
   for Windows,  which  provides  a complete  yet  simple to
   understand  view  for  analyzing  USB  Host  Controllers,
   USB Hubs and USB Devices activity.

   With USBlyzer you can view detailed information about all
   USB devices and their child components.

   USBlyzer  allows  you  to  capture,  decode  and  display
   important  information  such  as URB requests and related
   structures used by USB drivers, IRP used by PnP subsystem,
   Kernel-Mode and User-Mode I/O Requests used by USB client
   drivers and user-mode applications. 

   USBlyzer can be successfully used for application, device
   driver and hardware development and can help you test and
   troubleshoot software and hardware. 

   USBlyzer is a complete  software  solution,  so you won't
   have to install any additional hardware or software. 

   You'll find  USBlyzer  extremely useful for understanding
   how system-supplied and vendor-supplied USB device drivers
   communicate with the USB driver stack.


 FEATURES

   - Completely customizable interface with docked windows and
     user-defined screen sets.

   Viewing

   - Display all plugged USB devices in a hierarchical auto-
     refreshed tree-view.
   - View and explore the USB Devices and their components.
   - View detailed USB-related information about each USB device:
     Device Descriptor, Configuration, Interfaces, Endpoints, etc.
   - Verify the general compliance of all standard USB descriptors
     with the USB Specification.
   - View detailed PnP-related information about each USB device:
     Hardware IDs, Instance ID, Software Key, PDO Name, etc.

   Capturing

   - Real-Time  monitoring  at any level in the USB driver stack
     from USB Host Controller to target USB Device.
   - Capture several USB devices simultaneously.
   - Separate log records for request issue and completion.
   - Capture almost all types of USB Request Block (URB).
   - Capture almost all types of USB-related  kernel-mode device
     I/O control requests.
   - Capture  almost  all  types of user-mode device I/O control
     requests to USB Host Controller and USB Hub.
   - Capture all PnP IRPs.
   - Automatically  capture  hot plugged devices. Can be used to
     monitor device enumeration process.

   Analyzing

   - Analyze USB protocol and USB devices I/O activity with ease.
   - Display detailed analysis of all USB standard requests such
     as Set Feature, Get Descriptor etc.
   - Includes comprehensive USB Class Decoders.
   - Display detailed information about IRP, IO_STACK_LOCATION
     and URB structures associated with each captured request.
   - Display the buffer contents, if any, associated with the
     request in hex format.
   - Configurable filtering to exclude non-essential information
     from the view.
   - Search feature to search the capture file for the particular
     request types.

   Saving

   - Save captured data in binary file for later analysis.
   - Export Capture List content or any part of it to plain text,
     CSV, XML or HTML formats.
   - Export USB Descriptor hierarchy of any USB Device to HTML
     formats.


 SYSTEM REQUIREMENTS

   Supported Microsoft® Windows® platforms (both x86 and x64 supported):
     - Windows 2000
     - Windows XP
     - Windows Vista
     - Windows 7
     - Windows 8
     - Windows 10
     - Windows Server 2003
     - Windows Server 2008

     USBlyzer runs on all of the above mentioned operating
     systems without any compatibility issues and does not
     require any service pack.

     Microsoft® Windows 95, 98, ME and NT4 are not supported.

   Hardware Requirements:
     - Any Intel® compatible CPU (233 MHz required, 1 GHz
       or faster recommended)
     - 64 MB of RAM or more (At least 256 MB recommended)
     - At least one USB 1.1, 2.0 or 3.0 Host Controller
     - 10 MB of available hard disk space (At least 16 MB of
       extra disk space for temporary capture file recommended)


 VERSION HISTORY

   2.2 - Released May 15, 2016

     - Mass Storage Class (MSC) support added. Now we decode and display
       MSC class-specific requests, Command Block Wrapper (CBW), Command
       Status Wrapper (CSW) and SCSI command descriptor blocks and response
       data.
     - Multiple instances of USBlyzer client application can be run
       simultaneously (only one in capture mode).
     - Bug fixes and small improvements.

   2.1 - Released March 16, 2014

     - USB 3.0 support added.
     - Capture file size limit was increased from 256 MB to 1 GB.
     - URB transfer buffer size limit was increased from 256 MB to 4 MB.
     - Displaying USB device operating speed has been correted.
     - Pended IRPs used in "Inverted call model" are now capturable.
     - Displaying URB transfer direction in I/O column has been correted.
     - Bug fixes and improvements.

   2.0 - Released April 3, 2011

     - 64-bit OS support.
     - Added capturing and decoding support for Power IRPs.
     - Added capturing and decoding support for Create/Cleanup/Close IRPs.
     - Added elapsed and duration time measuring.
     - Added ability to set elapsed time reference point.
     - Improved date and time formating.
     - Added failed IRPs highlighting.
     - Added filtering URB In/Out transfers.
     - Added exporting raw data dump.

   1.6 - Released March 24, 2010

     - Added support for Virtual USB Devices.
     - Improved Wireless USB Devices support.
     - Minor bug fixes and improvements.

   1.5 - Released August 24, 2009

     - Added Windows 7 32-bit OS support. 
     - Minor bug fixes and improvements.

   1.4 - Released October 07, 2008

     - Communication Device Class (CDC) support added. Now we
       decode and display CDC class-specific functional descriptors,
       decode communication interface management element requests
       and notifications.

     - New capture list column "Raw Data" has been added. This
       column displays up to 8 bytes of the buffer contents for
       control, bulk, interrupt, and isochronous transfers and
       for any other URBs which contain the transfer buffer. If
       the number of bytes that was actually transferred is greater
       than 8, the displayed sequence is terminated with an
       ellipsis (...).

     - Previously, for bulk, interrupt and isochronous transfer
       URBs the "Request Details" column in the capture list
       displayed only the value of TransferBufferLength field
       of URB_BULK_OR_INTERRUPT_TRANSFER and URB_ISOCH_TRANSFER.
       Now the protocol analyzer also shows you whether the buffer
       is filled with meaningful data or it's just an empty buffer
       to be filled with data.


   1.3 - Released June 18, 2008

     - Human  Interface  Device (HID) class support added.  Now
       we parse and display HID reports in an easy to view form,
       decode and display HID class-specific descriptors, decode
       all HID class-specific requests). Compound and composite
       devices with HID class interface(s) are supported.

     - Syncing Capture List with Device Tree + Auto Sync feature

     - 2440 vendors recognized


   1.2 - Released December 26, 2007

     - When displaying the time, we previously only showed
       the absolute system time the I/O request was captured.
       Now you can configure USBlyzer to display the time in
       the following formats:

        - Absolute system time (11:45:14.278)
        - Time elapsed since capture started (00:00:15.953)
        - Seconds elapsed since capture started (2.396)

     - To configure the time display settings, new section
       was added in the Preferences Dialog.

     - Hub Class support added. Now we decode all USB Hub
       Requests (Get Hub Status, Clear Port Feature, Get Hub
       Descriptor, Reset TT etc.).

     - Request Summary analysis was significantly improved.
       When displaying the summary for Control Transfers,
       we previously only showed the Setup Packet in raw
       format. Now the summary analysis is much more specific
       and relevant for all USB Standard and USB Hub Requests.

     - Previously we only captured state-transition Plug and
       Play IRPs (start, stop, remove). Now USBlyzer captures
       and decodes all Plug and Play IRPs.

     - Added capturing and decoding support for the following
       Windows® Vista™ URBs:

       URB_FUNCTION_CONTROL_TRANSFER_EX
       URB_FUNCTION_SET_PIPE_IO_POLICY
       URB_FUNCTION_GET_PIPE_IO_POLICY

     - Added capturing and decoding support for the following
       Windows® Vista™ IOCTLs:

       IOCTL_USB_GET_HUB_CAPABILITIES_EX

     - When displaying the completed IRP status, we previously
       only showed the completion status of the IRP itself in
       the IRP Status column of the Capture List. Now for all
       completed URBs you can also see the USBD_STATUS.

     - Export Capture List content to XML report.

     - New Capture List column "Request Details" has been added.
       This feature is extremely useful in analyzing the captured
       data and greatly speeds up the analysis process. Now you
       can see, at a glance, by just looking at Capture List the
       Number of Bytes transferred for bulk and isoch transfers,
       the Port Number for IOCTL_USB_GET_NODE_CONNECTION_XXX I/O
       control requests, Request Type and Recipient for control
       transfers and more.

     - New Data Analysis Panel has been added. When displaying
       the data buffer contents, we previously only showed the
       raw hexadecimal dump in the Raw Data Panel. Now you can
       also see the complete analysis for many types of requests
       in Data Analysis Panel. USBlyzer is able to verify the
       general compliance of USB Request Packets with the USB
       Specification. Any incompatibilities are marked with red
       color.


   1.1 - Released September 18, 2007

     - The USB Properties panel has been completely re-designed
       and now the USB device descriptors and related information
       are presented in much greater details.

     - USBlyzer is now able to verify the general compliance of
       all standard USB descriptors with the  USB Specification.
       Any  incompatibilities  are marked with red color in the
       USB Properties panel.

     - The content of the USB Properties panel can now be exported
       to the HTML report.

     - Capture Settings, Filter Settings and Find Settings dialogs
       are now resizable.

     - The Capture List is now colorized. You have three options:
       colorize entire row, type column only or not colorize at all.

     - The Device Manager's  device  properties  dialog  box can be
       invoked by right-clicking the specific device in the  Device
       Tree  and  then  clicking  Properties.  This allow you  view
       information about a device driver, bandwidth allocations for
       USB host controllers, power allocations for USB hubs and more.

     - The  device  tree  now  displays  the drive letter that is 
       assigned to each USB mass-storage device such as USB Flash
       Drive, USB CD-ROM Device, USB Card Reader etc.

     - Internal  improvements  in  saving  the captured data to a
       capture file.

     - Minor bug fixes and improvements.


   1.0 - Released July 02, 2007

     - Displaying Interface Association Descriptor (IAD)
     - Displaying Device Class, Subclass, Protocol
     - Displaying Interface Class, Subclass, Protocol
     - More than 2000 vendors recognized


   1.0 Beta 3  - Released June 10, 2007

     - Critical bug in capture driver causing BSOD
       on multiprocessor systems was fixed
     - Minor GUI fixes and improvements


   1.0 Beta 2  - Released May 06, 2007

     - Several compatibility issues were fixed
     - Several minor bugs were fixed


   1.0 Beta 1  - Released February 02, 2007


   1.0 Alpha 1 - Released June 20, 2006


 CONTACT US

   To report a problem, please provide a detailed description
   of the ways  in  which  it manifests itself on your system,
   the steps  which  lead up to the error and the information
   about your operating system version used for testing.

   If you have any questions  or would you like to provide us
   with your feedback please email support@usblyzer.com

   For queries regarding pricing and licensing, please contact
   us at sales@usblyzer.com.

                          Copyright © 2006-2016 USBlyzer Team
                                          All Rights Reserved
                                      http://www.usblyzer.com
