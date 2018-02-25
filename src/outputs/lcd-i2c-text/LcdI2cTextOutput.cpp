#include <Arduino.h>
#include "./LcdI2cTextOutput.h"


namespace Menu {

  LcdI2cTextOutput::LcdI2cTextOutput(LiquidCrystal_I2C* _driver) : driver(_driver) {
    linesCount = 2;
  };

  void LcdI2cTextOutput::print(char* str) {
    driver->print(str);

    currentX += strlen(str);
  };

  void LcdI2cTextOutput::printEditMode(char* str) {
    print(str);

    lastEditCharacterPositionX = currentX - 1;
    lastEditCharacterPositionY = currentY;
    isEditing = true;
  };

  void LcdI2cTextOutput::clear() {
    currentX = 0;
    currentY = 0;
    isEditing = false;
    driver->clear();
    driver->setCursor(0, 0);
  };

  void LcdI2cTextOutput::end() {
    if (!isEditing) {
      driver->noBlink();
      return;
    }

    driver->setCursor(lastEditCharacterPositionX, lastEditCharacterPositionY);
    driver->blink();
  };

  void LcdI2cTextOutput::nextLine() {
    currentX = 0;
    currentY++;
    driver->setCursor(0, currentY);
  };
};

