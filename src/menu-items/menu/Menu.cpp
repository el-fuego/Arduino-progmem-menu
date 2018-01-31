#include <avr/pgmspace.h>
#include "./Menu.h"
#include "../action/Action.h"
#include "../number-field/NumberField.h"
#include "../text-field/TextField.h"
#include "../../Controller.h"


namespace Menu {

  //////////////////////////////////////////
  // DATA GETTERS

  /**
  * Copy of baseData to memory and return pointer to it
  */
  MenuData* Menu::getData() {
    MenuData temp;
    memcpy_P((void*)&temp, data, sizeof(temp));
    return &temp;
  };

  uint8_t Menu::getChildCount() {
    return getData()->childCount;
  };

  // Child can be one of classes, what are extending BaseChild
  // Real type can be determined, basing on child.getType() return value
  BaseChild* Menu::getChildAtIndexAsBase(uint8_t childIndex) {
    return pgm_read_word_near(getData()->childList + childIndex);
  };

  BaseChild* Menu::getSelectedChildAsBase() {
    return pgm_read_word_near(getData()->childList + selectedChildIndex);
  };

  // Is bit flag present?
  bool Menu::hasStyle(MENU_STYLE styleToCheck) {
    return (getData()->styles & styleToCheck) == styleToCheck;
  };


  //////////////////////////////////////////
  // BEHAVIOUR

  void Menu::selectChildAtIndex(uint8_t index) {
    selectedChildIndex = index;
  };

  void Menu::selectPreviousChild() {
    if (selectedChildIndex == 0) {
      return;
    }

    selectedChildIndex--;
  };

  void Menu::selectPreviousChildOrExit() {
    if (selectedChildIndex == 0) {
      return exit();
    }

    selectedChildIndex--;
  };

  void Menu::selectNextChild() {
    if (selectedChildIndex == getChildCount() - 1) {
      return;
    }

    selectedChildIndex++;
  };

  void Menu::enterSelectedChild() {
    BaseChild* child = getSelectedChildAsBase();
    uint8_t type = child->getType();

    switch(type) {
      case TYPE::SUBMENU:
        return ((Menu*)child)->enter();
      case TYPE::NUMBER_FIELD:
        return ((NumberField*)child)->enter();
      case TYPE::TEXT_FIELD:
        return ((TextField*)child)->enter();
      case TYPE::ACTION:
        return ((Action*)child)->enter();
    }
  };

  void Menu::exit() {
    BaseChild::exit();
    selectedChildIndex = 0;
  };
  
  
  //////////////////////////////////////////
  // RENDER
  // Prepare text to output
  
  uint8_t Menu::_getFirstItemOnPageIndex(uint8_t startLineIndex) {
    unsigned char linesCount = controller->output->linesCount;
    uint8_t pageNumber = selectedChildIndex / (linesCount - startLineIndex);
    return pageNumber * (linesCount - startLineIndex);
  }

  void Menu::_renderChildAtIndex(uint8_t childIndex) {
    BaseChild* child = getChildAtIndexAsBase(childIndex);
    uint8_t type = child->getType();

    switch(type) {
      case TYPE::SUBMENU:
        return ((Menu*)child)->renderSelf();
      case TYPE::NUMBER_FIELD:
        return ((NumberField*)child)->renderSelf();
      case TYPE::TEXT_FIELD:
        return ((TextField*)child)->renderSelf();
      case TYPE::ACTION:
        return ((Action*)child)->renderSelf();
    }
  }

  void Menu::_renderChildList(uint8_t startLineIndex) {
    uint8_t lineIndex = startLineIndex;
    unsigned char linesCount = controller->output->linesCount;
    bool isHorizontalView = hasStyle(MENU_STYLE::HORIZONTAL_CHILD_LIST);
    uint8_t childrenCount = getChildCount();
    uint8_t childIndex = _getFirstItemOnPageIndex(lineIndex);

    while (lineIndex < linesCount && childIndex < childrenCount) {
      controller->output->print(
        childIndex == selectedChildIndex ?
          SELECTED_LINE_START_SYMBOL :
          UNSELECTED_LINE_START_SYMBOL
      );

      _renderChildAtIndex(childIndex);

      if (!isHorizontalView) {
        controller->output->nextLine();
        lineIndex++;
      }

      childIndex++;
    }
  }

  /**
  * Render screen with child list
  */
  void Menu::renderScreen() {
    controller->output->clear();

    uint8_t lineIndex = 0;
    if (!hasStyle(MENU_STYLE::NAME_HIDDEN_FOR_CHILD_LIST)) {
      controller->output->print(getName());
      controller->output->print(MENU_NAME_END_SYMBOL);

      controller->output->nextLine();
      lineIndex++;
    }

    _renderChildList(lineIndex);
  };

  /**
  * Render as item for parent child list
  */
  void Menu::renderSelf() {
    controller->output->print(getName());

    if(!hasStyle(MENU_STYLE::INLINE_CHILD_LIST)) {
      return;
    }

    _renderChildList(0);
  };

};