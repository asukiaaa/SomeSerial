#include "SomeSerial.h"

#define FLAG_HARDWARE_SERIAL 0
#define FLAG_SOFTWARE_SERIAL 1
#define FLAG_USBCON_SERIAL   2

SomeSerial::SomeSerial(HardwareSerial* _thisHardwareSerial) {
  thisHardwareSerial = _thisHardwareSerial;
  flag = FLAG_HARDWARE_SERIAL;
}

#ifndef SOME_SERIAL_NOT_SUPPORT_SOFTWARE_SERIAL
SomeSerial::SomeSerial(SoftwareSerial* _thisSoftwareSerial) {
  thisSoftwareSerial = _thisSoftwareSerial;
  flag = FLAG_SOFTWARE_SERIAL;
}

SomeSerial::SomeSerial(int rx, int tx) {
  thisSoftwareSerial = new SoftwareSerial(rx, tx);
  flag = FLAG_SOFTWARE_SERIAL;
}
#endif

#ifdef USBCON
SomeSerial::SomeSerial(Serial_* _thisSerial_) {
  thisSerial_ = _thisSerial_;
  flag = FLAG_USBCON_SERIAL;
}
#endif

void SomeSerial::begin(long speed) {
  switch (flag) {
#ifndef SOME_SERIAL_NOT_SUPPORT_SOFTWARE_SERIAL
  case FLAG_SOFTWARE_SERIAL:
    thisSoftwareSerial->begin(speed);
    break;
#endif
#ifdef USBCON
  case FLAG_USBCON_SERIAL:
    thisSerial_->begin(speed);
    break;
#endif
  default: // FLAG_HARDWARE_SERIAL
    thisHardwareSerial->begin(speed);
  }
}

void SomeSerial::end() {
  switch (flag) {
#ifndef SOME_SERIAL_NOT_SUPPORT_SOFTWARE_SERIAL
  case FLAG_SOFTWARE_SERIAL:
    thisSoftwareSerial->end();
    break;
#endif
#ifdef USBCON
  case FLAG_USBCON_SERIAL:
    thisSerial_->end();
    break;
#endif
  default: // FLAG_HARDWARE_SERIAL
    thisHardwareSerial->end();
  }
}

bool SomeSerial::isHardwareSerial() {
  return flag == FLAG_HARDWARE_SERIAL;
}

bool SomeSerial::isSoftwareSerial() {
  return flag == FLAG_SOFTWARE_SERIAL;
}

bool SomeSerial::isSerial_() {
  return flag == FLAG_USBCON_SERIAL;
}

int SomeSerial::peek() {
  switch (flag) {
#ifndef SOME_SERIAL_NOT_SUPPORT_SOFTWARE_SERIAL
  case FLAG_SOFTWARE_SERIAL:
    return thisSoftwareSerial->peek();
#endif
#ifdef USBCON
  case FLAG_USBCON_SERIAL:
    return thisSerial_->peek();
#endif
  default: // FLAG_HARDWARE_SERIAL
    return thisHardwareSerial->peek();
  }
}

size_t SomeSerial::write(uint8_t byte) {
  switch (flag) {
#ifndef SOME_SERIAL_NOT_SUPPORT_SOFTWARE_SERIAL
  case FLAG_SOFTWARE_SERIAL:
    return thisSoftwareSerial->write(byte);
#endif
#ifdef USBCON
  case FLAG_USBCON_SERIAL:
    return thisSerial_->write(byte);
#endif
  default: // FLAG_HARDWARE_SERIAL
    return thisHardwareSerial->write(byte);
  }
}

int SomeSerial::read() {
  switch (flag) {
#ifndef SOME_SERIAL_NOT_SUPPORT_SOFTWARE_SERIAL
  case FLAG_SOFTWARE_SERIAL:
    return thisSoftwareSerial->read();
#endif
#ifdef USBCON
  case FLAG_USBCON_SERIAL:
    return thisSerial_->read();
#endif
  default: // FLAG_HARDWARE_SERIAL
    return thisHardwareSerial->read();
  }
}

int SomeSerial::available() {
  switch (flag) {
#ifndef SOME_SERIAL_NOT_SUPPORT_SOFTWARE_SERIAL
  case FLAG_SOFTWARE_SERIAL:
    return thisSoftwareSerial->available();
#endif
#ifdef USBCON
  case FLAG_USBCON_SERIAL:
    return thisSerial_->available();
#endif
  default: // FLAG_HARDWARE_SERIAL
    return thisHardwareSerial->available();
  }
}

void SomeSerial::flush() {
  switch (flag) {
#ifndef SOME_SERIAL_NOT_SUPPORT_SOFTWARE_SERIAL
  case FLAG_SOFTWARE_SERIAL:
    thisSoftwareSerial->flush();
    break;
#endif
#ifdef USBCON
  case FLAG_USBCON_SERIAL:
    thisSerial_->flush();
    break;
#endif
  default: // FLAG_HARDWARE_SERIAL
    thisHardwareSerial->flush();
  }
}
