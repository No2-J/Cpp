#include "ranking.h"
#define NUM_MVP 5
static PlayInfo MVP[NUM_MVP];
static int nMVP = NUM_MVP;

void printRanking() {
	cout << fixed << setprecision(2);
	for (int i = 0; i < nMVP; i++)
		cout << i + 1 << "\t" << MVP[i].name << "\t" << MVP[i].nMove << "\t" << MVP[i].tElapsed << endl;
}


void loadRanking(const string fname) {
	ifstream fin;
	fin.open(fname, ios::in);  // default mode ios::in
	if (fin) {
		string line;
		int count = 0;
		while (getline(fin, line)) {
			istringstream ss(line);
			ss >> MVP[count].name >> MVP[count].nMove >> MVP[count].tElapsed;
			count++;
		}
		cout << "Number of records read from file : " << count << '\n';
	}

	else
	{
		cerr << "error: open file for output failed!" << endl;
		abort();
	}
	fin.close();
}

void storeRanking(const string fname) {
	ofstream fout;
	fout.open(fname, ios::out);
	if (fout) {
		for (int i = 0; i < nMVP; i++)
			fout << MVP[i].name << ' '
			<< MVP[i].nMove << ' '
			<< MVP[i].tElapsed << endl;
		fout.close();
	}
	else {
		cerr << "error: open file for output failed!" << endl;
		abort();
	}


}

int addRanking(int nMove, double tElap) {
	if (nMove < MVP[nMVP - 1].nMove) {
		int pos = nMVP - 1;
		for (; pos > 0; pos--) {
			if (nMove >= MVP[pos - 1].nMove) break;
			MVP[pos] = MVP[pos - 1];
		}
		MVP[pos].nMove = nMove;
		MVP[pos].tElapsed = tElap;
		cout << "Name at :  " << pos + 1 << "  ";
		cin >> MVP[pos].name;
		return pos + 1;
	}
	return 0;
}