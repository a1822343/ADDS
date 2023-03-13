#ifndef MOVE_H
#define MOVE_H

#include <iostream>
#include <vector>

// all moves will use these two functions
class Move {
 public:
  virtual std::string getName() = 0;
  virtual std::vector<std::string> getWins() = 0;
};
#endif