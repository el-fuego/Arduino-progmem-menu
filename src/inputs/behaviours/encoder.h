#ifndef MENU__3_BUTTONS_BEHAVIOUR_H
#define MENU__3_BUTTONS_BEHAVIOUR_H

#include "../../menu-items/menu/Menu.h"
#include "../../menu-items/number-field/NumberField.h"
#include "../../menu-items/text-field/TextField.h"


////////////////////////////////////
// 3 ACTIONS NAVIGATION CONTROLLER
// Use it for encoder with button
////////////////////////////////////
namespace Menu {
  enum INPUT_ACTION { NONE, CLOCKWISE, ANTICLOCKWISE, SELECT };
  bool isSymbolEdit = false;

  /**
  * Navigate inside Menu
  * Return {bool} has updates
  */
  inline bool navigate(INPUT_ACTION action, Menu* menu) {
    if (!menu->isActive && action != INPUT_ACTION::NONE) {
      menu->enter();
      return true;
    }

    switch(action) {
      case INPUT_ACTION::CLOCKWISE:
        menu->selectPreviousChild();
        return true;

      case INPUT_ACTION::ANTICLOCKWISE:
        menu->selectNextChild();
        return true;

      case INPUT_ACTION::SELECT:
        menu->enterSelectedChild();
        return true;
    }

    return false;
  };

  /**
  * Navigate inside NumberField
  * Return {bool} has updates
  */
  inline bool navigate(INPUT_ACTION action, NumberField* numberField) {
    switch(action) {
      case INPUT_ACTION::CLOCKWISE:
        numberField->incrementValue();
        return true;

      case INPUT_ACTION::ANTICLOCKWISE:
        numberField->decrementValue();
        return true;

      case INPUT_ACTION::SELECT:
        numberField->exit();
        return true;
    }

    return false;
  };

  /**
  * Navigate inside TextField
  * Return {bool} has updates
  */
  inline bool navigate(INPUT_ACTION action, TextField* textField) {
    switch(action) {

      case INPUT_ACTION::CLOCKWISE:
        if (isSymbolEdit) {
          textField->incrementSymbol();
          return true;
        }
        textField->selectPreviousSymbolOrExit();
        return true;

      case INPUT_ACTION::ANTICLOCKWISE:
        if (isSymbolEdit) {
          textField->decrementSymbol();
          return true;
        }
        textField->selectPreviousSymbolOrExit();
        return true;

      case INPUT_ACTION::SELECT:
        if (isSymbolEdit) {
          isSymbolEdit = false;
        }
        textField->exit();
        return true;
    }

    return false;
  };
};

#endif
