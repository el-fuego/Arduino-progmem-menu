#ifndef MENU__INPUT_BASE_H
#define MENU__INPUT_BASE_H

#include <inttypes.h>
#include "../menu-items/menu/Menu.h"
#include "../menu-items/number-field/NumberField.h"
#include "../menu-items/text-field/TextField.h"


namespace Menu {
  class Input {
    public:
      virtual bool navigate(Menu* menu);
      virtual bool navigate(NumberField* numberField);
      virtual bool navigate(TextField* textField);
  };
};

#endif
