#include "lab02.h"

static int NumGames = 0;
static int NumWins = 0;
static double Score = 0.0;
static double tElapsed = 0.0;

static bool playGuguOnce() {
	int a = rand() % 8 + 2; //2~9
	int b = rand() % 8 + 2;

	int result;
	NumGames++;
	cout << "[Q.# : " << NumGames << " ]  " << a << " x " << b << " = ";
	cin >> result;
	if (result == a * b) NumWins++;

	return (result == a * b);
}

double speedGugu(int nPlay) {
	clock_t t0 = clock();
	for (int i = 0;i < nPlay;i++) {
		if (playGuguOnce() == false) {
			cout << "Incorrect Answer...\n";
		}
	}
	clock_t t1 = clock();

	tElapsed = (double)(t1 - t0) / CLOCKS_PER_SEC;
	double score = (NumGames > NumWins) ? 0.0 : 100 * (5.0 * NumWins - tElapsed) / (5.0 * NumGames);
	return score;
}

void playGugu() {
	int nPlay = 10;
	//cout << "Enter Number of Games : ";
	//cin >> nPlay;
	cout << "Speed Multiplication Game : \n";
	cout << "Test your Multiplication skills\n";
	cout << "Number of Games : " << nPlay << endl;
	cout << "Take a deep breath.....\n";
	cout << "Press any key to start.....\n";
	cin.ignore();
	system("cls");

	Score = speedGugu(nPlay);
	cout << "Total Score : " << Score 
		<< "\nTime Elapsed : " << tElapsed << endl;

}
/////////////////////////////////////////////////////

int russianRoullete(int nTurns, int nBullets) {
	int start = rand() % nTurns;
	cout << "Game start at " << start + 1 << endl;
	while (true) {
		int pos = rand() % 6;
		cout << "Magazine was tandomly turn in " << start + 1 << endl;
		
		cout << "Enter for Trigger.....";
		cin.ignore();

		if (pos < nBullets) break;
		cout << "You survived....." << endl;
		start = (start + 1) % nTurns;
	}
	cout << "\n\nBang..." << endl;
	return start + 1;
}
void runRussianRoullete() {
	int nTurns, nBullets;
	cout << "Enter Number of Players : ";
	cin >> nTurns;
	cout << "Enter Number of Bullets(1~6) : ";
	cin >> nBullets;

	cin.ignore();

	int bang = russianRoullete(nTurns, nBullets);
	cout << "\n\nNO of Player : " << bang << endl;
}

/////////////////////////////////////////////////////

static int flip() {
	return rand() % 2; //return 0 or 1.
}

void playTossCoin() {
	int hCount = 0, tCount = 0;
	srand(time(NULL));

	for (int loop = 1;loop <= 100;loop++) {
		if (flip()==0) {
			++tCount;
			cout << setw(5) << "T";
		}
		else {
			++hCount;
			cout << setw(5) << "H";
		}
		if (loop % 10 == 0) {
			cout << endl; // Enter line each 10th count
		}
	}

	cout << "Total Heads : " << hCount << endl;
	cout << "Total Tails : " << tCount << endl;
}