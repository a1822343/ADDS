#ifndef ZOMBIE
#define ZOMBIE
#include <vector>

#include "Move.h"

class Zombie : public Move {
 private:
  std::string name;
  std::vector<std::string> winsAgainst;

 public:
  Zombie();
  std::string getName();
  std::vector<std::string> getWins();
};
#endif