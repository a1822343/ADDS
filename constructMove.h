#ifndef CONSTRUCTMOVE_H
#define CONSTRUCTMOVE_H

#include <iostream>
#include "Move.h"
#include "Rock.h"
#include "Paper.h"
#include "Scissors.h"
#include "Monkey.h"
#include "Robot.h"
#include "Pirate.h"
#include "Ninja.h"
#include "Zombie.h"

class constructMove {
 public:
  constructMove();
  std::vector<Move*> possibleMoves;
  int moveID(std::string userInput);
  Move * getMove(int _moveID);
};

#endif