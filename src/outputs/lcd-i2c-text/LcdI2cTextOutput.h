#ifndef MENU__LCD_I2C_TEXT_OUTPUT_H
#define MENU__LCD_I2C_TEXT_OUTPUT_H

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "../base.h"


//////////////////////////////////////////////////////
// MENU output for 16x2, 20x4 text screens
// Depends on https://github.com/marcoschwartz/LiquidCrystal_I2C
//////////////////////////////////////////////////////
namespace Menu {
  class LcdI2cTextOutput : public Output {
    private:
      LiquidCrystal_I2C* driver;
      bool isEditing = false;
      unsigned char currentX = 0;
      unsigned char currentY = 0;
      unsigned char lastEditCharacterPositionX = 0;
      unsigned char lastEditCharacterPositionY = 0;

    public:
      LcdI2cTextOutput(LiquidCrystal_I2C* _driver);
      void print(char* str);
      void printEditMode(char* str);
      void clear();
      void nextLine();
      void end();
  };
};

#endif;
