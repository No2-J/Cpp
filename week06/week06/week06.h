#pragma once

#include <iostream>
#include <iomanip>
using namespace std;

class Calculator {
private:
	double a = 0.0, b = 0.0;
public:
	void setData(double a1, double a2) { a = a1;b = a2; }
	double add() { return a + b; }
	double sub() { return a - b; }
	double mul() { return a * b; }
	void print() { cout << "A = " << a << ", B = " << b << endl; }
};

void tstCalculator();
void tstCalculator2();


class Complex1 {
private:
	double re = 0.0;
	double im = 0.0;
public:
	void read(const char* msg = " Complex Number ");
	void print(const char* msg = " Complex Number ");
	Complex1 add(Complex1 a, Complex1 b);
};

class Complex2 {
private:
	double re = 0.0;
	double im = 0.0;
public:
	void read(const char* msg = " Complex Number ") {
		cout << msg;
		cin >> re >> im;
	}
	void print(const char* msg = " Complex Number ") {
		cout << msg;
		cout << re << " + " << im << "i" << endl;
	}
	void add(Complex2 a, Complex2 b) {
		Complex2 c;
		c.re = a.re + b.re;
		c.im = a.im + b.im;
	}
};