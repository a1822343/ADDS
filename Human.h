#include "Player.h"

#ifndef HUMAN_H
#define HUMAN_H

class Human: public Player{
 public:
  Human();
  Human(std::string _name);
  std::string name;
  std::string getName();
  char makeMove();
  char move;
};
#endif