#ifndef MENU__ANALOG_JOYSTICK_INPUT_H
#define MENU__ANALOG_JOYSTICK_INPUT_H

#include <inttypes.h>
#include "../base.h"
#include "../behaviours/4-buttons.h"
#include "../../menu-items/menu/Menu.h"
#include "../../menu-items/number-field/NumberField.h"
#include "../../menu-items/text-field/TextField.h"


////////////////////////////////////
// JOYSTICK NAVIGATION CONTROLLER
////////////////////////////////////
namespace Menu {

  class AnalogJoystickInput : public Input {
    private:
      uint8_t pinX;
      uint8_t pinY;
      unsigned long updatedAt;
      INPUT_ACTION previousAction = INPUT_ACTION::NONE;
      INPUT_ACTION readRawAction();
      INPUT_ACTION getAction();

    public:
      AnalogJoystickInput(uint8_t _pinX, uint8_t _pinY);
      void init();
      bool navigate(Menu* menu);
      bool navigate(NumberField* numberField);
      bool navigate(TextField* textField);
  };
};

#endif;
