#include "SomeSerial.h"

#define FLAG_HARDWARE_SERIAL 0
#define FLAG_SOFTWARE_SERIAL 1
#define FLAG_USBCON_SERIAL   2
#define FLAG_UART_CLASS      3
#define FLAG_UART            4

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
#ifdef ARDUINO_SAM_DUE
SomeSerial::SomeSerial(UARTClass* _thisUARTClass) {
  thisUARTClass = _thisUARTClass;
  flag = FLAG_UART_CLASS;
}
#elif defined(UART)
SomeSerial::SomeSerial(Uart* _thisUart) {
  thisUart = _thisUart;
  flag = FLAG_UART;
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
#ifdef ARDUINO_SAM_DUE
  case FLAG_UART_CLASS:
    thisUARTClass->begin(speed);
    break;
#elif defined(UART)
  case FLAG_UART:
    thisUart->begin(speed);
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
#ifdef ARDUINO_SAM_DUE
  case FLAG_UART_CLASS:
    thisUARTClass->end();
    break;
#elif defined(UART)
  case FLAG_UART:
    thisUart->end();
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

bool SomeSerial::isUARTClass() {
  return flag == FLAG_UART_CLASS;
}

bool SomeSerial::isUart() {
  return flag == FLAG_UART;
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
#ifdef ARDUINO_SAM_DUE
  case FLAG_UART_CLASS:
    return thisUARTClass->peek();
#elif defined(UART)
  case FLAG_UART:
    return thisUart->peek();
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
#ifdef ARDUINO_SAM_DUE
  case FLAG_UART_CLASS:
    return thisUARTClass->write(byte);
#elif defined(UART)
  case FLAG_UART:
    return thisUart->write(byte);
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
#ifdef ARDUINO_SAM_DUE
  case FLAG_UART_CLASS:
    return thisUARTClass->read();
#elif defined(UART)
  case FLAG_UART:
    return thisUart->read();
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
#ifdef ARDUINO_SAM_DUE
  case FLAG_UART_CLASS:
    return thisUARTClass->available();
#elif defined(UART)
  case FLAG_UART:
    return thisUart->available();
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
#ifdef ARDUINO_SAM_DUE
  case FLAG_UART_CLASS:
    thisUARTClass->flush();
    break;
#elif defined(UART)
  case FLAG_UART:
    thisUart->flush();
    break;
#endif
  default: // FLAG_HARDWARE_SERIAL
    thisHardwareSerial->flush();
  }
}
