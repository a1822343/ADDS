#include "Computer.h"

std::string Computer::getName() { return "Computer"; }

Move * Computer::makeMove(ConstructMoves * _moves) {
    return _moves->getMove("Rock");
}
