#include "HardOrSoftSerial.h"

HardOrSoftSerial::HardOrSoftSerial(HardwareSerial* _hardSerial) {
  hardSerial = _hardSerial;
  isHard = true;
}

HardOrSoftSerial::HardOrSoftSerial(SoftwareSerial* _softSerial) {
  softSerial = _softSerial;
  isHard = false;
}

HardOrSoftSerial::HardOrSoftSerial(int rx, int tx) {
  softSerial = new SoftwareSerial(rx, tx);
  isHard = false;
}

void HardOrSoftSerial::begin(long speed) {
  if (isHard) {
    hardSerial->begin(speed);
  } else {
    softSerial->begin(speed);
  }
}

void HardOrSoftSerial::end() {
  if (isHard) {
    hardSerial->end();
  } else {
    softSerial->end();
  }
}

bool HardOrSoftSerial::isHardSerial() {
  return isHard;
}

bool HardOrSoftSerial::isSoftSerial() {
  return ! isHard;
}

int HardOrSoftSerial::peek() {
  if (isHard) {
    return hardSerial->peek();
  } else {
    return softSerial->peek();
  }
}

size_t HardOrSoftSerial::write(uint8_t byte) {
  if (isHard) {
    return hardSerial->write(byte);
  } else {
    return softSerial->write(byte);
  }
}

int HardOrSoftSerial::read() {
  if (isHard) {
    return hardSerial->read();
  } else {
    return softSerial->read();
  }
}

int HardOrSoftSerial::available() {
  if (isHard) {
    return hardSerial->available();
  } else {
    return softSerial->available();
  }
}

void HardOrSoftSerial::flush() {
  if (isHard) {
    return hardSerial->available();
  } else {
    return softSerial->available();
  }
}
