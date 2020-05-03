#ifndef MENU__ACTION_H
#define MENU__ACTION_H

#include <Arduino.h>

#include "../_base/BaseChild.h"


namespace Menu {
  class Action : public BaseChild {
    public:
      void (*onEnter)() = 0;
      Action(BaseData* _baseData, void (*_onEnter)()) : BaseChild(_baseData), onEnter(_onEnter) {};

      void enter();

      void renderSelf();
  };
};

#endif
