#include <avr/pgmspace.h>
#include "./NumberField.h"
#include "../_base/helpers.h"
#include "../../Controller.h"


namespace Menu {

  //////////////////////////////////////////
  // DATA GETTERS

  /**
  * Copy of baseData to memory and return pointer to it
  */
  NumberFieldData* NumberField::getData() {
    NumberFieldData temp;
    memcpy_P((void*)&temp, data, sizeof(temp));
    return &temp;
  };

  char* NumberField::getTextAfter() {
    return readProgmemSrt(getData()->textAfter);
  };

  int* NumberField::getValue() {
    return getData()->value;
  };


  //////////////////////////////////////////
  // BEHAVIOUR

  void NumberField::decrementValue() {
    int* value = getValue();
    int minValue = getData()->minValue;

    (*value) -= getData()->valueStep;

    if ((*value) < minValue) {
      (*value) = minValue;
    }
  };

  void NumberField::incrementValue() {
    int* value = getValue();
    int maxValue = getData()->maxValue;

    (*value) += getData()->valueStep;

    if ((*value) > maxValue) {
      (*value) = maxValue;
    }
  };


  //////////////////////////////////////////
  // RENDER
  // Prepare text to output
  
  /**
  * Render as item for parent child list
  */
  void NumberField::renderSelf() {

    controller->output->print(getName());

    char* value = getData()->formatValue(*(getValue()));
    if (isActive) {
      controller->output->printEditMode(value);
    } else {
      controller->output->print(value);
    }

    controller->output->print(getTextAfter());
  };
};