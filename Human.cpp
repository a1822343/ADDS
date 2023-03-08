#include "Human.h"

Human::Human() { name = "Human"; }
Human::Human(std::string _name) { name = _name; }

Move * Human::makeMove(){
  
  std::cout << "Enter move: ";
  std::cin >> move;

  return move;
}

std::string Human::getName() { return name; }