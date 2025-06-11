//Rational.h
#pragma once
#include <iostream>
using namespace std;

class Rational {
    int top;     // numerator
    int bottom;  // denominator

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void normalize() {
        if (bottom == 0) {
            cerr << "Error: Denominator cannot be zero.\n";
            exit(1);
        }
        int g = gcd(abs(top), abs(bottom));
        top /= g;
        bottom /= g;
        if (bottom < 0) {
            top = -top;
            bottom = -bottom;
        }
    }

public:
    Rational(int t = 1, int b = 1) : top(t), bottom(b) {
        normalize();
    }
    ~Rational() {}

    // Prefix ++
    Rational& operator++() {
        top += bottom;
        return *this;
    }

    // Postfix ++
    Rational operator++(int) {
        Rational temp = *this;
        top += bottom;
        return temp;
    }

    // Prefix --
    Rational& operator--() {
        top -= bottom;
        return *this;
    }

    // Postfix --
    Rational operator--(int) {
        Rational temp = *this;
        top -= bottom;
        return temp;
    }

    double toDouble() const {
        return  (double)(top) / bottom;
    }
    operator double() const {
        return (double)(top) / bottom;
    }

    // Accessors using operator[]
    int& operator[](int id) {
        if (id == 0) return top;
        else if (id == 1) return bottom;
        else {
            cerr << "Error: Invalid index. Use 0 for numerator, 1 for denominator.\n";
            exit(1);
        }
    }

    int& operator()(int id) {
        return (*this)[id];
    }

    friend ostream& operator<<(ostream& os, const Rational& f) {
        os << f.top << "/" << f.bottom;
        return os;
    }

    friend istream& operator>>(istream& is, Rational& f) {
        is >> f.top >> f.bottom;
        if (f.bottom == 0) {
            cerr << "Error: Denominator cannot be zero.\n";
            exit(1);
        }
        f.normalize();
        return is;
    }



    // Arithmetic operators
    Rational operator+(const Rational& rhs) const {
        int num = top * rhs.bottom + rhs.top * bottom;
        int den = bottom * rhs.bottom;
        return Rational(num, den);
    }

    Rational operator-(const Rational& rhs) const {
        int num = top * rhs.bottom - rhs.top * bottom;
        int den = bottom * rhs.bottom;
        return Rational(num, den);
    }

    Rational operator*(const Rational& rhs) const {
        return Rational(top * rhs.top, bottom * rhs.bottom);
    }

    Rational operator/(const Rational& rhs) const {
        if (rhs.top == 0) {
            cerr << "Error: Division by zero rational number.\n";
            exit(1);
        }
        return Rational(top * rhs.bottom, bottom * rhs.top);
    }

    // Comparison operators
    bool operator==(const Rational& rhs) const {
        return (top == rhs.top && bottom == rhs.bottom);
    }

    bool operator!=(const Rational& rhs) const {
        return !(*this == rhs);
    }

    bool operator<(const Rational& rhs) const {
        return top * rhs.bottom < rhs.top * bottom;
    }

    bool operator<=(const Rational& rhs) const {
        return top * rhs.bottom <= rhs.top * bottom;
    }

    bool operator>(const Rational& rhs) const {
        return top * rhs.bottom > rhs.top * bottom;
    }

    bool operator>=(const Rational& rhs) const {
        return top * rhs.bottom >= rhs.top * bottom;
    }
};

