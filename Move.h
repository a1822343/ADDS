#ifndef MOVE_H
#define MOVE_H

#include <iostream>

class Move {
 private:
  std::string name;
 public:
  std::string getName() { return name; }
};
#endif