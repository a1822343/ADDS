#include "Monkey.h"

Monkey::Monkey(){ name = "Monkey"; winsAgainst.push_back("Ninja"); winsAgainst.push_back("Robot");}

std::string Monkey::getName(){ return name; }

std::vector<std::string> Monkey::getWins(){ return winsAgainst; }