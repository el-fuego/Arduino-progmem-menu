#ifndef MENU__SUBMENU_MACROS_H
#define MENU__SUBMENU_MACROS_H

#include "../_base/helpersMacros.h"
#include "../menu/Menu.h"


/////////////////////////////////////////////////////////////////////////////////////////////////
// SUBMENU macros
// Used as nested function at MENU macros
/////////////////////////////////////////////////////////////////////////////////////////////////
// Usage example:
//   MENU(mySubmenu, ...)
//   MENU(..., SUBMENU(mySubmenu))
//   ... - omited for example args for MENU macros (see MENU macros for details)

#define VAR_NAME_FOR_LIST__SUBMENU(id, ...) &id##Menu,
#define CHILD_MACRO__SUBMENU(id) CHILD_MACRO__BLANK()

/////////////////////////////////////////////////////////////////////////////////////////////////

#endif;
