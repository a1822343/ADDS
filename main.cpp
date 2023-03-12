#include "Referee.h"
#include "Computer.h"
#include "Human.h"
#include "Player.h"

int main(void){
    Referee ref;
    Player* human = new Human;
    Player* computer = new Computer;

    // make a move vector of all moves
    // loop over using .getName compare to cin and return the move at [i]
    // in the move vector
    Player* winner = ref.refGame(human, computer);
    std::cout << winner->getName() << " Wins\n";
    return 0;
}