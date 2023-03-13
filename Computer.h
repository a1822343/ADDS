#ifndef COMPUTER_H
#define COMPUTER_H

#include "Player.h"

// this class is never constructed
class Computer: public Player{
 public:
  std::string getName(); // return the name "Computer"
  Move * makeMove(); // return the move "Rock"
};
#endif