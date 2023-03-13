#ifndef CONSTRUCTMOVES_H
#define CONSTRUCTMOVES_H

// technically included in the move classes, but are referred to directly
#include <iostream>
#include "Move.h"

// each move is a seperate class with near identical behaviour
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
  std::vector<Move*> moves; // a vector of all the moves
 public:
  ConstructMoves(); // construct every move and add them to the "moves" vector
  Move * getMove(std::string userInput); // returns a move by comparing each moves' name to the user's input
};

#endif