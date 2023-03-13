#include "Computer.h"
#include "Human.h"
#include "Referee.h"

// included in above classes, but directly used in main
#include <iostream>

int main(void) {
  Referee ref;
  Player* human = new Human;
  Player* computer = new Computer;

  Player* winner = ref.refGame(human, computer);           // decide who wins
  std::cout << winner->getName() << " Wins" << std::endl;  // output winner

  return 0;
}