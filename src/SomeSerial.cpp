#include "SomeSerial.h"

SomeSerial::SomeSerial(HardwareSerial* _thisHardwareSerial) {
  thisHardwareSerial = _thisHardwareSerial;
  setAllFlagsFalse();
  flagHardwareSerial = true;
}

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

#ifdef __USB_SERIAL_AVAILABLE__
SomeSerial::SomeSerial(Serial_* _thisSerial_) {
  thisSerial_ = _thisSerial_;
  setAllFlagsFalse();
  flagSerial_ = true;
}
#endif

void SomeSerial::begin(long speed) {
  if (flagHardwareSerial) {
    thisHardwareSerial->begin(speed);
#ifdef __USB_SERIAL_AVAILABLE__
  } else if (flagSerial_) {
    thisSerial_->begin(speed);
#endif
  } else {
    thisSoftwareSerial->begin(speed);
  }
}

void SomeSerial::end() {
  if (flagHardwareSerial) {
    thisHardwareSerial->end();
#ifdef __USB_SERIAL_AVAILABLE__
  } else if (flagSerial_) {
    thisSerial_->end();
#endif
  } else {
    thisSoftwareSerial->end();
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

int SomeSerial::peek() {
  if (flagHardwareSerial) {
    return thisHardwareSerial->peek();
#ifdef __USB_SERIAL_AVAILABLE__
  } else if (flagSerial_) {
    return thisSerial_->peek();
#endif
  } else {
    return thisSoftwareSerial->peek();
  }
}

size_t SomeSerial::write(uint8_t byte) {
  if (flagHardwareSerial) {
    return thisHardwareSerial->write(byte);
#ifdef __USB_SERIAL_AVAILABLE__
  } else if (flagSerial_) {
    return thisSerial_->write(byte);
#endif
  } else {
    return thisSoftwareSerial->write(byte);
  }
}

int SomeSerial::read() {
  if (flagHardwareSerial) {
    return thisHardwareSerial->read();
#ifdef __USB_SERIAL_AVAILABLE__
  } else if (flagSerial_) {
    return thisSerial_->read();
#endif
  } else {
    return thisSoftwareSerial->read();
  }
}

int SomeSerial::available() {
  if (flagHardwareSerial) {
    return thisHardwareSerial->available();
#ifdef __USB_SERIAL_AVAILABLE__
  } else if (flagSerial_) {
    return thisSerial_->available();
#endif
  } else {
    return thisSoftwareSerial->available();
  }
}

void SomeSerial::flush() {
  if (flagHardwareSerial) {
    thisHardwareSerial->flush();
#ifdef __USB_SERIAL_AVAILABLE__
  } else if (flagSerial_) {
    thisSerial_->flush();
#endif
  } else {
    thisSoftwareSerial->flush();
  }
}

void SomeSerial::setAllFlagsFalse() {
  flagHardwareSerial = false;
  flagSoftwareSerial = false;
  flagSerial_ = false;
}
