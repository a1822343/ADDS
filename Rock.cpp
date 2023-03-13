#include "Rock.h"

Rock::Rock() {
  name = "Rock";
  winsAgainst.push_back("Scissors");
}

std::string Rock::getName() { return name; }

std::vector<std::string> Rock::getWins() { return winsAgainst; }