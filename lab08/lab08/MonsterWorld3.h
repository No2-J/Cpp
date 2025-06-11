#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
#define MAX_MONSTERS 5

class Cell;
class Canvas;
class Monster;
class MonsterWorld;

class Cell {
private:
protected:
	bool hasItem;
	bool hasMonster;
	int score;
	string symbol;
public:
	Cell(bool item = false, bool mon = false, int s = 0, const string& sym = ".") :
		hasItem(item), hasMonster(mon), score(s), symbol(sym) {}
	~Cell() {}

	void setItem(bool val) { hasItem = val; }
	bool isItem() const { return hasItem; }

	void setMonster(bool val) { hasItem = val; }
	bool isMonster() const { return hasMonster; }

	int getScore() const { return score; }
	void setScore(int s) { score = s; }

	void setSymbol(string sy) { symbol = sy; }
	string getSymbol() const { return symbol; }

	void consume() {
		hasItem = false;
		score = 0;
		symbol = ".";
	}
	string draw() const { return hasItem ? symbol : "."; }
};

class Water : public Cell {
private:
protected:
public:
	Water() : Cell(true, false, 2, "~") {}
	~Water() {}
};

class Grass : public Cell {
private:
protected:
public:
	Grass() : Cell(true, false, 3, "-") {}
	~Grass() {}
};

class Fire : public Cell {
private:
protected:
public:
	Fire() : Cell(true, false, 3, "^") {}
	~Fire() {}
};

class Apple : public Cell {
private:
protected:
public:
	Apple() : Cell(true, false, 4, "*") {}
	~Apple() {}
};

class Canvas {
private:
	Cell*** grid;
	int width, height;
public:
	Canvas(int w, int h) : width(w), height(h) {
		grid = new Cell * *[height];
		for (int y = 0;y < height; ++y) {
			grid[y] = new Cell * [width];
		}
	}
	void fillItems() {
		for (int y = 0;y < height;y++) {
			for (int x = 0; x < width; x++) {
				int type = rand() % 4;
				if (type == 0)grid[y][x] = new Water();
				else if (type == 1)grid[y][x] = new Grass();
				else if (type == 2)grid[y][x] = new Fire();
				else grid[y][x] = new Apple();
			}
		}
	}
	~Canvas() {
		for (int y = 0;y < height;y++) {
			for (int x = 0; x < width; x++) {
				delete[] grid[y][x];
			}
			delete[] grid[y];
		}
	}
	bool isInside(int x, int y) const {
		return x >= 0 && x < width && y >= 0 && y < height;
	}
	int getWidth() const { return width; }
	int getHeight() const { return height; }

	Cell* getCell(int x, int y)const {
		return grid[y][x];
	}
};

class Monster {
protected:
	int x, y;
	string name;
	string icon;
	int itemsEaten;
public:
	Monster(const string& na = " ", const string& ic = " ") : name(na), icon(ic), x(0), y(0), itemsEaten(0) {}
	~Monster() {}
	string getIcon() const { return icon; }
	string getName() const { return name; }
	int getX() const { return x; }
	int getY() const { return y; }
	int getItemsEaten() const { return itemsEaten; }

	void setInfo(const string& n, const string& i) {
		name = n;
		icon = i;
	}
	void setPosition(int x0, int y0) {
		x = x0;
		y = y0;
	}
	void eat(Cell* cell) {
		if (cell->isItem()) {
			itemsEaten += cell->getScore();
			cell->consume();
			cell->setMonster(true);
		}
	}
};

class Zombie : public Monster {
public:
	Zombie(const string& na = " ", const string& ic = " ") : Monster(na, ic) {}
	~Zombie() {}

	void move(Canvas& canvas) {
		int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
		int dy[8] = { -1,-1,0,1,1,1,0,-1 };

		int dir = rand() % 8;
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (canvas.isInside(nx, ny) && !canvas.getCell(nx, ny)->isMonster()) {
			canvas.getCell(x, y)->setMonster(false); //clear current position
			x = nx;
			y = ny;
			eat(canvas.getCell(x, y));
		}
	}
};

class Jiangshi : public Monster {
private:
	bool bHori;
public:
	Jiangshi(const string& na = " ", const string& ic = " ", bool h=true)
		: Monster(na, ic), bHori(h) {}
	~Jiangshi() {}
	void move(Canvas& canvas) {
		int nx = x, ny = y;
		int dir = rand() % 2;
		int jump = rand() % 2 + 1;
		if (bHori) nx += ((dir == 0) ? -jump : jump);
		else ny += ((dir == 0) ? -jump : jump);

		if (canvas.isInside(nx, ny) && !canvas.getCell(nx, ny)->isMonster()) {
			canvas.getCell(x, y)->setMonster(false); // clear current position
			x = nx;
			y = ny;
			eat(canvas.getCell(x, y));
		}
	}
};

class Vampire : public Monster {
public:
	Vampire(const string& na = "", const string& ic = " ") : Monster(na, ic) {}
~Vampire(){}
void move(Canvas& canvas) {
	if (rand() % 2 == 0) return;
	int dir = rand() % 4;
	int dx[] = { 1, -1, 0, 0 };
	int dy[] = { 0, 0, 1,-1 };
	int nx = x + dx[dir], ny = y + dy[dir];
	if (canvas.isInside(nx, ny) && !canvas.getCell(nx, ny)->isMonster()) {
		canvas.getCell(x, y)->setMonster(false); // clear current position
		eat(canvas.getCell(nx, ny));
		setPosition(nx, ny);
	}
	}
};

class KGhost : public Monster {
public:
	KGhost(const string& na = " ", const string& ic = "")
		: Monster(na, ic) {}
	~KGhost() {}

	void move(Canvas& canvas) {
		int nx = rand() % canvas.getWidth();
		int ny = rand() % canvas.getHeight();
		if (canvas.isInside(nx, ny) && !canvas.getCell(nx, ny)->isMonster()) {
			canvas.getCell(x, y)->setMonster(false); // clear current position
			eat(canvas.getCell(nx, ny));
			setPosition(nx, ny);
		}
	}
};

class Smart : public Monster {
public:
	Smart(const string& na = " ", const string& ic = "")
		: Monster(na, ic) {
	}
	~Smart() {}
	void move(Canvas& canvas) {
		int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
		int dy[8] = { -1,-1,0,1,1,1,0,-1 };

		int bestX = x, bestY = y;
		int maxScore = 0;

		for (int dir = 0; dir < 8; ++dir) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (canvas.isInside(nx, ny)) {
				Cell* c = canvas.getCell(nx, ny);
				if (c->isItem() && c->getScore() > maxScore) {
					maxScore = c->getScore();
					bestX = nx;
					bestY = ny;
				}
			}
		}

		if (maxScore > 0 && canvas.isInside(bestX, bestY) && !canvas.getCell(bestX, bestY)->isMonster()) {
			canvas.getCell(x, y)->setMonster(false); // clear current position
			x = bestX;
			y = bestY;
			eat(canvas.getCell(x, y));
		}
		else {
			int nx = rand() % canvas.getWidth();
			int ny = rand() % canvas.getHeight();
			if (!canvas.getCell(nx, ny)->isMonster()) {
				canvas.getCell(x, y)->setMonster(false); // clear current position
				x = nx;
				y = ny;
				eat(canvas.getCell(x, y));
			}
		}
	}
};

class MonsterWorld {
private:
	Canvas* canvas;
	Monster** monsters;
	int mCount;
	int maxTurns;
public:
	MonsterWorld(int w = 20, int h = 15, int turns = 50) : maxTurns(turns), mCount(0) {
		canvas = new Canvas(w, h);
		monsters = new Monster * [MAX_MONSTERS];

	}
	~MonsterWorld() {
		delete canvas;
		for (int i = 0; i < mCount; ++i)
			delete monsters[i];
		delete[] monsters;
	}
	void addMonster(Monster* m) {
		int x, y;
		do {
			x = rand() % canvas->getWidth();
			y = rand() % canvas->getHeight();
		} while (canvas->getCell(x, y)->isMonster());

		canvas->getCell(x, y)->setItem(false);
		canvas->getCell(x, y)->setScore(0);
		canvas->getCell(x, y)->setSymbol(".");

		m->setPosition(x, y);
		monsters[mCount++] = m;
	}
	void drawCanvas() const {
		const int ICON_WIDTH = 4;
		for (int y = 0; y < canvas->getHeight(); ++y) {
			for (int x = 0; x < canvas->getWidth(); ++x) {
				bool found = false;
				for (int i = 0; i < mCount; ++i) {
					if (monsters[i]->getX() == x && monsters[i]->getY() == y) {
						cout << left << setw(ICON_WIDTH) << monsters[i]->getIcon();
						found = true;
						break;
					}
				}
				if (!found)
					cout << left << setw(ICON_WIDTH) << canvas->getCell(x, y)->draw();
			}
			cout << "\n";
		}
	}

	void setMonsters() {
		if (mCount > MAX_MONSTERS) return;
		addMonster(new Zombie("Zombie", "Z"));
		addMonster(new Jiangshi("Jiangshi", "J"));
		addMonster(new Vampire("Vampire", "V"));
		addMonster(new KGhost("KGhost", "K"));
		addMonster(new Smart("Smart", "S"));

	}
	void displayMonsterStatus() {


		cout << "\nMonster Status:\n";
		for (int i = 0; i < mCount; ++i) {
			cout << left << setw(4) << monsters[i]->getIcon()
				<< " " << setw(20) << monsters[i]->getName()
				<< " at (" << setw(3) << monsters[i]->getX() << ", " << setw(3) << monsters[i]->getY() << ")"
				<< " | Score: " << setw(10) << monsters[i]->getItemsEaten() << "\n";
		}
	}

	void displayCellStatus() {
		struct CellStat {
			const char* symbol;
			const char* type;
			int scorePerItem;
			int count;
			int totalScore;
		};

		// Define cell types
		CellStat stats[] = {
			{"~", "WaterCell", 2, 0, 0},
			{"-", "GrassCell", 3, 0, 0},
			{"^", "FireCell", 4, 0, 0},
			{"*", "AppleCell", 5, 0, 0}
		};
		const int numTypes = sizeof(stats) / sizeof(stats[0]);

		// Count and total scores
		for (int y = 0; y < canvas->getHeight(); ++y) {
			for (int x = 0; x < canvas->getWidth(); ++x) {
				Cell* cell = canvas->getCell(x, y);
				if (!cell->isItem()) continue;

				const string& sym = cell->getSymbol();
				int score = cell->getScore();

				for (int i = 0; i < numTypes; ++i) {
					if (sym == stats[i].symbol) {
						stats[i].count++;
						stats[i].totalScore += score;
						break;
					}
				}
			}
		}

		// Display summary
		cout << "\nCell Status Summary:\n";
		cout << left << setw(10) << "Symbol"
			<< setw(15) << "Type"
			<< setw(12) << "Score/Item"
			<< setw(10) << "Count"
			<< setw(12) << "Total Score" << "\n";

		cout << string(59, '-') << "\n";

		for (int i = 0; i < numTypes; ++i) {
			cout << left << setw(10) << stats[i].symbol
				<< setw(15) << stats[i].type
				<< setw(12) << stats[i].scorePerItem
				<< setw(10) << stats[i].count
				<< setw(12) << stats[i].totalScore << "\n";
		}
	}


	void run(int wait) {
		int t = 0;
		canvas->fillItems();
		setMonsters();
		cout << "\n \t ---------   Monster World   --------  " << t << "/" << maxTurns << " \n\n";
		drawCanvas();
		displayMonsterStatus();
		displayCellStatus();

		cout << "Press any key.....";
		cin.get();

		for (t = 1; t < maxTurns; ++t) {
			system("cls");

			cout << "\n \t ---------   Monster World   --------  " << t << "/" << maxTurns << " \n\n";

			((Zombie*)monsters[0])->move(*canvas);
			((Jiangshi*)monsters[1])->move(*canvas);
			((Vampire*)monsters[2])->move(*canvas);
			((KGhost*)monsters[3])->move(*canvas);
			((Smart*)monsters[4])->move(*canvas);


			drawCanvas();
			displayMonsterStatus();
			displayCellStatus();

			Sleep(wait);
		}
	}
};