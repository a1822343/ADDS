#include "Pirate.h"

Pirate::Pirate(){ name = "Pirate"; winsAgainst.push_back("Robot"); winsAgainst.push_back("Monkey");}

std::string Pirate::getName(){ return name; }

std::vector<std::string> Pirate::getWins(){ return winsAgainst; }