#ifndef MENU__OUTPUT_BASE_H
#define MENU__OUTPUT_BASE_H


namespace Menu {
  class Output {
    public:
      unsigned char linesCount = 255;
      virtual void print(const char* str);
      virtual void printEditMode(const char* str);
      virtual void clear();
      virtual void nextLine();
      virtual void end();
  };
};

#endif
