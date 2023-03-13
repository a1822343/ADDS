#include "Zombie.h"

Zombie::Zombie() {
  name = "Zombie";
  winsAgainst.push_back("Pirate");
  winsAgainst.push_back("Monkey");
}

std::string Zombie::getName() { return name; }

std::vector<std::string> Zombie::getWins() { return winsAgainst; }