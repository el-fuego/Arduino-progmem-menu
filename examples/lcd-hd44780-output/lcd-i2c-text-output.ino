#include <Wire.h>
#include <Arduino-progmem-menu.h>
#include "outputs/lcd-hd44780/LcdHd44780Output.h"
#include "inputs/analog-joystick/AnalogJoystick.h"

// https://github.com/duinoWitchery/hd44780
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>

hd44780_I2Cexp lcd lcd(0x3F); // or lcd(0x27);
Menu::AnalogJoystickInput menuInput(A6, A7 /*, false, false */);
Menu::LcdHd44780Output menuOutput(&lcd);

#define MAX_TIME_VALUE 24*60 - 1 // 11:59 PM
int lighteningFrom = 05*60 + 30; // 5:30 AM
int lighteningTo = 18*60; // till 6:00 PM
char text[] = "abc324";


MENU(lightening, "Lightening", 0
  ,NUMBER_FIELD(lighteningFromMenu, "from ", lighteningFrom, Menu::toTime, "", 0, MAX_TIME_VALUE, 10)
  ,NUMBER_FIELD(lighteningToMenu, "to ", lighteningTo, Menu::toTime, "", 0, MAX_TIME_VALUE, 10)
);

MENU(test, "Settings", 0
  ,SUBMENU(lightening)
  ,TEXT_FIELD(testField, "Mess '", text, "'")
  ,BLANK()
);


void setup() {
  lcd.init();
  lcd.backlight();

  Menu::controller->init(&testMenu, &menuInput, &menuOutput);
}

void loop() {
  Menu::controller->update();
}