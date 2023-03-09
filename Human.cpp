#include "Human.h"
#include "Paper.h"

Human::Human() { name = "Human"; }
Human::Human(std::string _name) { name = _name; }

Move * Human::makeMove(){
  Move * move;
  std::string userInput;
  std::cout << "Enter move: ";
  std::cin >> userInput;
  move = new Paper();

  return move;
}

std::string Human::getName() { return name; }