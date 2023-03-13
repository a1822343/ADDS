#include "Robot.h"

Robot::Robot() {
  name = "Robot";
  winsAgainst.push_back("Ninja");
  winsAgainst.push_back("Zombie");
}

std::string Robot::getName() { return name; }

std::vector<std::string> Robot::getWins() { return winsAgainst; }