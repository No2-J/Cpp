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
    bool isMine, isRevealed, isFlagged;
    int adjMines;
public:
    void init() {
        isMine = false;
        isRevealed = false;
        isFlagged = false;
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
    void toggleFlag(){
        if (!isRevealed) // ÀÌ¹Ì ¿­¸° Ä­¿¡´Â ±ê¹ß ¸ø ²È°Ô
            isFlagged = !isFlagged;
    }
    bool mine() const { return isMine; }
    bool flagged() const { return isFlagged; }
    bool revealed() const { return isRevealed; }
    int getAdjMines() const { return adjMines; }
};

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
    void flagCell(int r, int c) {
        if (isValid(r, c))
            grid[r][c].toggleFlag();
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
                else if (grid[i][j].flagged()) {
                    cout << "F ";
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

class MineSweeper {
private:
    Panel board;
    Cell grid[DIM][DIM];
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
            char action;
            cout << "Enter coordinates to reveal (r r c), (f r c) : ";
            cin >> action >> x >> y;
            if (action == 'r') {
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
            else if (action == 'f') {
                board.flagCell(x, y);
            }
        }
    }
};