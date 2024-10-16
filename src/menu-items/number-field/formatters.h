#ifndef MENU__NUMBER_FORMATTERS_H
#define MENU__NUMBER_FORMATTERS_H

#include <inttypes.h>


namespace Menu {
  char* toFormatted(char* sprintfFormat, unsigned int value);

  char* toNumber(unsigned int value);

  char* to2Digits(unsigned int value);
  char* to3Digits(unsigned int value);
  char* to4Digits(unsigned int value);
  char* to5Digits(unsigned int value);
  char* to6Digits(unsigned int value);
  char* to7Digits(unsigned int value);
  char* to8Digits(unsigned int value);
  char* to9Digits(unsigned int value);
  char* to10Digits(unsigned int value);

  char* toTime(unsigned int value);
  char* toTime24(unsigned int value);

  char* toPeriod(unsigned int value);
};

#endif
