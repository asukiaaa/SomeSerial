#ifndef SOME_SERIAL_H
#define SOME_SERIAL_H

#include <Arduino.h>

#if defined(__arm__) || defined(ESP32) // arm boards and esp32 do not support SoftwareSerial
#define SOME_SERIAL_NOT_SUPPORT_SOFTWARE_SERIAL
#endif

#ifndef SOME_SERIAL_NOT_SUPPORT_SOFTWARE_SERIAL
#include <SoftwareSerial.h>
#endif

#ifdef USBCON
#ifdef __arm__
#include <USB/USBAPI.h>
#else
#include <USBAPI.h>
#endif
#endif

class SomeSerial : public Stream {
  public:
  SomeSerial(HardwareSerial* _thisHardwareSerial);
#ifndef SOME_SERIAL_NOT_SUPPORT_SOFTWARE_SERIAL
  SomeSerial(SoftwareSerial* _thisSoftwareSerial);
  SomeSerial(int rx, int tx);
#endif
#ifdef USBCON
  SomeSerial(Serial_* _thisSerial_);
#endif

  HardwareSerial* thisHardwareSerial;
#ifndef SOME_SERIAL_NOT_SUPPORT_SOFTWARE_SERIAL
  SoftwareSerial* thisSoftwareSerial;
#endif
#ifdef USBCON
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
  int flag;
};

#endif
