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
    BaseData temp;
    memcpy_P((void*)&temp, baseData, sizeof(temp));
    return &temp;
  };

  uint8_t BaseChild::getType() {
    return getBaseData()->type;
  };

  char* BaseChild::getName() {
    return readProgmemSrt(getBaseData()->name);
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