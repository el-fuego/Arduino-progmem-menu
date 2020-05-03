#ifndef MENU__CONTROLLER_H
#define MENU__CONTROLLER_H

#include "./outputs/base.h"
#include "./inputs/base.h"
#include "./menu-items/menu/Menu.h"


namespace Menu {
  class Controller {
    private:
      Menu* topLevelMenu;
      Input* input;
      bool updateMenuItemState(BaseChild* menuItem);
      Menu* getMostDeepActiveOrTopMenu();

    public:
      Controller();
      Output* output;
      void init(Menu* _topLevelMenu, Input* _input, Output* _output);
      void update();
  };

  extern Controller* controller;
};

#endif
