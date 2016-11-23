#ifndef SOME_SERIAL_H
#define SOME_SERIAL_H

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <USBAPI.h>

#ifdef USBCON
#define __USB_SERIAL_AVAILABLE__
#endif

class SomeSerial : public Stream {
  public:
  SomeSerial(HardwareSerial* _thisHardwareSerial);
  SomeSerial(SoftwareSerial* _thisSoftwareSerial);
  SomeSerial(int rx, int tx);
#ifdef __USB_SERIAL_AVAILABLE__
  SomeSerial(Serial_* _thisSerial_);
#endif

  HardwareSerial* thisHardwareSerial;
  SoftwareSerial* thisSoftwareSerial;
#ifdef __USB_SERIAL_AVAILABLE__
  Serial_* thisSerial_;
#endif

  void begin(long speed);
  void end();
  bool isHardwareSerial();
  bool isSoftwareSerial();
  bool isSerial_();

  virtual int peek();
  virtual size_t write(uint8_t byte);
  virtual int read();
  virtual int available();
  virtual void flush();

  using Print::write;

  private:
  void setAllFlagsFalse();
  bool flagHardwareSerial;
  bool flagSoftwareSerial;
  bool flagSerial_;
};

#endif
