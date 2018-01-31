#include <Arduino.h>
#include "./LcdPcd8544Output.h"


namespace Menu {

  LcdPcd8544Output::LcdPcd8544Output(PCD8544* _driver) : driver(_driver) {
    linesCount = 6;
  };

  void LcdPcd8544Output::print(char* str) {
    driver->print(str);
  };

  void LcdPcd8544Output::printEditMode(char* str) {
    driver->setInverseOutput(true);
    print(str);
    driver->setInverseOutput(false);
  };

  void LcdPcd8544Output::clear() {
    currentY = 0;
    driver->clear();
    driver->setCursor(0, 0);
  };

  void LcdPcd8544Output::nextLine() {
    currentY++;
    driver->setCursor(0, currentY);
  };
};

