#pragma once

#include <iostream>  // Needed to use I/O functions
#include <limits>    // integer limits
#include <iomanip>   // needed for formatting floating-point numbers
#include <string>    // use string class
#include <time.h>
using namespace std;

const int PI = 3.14159265;
#define SQUARE(x) x*x     // Macro with argument

// inline functions
inline int square(int x) { return x * x; }
inline int randCoin() { return rand() % 2; }
inline int randDice() { return rand() % 6 + 1; }
inline char randLChar() { return rand() % 24 + 'a'; }
inline char randUChar() { return rand() % 24 + 'A'; }
inline char randNum() { return rand() % 10 + '0'; }



void charString();        // C++ char based strings
void stringIO();          // string class input and output 
void stringOperations();  // C++ string function
void mathFunctions();     // math functions

double getArea(double);
void callGetArea();
void randomNumbers();
void inlineMacro();       // Inline Function vs. #define Macro
int add(int, int);
float add(float, float);
double add(double, double);
void callOverloaded();
bool isOdd(int); // boolean function

int fun1(int = 1, int = 2, int = 3);
int fun2(int, int, int = 3);
void callDefault();
