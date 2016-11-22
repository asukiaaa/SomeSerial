#ifndef HARD_OR_SOFT_SERIAL_H
#define HARD_OR_SOFT_SERIAL_H

#include <Arduino.h>
#include <SoftwareSerial.h>

class HardOrSoftSerial : public Stream {
  public:
  HardOrSoftSerial(HardwareSerial* _hardSerial);
  HardOrSoftSerial(SoftwareSerial* _softSerial);
  HardOrSoftSerial(int rx, int tx);

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
