#include "./SerialOutput.h"


namespace Menu {
  SerialOutput::SerialOutput() {};
  SerialOutput::SerialOutput(HardwareSerial *_serial) : serial(_serial) {};

  void SerialOutput::print(char* str) {
    serial->print(str);
  };

  void SerialOutput::printEditMode(char* str) {
    serial->print("*");
    serial->print(str);
    serial->print("*");
  };

  void SerialOutput::clear() {
    char i = 20;

    while (i--) {
      serial->println("");
    }
  };

  void SerialOutput::nextLine() {
    serial->println("");
  };
};

