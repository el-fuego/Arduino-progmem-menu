#include <Arduino.h>
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
    void* tempTextFieldData = malloc(sizeof(TextFieldData));
    memcpy_P(tempTextFieldData, data, sizeof(TextFieldData));
    return (TextFieldData*)tempTextFieldData;
  };

  const uint8_t TextField::getValueLength() {
    TextFieldData* data = getData();
    uint8_t valueLength = data->valueLength;

    free(data);
    return valueLength;
  };

  const char* TextField::getTextAfter() {
    TextFieldData* data = getData();
    char* textAfter = data->textAfter;

    free(data);
    return readProgmemSrt(textAfter);
  };

  char* TextField::getValue() {
    TextFieldData* data = getData();
    char* value = data->value;

    free(data);
    return value;
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
    const char* name = getName();
    controller->output->print(name);
    free(name);

    uint8_t symbolIndex;
    const uint8_t symbolsCount = getValueLength();
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
    free(value);

    char* textAfter = getTextAfter();
    controller->output->print(textAfter);
    free(textAfter);
  };
};