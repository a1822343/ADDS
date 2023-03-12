#ifndef MONKEY
#define MONKEY
#include "Move.h"
#include <vector>

class Monkey: public Move {
 private:
  std::string name;
  std::vector<std::string> winsAgainst;
 public:
  Monkey();
  std::string getName();
  std::vector<std::string> getWins();
};
#endif