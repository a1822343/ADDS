#include <iostream>

#ifndef PLAYER_H
#define PLAYER_H

class Player {
 public:
  virtual char makeMove() = 0;
  virtual std::string getName() = 0;
};
#endif