#include "Player.h"

#ifndef HUMAN_H
#define HUMAN_H

class Human: public Player{
 private:
  std::string name;
  std::string move;
 public:
  Human();
  Human(std::string _name);
  
  std::string getName();
  Move * makeMove();
};
#endif