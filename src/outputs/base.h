#ifndef MENU__OUTPUT_BASE_H
#define MENU__OUTPUT_BASE_H


namespace Menu {
  class Output {
    public:
      unsigned char linesCount = 255;
      virtual void print(char* str);
      virtual void printEditMode(char* str);
      virtual void clear();
      virtual void nextLine();
  };
};

#endif;
