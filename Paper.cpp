#include "Paper.h"

Paper::Paper(){ name = "Paper"; winsAgainst.push_back("Rock");}

std::string Paper::getName(){ return name; }

std::vector<std::string> Paper::getWins(){ return winsAgainst; }