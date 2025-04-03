#include "battleships.h"

void cpuAttack(Player& player) {
    int x, y;
    do {
        x = rand() % SIZE;
        y = rand() % SIZE;
    } while (player.board[x][y] == HIT || player.board[x][y] == MISS);

    cout << "CPU attacks: " << x << " " << y << "\n";
    if (player.board[x][y] == SHIP) {
        cout << "CPU hit your ship! \n";
        player.board[x][y] = HIT;
    }
    else {
        cout << "CPU missed! \n";
        player.board[x][y] = MISS;
    }
}

void PlayGame(Player& player, Player& cpu) {
    int x, y;
    while (true) {
        //Player turn 
        cout << "\nYour Board : \n";
        player.printBoard();
        cout << "\nCPU board (hidden ships) : \n";
        cpu.printBoard(true);

        cout << "Enter attack coordinates (row col) : ";
        cin >> x >> y;

        if (!player.attack(cpu, x, y)) continue;

        if (cpu.isGameOver()) {
            cout << "You Won\n";
            break;
        }
    }
}

void runBattleShips() {
    srand(time(0));

    Player player, cpu;
    player.initialize();
    cpu.initialize();

    cout << "Place your ships (total 3) : \n";
    player.placeShips(true);
    
    cout << "\nCPU is placing ships... \n";
    cpu.placeShips(true);

    PlayGame(player, cpu);
}