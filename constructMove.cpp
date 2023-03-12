#include "constructMove.h"

constructMove::constructMove(){
    Move * rock = new Rock();
    Move * paper = new Paper();
    Move * scissors = new Scissors();
    Move * monkey = new Monkey();
    Move * robot = new Robot();
    Move * pirate = new Pirate();
    Move * ninja = new Ninja();
    Move * zombie = new Zombie();
    possibleMoves.push_back(rock);
    possibleMoves.push_back(paper);
    possibleMoves.push_back(scissors);
    possibleMoves.push_back(monkey);
    possibleMoves.push_back(robot);
    possibleMoves.push_back(pirate);
    possibleMoves.push_back(ninja);
    possibleMoves.push_back(zombie);
}

int constructMove::moveID(std::string userInput){
    for (int i = 0; i < possibleMoves.size(); i++){
        if (userInput == possibleMoves.at(i)->getName()){
            return i;
        }
    }
    return -1;
}

Move* constructMove::getMove(int _moveID){
    return possibleMoves.at(_moveID);
}