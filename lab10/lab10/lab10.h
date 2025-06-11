//lab10.h
#pragma once
#include "Matrix.h"
#include "Rational.h"

void tstRational01() {
    Rational r1(5, 15);
    Rational r2(2, 5);

    cout << "Initial values:\n";
    cout << "r1 = " << r1 << "\n";
    cout << "r2 = " << r2 << "\n\n";
    cout << "Enter a Rational num : " << endl;
    cout << "Arithmetic operations:\n";
    cout << "r1 + r2 = " << (r1 + r2) << "\n";
    cout << "r1 - r2 = " << (r1 - r2) << "\n";
    cout << "r1 * r2 = " << (r1 * r2) << "\n";
    cout << "r1 / r2 = " << (r1 / r2) << "\n\n";

}

void tstMatrix03() {
    srand(time(0));

    Matrix A(2,2), B(2,2);

    A.fillMatrix();
    B.fillMatrix();
    cout << "Matrix A:\n" << A;
    cout << "Matrix B:\n" << B;

}

void tstRational04() {
    Rational r1(5, 15);
    Rational r2(2, 5);
    double d = r1;
    cout << "Accessors:\n";
    cout << "r1[0] = " << r1[0] << ", r1[1] = " << r1[1] << "\n";
    cout << "r2(0) = " << r2(0) << ", r2(1) = " << r2(1) << "\n\n";

    cout << "Conversion to double:\n";
    cout << "r1 as double: " << d << "\n";
    cout << "r2.toDouble(): " << r1.toDouble() << "\n\n";

    cout << "Input test (enter numerator and denominator): ";
    Rational r5;
    cin >> r5;
    cout << "You entered: " << r5 << "\n";
}

void tstRational03() {
    Rational r1(5, 15);
    Rational r2(2, 5);
    cout << "Comparison operations:\n";
    cout << "r1 == r2? " << (r1 == r2) << "\n";
    cout << "r1 != r2? " << (r1 != r2) << "\n";
    cout << "r1 < r2?  " << (r1 < r2) << "\n";
    cout << "r1 > r2?  " << (r1 > r2) << "\n";
    cout << "r1 <= r2? " << (r1 <= r2) << "\n";
    cout << "r1 >= r2? " << (r1 >= r2) << "\n\n";
}

void tstRational02() {
    Rational r1(5, 15);
    Rational r2(2, 5);
    cout << "Increment operations:\n";
    Rational r3 = r1;
    cout << "++r3 = " << ++r3 << "\n";   // Prefix
    Rational r4 = r1;
    cout << "r4++ = " << r4++ << " (before), " << r4 << " (after)\n\n"; // Postfix

    cout << "Decrement operations:\n";
    Rational r5 = r1;
    cout << "--r5 = " << --r5 << "\n";   // Prefix
    Rational r6 = r1;
    cout << "r6-- = " << r6-- << " (before), " << r6 << " (after)\n\n"; // Postfix

}

void tstMatrix02() {

    srand(time(0));

    Matrix A(3, 3), B(3, 3);

    cout << "Enter elements(rational numbers) for Matrix A" << endl;
    cin >> A;
    cout << "Enter elements(rational numbers) for Matrix B" << endl;
    cin >> B;

    cout << "Matrix A:\n" << A;
    cout << "Matrix B:\n" << B;

    Matrix C = A + B;
    cout << "A + B:\n" << C;

    Matrix D = A * B;
    cout << "A * B:\n" << D;

    Matrix E = A * Rational(2, 3);
    cout << "A * (2/3):\n" << E;

}

void tstMatrix01() {

    srand(time(0));

    Matrix A(3, 3), B(3, 3);
    A.fillMatrix();
    B.fillMatrix();

    cout << "Matrix A:\n" << A;
    cout << "Matrix B:\n" << B;

    Matrix C = A + B;
    cout << "A + B:\n" << C;

    Matrix D = A * B;
    cout << "A * B:\n" << D;

    Matrix E = A * Rational(2, 3);
    cout << "A * (2/3):\n" << E;

}
