#ifndef MENU__ACTION_MACROS_H
#define MENU__ACTION_MACROS_H

#include "../_base/forEachMacros.h"
#include "../_base/helpersMacros.h"
#include "../_base/BaseChild.h"
#include "./Action.h"


/////////////////////////////////////////////////////////////////////////////////////////////////
// ACTION macros
// Will define Action variables at PROGMEM
// Use as nested function at MENU macros
/////////////////////////////////////////////////////////////////////////////////////////////////
// Usage example:
//   MENU(..., ACTION(save, "Save", callback))
//   ... - omited for example args for MENU macros (see MENU macros for details)
// Will define at PROGMEM:
//   char saveName[] = "Save";
//   Menu::BaseChild* saveBaseData = ...;
//   Menu::Action saveAction = ...;

#define VAR_NAME_FOR_LIST__ACTION(id, ...) &id##Action,
#define CHILD_MACRO__ACTION(id, name, onEnter)\
  const char id##Name[] PROGMEM = name;\
  \
  const PROGMEM Menu::BaseData id##BaseData = {\
    Menu::TYPE::ACTION,\
    id##Name\
  };\
  Menu::Action id##Action(&id##BaseData, &onEnter);\

/////////////////////////////////////////////////////////////////////////////////////////////////

#endif
