#ifndef MENU__MENU_H
#define MENU__MENU_H

#include <inttypes.h>
#include "../_base/BaseChild.h"


// TODO: use from current output instead (override ability)
#ifndef SELECTED_LINE_START_SYMBOL
  #define SELECTED_LINE_START_SYMBOL ">"
#endif
#ifndef UNSELECTED_LINE_START_SYMBOL
  #define UNSELECTED_LINE_START_SYMBOL " "
#endif
#ifndef SELECTED_VALUE_START_SYMBOL
  #define SELECTED_VALUE_START_SYMBOL ">"
#endif
#ifndef UNSELECTED_VALUE_START_SYMBOL
  #define UNSELECTED_VALUE_START_SYMBOL " "
#endif
#ifndef ACTIVE_VALUE_START_SYMBOL
  #define ACTIVE_VALUE_START_SYMBOL " "
#endif
#ifndef UNACTIVE_VALUE_START_SYMBOL
  #define UNACTIVE_VALUE_START_SYMBOL " "
#endif
#ifndef MENU_NAME_END_SYMBOL
  #define MENU_NAME_END_SYMBOL ":"
#endif
#ifndef OUTPUT_LINES_COUNT
  #define OUTPUT_LINES_COUNT 255
#endif


namespace Menu {

  enum MENU_STYLE {
    // Name visibility for child list
    NAME_HIDDEN_FOR_CHILD_LIST = (1 << 0), // 01

    // Child place style (horizontal or vertical):
    HORIZONTAL_CHILD_LIST = (1 << 1), // 010

    // Style at parent list (inline or nested):
    INLINE_CHILD_LIST = (1 << 2), // 0100
  };

  struct MenuData {
    uint8_t childCount;
    BaseChild* const* childList; // pointer to PROGMEM list of pointers to RAM
    uint8_t styles;
  };

  class Menu : public BaseChild {
    private:
      const MenuData *data; // pointer to PROGMEM
      MenuData* getData();

      uint8_t _getFirstItemOnPageIndex(uint8_t startLineIndex = 0);
      void _renderChildList(uint8_t startLineIndex = 0);
      void _renderChildAtIndex(uint8_t childIndex);

    public:
      Menu(const BaseData* _baseData, const MenuData* _data) : BaseChild(_baseData), data(_data) {};

      uint8_t selectedChildIndex = 0;

      uint8_t getChildCount();
      BaseChild* getChildAtIndexAsBase(uint8_t childIndex);
      BaseChild* getSelectedChildAsBase();
      bool hasStyle(MENU_STYLE styleToCheck);
      void selectChildAtIndex(uint8_t index);
      void selectPreviousChild();
      void selectPreviousChildOrExit();
      void selectNextChild();
      void enterSelectedChild();
      void exit();

      void renderScreen();
      void renderSelf();
  };
};

#endif
