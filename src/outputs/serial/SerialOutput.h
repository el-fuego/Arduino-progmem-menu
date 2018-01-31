#ifndef MENU__SERIAL_OUTPUT_H
#define MENU__SERIAL_OUTPUT_H

#include <Arduino.h>
#include "../base.h"


namespace Menu {
  class SerialOutput : public Output {
    private:
      HardwareSerial *serial = &Serial;

    public:
      SerialOutput();
      SerialOutput(HardwareSerial *serial);
      void print(char* str);
      void printEditMode(char* str);
      void clear();
      void nextLine();
  };
};

#endif;
