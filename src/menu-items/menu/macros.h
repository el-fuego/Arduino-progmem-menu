#ifndef MENU__MENU_MACROS_H
#define MENU__MENU_MACROS_H

#include "../_base/forEachMacros.h"
#include "../_base/helpersMacros.h"
#include "../_base/BaseChild.h"
#include "./Menu.h"


/////////////////////////////////////////////////////////////////////////////////////////////////
// MENU macros
// Will define menu variables at PROGMEM
// Use with nested macros functions (SUBMENU, NUMBER_FIELD, ACTION...)
// For singe child, pass BLANK() as second macros
/////////////////////////////////////////////////////////////////////////////////////////////////
// Usage example:
//   MENU(myMenu, "Cool Menu Name", Menu::MENU_STYLE::NAME_HIDDEN_FOR_CHILD_LIST | Menu::MENU_STYLE::HORIZONTAL_CHILD_LIST, NUMBER_FIELD(...), SUBMENU(...))
//   ... - omited for example args for other macros (see specific macros for details)
//   see all Menu::MENU_STYLE at Menu.h
// Will define at PROGMEM:
//   nested macros list data (see specific macros for details)
//   char myMenuName[] = "Cool name";
//   Menu::BaseChild* myMenuBaseData = ...;
//   Menu::MenuData myMenuMenuData = ...;
//   Menu::Menu myMenuMenu = ...;

#define MENU(id, name, style, args...)\
  FOR_EACH(CALL_CHILD_MACRO, args)\
  const char id##Name[] PROGMEM = name;\
  Menu::BaseChild* const id##ChildList[] PROGMEM = {\
    FOR_EACH(GET_VAR_NAME_FOR_LIST, args)\
  };\
  \
  const PROGMEM Menu::BaseData id##BaseData = {\
    Menu::TYPE::SUBMENU,\
    id##Name\
  };\
  const PROGMEM Menu::MenuData id##MenuData = {\
    sizeof(id##ChildList)/sizeof(Menu::BaseChild*),\
    id##ChildList,\
    style\
  };\
  Menu::Menu id##Menu(&id##BaseData, &id##MenuData);\

/////////////////////////////////////////////////////////////////////////////////////////////////


#endif
