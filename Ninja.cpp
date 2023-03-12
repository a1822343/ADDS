#include "Ninja.h"

Ninja::Ninja(){ name = "Ninja"; winsAgainst.push_back("Pirate"); winsAgainst.push_back("Zombie");}

std::string Ninja::getName(){ return name; }

std::vector<std::string> Ninja::getWins(){ return winsAgainst; }