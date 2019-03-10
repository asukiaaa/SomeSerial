#include "SomeSerial.h"

SomeSerial::SomeSerial(HardwareSerial* _thisHardwareSerial) {
  thisHardwareSerial = _thisHardwareSerial;
  setAllFlagsFalse();
  flagHardwareSerial = true;
}

#ifndef SOME_SERIAL_NOT_SUPPORT_SOFTWARE_SERIAL
SomeSerial::SomeSerial(SoftwareSerial* _thisSoftwareSerial) {
  thisSoftwareSerial = _thisSoftwareSerial;
  setAllFlagsFalse();
  flagSoftwareSerial = true;
}

SomeSerial::SomeSerial(int rx, int tx) {
  thisSoftwareSerial = new SoftwareSerial(rx, tx);
  setAllFlagsFalse();
  flagSoftwareSerial = true;
}
#endif

#ifdef USBCON
SomeSerial::SomeSerial(Serial_* _thisSerial_) {
  thisSerial_ = _thisSerial_;
  setAllFlagsFalse();
  flagSerial_ = true;
}
#endif
#ifdef ARDUINO_SAM_DUE
SomeSerial::SomeSerial(UARTClass* _thisUARTClass) {
  thisUARTClass = _thisUARTClass;
  setAllFlagsFalse();
  flagUARTClass = true;
}
#elif defined(UART)
SomeSerial::SomeSerial(Uart* _thisUart) {
  thisUart = _thisUart;
  setAllFlagsFalse();
  flagUart = true;
}
#endif

void SomeSerial::begin(long speed) {
  if (flagHardwareSerial) {
    thisHardwareSerial->begin(speed);
#ifdef USBCON
  } else if (flagSerial_) {
    thisSerial_->begin(speed);
#endif
#ifdef ARDUINO_SAM_DUE
  } else if (flagUARTClass) {
    thisUARTClass->begin(speed);
#elif defined(UART)
  } else if (flagUart) {
    thisUart->begin(speed);
#endif
#ifndef SOME_SERIAL_NOT_SUPPORT_SOFTWARE_SERIAL
  } else {
    thisSoftwareSerial->begin(speed);
#endif
  }
}

void SomeSerial::end() {
  if (flagHardwareSerial) {
    thisHardwareSerial->end();
#ifdef USBCON
  } else if (flagSerial_) {
    thisSerial_->end();
#endif
#ifdef ARDUINO_SAM_DUE
  } else if (flagUARTClass) {
    thisUARTClass->end();
#elif defined(UART)
  } else if (flagUart) {
    thisUart->end();
#endif
#ifndef SOME_SERIAL_NOT_SUPPORT_SOFTWARE_SERIAL
  } else {
    thisSoftwareSerial->end();
#endif
  }
}

bool SomeSerial::isHardwareSerial() {
  return flagHardwareSerial;
}

bool SomeSerial::isSoftwareSerial() {
  return flagSoftwareSerial;
}

bool SomeSerial::isSerial_() {
  return flagSerial_;
}

bool SomeSerial::isUARTClass() {
  return flagSerial_;
}

bool SomeSerial::isUart() {
  return flagSerial_;
}

int SomeSerial::peek() {
  if (flagHardwareSerial) {
    return thisHardwareSerial->peek();
#ifdef USBCON
  } else if (flagSerial_) {
    return thisSerial_->peek();
#endif
#ifdef ARDUINO_SAM_DUE
  } else if (flagUARTClass) {
    return thisUARTClass->peek();
#elif defined(UART)
  } else if (flagUart) {
    return thisUart->peek();
#endif
#ifndef SOME_SERIAL_NOT_SUPPORT_SOFTWARE_SERIAL
  } else {
    return thisSoftwareSerial->peek();
#endif
  }
}

size_t SomeSerial::write(uint8_t byte) {
  if (flagHardwareSerial) {
    return thisHardwareSerial->write(byte);
#ifdef USBCON
  } else if (flagSerial_) {
    return thisSerial_->write(byte);
#endif
#ifdef ARDUINO_SAM_DUE
  } else if (flagUARTClass) {
    return thisUARTClass->write(byte);
#elif defined(UART)
  } else if (flagUart) {
    return thisUart->write(byte);
#endif
#ifndef SOME_SERIAL_NOT_SUPPORT_SOFTWARE_SERIAL
  } else {
    return thisSoftwareSerial->write(byte);
#endif
  }
}

int SomeSerial::read() {
  if (flagHardwareSerial) {
    return thisHardwareSerial->read();
#ifdef USBCON
  } else if (flagSerial_) {
    return thisSerial_->read();
#endif
#ifdef ARDUINO_SAM_DUE
  } else if (flagUARTClass) {
    return thisUARTClass->read();
#elif defined(UART)
  } else if (flagUart) {
    return thisUart->read();
#endif
#ifndef SOME_SERIAL_NOT_SUPPORT_SOFTWARE_SERIAL
  } else {
    return thisSoftwareSerial->read();
#endif
  }
}

int SomeSerial::available() {
  if (flagHardwareSerial) {
    return thisHardwareSerial->available();
#ifdef USBCON
  } else if (flagSerial_) {
    return thisSerial_->available();
#endif
#ifdef ARDUINO_SAM_DUE
  } else if (flagUARTClass) {
    return thisUARTClass->available();
#elif defined(UART)
  } else if (flagUart) {
    return thisUart->available();
#endif
#ifndef SOME_SERIAL_NOT_SUPPORT_SOFTWARE_SERIAL
  } else {
    return thisSoftwareSerial->available();
#endif
  }
}

void SomeSerial::flush() {
  if (flagHardwareSerial) {
    thisHardwareSerial->flush();
#ifdef USBCON
  } else if (flagSerial_) {
    thisSerial_->flush();
#endif
#ifdef ARDUINO_SAM_DUE
  } else if (flagUARTClass) {
    thisUARTClass->flush();
#elif defined(UART)
  } else if (flagUart) {
    thisUart->flush();
#endif
#ifndef SOME_SERIAL_NOT_SUPPORT_SOFTWARE_SERIAL
  } else {
    thisSoftwareSerial->flush();
#endif
  }
}

void SomeSerial::setAllFlagsFalse() {
  flagHardwareSerial = false;
  flagSoftwareSerial = false;
  flagSerial_ = false;
  flagUARTClass = false;
  flagUart = false;
}
