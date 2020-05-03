#ifndef MENU__SERIAL_OUTPUT_H
#define MENU__SERIAL_OUTPUT_H

#include <Arduino.h>
#include "../base.h"

#ifndef USBSerial
#define SerialType HardwareSerial
#else
#define SerialType USBSerial
#endif


namespace Menu {
  class SerialOutput : public Output {
    private:
      SerialType *serial = &Serial;

    public:
      SerialOutput();
      SerialOutput(SerialType *serial);
      void print(const char* str);
      void printEditMode(const char* str);
      void clear();
      void nextLine();
      inline void end() {};
  };
};

#endif
