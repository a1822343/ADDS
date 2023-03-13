#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Move.h"

// all players use construct moves, though not used in the parent class
#include "ConstructMoves.h"

// all players will use these two functions

class Player {
 public:
  virtual Move * makeMove() = 0; // return player's move
  virtual std::string getName() = 0; // return player's name
};
#endif