#ifndef MENU__BASE_H
#define MENU__BASE_H

#include <inttypes.h>


namespace Menu {
  enum TYPE { SUBMENU, NUMBER_FIELD, TEXT_FIELD, ACTION };

  struct BaseData {
    uint8_t type;
    char* name; // pointer to PROGMEM
  };

  class BaseChild {
    private:
      BaseData *baseData; // pointer to PROGMEM
      BaseData* getBaseData();

    public:
      BaseChild(BaseData* _baseData) : baseData(_baseData) {};

      bool isActive = false;

      uint8_t getType();
      char* getName();

      void enter();
      void exit();
  };
};

#endif;