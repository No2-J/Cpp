//Rational.h
#pragma once
#include <iostream>
using namespace std;

class Rational {
private:
	int top;
	int bottom;
	void normalize() {}
	int gcd(int a, int b) { return 0; }
public:
	Rational(int a = 1, int b = 1) : top(a), bottom(b) { normalize(); }
	~Rational() {}

	friend ostream& operator<<(ostream& os, const Rational& f) {
		os << f.top << "/" << f.bottom;
		return os;
	}
	friend istream& operator>>(istream& is, Rational& f) {
		is >> f.top >> f.bottom;
		f.normalize();
		return is;
	}
	// ***************************
	Rational operator++() {
		top += bottom;
		normalize();
		return *this;
	}

	Rational operator++(int) {
		Rational temp = *this;
		top += bottom;
		normalize();
		return temp;
	}
	
	Rational operator--() {
		top -= bottom;
		normalize();
		return *this;
	}

	Rational operator--(int) {
		Rational temp = *this;
		top -= bottom;
		normalize();
		return temp;
	}

	int& operator[](int id) {
		if (id == 0) return top;
		else return bottom; 
	}

	int& operator()(int id) {
		if (id == 0) return top;
		else return bottom;
	}

	operator double() const {
		return static_cast<double>(top) / bottom;
	}

	double toDouble() const {
		return static_cast<double>(top) / bottom;
	}

	bool operator==(const Rational& rhs) const {
		return (top * rhs.bottom == rhs.top * bottom);
	}
	bool operator!=(const Rational& rhs) const {
		return (top * rhs.bottom != rhs.top * bottom);
	}
	bool operator<(const Rational& rhs) const {
		return (top * rhs.bottom < rhs.top * bottom);
	}
	bool operator<=(const Rational& rhs) const {
		return (top * rhs.bottom <= rhs.top * bottom);
	}
	bool operator>(const Rational& rhs) const {
		return (top * rhs.bottom > rhs.top * bottom);
	}
	bool operator>=(const Rational& rhs) const {
		return (top * rhs.bottom >= rhs.top * bottom);
	}
	// ***************************
	Rational operator+(const Rational& rhs)const {
		int t = this->top * rhs.bottom + rhs.top * this->bottom;
		int b = rhs.bottom * this->bottom;

		return Rational(t, b);
	}
	Rational operator-(const Rational& rhs)const {
		int t = this->top * rhs.bottom - rhs.top * this->bottom;
		int b = rhs.bottom * this->bottom;

		return Rational(t, b);
	}
	Rational operator*(const Rational& rhs)const {
		int t = this->top * rhs.top;
		int b = rhs.bottom * this->bottom;

		return Rational(t, b);
	}

	Rational operator/(const Rational& rhs)const {
		int t = this->top * rhs.bottom;
		int b = this->bottom * rhs.top;

		return Rational(t, b);
	}
};