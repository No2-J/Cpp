//lab.h
#pragma once
#include "Matrix.h"
#include "Rational.h"
#include "Complex.h"
#include <iostream>
#include <ctime>
#include "Shape.h"
using namespace std;

void tstMatrix01() {
    Matrix<int> A(2, 2), B(2, 2);
    A.fillMatrix();
    B.fillMatrix();

    cout << "Matrix A:\n" << A;
    cout << "Matrix B:\n" << B;

    Matrix<int> C = A + B;
    cout << "A + B:\n" << C;

    Matrix<int> D = A * B;
    cout << "A * B:\n" << D;

    int  r = 10;
    Matrix<int> E = A * r;
    cout << "A * r:\n" << E;

}

void tstMatrix02() {
    Matrix<double> A(2, 2), B(2, 2);
    A.fillMatrix();
    B.fillMatrix();

    cout << "Matrix A:\n" << A;
    cout << "Matrix B:\n" << B;

    Matrix<double> C = A + B;
    cout << "A + B:\n" << C;

    Matrix<double> D = A * B;
    cout << "A * B:\n" << D;

    double r = 2.5;
    Matrix<double> E = A * r;
    cout << "A * r:\n" << E;

}

void tstMatrix03() {
    Matrix<Complex> A(3, 3), B(3, 3);
    A.fillMatrix();
    B.fillMatrix();

    cout << "Matrix A:\n" << A;
    cout << "Matrix B:\n" << B;

    Matrix<Complex> C = A + B;
    cout << "A + B:\n" << C;

    Matrix<Complex> D = A * B;
    cout << "A * B:\n" << D;

    Complex r(2.3, 3.5);
    Matrix<Complex> E = A * r;
    cout << "A * r:\n" << E;

}

void tstMatrix04() {
    Matrix<Rational> A(2, 2), B(2, 2);
    //A.fillMatrix();
    //B.fillMatrix();

    cout << "Enter Matrix : ";
    cin >> A;
    cin >> B;

    cout << "Matrix A:\n" << A;
    cout << "Matrix B:\n" << B;

    Matrix<Rational> C = A + B;
    cout << "A + B:\n" << C;

    Matrix<Rational> D = A * B;
    cout << "A * B:\n" << D;

    Rational r(2, 3);
    Matrix<Rational> E = A * r;
    cout << "A * (2/3):\n" << E;

}
void tstPoint() {
    Point<int> p1(3, 4), p2(1, 2);
    cout << "p1 = " << p1 << ", p2 = " << p2 << endl;
    cout << "p1 + p2 = " << (p1 + p2) << " \n";
    cout << "p1 - p2 = " << (p1 - p2) << " \n";
    cout << "2.0 * p1 = " << (2.0 * p1) << " \n";

    Point<double> d1(1.5, 2.5), d2(0.5, 1.0);
    cout << "d1 = " << d1 << ", d2 = " << d2 << endl;
    cout << "d1 + d2 = " << (d1 + d2) << "\n";
    cout << "d1 - d2 = " << (d1 - d2) << " \n";
    cout << "3.0 * d2 = " << (3.0 * d2) << " \n";
}
void tstShape() {
    using T = double;

    Point<T> A(1.0, 2.0);
    Point<T> B(4.0, 6.0);
    Point<T> C(7.0, 3.0);
    Point<T> D(1.0, 6.0);
    Point<T> E(4.0, 2.0);

    Circle<T> circle(A, 3.5);
    Line<T> line(A, B);
    Rectangle<T> rectangle(D, E);
    Triangle<T> triangle(A, B, C);
    Rectangle<T> square(Point<T>(0, 0), Point<T>(2, 2)); // Simulate a square

    Shape<T>* shapes[5] = { &circle, &line, &rectangle, &triangle, &square };

    cout << "Shapes :\n";
    for (int i = 0; i < 5; ++i) {
        cout << *shapes[i] << endl;
    }
}