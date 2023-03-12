#ifndef NINJA
#define NINJA
#include "Move.h"
#include <vector>

class Ninja: public Move {
 private:
  std::string name;
  std::vector<std::string> winsAgainst;
 public:
  Ninja();
  std::string getName();
  std::vector<std::string> getWins();
};
#endif