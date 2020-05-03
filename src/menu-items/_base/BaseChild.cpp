#include <Arduino.h>
#include <avr/pgmspace.h>
#include "./BaseChild.h"
#include "./helpers.h"


namespace Menu {
  //////////////////////////////////////////
  // DATA GETTERS

  /**
  * Copy of baseData to memory and return pointer to it
  */
  BaseData* BaseChild::getBaseData() {
    void* tempBaseData = malloc(sizeof(BaseData));
    memcpy_P(tempBaseData, baseData, sizeof(BaseData));
    return (BaseData*)tempBaseData;
  };

  const uint8_t BaseChild::getType() {
    BaseData* data = getBaseData();
    const uint8_t type = data->type;

    free(data);
    return type;
  };

  const char* BaseChild::getName() {
    BaseData* data = getBaseData();
    const char* name = data->name;

    free(data);
    return readProgmemSrt(name);
  };


  //////////////////////////////////////////
  // BEHAVIOUR

  void BaseChild::enter() {
    isActive = true;
  };

  void BaseChild::exit() {
    isActive = false;
  };

};