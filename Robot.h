#ifndef ROBOT
#define ROBOT
#include <vector>

#include "Move.h"

class Robot : public Move {
 private:
  std::string name;
  std::vector<std::string> winsAgainst;

 public:
  Robot();
  std::string getName();
  std::vector<std::string> getWins();
};
#endif