#include "Human.h"

Human::Human() { name = "Human"; }  // returns the name
Human::Human(std::string _name) { name = _name; }

std::string Human::getName() { return name; }  // return the name

Move* Human::makeMove() {  // prompt for a move, return the move

  ConstructMoves* _moves =
      new ConstructMoves();  // constructs all the possible moves

  std::string
      userInput;  // doesn't need to be accessed, only used in this one function

  // take the user's move
  std::cout << "Enter move: ";
  std::cin >> userInput;

  return _moves->getMove(
      userInput);  // find the corresponding move in the array and return it
}