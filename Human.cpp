#include "Human.h"

Human::Human() { name = "Human";}
Human::Human(std::string _name) { name = _name; }

Move * Human::makeMove(ConstructMoves * _moves){
  std::string userInput;
  std::cout << "Enter move: ";
  std::cin >> userInput;
  return _moves->getMove(userInput);
}

std::string Human::getName() { return name; }