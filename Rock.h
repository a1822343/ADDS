#ifndef ROCK
#define ROCK
#include "Move.h"
#include <vector>

class Rock: public Move {
 private:
  std::string name;
  std::vector<std::string> winsAgainst;
 public:
  Rock();
  std::string getName();
  std::vector<std::string> getWins();
};
#endif