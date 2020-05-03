#ifndef MENU__BASE_H
#define MENU__BASE_H

#include <inttypes.h>


namespace Menu {
  enum TYPE { SUBMENU, NUMBER_FIELD, TEXT_FIELD, ACTION };

  struct BaseData {
    const uint8_t type;
    const char* name; // pointer to PROGMEM
  };

  class BaseChild {
    private:
      const BaseData* baseData; // pointer to PROGMEM
      BaseData* getBaseData();

    public:
      BaseChild(const BaseData* _baseData) : baseData(_baseData) {};

      bool isActive = false;

      const uint8_t getType();
      const char* getName();

      void enter();
      void exit();
  };
};

#endif