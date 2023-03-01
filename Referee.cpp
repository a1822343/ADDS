#include "Referee.h"

Referee::Referee() {}
Player* Referee::refGame(Player* player1, Player* player2){ 
    char p1_move = player1->makeMove();
    char p2_move = player2->makeMove();
    if (p1_move == 'R'){
        if (p2_move == 'R'){
            return nullptr;
        } else if (p2_move == 'P'){
            return player2;
        } else if (p2_move == 'S'){
            return player1;
        }
    } else if (p1_move == 'P'){
        if (p2_move == 'P'){
            return nullptr;
        } else if (p2_move == 'S'){
            return player2;
        } else if (p2_move == 'R'){
            return player1;
        }
    } else if (p1_move == 'S'){
        if (p2_move == 'S'){
            return nullptr;
        } else if (p2_move == 'R'){
            return player2;
        } else if (p2_move == 'P'){
            return player1;
        }
    }
}