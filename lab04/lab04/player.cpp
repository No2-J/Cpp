#include "Player.h"

void Player::initialize() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
            display[i][j] = EMPTY;
        }
    }
}


void Player::printBoard(bool hideShips) {
    cout << "  ";
    for (int i = 0; i < SIZE; i++) cout << i << " ";
    cout << "\n";

    for (int i = 0; i < SIZE; i++) {
        cout << i << " ";
        for (int j = 0; j < SIZE; j++) {
            if (hideShips && board[i][j] == SHIP)
                cout << EMPTY << " ";
            else
                cout << board[i][j] << " ";
        }
        cout << endl;
    }
}


void Player::placeShips(bool isPlayer) {
    int placed = 0;
    while (placed < SHIPS) {
        int x, y;
        if (isPlayer) {
            cout << "Enter ship " << placed + 1 << " coordinates (row col): ";
            cin >> x >> y;
        }
        else {
            x = rand() % SIZE;
            y = rand() % SIZE;
        }

        if (x >= 0 && x < SIZE && y >= 0 && y < SIZE && board[x][y] == EMPTY) {
            board[x][y] = SHIP;
            placed++;
        }
        else if (isPlayer) {
            cout << "Invalid position! Try again.\n";
        }
    }
}

bool Player::attack(Player& opponent, int x, int y) {
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || display[x][y] != EMPTY) {
        cout << "Invalid attack! Try again.\n";
        return false;
    }

    if (opponent.board[x][y] == SHIP) {
        cout << "Hit!\n";
        display[x][y] = HIT;
        opponent.board[x][y] = HIT;
    }
    else {
        cout << "Miss!\n";
        display[x][y] = MISS;
        opponent.board[x][y] = MISS;
    }
    return true;
}


bool Player::isGameOver() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == SHIP) return false;
        }
    }
    return true;
}