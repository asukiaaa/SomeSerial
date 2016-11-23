# SomeSerial
An Arduino library to wrap multiple kind of serials.

# Useage
## Include

```c
#include "SomeSerial.h"

```

## Definition
### USB Serial or HardwareSerial

```c
SomeSerial someSerial(&Serial);
```

### SoftwareSerial

```c
SomeSerial someSerial(10, 11); // RX, TX
```

or

```c
SoftwareSerial mySoftwareSerial(10, 11); //RX, TX
SomeSerial someSerial(&mySoftwareSerial);
```

Be careful that not all pins support SofwareSerial.

Please check or test whether using pins for SoftwareSerial work or not.

[SoftwareSerial](https://www.arduino.cc/en/Reference/SoftwareSerial)

[ArduinoProducts](https://www.arduino.cc/en/Main/Products)

## Use like Serial

```c
void setup() {
  someSerial.begin(115200);
}

void loop() {
  someSerial.println("Hello world!");
  delay(1000);
}
```

## As HardwareSerial

```c
if (someSerial->isHardwareSerial()) {
  someSerial->println("It is HardwareSerial");
  someSerial->thisHardwareSerial->println("Direct print to HardwareSerial");

}
```

## As SoftwareSerial

```c
if (someSerial->isSoftwareSerial()) {
  someSerial->println("It is SoftwareSerial");
  someSerial->thisSoftwareSerial->println("Direct print to SoftwareSerial");
}
```

## As USBAPI Serial_

```c
if (someSerial->isSerial_()) {
  someSerial->println("It is USBAPI Serial_");
  someSerial->thisSerial_->println("Direct print to USBAPI Serial_");
}
```

If you want to use code for multiple platform including any board that does not support Serial_, call `thisSerial_` between `#ifdef __USB_SERIAL_AVAILABLE__` and `#endif`.

```c
#ifdef __USB_SERIAL_AVAILABLE__
  someSerial->thisSerial_->println("Direct print to USBAPI Serial_");
#endif
```

# References
- [HardwareSerial.h](https://github.com/arduino/Arduino/blob/master/hardware/arduino/avr/cores/arduino/HardwareSerial.h)
- [SoftwareSerial.h](https://github.com/arduino/Arduino/blob/master/hardware/arduino/avr/libraries/SoftwareSerial/src/SoftwareSerial.h)
- [USBAPI.h](https://github.com/arduino/Arduino/blob/2bfe164b9a5835e8cb6e194b928538a9093be333/hardware/arduino/avr/cores/arduino/USBAPI.h)
- [SoftwareSeiral/keywords.txt](https://github.com/arduino/Arduino/blob/master/hardware/arduino/avr/libraries/SoftwareSerial/keywords.txt)