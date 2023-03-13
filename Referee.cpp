#include "Referee.h"

Referee::Referee() {}
Player* Referee::refGame(Player* player1, Player* player2) {
  // get the player's moves, through user input or pre-determined choice
  Move* p1_move = player1->makeMove();
  Move* p2_move = player2->makeMove();

  // check for a tie
  if (p1_move->getName() == p2_move->getName()) {
    return nullptr;
  }

  // see if player 1 beats player 2
  for (size_t i = 0; i < p1_move->getWins().size(); i++) {
    if (p2_move->getName() == p1_move->getWins().at(i)) {
      return player1;
    }
  }
  // if not, player 2 wins, since tie has already been checked
  return player2;
}