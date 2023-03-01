#include <iostream>

#ifndef PLAYER_H
#define PLAYER_H

class Player {
 public:
  virtual char makeMove();
  virtual std::string getName();
};
#endif