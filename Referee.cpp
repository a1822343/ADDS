#include "Referee.h"

Referee::Referee() {}
Player * Referee::refGame(Player * player1, Player * player2){ 
    ConstructMoves * moves = new ConstructMoves();

    Move * p1_move = player1->makeMove(moves);
    Move * p2_move = player2->makeMove(moves);
    
    for(size_t i = 0; i < p1_move->getWins().size(); i++){
        if (p2_move->getName() == p1_move->getWins().at(i)){
            delete moves;
            return player1;
        }
    }

    for(size_t i = 0; i < p2_move->getWins().size(); i++){
        if (p1_move->getName() == p2_move->getWins().at(i)){
            delete moves;
            return player2;
        }
    }
    delete moves;
    return nullptr;
}