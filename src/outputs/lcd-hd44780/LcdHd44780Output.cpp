#include <Arduino.h>
#include "./LcdHd44780Output.h"


namespace Menu {

  LcdHd44780Output::LcdHd44780Output(hd44780_I2Cexp* _driver) : driver(_driver) {
    linesCount = 2;
  };

  void LcdHd44780Output::print(const char* str) {
    driver->print(str);

    currentX += strlen(str);
  };

  void LcdHd44780Output::printEditMode(const char* str) {
    print(str);

    lastEditCharacterPositionX = currentX - 1;
    lastEditCharacterPositionY = currentY;
    isEditing = true;
  };

  void LcdHd44780Output::clear() {
    currentX = 0;
    currentY = 0;
    isEditing = false;
    driver->clear();
    driver->setCursor(0, 0);
  };

  void LcdHd44780Output::end() {
    if (!isEditing) {
      driver->noBlink();
      return;
    }

    driver->setCursor(lastEditCharacterPositionX, lastEditCharacterPositionY);
    driver->blink();
  };

  void LcdHd44780Output::nextLine() {
    currentX = 0;
    currentY++;
    driver->setCursor(0, currentY);
  };
};

