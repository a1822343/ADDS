#include "Computer.h"
#include "Rock.h"

std::string Computer::getName() { return "Computer"; }

Move * Computer::makeMove() { 
    move = new Rock();
    return move;
}
