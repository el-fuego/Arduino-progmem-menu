#ifndef MENU__NUMBER_FIELD_H
#define MENU__NUMBER_FIELD_H

#include <inttypes.h>
#include "../_base/BaseChild.h"
#include "./formatters.h"


namespace Menu {

  struct NumberFieldData {
    unsigned int* value; // pointer to RAM
    char* (*formatValue)(unsigned int value); // pointer to RAM
    const char* textAfter; // pointer to PROGMEM
    const unsigned int minValue;
    const unsigned int maxValue;
    const unsigned int valueStep;
  };

  class NumberField : public BaseChild {
    private:
      const NumberFieldData* data; // pointer to PROGMEM
      NumberFieldData* getData();

    public:
      NumberField(const BaseData* _baseData, const NumberFieldData* _data) : BaseChild(_baseData), data(_data) {};

      char* getTextAfter();
      unsigned int* getValue();

      void decrementValue();
      void incrementValue();

      void renderSelf();
  };
};

#endif
