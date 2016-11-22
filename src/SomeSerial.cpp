#include "SomeSerial.h"

SomeSerial::SomeSerial(HardwareSerial* _hardSerial) {
  hardSerial = _hardSerial;
  isHard = true;
}

SomeSerial::SomeSerial(SoftwareSerial* _softSerial) {
  softSerial = _softSerial;
  isHard = false;
}

SomeSerial::SomeSerial(int rx, int tx) {
  softSerial = new SoftwareSerial(rx, tx);
  isHard = false;
}

void SomeSerial::begin(long speed) {
  if (isHard) {
    hardSerial->begin(speed);
  } else {
    softSerial->begin(speed);
  }
}

void SomeSerial::end() {
  if (isHard) {
    hardSerial->end();
  } else {
    softSerial->end();
  }
}

bool SomeSerial::isHardSerial() {
  return isHard;
}

bool SomeSerial::isSoftSerial() {
  return ! isHard;
}

int SomeSerial::peek() {
  if (isHard) {
    return hardSerial->peek();
  } else {
    return softSerial->peek();
  }
}

size_t SomeSerial::write(uint8_t byte) {
  if (isHard) {
    return hardSerial->write(byte);
  } else {
    return softSerial->write(byte);
  }
}

int SomeSerial::read() {
  if (isHard) {
    return hardSerial->read();
  } else {
    return softSerial->read();
  }
}

int SomeSerial::available() {
  if (isHard) {
    return hardSerial->available();
  } else {
    return softSerial->available();
  }
}

void SomeSerial::flush() {
  if (isHard) {
    return hardSerial->available();
  } else {
    return softSerial->available();
  }
}
