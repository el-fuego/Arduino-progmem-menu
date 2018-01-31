#ifndef MENU__HELPERS_H
#define MENU__HELPERS_H


namespace Menu {
  #define CHAR_BUFFER_LENGTH 16
  extern char charBuffer[CHAR_BUFFER_LENGTH];

  void clearBuffer();

  char* readProgmemSrt(char* progmemSrt);
};

#endif;