#include "SomeSerial.h"

SomeSerial myHardOrUsbSerial(&Serial);

SomeSerial mySoftSerial1(10, 11); // RX, TX

SoftwareSerial mySoftwareSerial(8,9); //RX, TX
SomeSerial mySoftSerial2(&mySoftwareSerial);

void setup() {
  myHardOrUsbSerial.begin(115200);
  mySoftSerial1.begin(19200);
  mySoftSerial2.begin(9600);
}

void loop() {
  testPrintWithSomeSerial(&myHardOrUsbSerial);
  testPrintWithSomeSerial(&mySoftSerial1);
  testPrintWithSomeSerial(&mySoftSerial2);
  delay(1000);
}

void testPrintWithSomeSerial(SomeSerial* someSerial) {
  someSerial->print("## start some serial at ");
  someSerial->println(millis());
  if (someSerial->isHardSerial()) {
    someSerial->println("It is HardwareSerial");
    someSerial->hardSerial->println("Direct print to HardwareSerial");

  } else if (someSerial->isUsbSerial()) {
    someSerial->println("It is UsbSerial");
#ifdef __USB_SERIAL_AVAILABLE__
    someSerial->usbSerial->println("Direct print to UsbSerial");
#endif

  } else if (someSerial->isSoftSerial()) {
    someSerial->println("It is SoftwareSerial");
    someSerial->softSerial->println("Direct print to SoftwareSerial");
  }
  someSerial->println("## end some serial");
}

