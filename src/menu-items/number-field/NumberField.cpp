#include <Arduino.h>
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
    void* tempNumberFieldData = malloc(sizeof(NumberFieldData));
    memcpy_P(tempNumberFieldData, data, sizeof(NumberFieldData));
    return (NumberFieldData*)tempNumberFieldData;
  };

  char* NumberField::getTextAfter() {
    NumberFieldData* data = getData();
    char* textAfter = readProgmemSrt(data->textAfter);

    free(data);
    return textAfter;
  };

  unsigned int* NumberField::getValue() {
    NumberFieldData* data = getData();
    unsigned int* value = data->value;

    free(data);
    return value;
  };


  //////////////////////////////////////////
  // BEHAVIOUR

  void NumberField::decrementValue() {
    NumberFieldData* data = getData();
    unsigned int* value = data->value;
    unsigned int minValue = data->minValue;
    unsigned int valueStep = data->valueStep;

    free(data);

    (*value) = (*value) - valueStep;

    if ((*value) < minValue) {
      (*value) = minValue;
    }
  };

  void NumberField::incrementValue() {
    NumberFieldData* data = getData();
    unsigned int* value = data->value;
    unsigned int maxValue = data->maxValue;
    unsigned int valueStep = data->valueStep;

    free(data);

    (*value) = (*value) + valueStep;

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
    const char* name = getName();
    controller->output->print(name);
    free(name);

    NumberFieldData* data = getData();
    char* formattedValue = data->formatValue(*(data->value));
    free(data);

    if (isActive) {
      controller->output->printEditMode(formattedValue);
    } else {
      controller->output->print(formattedValue);
    }
    free(formattedValue);

    char* textAfter = getTextAfter();
    controller->output->print(textAfter);
    free(textAfter);
  };
};
