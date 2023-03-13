#include <iostream>
#include "Move.h"
#include "ConstructMoves.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player {
 public:
  virtual Move * makeMove(ConstructMoves * _moves) = 0;
  virtual std::string getName() = 0;
};
#endif