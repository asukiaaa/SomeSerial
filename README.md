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

## Specific use by the Serial type

```c
if (someSerial.isHardSerial()) {
  someSerial->hardSerial->print("I am HardwareSerial");
else if (someSerial.isUsbSerial()) {
#ifdef __USB_SERIAL_AVAILABLE__
  someSerial->usbSerial->println("I am USBAPI Serial_");
#endif
else if (someSerial.isSoftSerial()) {
  someSerial->softSerial->println("I am SoftwareSerial");
}
```

# References
- [HardwareSerial.h](https://github.com/arduino/Arduino/blob/master/hardware/arduino/avr/cores/arduino/HardwareSerial.h)
- [SoftwareSerial.h](https://github.com/arduino/Arduino/blob/master/hardware/arduino/avr/libraries/SoftwareSerial/src/SoftwareSerial.h)
- [USBAPI.h](https://github.com/arduino/Arduino/blob/2bfe164b9a5835e8cb6e194b928538a9093be333/hardware/arduino/avr/cores/arduino/USBAPI.h)
