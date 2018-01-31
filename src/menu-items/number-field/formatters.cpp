#include <Arduino.h>
#include "./formatters.h"
#include "../_base/helpers.h"


// TODO: add float support
namespace Menu {
  char* toFormatted(char* format, int value) {
    clearBuffer();
    sprintf(charBuffer, format, value);
    return charBuffer;
  };

  char* toNumber(int value) {
    return toFormatted("%d", value);
  };

  char* to2Digits(int value) {
    return toFormatted("%02d", value);
  };

  char* to3Digits(int value) {
    return toFormatted("%03d", value);
  };

  char* to4Digits(int value) {
    return toFormatted("%04d", value);
  };

  char* to5Digits(int value) {
    return toFormatted("%05d", value);
  };

  char* to6Digits(int value) {
    return toFormatted("%06d", value);
  };

  char* to7Digits(int value) {
    return toFormatted("%07d", value);
  };

  char* to8Digits(int value) {
    return toFormatted("%08d", value);
  };

  char* to9Digits(int value) {
    return toFormatted("%09d", value);
  };

  char* to10Digits(int value) {
    return toFormatted("%010d", value);
  };

  char* toTime(int value) {
    unsigned char hours24 = value / 60;
    unsigned char hours = hours24 % 12;
    unsigned char minutes = value % 60;
    bool isAm = hours24 < 12;

    if (hours == 0) {
      hours = 12;
    }

    clearBuffer();
    sprintf(charBuffer, "%02d:%02d%s", hours, minutes, isAm ? "AM" : "PM");
    return charBuffer;
  };

  char* toTime24(int value) {
    unsigned char hours = value / 60;
    unsigned char minutes = value % 60;

    clearBuffer();
    sprintf(charBuffer, "%02d:%02d", hours, minutes);
    return charBuffer;
  };

  char* toPeriod(int value) {
    clearBuffer();

    if (value < 60) {
      return toFormatted("%02dm", value);
    }
    return toFormatted("%02dh", value / 60);
  };

};
