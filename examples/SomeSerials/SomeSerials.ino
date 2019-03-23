#include "SomeSerial.h"

#if defined(__arm__) && !defined(ADAFRUIT_METRO_M4_EXPRESS) // adafruit samd boards does not use SerialUSB
SomeSerial myHardOrUsbSerial(&SerialUSB);
#else
SomeSerial myHardOrUsbSerial(&Serial);
#endif

#ifndef SOME_SERIAL_NOT_SUPPORT_SOFTWARE_SERIAL
// arm boards and esp32 do not support SoftwareSerial
SomeSerial mySoftSerial1(10, 11); // RX, TX

SoftwareSerial mySoftwareSerial(8, 9); //RX, TX
SomeSerial mySoftSerial2(&mySoftwareSerial);
#endif

void setup() {
  myHardOrUsbSerial.begin(115200);
#ifndef SOME_SERIAL_NOT_SUPPORT_SOFTWARE_SERIAL
  mySoftSerial1.begin(19200);
  mySoftSerial2.begin(9600);
#endif
}

void loop() {
  testPrintWithSomeSerial(&myHardOrUsbSerial);
#ifndef SOME_SERIAL_NOT_SUPPORT_SOFTWARE_SERIAL
  testPrintWithSomeSerial(&mySoftSerial1);
  testPrintWithSomeSerial(&mySoftSerial2);
  delay(1000);
#endif
}

void testPrintWithSomeSerial(SomeSerial* someSerial) {
  someSerial->print("## start some serial at ");
  someSerial->println(millis());
  if (someSerial->isHardwareSerial()) {
    someSerial->println("It is HardwareSerial");
    someSerial->thisHardwareSerial->println("Direct print to HardwareSerial");

  } else if (someSerial->isSerial_()) {
    someSerial->println("It is USBAPI Serial_");
#ifdef USBCON
    someSerial->thisSerial_->println("Direct print to USBAPI Serial_");
#endif
  } else if (someSerial->isSoftwareSerial()) {
    someSerial->println("It is SoftwareSerial");
#ifndef SOME_SERIAL_NOT_SUPPORT_SOFTWARE_SERIAL
    someSerial->thisSoftwareSerial->println("Direct print to SoftwareSerial");
#endif
  }
  someSerial->println("## end some serial");
}

