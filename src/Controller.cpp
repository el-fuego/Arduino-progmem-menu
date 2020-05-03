#include "./Controller.h"
#include "./menu-items/number-field/NumberField.h"
#include "./menu-items/text-field/TextField.h"


namespace Menu {
  Controller::Controller(){};

  void Controller::init(Menu* _topLevelMenu, Input* _input, Output* _output) {
    topLevelMenu = _topLevelMenu;
    input = _input;
    output = _output;
  };

  bool Controller::updateMenuItemState(BaseChild* menuItem) {
    uint8_t type = menuItem->getType();

    switch(type) {
      case TYPE::SUBMENU:
        return input->navigate((Menu*)menuItem);
      case TYPE::NUMBER_FIELD:
        return input->navigate((NumberField*)menuItem);
      case TYPE::TEXT_FIELD:
        return input->navigate((TextField*)menuItem);
    }
  }

  Menu* Controller::getMostDeepActiveOrTopMenu() {
    Menu* lastSubmenu = topLevelMenu;
    BaseChild* child = (BaseChild*)topLevelMenu;

    while (child->isActive) {
      if (child->getType() != TYPE::SUBMENU) {
        return lastSubmenu;
      }
      lastSubmenu = (Menu*)child;
      child = lastSubmenu->getSelectedChildAsBase();
    }

    return lastSubmenu;
  };

  void Controller::update() {
    // get current active menu
    Menu* activeMenu = getMostDeepActiveOrTopMenu();
    // get current active child (menu, field, action)
    BaseChild* activeChild = activeMenu->getSelectedChildAsBase();
    if (!activeChild->isActive) {
      activeChild = (BaseChild*)activeMenu;
    }

    // navigate by provided input method
    bool hasUpdates = updateMenuItemState(activeChild);
    if (!hasUpdates) {
      return;
    }

    // clean-up on exit main menu
    if (!topLevelMenu->isActive) {
      output->clear();
      return;
    }

    // update provided output method
    activeMenu = getMostDeepActiveOrTopMenu();
    activeMenu->renderScreen();
  };


  extern Controller* controller = new Controller();
};

