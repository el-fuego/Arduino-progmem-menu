#include <Arduino-progmem-menu.h>
#include "outputs/lcd-i2c-text/LcdI2cTextOutput.h"
#include "inputs/analog-joystick/AnalogJoystick.h"

// https://github.com/marcoschwartz/LiquidCrystal_I2C
#include <LiquidCrystal_I2C.h>

//////////////////////////////////////////////
//             !DEPRECATED!
//   Latest library version need to be
// installed manually, not through the IDE
//          Use hd44780 instead
//////////////////////////////////////////////

LiquidCrystal_I2C lcd(0x3F, 16, 2); // or lcd(0x27, 16, 2);
Menu::AnalogJoystickInput menuInput(A6, A7 /*, false, false */);
Menu::LcdI2cTextOutput menuOutput(&lcd);

#define MAX_TIME_VALUE 24*60 - 1 // 11:59 PM
int lighteningFrom = 05*60 + 30; // 5:30 AM
int lighteningTo = 18*60; // till 6:00 PM
char text[] = "abc324";


MENU(lightening, "Lightening", 0
  ,NUMBER_FIELD(lighteningFromMenu, "from ", lighteningFrom, Menu::toTime, "", 0, MAX_TIME_VALUE, 10)
  ,NUMBER_FIELD(lighteningToMenu, "to ", lighteningTo, Menu::toTime, "", 0, MAX_TIME_VALUE, 10)
);

MENU(main, "Settings", 0
  ,SUBMENU(lightening)
  ,TEXT_FIELD(testField, "Mess '", text, "'")
  ,BLANK()
);


void setup() {
  lcd.init();
  lcd.backlight();

  Menu::controller->init(&mainMenu, &menuInput, &menuOutput);
}

void loop() {
  Menu::controller->update();
}
