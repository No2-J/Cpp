#pragma once
#include<iostream>
#include<iomanip>
#include<ctime>
#include<conio.h>
#include<string>
using namespace std;
const int DIM = 10; // 10X10
class Cell;
class Panel;
class MineSweeper;
class Cell {
private:
    bool isMine, isRevealed;
    int adjMines;
public:
    void init() {
        isMine = false;
        isRevealed = false;
        adjMines = 0;
    }
    void placeMine() {
        isMine = true;
    }
    void increMines() {
        if (!isMine)
            adjMines++;
    }
    bool reveal() {
        isRevealed = true;
        return !isMine;
    }
    bool mine() const { return isMine; }
    bool revealed() const { return isRevealed; }
    int getAdjMines() const { return adjMines; }

};
//cell class end
class Panel {
private:
    int rows, cols, totalMines;
    Cell grid[DIM][DIM];
public:
    bool isValid(int r, int c) const {
        return r >= 0 && r < rows && c >= 0 && c < cols;
    }
    void init(int r, int c, int mines) {
        rows = r;
        cols = c;
        totalMines = mines;
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                grid[i][j].init();
        placeMines();
    }
    void placeMines() {
        int placed = 0;
        while (placed < totalMines) {
            int x = rand() % rows;
            int y = rand() % cols;
            if (!grid[x][y].mine()) {
                grid[x][y].placeMine();
                placed++;
                // count adjacent mines (mines in surrounding cells)
                for (int dx = -1; dx <= 1; ++dx)
                    for (int dy = -1; dy <= 1; ++dy) {
                        int nx = x + dx;
                        int ny = y + dy;
                        if (isValid(nx, ny))
                            grid[nx][ny].increMines();
                    }
            }
        }
    }
    void display(bool revealAll = false) const {
        cout << "   ";
        for (int j = 0; j < cols; ++j) cout << j << " ";
        cout << "\n";
        for (int i = 0; i < rows; ++i) {
            cout << i << " ";
            if (i < 10) cout << " ";
            for (int j = 0; j < cols; ++j) {
                if (revealAll || grid[i][j].revealed()) {
                    if (grid[i][j].mine())
                        cout << "* ";
                    else
                        cout << grid[i][j].getAdjMines() << " ";
                }
                else {
                    cout << ". ";
                }
            }
            cout << "\n";
        }
    }
    bool revealCell(int r, int c) {
        if (!isValid(r, c) || grid[r][c].revealed()) return true;
        if (!grid[r][c].reveal()) return false;
        // If empty, reveal surrounding
        if (grid[r][c].getAdjMines() == 0) {
            for (int dx = -1; dx <= 1; ++dx)
                for (int dy = -1; dy <= 1; ++dy)
                    if (dx != 0 || dy != 0)
                        revealCell(r + dx, c + dy);
        }
        return true;
    }
    bool isWon() const {
        int count = 0;
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                if (!grid[i][j].mine() && grid[i][j].revealed())
                    count++;
        return count == (rows * cols - totalMines);
    }
};
//panel class end
class MineSweeper {
private:
    Panel board;
    int rows, cols, mines;
    bool gameOver;
public:
    void init(int r, int c, int m) {
        rows = r;
        cols = c;
        mines = m;
        gameOver = false;
        board.init(rows, cols, mines);
    }
    void play() {
        while (!gameOver) {
            board.display();
            int x, y;
            cout << "Enter coordinates to reveal (row col): ";
            cin >> x >> y;
            if (!board.revealCell(x, y)) {
                cout << "BOOM! You hit a mine!\n";
                board.display(true);
                gameOver = true;
            }
            else if (board.isWon()) {
                cout << "You won! All safe cells revealed.\n";
                board.display(true);
                gameOver = true;
            }
        }
    }
};
//minesweeper class end
