#ifndef MENU__NUMBER_FIELD_MACROS_H
#define MENU__NUMBER_FIELD_MACROS_H

#include "../_base/forEachMacros.h"
#include "../_base/helpersMacros.h"
#include "../_base/BaseChild.h"
#include "./NumberField.h"


/////////////////////////////////////////////////////////////////////////////////////////////////
// MENU macros
// Will define NumberField variables at PROGMEM
// Use as nested function at MENU macros
/////////////////////////////////////////////////////////////////////////////////////////////////
// Usage example:
//   MENU(..., NUMBER_FIELD(distance, "Distance ", distanceValue, toNumber, " m.", 0, 50, 1))
//   ... - omited for example args for MENU macros (see MENU macros for details)
// Will define at PROGMEM:
//   char distanceTextBefore[] = "Distance ";
//   char distanceTextAfter[] = " m.";
//   Menu::BaseChild* distanceBaseData = ...;
//   Menu::NumberFieldData distanceNumberFieldData = ...;
//   Menu::NumberField distanceNumberField = ...;

#define VAR_NAME_FOR_LIST__NUMBER_FIELD(id, ...) &id##NumberField,
#define CHILD_MACRO__NUMBER_FIELD(id, textBefore, value, formatValue, textAfter, minValue, maxValue, valueStep)\
  const char id##TextBefore[] PROGMEM = textBefore;\
  const char id##TextAfter[] PROGMEM = textAfter;\
  \
  const PROGMEM Menu::BaseData id##BaseData = {\
    Menu::TYPE::NUMBER_FIELD,\
    id##TextBefore\
  };\
  const PROGMEM Menu::NumberFieldData id##NumberFieldData = {\
    &value,\
    &formatValue,\
    id##TextAfter,\
    minValue,\
    maxValue,\
    valueStep\
  };\
  Menu::NumberField id##NumberField(&id##BaseData, &id##NumberFieldData);\

/////////////////////////////////////////////////////////////////////////////////////////////////

#endif
