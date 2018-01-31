#ifndef MENU__TEXT_FIELD_H
#define MENU__TEXT_FIELD_H

#include <inttypes.h>
#include "../_base/BaseChild.h"

// TODO add available symbols support
namespace Menu {

  struct TextFieldData {
    uint8_t valueLength;
    char* value; // pointer to RAM
    char* textAfter; // pointer to PROGMEM
  };

  class TextField : public BaseChild {
    private:
      TextFieldData *data; // pointer to PROGMEM
      TextFieldData* getData();

    public:
      TextField(BaseData* _baseData, TextFieldData* _data) : BaseChild(_baseData), data(_data) {};

      uint8_t selectedSymbolIndex = 0;

      uint8_t getValueLength();
      char* getTextAfter();
      char* getValue();

      void selectSymbolAtIndex(uint8_t index);
      void selectPreviousSymbolOrExit();
      void selectPreviousSymbol();
      void selectNextSymbol();
      void decrementSymbol();
      void incrementSymbol();
      void exit();

      void renderSelf();
  };
};

#endif;
