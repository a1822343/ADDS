#ifndef HUMAN_H
#define HUMAN_H

#include "Player.h"

class Human: public Player {
 private:
  std::string name;
 public:
  Human(); // constructs a human player with the name "Human"
  Human(std::string _name); // constructs a human player with the name _name
  
  std::string getName(); // returns name
  Move * makeMove(); // returns the user's inputted move
};
#endif