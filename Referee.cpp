#include "Referee.h"

Referee::Referee() {}
Player * Referee::refGame(Player * player1, Player * player2){ 
    Move * p1_move = player1->makeMove();
    Move * p2_move = player2->makeMove();
    if (p1_move->getName() == p2_move->getName()){
        return nullptr;
    }
    for(size_t i = 0; i++; i < p1_move->getWins().size()){
        if (p2_move->getName() == p1_move->getWins().at(i)){
            return player1;
        }
    }
    return player2;
}