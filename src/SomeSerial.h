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
  SomeSerial(HardwareSerial* _hardSerial);
  SomeSerial(SoftwareSerial* _softSerial);
  SomeSerial(int rx, int tx);
#ifdef __USB_SERIAL_AVAILABLE__
  SomeSerial(Serial_* _usbSerial);
#endif

  HardwareSerial* hardSerial;
  SoftwareSerial* softSerial;
#ifdef __USB_SERIAL_AVAILABLE__
  Serial_* usbSerial;
#endif

  void begin(long speed);
  void end();
  bool isHardSerial();
  bool isSoftSerial();
  bool isUsbSerial();

  virtual int peek();
  virtual size_t write(uint8_t byte);
  virtual int read();
  virtual int available();
  virtual void flush();

  using Print::write;

  private:
  bool isHard;
  bool isSoft;
  bool isUsb;
};

#endif
