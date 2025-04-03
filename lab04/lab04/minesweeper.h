#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Cell {
	bool isMine = false;
	bool isRevealed = false;
	bool isFlagged = false;
	int adjacentMines = 0;
};

void initializeBoard();
void placeMines();
void calculateAdjacency();
void printBoard(bool revealAll=false);
void revealCell(int , int);
bool checkWin();
bool isValid(int, int);
void playMineSweeper();