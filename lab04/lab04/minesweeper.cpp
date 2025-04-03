#include "minesweeper.h"
static const int SIZE = 10;
static int numMines = 10;

Cell board[SIZE][SIZE];

void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j].isMine = false;
            board[i][j].isRevealed = false;
            board[i][j].isFlagged = false;
            board[i][j].adjacentMines = 0;
        }
    }
}

void placeMines() {
    srand(time(0));
    int placed = 0;
    while (placed < numMines) {
        int row = rand() % SIZE;
        int col = rand() % SIZE;
        if (!board[row][col].isMine) {
            board[row][col].isMine = true;
            placed++;
        }
    }
}

void calculateAdjacency() {
    int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j].isMine) continue;
            int count = 0;
            for (int d = 0; d < 8; d++) {
                int ni = i + dx[d], nj = j + dy[d];
                if (board[ni][nj].isMine && isValid(ni, nj)) {
                    count++;
                }
            }
            board[i][j].adjacentMines = count;
        }
    }
}

bool isValid(int row, int col) {
    return row >= 0 && row < SIZE && col >= 0 && col < SIZE;
}

void printBoard(bool revealAll) {
    cout << "   ";
    for (int i = 0; i < SIZE; i++) cout << i << " ";
    cout << "\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << " |";
        for (int j = 0; j < SIZE; j++) {
            if (revealAll || board[i][j].isRevealed) {
                if (board[i][j].isMine) cout << "* ";
                else cout << board[i][j].adjacentMines << " ";
            }
            else if (board[i][j].isFlagged) {
                cout << "F ";
            }
            else {
                cout << ". ";
            }
        }
        cout << "|\n";
    }
}

void revealCell(int row, int col) {
    if (!isValid(row, col) || board[row][col].isRevealed || board[row][col].isFlagged) return;
    board[row][col].isRevealed = true;
    if (board[row][col].adjacentMines == 0) {
        int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
        int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
        for (int d = 0; d < 8; d++) {
            revealCell(row + dx[d], col + dy[d]);
        }
    }
}

bool checkWin() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!board[i][j].isMine && !board[i][j].isRevealed) return false;
        }
    }
    return true;
}

void playMineSweeper() {
    cout << "Enter Number of Mines : ";
    cin >> numMines;
    initializeBoard();
    placeMines();
    calculateAdjacency();
    while (true) {
        printBoard();
        int row, col;
        char action;

        cout << "Action : (r rc), (f r c)";
        cin >> action >> row >> col;
        if(action=='r'){
            if (board[row][col].isMine) {
                cout << "You Hit the mine.. Game Over\n";
                printBoard(true);
                return;
            }
            revealCell(row, col);
        }
        else if (action == 'f') {
            (board[row][col].isFlagged) = !board[row][col].isFlagged;
        }
        if (checkWin()) {
            cout << "You Won";
            printBoard(true);
            return;
        }
    }
}