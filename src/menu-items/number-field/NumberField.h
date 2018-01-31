#ifndef MENU__NUMBER_FIELD_H
#define MENU__NUMBER_FIELD_H

#include <inttypes.h>
#include "../_base/BaseChild.h"
#include "./formatters.h"


namespace Menu {

  struct NumberFieldData {
    int* value; // pointer to RAM
    char* (*formatValue)(int* value); // pointer to RAM
    char* textAfter; // pointer to PROGMEM
    int minValue;
    int maxValue;
    int valueStep;
  };

  class NumberField : public BaseChild {
    private:
      NumberFieldData* data; // pointer to PROGMEM
      NumberFieldData* getData();

    public:
      NumberField(BaseData* _baseData, NumberFieldData* _data) : BaseChild(_baseData), data(_data) {};

      char* getTextAfter();
      int* getValue();

      void decrementValue();
      void incrementValue();

      void renderSelf();
  };
};

#endif;
