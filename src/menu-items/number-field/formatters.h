#ifndef MENU__NUMBER_FORMATTERS_H
#define MENU__NUMBER_FORMATTERS_H


namespace Menu {
  char* toFormatted(char* format, int value);

  char* toNumber(int value);

  char* to2Digits(int value);
  char* to3Digits(int value);
  char* to4Digits(int value);
  char* to5Digits(int value);
  char* to6Digits(int value);
  char* to7Digits(int value);
  char* to8Digits(int value);
  char* to9Digits(int value);
  char* to10Digits(int value);

  char* toTime(int value);
  char* toTime24(int value);

  char* toPeriod(int value);

};

#endif;
