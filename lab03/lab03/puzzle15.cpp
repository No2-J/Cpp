#include "puzzle15.h"
#include "ranking.h"
#define DIM 5

//enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };
static const int Left = 75;
static const int Right = 77;
static const int Up = 72;
static const int Down = 80;

static int DirKey[4] = { Left, Right, Up, Down };
static int map[DIM][DIM];// puzzle map
static int x, y; // pos of the empty slot (row:y, col:x)
static int nMove; // #move
static clock_t tStart; // initial time

static void init() {
	for (int i = 0; i < DIM * DIM - 1; i++)
		map[i / DIM][i % DIM] = i + 1;
	map[DIM - 1][DIM - 1] = 0;
	x = DIM - 1; y = DIM - 1;

	srand((unsigned int)time(NULL));
	tStart = clock();
	nMove = 0;
}
static void display() {
	system("cls");
	cout << "\tFifteen Puzzle\n\t";
	cout << "----------------\n\t";
	for (int r = 0; r < DIM; r++) {
		for (int c = 0; c < DIM; c++) {
			if (map[r][c] > 0)
				cout << setw(3) << map[r][c];
			else cout << "   ";
		}
		cout << "\n\t";
	}
	cout << "--------------\n\t";
	clock_t	t1 = clock();
	double d = (double)(t1 - tStart) / CLOCKS_PER_SEC;
	cout << "\n\t Number of moves " << nMove;
	cout << "\n\t The time takena " << d << "\n\n";

}
static bool move(int dir) {
	if (dir == Right && x > 0) {
		map[y][x] = map[y][x - 1];
		map[y][--x] = 0;
	}
	else if (dir == Left && x < DIM - 1) {
		map[y][x] = map[y][x + 1];
		map[y][++x] = 0;
	}
	else if (dir == Up && y < DIM - 1) {
		map[y][x] = map[y + 1][x];
		map[++y][x] = 0;
	}
	else if (dir == Down && y > 0) {
		map[y][x] = map[y - 1][x];
		map[--y][x] = 0;
	}
	else return false;

	nMove++;
	return true;
}
static void shuffle(int nShuffle) {
	for (int i = 0; i < nShuffle; i++) {
		int key = DirKey[rand() % 4];
		if (move(key) == false) { i--; continue; }
		display();
		Sleep(50);
	}
}
static bool isDone() {
	for (int r = 0; r < DIM; r++) {
		for (int c = 0; c < DIM; c++) {
			if (map[r][c] != r * DIM + c + 1)
				return (r == DIM - 1) && (c == DIM - 1);
		}
	}
	return true;
}
static int getDirKey() { 
	return _getche() == 224 ? _getche() : 0; 
}

int playFifteenPuzzle() {
	init();
	display();
	printRanking();
	cout << "\nSuffle(50) : ";
	shuffle(5);
	cout << "\nUse arrow keys to play the game...";
	cin.ignore();
	nMove = 0;
	tStart = clock();
	while (!isDone()) {
		move(getDirKey());
		display();
	}
	clock_t t1 = clock();
	double t = (double)(t1 - tStart) / CLOCKS_PER_SEC;
	//return addRanking(nMove, t);
	int rank = addRanking(nMove, t);
	cout << "Your rank : " << rank << endl;
	printRanking();
	storeRanking("ranking.txt");
	return addRanking(nMove, t);
}