#ifndef SOME_SERIAL_H
#define SOME_SERIAL_H

#include <Arduino.h>
#include <SoftwareSerial.h>

class SomeSerial : public Stream {
  public:
  SomeSerial(HardwareSerial* _hardSerial);
  SomeSerial(SoftwareSerial* _softSerial);
  SomeSerial(int rx, int tx);

  HardwareSerial* hardSerial;
  SoftwareSerial* softSerial;

  void begin(long speed);
  void end();
  bool isHardSerial();
  bool isSoftSerial();

  virtual int peek();
  virtual size_t write(uint8_t byte);
  virtual int read();
  virtual int available();
  virtual void flush();

  using Print::write;

  private:
  bool isHard;
};

#endif
