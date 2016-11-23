#include "SomeSerial.h"

SomeSerial::SomeSerial(HardwareSerial* _hardSerial) {
  hardSerial = _hardSerial;
  setAllFlagsFalse();
  isHard = true;
}

SomeSerial::SomeSerial(SoftwareSerial* _softSerial) {
  softSerial = _softSerial;
  setAllFlagsFalse();
  isSoft = true;
}

SomeSerial::SomeSerial(int rx, int tx) {
  softSerial = new SoftwareSerial(rx, tx);
  setAllFlagsFalse();
  isSoft = true;
}

#ifdef __USB_SERIAL_AVAILABLE__
SomeSerial::SomeSerial(Serial_* _usbSerial) {
  usbSerial = _usbSerial;
  setAllFlagsFalse();
  isUsb = true;
}
#endif

void SomeSerial::begin(long speed) {
  if (isHard) {
    hardSerial->begin(speed);
#ifdef __USB_SERIAL_AVAILABLE__
  } else if (isUsb) {
    usbSerial->begin(speed);
#endif
  } else {
    softSerial->begin(speed);
  }
}

void SomeSerial::end() {
  if (isHard) {
    hardSerial->end();
#ifdef __USB_SERIAL_AVAILABLE__
  } else if (isUsb) {
    usbSerial->end();
#endif
  } else {
    softSerial->end();
  }
}

bool SomeSerial::isHardSerial() {
  return isHard;
}

bool SomeSerial::isSoftSerial() {
  return isSoft;
}

bool SomeSerial::isUsbSerial() {
  return isUsb;
}

int SomeSerial::peek() {
  if (isHard) {
    return hardSerial->peek();
#ifdef __USB_SERIAL_AVAILABLE__
  } else if (isUsb) {
    return usbSerial->peek();
#endif
  } else {
    return softSerial->peek();
  }
}

size_t SomeSerial::write(uint8_t byte) {
  if (isHard) {
    return hardSerial->write(byte);
#ifdef __USB_SERIAL_AVAILABLE__
  } else if (isUsb) {
    return usbSerial->write(byte);
#endif
  } else {
    return softSerial->write(byte);
  }
}

int SomeSerial::read() {
  if (isHard) {
    return hardSerial->read();
#ifdef __USB_SERIAL_AVAILABLE__
  } else if (isUsb) {
    return usbSerial->read();
#endif
  } else {
    return softSerial->read();
  }
}

int SomeSerial::available() {
  if (isHard) {
    return hardSerial->available();
#ifdef __USB_SERIAL_AVAILABLE__
  } else if (isUsb) {
    return usbSerial->available();
#endif
  } else {
    return softSerial->available();
  }
}

void SomeSerial::flush() {
  if (isHard) {
    return hardSerial->available();
#ifdef __USB_SERIAL_AVAILABLE__
  } else if (isUsb) {
    return usbSerial->available();
#endif
  } else {
    return softSerial->available();
  }
}

void SomeSerial::setAllFlagsFalse() {
  isHard = false;
  isSoft = false;
  isUsb = false;
}
