#ifndef REVERSER
#define REVERSER

#include <iostream>

class Reverser {
 private:
  std::string reversed;
 public:
  int reverseDigit(int value);
  std::string reverseString(std::string characters);
};
#endif