#include "ConstructMoves.h"

ConstructMoves::ConstructMoves(){
    // construct every move and add them to a vector

    Move * rock = new Rock();
    possibleMoves.push_back(rock);

    Move * paper = new Paper();
    possibleMoves.push_back(paper);

    Move * scissors = new Scissors();
    possibleMoves.push_back(scissors);

    Move * monkey = new Monkey();
    possibleMoves.push_back(monkey);

    Move * robot = new Robot();
    possibleMoves.push_back(robot);

    Move * pirate = new Pirate();
    possibleMoves.push_back(pirate);

    Move * ninja = new Ninja();
    possibleMoves.push_back(ninja);

    Move * zombie = new Zombie();
    possibleMoves.push_back(zombie);
}

Move * ConstructMoves::getMove(std::string userInput){
    // compares the name of each move to the user's input, returning it's element id
    for (int i = 0; i < possibleMoves.size(); i++){
        if (userInput == possibleMoves.at(i)->getName()){
            std::cout << possibleMoves.at(i)->getName() << std::endl;
            return possibleMoves.at(i);
        }
    }
    return nullptr;
}

ConstructMoves::~ConstructMoves(){
    for (size_t i = 0; i < possibleMoves.size(); i++){
        delete possibleMoves.at(i);
    }
}