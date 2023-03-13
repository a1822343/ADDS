#include "Computer.h"

std::string Computer::getName() { return "Computer"; }

Move * Computer::makeMove() {
    Move * move = new Rock();
    return move;
}
