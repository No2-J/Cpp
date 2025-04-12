#pragma once
#include<iostream>
#include<iomanip>
#include<ctime>
#include<conio.h>
#include<string>
using namespace std;
const int SIZE = 5;
const int NUM_SHIPS = 3;
class Ship;
class Board;
class Player;
class BattleShip; //클래스 4개

class Ship {
private:
    int x, y;
    bool sunk; //데이터 멤버
public:
    void init() { x = 0; y = 0; sunk = false; }
    void placeAt(int x1, int y1) { x = x1; y = y1; sunk = false; }
    bool isAt(int x1, int y1) const { return x == x1 && y == y1 && !sunk; }
    void sink() { sunk = true; }
    bool isSunk() const { return sunk; }
    int getX() const { return x; }
    int getY() const { return y; }

};
//Ship class end

class Board {
private:
    char grid[SIZE][SIZE];
    Ship ships[NUM_SHIPS];
public:
    void init() { 
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                grid[i][j] = '~';
        for (int i = 0; i < NUM_SHIPS; ++i)
            ships[i].init();
    }
    void placeShip(int index, int x, int y) {
        if (index >= 0 && index < NUM_SHIPS)
            ships[index].placeAt(x, y);
    }
    bool isPlaced(int x, int y) const {
        for (int i = 0; i < NUM_SHIPS; ++i)
            if (ships[i].getX() == x && ships[i].getY() == y)
                return true;
        return false;
    }
    bool isAttacked(int x, int y) const {
        return grid[y][x] == 'X' || grid[y][x] == 'O';
    }
    void markHit(int x, int y, bool hit) {
        grid[y][x] = hit ? 'X' : 'O';
    }
    bool allSunk() const {
        for (int i = 0; i < NUM_SHIPS; ++i)
            if (!ships[i].isSunk()) return false;
        return true;
    }
    bool checkHit(int x, int y) {
        for (int i = 0; i < NUM_SHIPS; ++i) {
            if (ships[i].isAt(x, y)) {
                ships[i].sink();
                return true;
            }
        }
        return false;
    }
    void display(bool hideShips) const {
        cout << "  ";
        for (int i = 0; i < SIZE; ++i) cout << i << " ";
        cout << "\n";
        for (int y = 0; y < SIZE; ++y) {
            cout << y << " ";
            for (int x = 0; x < SIZE; ++x) {
                char ch = grid[y][x];
                bool showS = false;
                for (int i = 0; i < NUM_SHIPS; ++i) {
                    if (!ships[i].isSunk() && ships[i].getX() == x && ships[i].getY() == y)
                        showS = true;
                }
                if (!hideShips && showS)
                    cout << "S ";
                else
                    cout << ch << " ";
            }
            cout << "\n";
        }
    }

};

class Player {
private:
    string name;
    bool isCPU;
    Board board;
public:
    void init(const string& pName, bool cpu) {
        name = pName;
        isCPU = cpu;
        board.init();
    }
    void placeShips() {
        cout << name << ", placing ships...\n";
        for (int i = 0; i < NUM_SHIPS; ++i) {
            int x, y;
            if (isCPU) {
                do {
                    x = rand() % SIZE;
                    y = rand() % SIZE;
                } while (board.isPlaced(x, y));
                board.placeShip(i, x, y);
            }
            else {
                cout << "Enter location for Ship #" << (i + 1) << " (x y): ";
                cin >> x >> y;
                while (x < 0 || x >= SIZE || y < 0 || y >= SIZE || board.isPlaced(x, y)) {
                    cout << "Invalid or duplicate. Try again: ";
                    cin >> x >> y;
                }
                board.placeShip(i, x, y);
            }
        }
    }
    bool attack(Player& opponent) {
        int x, y;
        if (isCPU) {
            do {
                x = rand() % SIZE;
                y = rand() % SIZE;
            } while (opponent.board.isAttacked(x, y));
            cout << name << " attacks (" << x << ", " << y << ")\n";
        }
        else {
            cout << name << ", enter attack coordinates (x y): ";
            cin >> x >> y;
            while (x < 0 || x >= SIZE || y < 0 || y >= SIZE || opponent.board.isAttacked(x, y)) {
                cout << "Invalid or already attacked. Try again: ";
                cin >> x >> y;
            }
        }
        bool hit = opponent.board.checkHit(x, y);
        opponent.board.markHit(x, y, hit);
        if (hit)
            cout << name << " hit a ship!\n";
        else
            cout << name << " missed.\n";
        return opponent.board.allSunk();
    }
    void showOwnBoard() const {
        cout << name << "'s Board:\n";
        board.display(false);
    }
    void showOpponentBoard() const {
        cout << "Opponent's Board:\n";
        board.display(true);
    }
    bool isLost() const {
        return board.allSunk();
    }
    string getName() const {
        return name;
    }

};

class BattleShip {
private:
    Player player;
    Player cpu;
public:
    void init() {
        player.init("Player", false);
        cpu.init("my Cmputer", true);
        player.placeShips();
        cpu.placeShips();
    }
    void play() {
        int turn = 1;
        while (!player.isLost() && !cpu.isLost()) {
            cout << "\n? Turn " << turn << " ?\n";
            player.showOwnBoard();
            cpu.showOpponentBoard();
            if (player.attack(cpu)) break;
            if (cpu.attack(player)) break;
            ++turn;
        }
        cout << "\n=== Final Boards ===\n";
        player.showOwnBoard();
        cpu.showOwnBoard();
        if (player.isLost())
            cout << "\n " << player.getName() << " lost! CPU wins.\n";
        else
            cout << "\n " << player.getName() << " wins! All CPU ships destroyed!\n";
    }

};