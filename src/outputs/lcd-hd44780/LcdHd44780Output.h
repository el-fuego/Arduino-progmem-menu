#ifndef MENU__LCD_I2C_TEXT_OUTPUT_H
#define MENU__LCD_I2C_TEXT_OUTPUT_H

#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>
#include "../base.h"


//////////////////////////////////////////////////////
// MENU output for 16x2, 20x4 text screens
// Depends on https://github.com/duinoWitchery/hd44780
//////////////////////////////////////////////////////
namespace Menu {
  class LcdHd44780Output : public Output {
    private:
      hd44780_I2Cexp* driver;
      bool isEditing = false;
      unsigned char currentX = 0;
      unsigned char currentY = 0;
      unsigned char lastEditCharacterPositionX = 0;
      unsigned char lastEditCharacterPositionY = 0;

    public:
      LcdHd44780Output(hd44780_I2Cexp* _driver);
      void print(const char* str);
      void printEditMode(const char* str);
      void clear();
      void nextLine();
      void end();
  };
};

#endif
