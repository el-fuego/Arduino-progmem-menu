#ifndef MENU__LCD_PCD8544_OUTPUT_H
#define MENU__LCD_PCD8544_OUTPUT_H

#include <PCD8544.h>
#include "../base.h"


//////////////////////////////////////////////////////
// MENU output for NOKIA 5110 (3310) screens
// Depends on https://github.com/carlosefr/pcd8544
//////////////////////////////////////////////////////
namespace Menu {
  class LcdPcd8544Output : public Output {
    private:
      PCD8544* driver;
      unsigned char currentY = 0;

    public:
      LcdPcd8544Output(PCD8544* _driver);
      void print(char* str);
      void printEditMode(char* str);
      void clear();
      void nextLine();
  };
};

#endif;
