#include "SomeSerial.h"

SomeSerial myHardOrUsbSerial(&Serial);

SomeSerial mySoftSerial1(10, 11); // RX, TX

SoftwareSerial mySoftwareSerial(8, 9); //RX, TX
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
  if (someSerial->isHardwareSerial()) {
    someSerial->println("It is HardwareSerial");
    someSerial->thisHardwareSerial->println("Direct print to HardwareSerial");

  } else if (someSerial->isSerial_()) {
    someSerial->println("It is USBAPI Serial_");
#ifdef __USB_SERIAL_AVAILABLE__
    someSerial->thisSerial_->println("Direct print to USBAPI Serial_");
#endif

  } else if (someSerial->isSoftwareSerial()) {
    someSerial->println("It is SoftwareSerial");
    someSerial->thisSoftwareSerial->println("Direct print to SoftwareSerial");
  }
  someSerial->println("## end some serial");
}

