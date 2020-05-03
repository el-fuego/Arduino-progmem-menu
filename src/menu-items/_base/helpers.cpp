#include <Arduino.h>
#include <avr/pgmspace.h>
#include "./helpers.h"


namespace Menu {
  char* readProgmemSrt(const char* progmemSrt) {
    char* charBuffer = malloc(CHAR_BUFFER_LENGTH);
    strcpy_P(charBuffer, progmemSrt);

    return charBuffer;
  };
};
