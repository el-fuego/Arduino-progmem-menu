#include <avr/pgmspace.h>
#include "./TextField.h"
#include "../_base/helpers.h"
#include "../../Controller.h"

#include <Arduino.h>


namespace Menu {

  //////////////////////////////////////////
  // DATA GETTERS

  /**
  * Copy of baseData to memory and return pointer to it
  */
  TextFieldData* TextField::getData() {
    TextFieldData temp;
    memcpy_P((void*)&temp, data, sizeof(temp));
    return &temp;
  };

  uint8_t TextField::getValueLength() {
    return getData()->valueLength;
  };

  char* TextField::getTextAfter() {
    return readProgmemSrt(getData()->textAfter);
  };

  char* TextField::getValue() {
    return getData()->value;
  };


  //////////////////////////////////////////
  // BEHAVIOUR

  void TextField::selectSymbolAtIndex(uint8_t index) {
    selectedSymbolIndex = index;
  };

  void TextField::selectPreviousSymbol() {
    if (selectedSymbolIndex == 0) {
      return;
    }

    selectedSymbolIndex--;
  };

  void TextField::selectPreviousSymbolOrExit() {
    if (selectedSymbolIndex == 0) {
      return exit();
    }

    selectedSymbolIndex--;
  };

  void TextField::selectNextSymbol() {
    if (selectedSymbolIndex == getValueLength() - 1) {
      return;
    }

    selectedSymbolIndex++;
  };

  void TextField::decrementSymbol() {
    (*(getValue() + selectedSymbolIndex)) --;
  };

  void TextField::incrementSymbol() {
    (*(getValue() + selectedSymbolIndex)) ++;
  };

  void TextField::exit() {
    BaseChild::exit();
    selectedSymbolIndex = 0;
  };


  //////////////////////////////////////////
  // RENDER
  // Prepare text to output

  /**
  * Render as item for parent child list
  */
  void TextField::renderSelf() {

    controller->output->print(getName());

    uint8_t symbolIndex;
    uint8_t symbolsCount = getValueLength();
    char* value = getValue();
    char symbol[] = " ";

    for (symbolIndex = 0; symbolIndex < symbolsCount; symbolIndex++) {
      *symbol = *(value + symbolIndex);
      if (isActive && symbolIndex == selectedSymbolIndex) {
        controller->output->printEditMode(symbol);
      } else {
        controller->output->print(symbol);
      }
    }

    controller->output->print(getTextAfter());
  };
};