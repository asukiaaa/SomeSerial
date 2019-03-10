#ifndef SOME_SERIAL_H
#define SOME_SERIAL_H

#include <Arduino.h>
#ifndef ARDUINO_SAM_DUE // arduino due does not support SoftwareSerial
#include <SoftwareSerial.h>
#endif

#ifdef USBCON
#define __USB_SERIAL_AVAILABLE__
#ifdef __arm__
#include <USB/USBAPI.h>
#else
#include <USBAPI.h>
#endif
#endif

#ifdef ARDUINO_SAM_DUE
#include <UARTClass.h>
#elif defined(UART)
#include <Uart.h>
#endif

class SomeSerial : public Stream {
  public:
  SomeSerial(HardwareSerial* _thisHardwareSerial);
#ifndef ARDUINO_SAM_DUE
  SomeSerial(SoftwareSerial* _thisSoftwareSerial);
  SomeSerial(int rx, int tx);
#endif
#ifdef USBCON
  SomeSerial(Serial_* _thisSerial_);
#endif
#ifdef ARDUINO_SAM_DUE
  SomeSerial(UARTClass* _thisUARTClass);
#elif defined(UART)
  SomeSerial(Uart* _thisUart);
#endif

  HardwareSerial* thisHardwareSerial;
#ifndef ARDUINO_SAM_DUE
  SoftwareSerial* thisSoftwareSerial;
#endif
#ifdef USBCON
  Serial_* thisSerial_;
#endif
#ifdef ARDUINO_SAM_DUE
  UARTClass* thisUARTClass;
#elif defined(UART)
  Uart* thisUart;
#endif

  void begin(long speed);
  void end();
  bool isHardwareSerial();
  bool isSoftwareSerial();
  bool isSerial_();
  bool isUARTClass();
  bool isUart();

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
  bool flagUARTClass;
  bool flagUart;
};

#endif
