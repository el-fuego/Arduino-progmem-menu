#ifndef MENU__4_BUTTONS_BEHAVIOUR_H
#define MENU__4_BUTTONS_BEHAVIOUR_H

#include "../../menu-items/menu/Menu.h"
#include "../../menu-items/number-field/NumberField.h"
#include "../../menu-items/text-field/TextField.h"


////////////////////////////////////
// 4 ACTIONS NAVIGATION CONTROLLER
// Use for 4 buttons or joystick
////////////////////////////////////
namespace Menu {
  enum INPUT_ACTION { NONE, LEFT, RIGHT, UP, DOWN };

  bool navigateChild(INPUT_ACTION action, Menu* menu);

  /**
  * Navigate inside Menu
  * Return {bool} has updates
  */
  inline bool navigateWithFourButtons(INPUT_ACTION action, Menu* menu) {
    if (!menu->isActive && action != INPUT_ACTION::NONE) {
      menu->enter();
      return true;
    }

    if (menu->hasStyle(MENU_STYLE::HORIZONTAL_CHILD_LIST)) {
      switch(action) {
        case INPUT_ACTION::LEFT:
          menu->selectPreviousChildOrExit();
          return true;

        case INPUT_ACTION::RIGHT:
          menu->selectNextChild();
          return true;

        case INPUT_ACTION::UP:
          menu->enterSelectedChild();
          navigateChild(action, menu);
          return true;

        case INPUT_ACTION::DOWN:
          menu->enterSelectedChild();
          navigateChild(action, menu);
          return true;
      }

      return false;
    }

    switch(action) {
      case INPUT_ACTION::LEFT:
        menu->exit();
        return true;

      case INPUT_ACTION::RIGHT:
        menu->enterSelectedChild();
        return true;

      case INPUT_ACTION::UP:
        menu->selectPreviousChild();
        return true;

      case INPUT_ACTION::DOWN:
        menu->selectNextChild();
        return true;
    }

    return false;
  };

  /**
  * Navigate inside NumberField
  * Return {bool} has updates
  */
  inline bool navigateWithFourButtons(INPUT_ACTION action, NumberField* numberField) {
    switch(action) {
      case INPUT_ACTION::LEFT:
        numberField->exit();
        // TODO navigateParent if parent->hasStyle(MENU_STYLE::HORIZONTAL_CHILD_LIST)
        return true;

      case INPUT_ACTION::RIGHT:
        // TODO navigateParent if parent->hasStyle(MENU_STYLE::HORIZONTAL_CHILD_LIST)
        numberField->exit();
        return true;

      case INPUT_ACTION::UP:
        numberField->incrementValue();
        return true;

      case INPUT_ACTION::DOWN:
        numberField->decrementValue();
        return true;
    }

    return false;
  };

  /**
  * Navigate inside TextField
  * Return {bool} has updates
  */
  inline bool navigateWithFourButtons(INPUT_ACTION action, TextField* textField) {
    switch(action) {
      case INPUT_ACTION::LEFT:
        textField->selectPreviousSymbolOrExit();
        return true;

      case INPUT_ACTION::RIGHT:
        textField->selectNextSymbol();
        return true;

      case INPUT_ACTION::UP:
        textField->incrementSymbol();
        return true;

      case INPUT_ACTION::DOWN:
        textField->decrementSymbol();
        return true;
    }

    return false;
  };


  inline bool navigateChild(INPUT_ACTION action, Menu* menu) {
    BaseChild* child = menu->getSelectedChildAsBase();
    uint8_t type = child->getType();

    switch(type) {
      case TYPE::SUBMENU:
        return navigateWithFourButtons(action, (Menu*)child);
      case TYPE::NUMBER_FIELD:
        return navigateWithFourButtons(action, (NumberField*)child);
      case TYPE::TEXT_FIELD:
        return navigateWithFourButtons(action, (TextField*)child);
    }
  }
};

#endif
