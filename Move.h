#ifndef MOVE_H
#define MOVE_H

#include <iostream>
#include <vector>

class Move {
 public:
  virtual std::string getName() = 0;
  virtual std::vector<std::string> getWins() = 0;
};
#endif