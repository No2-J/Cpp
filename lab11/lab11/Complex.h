//Complex.h
#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Constructors
    Complex(double r = 1.0, double i = 1.0) : real(r), imag(i) {}
    ~Complex() {}
    double getReal() const { return real; }
    double getImag() const { return imag; }


    // Unary operators
    Complex operator-() const { return Complex(-real, -imag); }
    Complex operator~() const { return Complex(real, -imag); }

    // Basic arithmetic
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        );
    }

    Complex operator*(double scalar) const {
        return Complex(real * scalar, imag * scalar);
    }

    Complex operator/(const Complex& other) const {
        double denom = other.real * other.real + other.imag * other.imag;
        return Complex(
            (real * other.real + imag * other.imag) / denom,
            (imag * other.real - real * other.imag) / denom
        );
    }

    Complex operator/(double scalar) const {
        return Complex(real / scalar, imag / scalar);
    }

    // Compound assignment
    Complex& operator+=(const Complex& other) {
        real += other.real;
        imag += other.imag;
        return *this;
    }

    Complex& operator-=(const Complex& other) {
        real -= other.real;
        imag -= other.imag;
        return *this;
    }

    Complex& operator*=(const Complex& other) {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
        real = r;
        imag = i;
        return *this;
    }

    Complex& operator*=(double scalar) {
        real *= scalar;
        imag *= scalar;
        return *this;
    }

    Complex& operator/=(const Complex& other) {
        double denom = other.real * other.real + other.imag * other.imag;
        double r = (real * other.real + imag * other.imag) / denom;
        double i = (imag * other.real - real * other.imag) / denom;
        real = r;
        imag = i;
        return *this;
    }

    Complex& operator/=(double scalar) {
        real /= scalar;
        imag /= scalar;
        return *this;
    }

    // Comparison
    bool operator==(const Complex& other) const {
        return real == other.real && imag == other.imag;
    }

    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    // Magnitude (modulus) and phase (argument)
    double magnitude() const {
        return sqrt(real * real + imag * imag);
    }

    double phase() const {
        return atan2(imag, real);
    }

    // Friend scalar multiplication
    friend Complex operator*(double scalar, const Complex& c) {
        return Complex(c.real * scalar, c.imag * scalar);
    }

    // Friend I/O stream
    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real << (c.imag >= 0 ? " + " : " - ") << abs(c.imag) << "i";
        return os;
    }

    friend istream& operator>>(istream& is, Complex& c) {
        return is >> c.real >> c.imag;
    }

};

