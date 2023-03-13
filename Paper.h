#ifndef PAPER
#define PAPER
#include <vector>

#include "Move.h"

class Paper : public Move {
 private:
  std::string name;
  std::vector<std::string> winsAgainst;

 public:
  Paper();
  std::string getName();
  std::vector<std::string> getWins();
};
#endif