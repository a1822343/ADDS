#include "Referee.h"

Referee::Referee() {}
Player * Referee::refGame(Player * player1, Player * player2){ 
    Move * p1_move = player1->makeMove();
    Move * p2_move = player2->makeMove();
    
    for(size_t i = 0; i < p1_move->getWins().size(); i++){
        if (p2_move->getName() == p1_move->getWins().at(i)){
            return player1;
        }
    }

    for(size_t i = 0; i < p2_move->getWins().size(); i++){
        if (p1_move->getName() == p2_move->getWins().at(i)){
            return player2;
        }
    }

    return nullptr;
}