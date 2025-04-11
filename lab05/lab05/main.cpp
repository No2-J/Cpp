#include"BattleShip.h"
#include"Hangman.h"
#include"MineSweeper.h"
void tstBattleShip() {
    srand(time(0));
    BattleShip game;
    game.init();
    game.play();
}
void tstInt() {
    int i;
    i = 10;
    cout << i << endl;
}
void tstHangman() {
    Hangman game;
    game.play("computer");
}
void tstMineSweeper() {
    srand(time(0));
    MineSweeper game;
    game.init(10, 10, 15);
    game.play();
}
int main()
{
    //dtstBattleShip(); 
    tstHangman();
    //tstMineSweeper();
    return 0;
}
