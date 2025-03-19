#include <iostream>
using namespace std;

extern int var=100;
extern void displayVar() {
	cout << "Variable Value = " << var << endl;
}
