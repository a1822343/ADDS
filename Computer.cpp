#include "Computer.h"

std::string Computer::getName() { return "Computer"; } // returns the name

Move * Computer::makeMove() { // returns the move "Rock"
    Move * move = new Rock();
    return move;
}
