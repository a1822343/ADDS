#ifndef PIRATE
#define PIRATE
#include "Move.h"
#include <vector>

class Pirate: public Move {
 private:
  std::string name;
  std::vector<std::string> winsAgainst;
 public:
  Pirate();
  std::string getName();
  std::vector<std::string> getWins();
};
#endif