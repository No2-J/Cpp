#pragma once
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <Windows.h>
#include <string>
#define MAX_MONSTERS 5

using namespace std;

class Cell;
class Canvas;
class Monster;
class MonsterWorld;

// --------------------- Cell ---------------------
class Cell {
private:
    bool hasMonster;
    bool hasItem;
public:
    Cell() : hasMonster(false), hasItem(false) {}

    void placeMonster() { hasMonster = true; }
    void removeMonster() { hasMonster = false; }
    bool isMonster() const { return hasMonster; }

    void placeItem() { hasItem = true; }
    void removeItem() { hasItem = false; }
    bool isItem() const { return hasItem; }

    const string display() const {
        if (hasItem) return "*";
        return ".";
    }
};

// --------------------- Canvas ---------------------
class Canvas {
private:
    Cell** grid;
    int width, height;
public:
    Canvas(int w, int h)
        : grid(nullptr), width(w), height(h) {
        grid = new Cell * [height];
        for (int i = 0;i < height;i++) {
            grid[i] = new Cell[width];
        }
        fillItems();
    }
    Canvas(const Canvas& c):width(c.width), height(c.height) {
        grid = new Cell * [height];
        for (int i = 0;i < height;i++) {
            grid[i] = new Cell[width];
        }

        for (int i = 0; i < height;i++) {
            for (int j = 0; j < width;j++) {
                this->grid[i][j] = c.grid[i][j];
            }
        }
    }
    ~Canvas() {
        for (int i = 0; i < height;i++) {
            delete[] grid[i];
        }
        delete[] grid;
    }
    void fillItems() {
        for (int y = 0; y < height; ++y)
            for (int x = 0; x < width; ++x)
                grid[y][x].placeItem();
    }

    void draw(string icons[], int positions[][2], int monsterCount) const {
        const int ICON_WIDTH = 5;

        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                bool found = false;
                for (int i = 0; i < monsterCount; ++i) {
                    if (positions[i][0] == x && positions[i][1] == y) {
                        cout << left << setw(ICON_WIDTH) << icons[i];
                        found = true;
                        break;
                    }
                }

                if (!found)
                    cout << left << setw(ICON_WIDTH) << grid[y][x].display();
            }
            cout << "\n";
        }
    }

    Cell& getCell(int x, int y) {
        return grid[y][x];
    }

    int getWidth() const { return width; }
    int getHeight() const { return height; }
};


// --------------------- Monster ---------------------
class Monster {
private:
    int x, y;
    string name;
    string icon;
    int itemsEaten;

public:
    Monster() : x(0), y(0), itemsEaten(0), name("Monster"), icon(" ") {}

    void setPosition(int x0, int y0) { x = x0; y = y0; }
    void setInfo(const string& n, const string& i) {
        name = n;
        icon = i;
    }

    string getName() const { return name; }
    string getIcon() const { return icon; }
    int getX() const { return x; }
    int getY() const { return y; }
    int getItemsEaten() const { return itemsEaten; }

    void move(Canvas& canvas, Monster monsters[], int count) {
        int dx[] = { 0, 1, 0, -1 };
        int dy[] = { -1, 0, 1, 0 };
        int dir = rand() % 4;
        int newX = x + dx[dir];
        int newY = y + dy[dir];

        if (newX < 0 || newX >= canvas.getWidth() || newY < 0 || newY >= canvas.getHeight())
            return;

        for (int i = 0; i < count; ++i)
            if (monsters[i].getX() == newX && monsters[i].getY() == newY)
                return;

        canvas.getCell(x, y).removeMonster();
        x = newX;
        y = newY;
        if (canvas.getCell(x, y).isItem()) {
            canvas.getCell(x, y).removeItem();
            itemsEaten++;
        }
        canvas.getCell(x, y).placeMonster();
    }
};

// --------------------- MonsterWorld ---------------------
class MonsterWorld {
private:
    Canvas* canvas;
    Monster* monsters;
    int monsterCount;
    int maxTurns;
public:
    MonsterWorld(int turns, int width , int height)
        :monsterCount(0), maxTurns(turns) {
        canvas = new Canvas(height, width);
        monsters = new Monster[MAX_MONSTERS];
        srand((unsigned)time(0));
    }
    ~MonsterWorld() {
        delete canvas;
        delete[] monsters;
    }
    bool addMonster(const string& name, const string& icon) {
        if (monsterCount >= MAX_MONSTERS) return false;

        int x, y;
        do {
            x = rand() % canvas->getWidth();
            y = rand() % canvas->getHeight();
        } while (canvas->getCell(x, y).isMonster());

        monsters[monsterCount].setPosition(x, y);
        monsters[monsterCount].setInfo(name, icon);
        canvas->getCell(x, y).placeMonster();
        monsterCount++;
        return true;
    }

    void display(int turn) {
        string icons[MAX_MONSTERS];
        int pos[MAX_MONSTERS][2];
        for (int i = 0; i < monsterCount; ++i) {
            icons[i] = monsters[i].getIcon();
            pos[i][0] = monsters[i].getX();
            pos[i][1] = monsters[i].getY();
        }

        system("cls");
        cout << "\n\n\t\t\t Welcome to Monster World :\n\n";
        canvas->draw(icons, pos, monsterCount);

        cout << "\n\n \t\t\tSummary (Turn " << turn << "/" << maxTurns << "):\n\n";

        for (int i = 0; i < monsterCount; ++i) {
            cout << left << setw(3) << monsters[i].getIcon() << " " << left << setw(15) << monsters[i].getName()
                << " | Eaten: " << left << setw(6) << monsters[i].getItemsEaten()
                << " | Position: (" << monsters[i].getX() << "," << monsters[i].getY() << ")\n";
        }


    }

    void play(int wait) {



        /*addMonster("Lobster", "🦞");
        addMonster("Goblin", "👺");
        addMonster("Ghost", "👻");
        addMonster("Skull", "☠️");
        addMonster("Alien", "👽");*/

        
        addMonster("Lobster", "L");
        addMonster("Goblin", "B");
        addMonster("Ghost", "G");
        addMonster("Skull", "S");
        addMonster("Alien", "A");
        

        display(0);
        cout << "\nPress Enter to start ...";
        cin.get();

        for (int t = 1; t <= maxTurns; ++t) {
            for (int i = 0; i < monsterCount; ++i) {
                monsters[i].move(*canvas, monsters, monsterCount);
            }
            display(t);
            Sleep(wait);
        }
    }
};