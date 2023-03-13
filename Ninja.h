#ifndef NINJA
#define NINJA
#include <vector>

#include "Move.h"

class Ninja : public Move {
 private:
  std::string name;
  std::vector<std::string> winsAgainst;

 public:
  Ninja();
  std::string getName();
  std::vector<std::string> getWins();
};
#endif