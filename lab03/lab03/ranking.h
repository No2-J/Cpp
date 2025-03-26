#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct PlayInfo {
	char name[20] = "ABC";
	int nMove = 1000;
	double tElapsed = 1000.0;
};

void loadRanking(const string);
void storeRanking(const string);
void printRanking();
int addRanking(int nMove, double tElapsed);