#include "week06.h"

void tstCalculator() {
	Calculator c1;
	c1.setData(4.5, 9.1);
	c1.print();

	cout << "Addition : " << c1.add() << endl;
	cout << "Subtraction : " << c1.sub() << endl;
	cout << "Multiplication : " << c1.mul() << endl;
}

void tstCalculator2() {
	Calculator c1;
	Calculator* ptrC1 = &c1;

	ptrC1->print();
	ptrC1->setData(4.5, 9.1);
	ptrC1->print();

	cout << "Addition : " << ptrC1->add() << endl;
	cout << "Subtraction : " << ptrC1->sub() << endl;
	cout << "Multiplication : " << ptrC1->mul() << endl;
}

void Complex1::read(const char* msg = "Complex Number") {
	cout << msg;
	cin >> re >> im;
}

void Complex1::print(const char* msg = " Complex Number ") {
	cout << msg;
	cout << re << " + " << im << "i" << endl;
}

void Complex1::add(Complex1 a, Complex1 b) {
	re = a.re + b.re;
	im = a.im + b.im;
}
