#include "Referee.h"
#include "Computer.h"
#include "Human.h"
#include "Player.h"

int main(void){
    Referee ref;
    Player* human = new Human;
    Player* computer = new Computer;
    Player* winner = ref.refGame(human, computer);
    std::cout << winner->getName() << " Wins\n";
    return 0;
}