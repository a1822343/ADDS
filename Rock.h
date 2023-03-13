#ifndef ROCK
#define ROCK
#include <vector>

#include "Move.h"

class Rock : public Move {
 private:
  std::string name;
  std::vector<std::string> winsAgainst;

 public:
  Rock();
  std::string getName();
  std::vector<std::string> getWins();
};
#endif