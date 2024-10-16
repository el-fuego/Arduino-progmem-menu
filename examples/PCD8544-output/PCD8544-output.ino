#include <Arduino-progmem-menu.h>
#include "outputs/lcd-pcd8544/LcdPcd8544Output.h"
#include "inputs/analog-joystick/AnalogJoystick.h"

// https://github.com/carlosefr/pcd8544
#include <PCD8544.h>


PCD8544 lcd(6, 5, 4, 2, 3);
Menu::AnalogJoystickInput menuInput(A6, A7);
Menu::LcdPcd8544Output menuOutput(&lcd);

#define MAX_TIME_VALUE 24*60 - 1 // 11:59 PM
int lighteningFrom = 05*60 + 30; // 5:30 AM
int lighteningTo = 18*60; // till 6:00 PM
char pin[] = "abc324";


MENU(lightening, "Lightening", 0
  ,NUMBER_FIELD(lighteningFromMenu, "from ", lighteningFrom, Menu::toTime, "", 0, MAX_TIME_VALUE, 10)
  ,NUMBER_FIELD(lighteningToMenu, "to ", lighteningTo, Menu::toTime, "", 0, MAX_TIME_VALUE, 10)
);

MENU(main, "Settings", 0
  ,SUBMENU(lightening)
  ,TEXT_FIELD(pinField, "Pin: '", pin, "'")
  ,BLANK()
);


void setup() {
  lcd.begin(84, 48);
  lcd.setContrast(63); // 127 max

  Menu::controller->init(&mainMenu, &menuInput, &menuOutput);
}

void loop() {
  Menu::controller->update();
}
