#ifndef MENU__TEXT_FIELD_MACROS_H
#define MENU__TEXT_FIELD_MACROS_H

#include "../_base/forEachMacros.h"
#include "../_base/helpersMacros.h"
#include "../_base/BaseChild.h"
#include "./TextField.h"


/////////////////////////////////////////////////////////////////////////////////////////////////
// MENU macros
// Will define TextField variables at PROGMEM
// Use as nested function at MENU macros
/////////////////////////////////////////////////////////////////////////////////////////////////
// Usage example:
//   MENU(..., TEXT_FIELD(message, "Text: '", messageValue, "'"))
//   ... - omited for example args for MENU macros (see MENU macros for details)
// Will define at PROGMEM:
//   char messageTextBefore[] = "Text: '";
//   char messageTextAfter[] = "'";
//   Menu::BaseChild* messageBaseData = ...;
//   Menu::TextFieldData messageTextFieldData = ...;
//   Menu::TextField messageTextField = ...;

#define VAR_NAME_FOR_LIST__TEXT_FIELD(id, ...) &id##TextField,
#define CHILD_MACRO__TEXT_FIELD(id, textBefore, value, textAfter)\
  const char id##TextBefore[] PROGMEM = textBefore;\
  const char id##TextAfter[] PROGMEM = textAfter;\
  \
  const PROGMEM Menu::BaseData id##BaseData = {\
    Menu::TYPE::TEXT_FIELD,\
    id##TextBefore\
  };\
  const PROGMEM Menu::TextFieldData id##TextFieldData = {\
    sizeof(value)/sizeof(char) - 1,\
    value,\
    id##TextAfter\
  };\
  Menu::TextField id##TextField(&id##BaseData, &id##TextFieldData);\

/////////////////////////////////////////////////////////////////////////////////////////////////

#endif;
