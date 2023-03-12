#include "Scissors.h"

Scissors::Scissors(){ name = "Scissors"; winsAgainst.push_back("Paper");}

std::string Scissors::getName(){ return name; }

std::vector<std::string> Scissors::getWins(){ return winsAgainst; }