#include <avr/pgmspace.h>
#include "./helpers.h"


namespace Menu {
  extern char charBuffer[CHAR_BUFFER_LENGTH] = "\0";

  void clearBuffer() {
    char i = CHAR_BUFFER_LENGTH;
    while (i--) {
      charBuffer[i] = "\0";
    }
  }

  char* readProgmemSrt(char* progmemSrt) {
    clearBuffer();
    strcpy_P(charBuffer, progmemSrt);

    return charBuffer;
  };
};
