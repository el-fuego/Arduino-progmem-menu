#include <Arduino-progmem-menu.h>
#include "outputs/serial/SerialOutput.h"
#include "inputs/analog-joystick/AnalogJoystick.h"


Menu::AnalogJoystickInput menuInput(A6, A7 /*, false, false */);
Menu::SerialOutput menuOutput;

int lighteningFrom = 124;
int lighteningTo = 546;
char text[] = "abc324";

void turnLedOn() {
  digitalWrite(LED_BUILTIN, HIGH);
}

MENU(lightening, "Lightening sett.", (Menu::MENU_STYLE::NAME_HIDDEN_FOR_CHILD_LIST | Menu::MENU_STYLE::HORIZONTAL_CHILD_LIST)
  ,NUMBER_FIELD(lighteningFromMenu, "from ", lighteningFrom, Menu::to3Digits, " m^2", 0, 1000, 10)
  ,NUMBER_FIELD(lighteningToMenu, "to ", lighteningTo, Menu::to3Digits, " m^2", 0, 1000, 1)
);

MENU(main, "Settings", (0 | Menu::MENU_STYLE::NAME_HIDDEN_FOR_CHILD_LIST)
  ,SUBMENU(lightening)
  ,TEXT_FIELD(testField, "Text Field '", text, "'")
  ,ACTION(turnLedOn, "Turn LED ON", turnLedOn)
);


void setup() {
  Serial.begin(19200);
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.println("Use joystick to open and navigate menu");
  Menu::controller->init(&mainMenu, &menuInput, &menuOutput);
}

void loop() {
  Menu::controller->update();
}
