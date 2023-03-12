#include "Human.h"
#include "Move.h"
#include "constructMove.h"

Human::Human() { name = "Human";}
Human::Human(std::string _name) { name = _name; }

Move * Human::makeMove(){
  constructMove moves;
  std::string userInput;
  std::cout << "Enter move: ";
  std::cin >> userInput;
  return moves.getMove(moves.moveID(userInput));
}

std::string Human::getName() { return name; }