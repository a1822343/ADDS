#include "ConstructMoves.h"

ConstructMoves::ConstructMoves() {  /* construct every move and add them to a
                                       vector */
  // moves can be made by copying any of the current moves' .cpp and .h,
  // replacing the name and modifying the winsAgainst string vector

  Move* rock = new Rock();
  moves.push_back(rock);

  Move* paper = new Paper();
  moves.push_back(paper);

  Move* scissors = new Scissors();
  moves.push_back(scissors);

  Move* monkey = new Monkey();
  moves.push_back(monkey);

  Move* robot = new Robot();
  moves.push_back(robot);

  Move* pirate = new Pirate();
  moves.push_back(pirate);

  Move* ninja = new Ninja();
  moves.push_back(ninja);

  Move* zombie = new Zombie();
  moves.push_back(zombie);
}

Move* ConstructMoves::getMove(
    std::string userInput) {  // returns a move by comparing each moves' name to
                              // the user's input
  for (int i = 0; i < moves.size(); i++) {
    if (userInput == moves.at(i)->getName()) {
      return moves.at(i);
    }
  }
  return nullptr;
}