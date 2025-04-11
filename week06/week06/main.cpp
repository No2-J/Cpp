#include "week06.h"

void tstComplex1(){
	Complex1 a, b, c;
	a.read("Read A = ");
	b.read("Read A = ");
	c.add(a, b);

	a.print("A = ");
	b.print("A = ");
	c.print("C=A+B = ");
}
void tstComplex2() {}
int main() {
	tstComplex1();
	/*tstCalculator();
	cout << endl;
	tstCalculator2();*/
	return 0;
}