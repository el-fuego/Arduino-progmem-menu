#ifndef MENU__ACTION_H
#define MENU__ACTION_H

#include "../_base/BaseChild.h"


namespace Menu {
  class Action : public BaseChild {
    public:
      void (*onEnter)();
      Action(BaseData* _baseData, void (*_onEnter)()) : BaseChild(_baseData), onEnter(_onEnter) {};

      void enter();

      void renderSelf();
  };
};

#endif;
