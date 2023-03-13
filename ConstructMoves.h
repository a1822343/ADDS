#ifndef CONSTRUCTMOVES_H
#define CONSTRUCTMOVES_H

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

class ConstructMoves {
 private:
  std::vector<Move*> possibleMoves;
 public:
  ConstructMoves();
  Move * getMove(std::string userInput);
  ~ConstructMoves();
};

#endif