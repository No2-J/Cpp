#include "week03.h"

void callline() {
    srand((unsigned)time(NULL));
    cout << " coin\tdice\tLChar\tUChar\tNum\n";
    for (int i = 0; i < 6; i++) {
        //cout << "\t"<< (randCoin() == 0 ? "head" : "tail") ;

        /*cout << randDice() << "\t";
        cout << randLChar() << "\t";
        cout << randUChar() << "\t";
        cout << randNum() << endl;*/

        if (randCoin() == 0)

            cout << "\t" << setw(5) << "head";
        else
            cout << setw(5) << "tail";
        cout << "\t" << setw(5) << randDice();
        cout << "\t" << setw(5) << randLChar();
        cout << "\t" << setw(5) << randUChar();
        cout << "\t" << setw(5) << randNum();
        cout << endl;
    }
}
int main() {
    callline();
	return 0;
}