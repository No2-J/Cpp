#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

const int SIZE = 5;
const int SHIPS = 3;
const char SHIP = 'S', HIT = 'X', MISS = 'o', EMPTY = '~';

struct Player {
	char board[SIZE][SIZE];
	char display[SIZE][SIZE];

	void initialize();
	void printBoard(bool hideShips = false);
	void placeShips(bool isPlayer);
	bool attack(Player& opponent, int r, int c);
	bool isGameOver();
};
struct CPU {
	char board[SIZE][SIZE];
	char display[SIZE][SIZE];

	void initialize();
	void printBoard(bool hideShips = false);
	void placeShips(bool isPlayer);
	bool attack(Player& opponent, int r, int c);
	bool isGameOver();
};
