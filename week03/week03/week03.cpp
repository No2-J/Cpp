#include "week03.h"

void randomNumbers() {
    srand((unsigned)time(NULL));
    cout << " coin\tdice\tLChar\tUChar\tNum\n";
    for (int i = 0; i < 6; i++) {
        cout << (randCoin() == 0 ? "head" : "tail") << "\t";
        cout << randDice() << "\t";
        cout << randLChar() << "\t";
        cout << randUChar() << "\t";
        cout << randNum() << endl;
    }

}

void charString() {
    char str1[4] = "C++";
    char str2[] = { 'C','+','+','\0' };
    char str3[4] = { 'C','+','+','\0' };

    printf("%s\n", str1);
    printf("%s\n", str2);
    printf("%s\n", str3);

    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;



    char str[100];
    printf("Enter a string: \n");
    scanf_s("%s", str, sizeof(str));
    printf("You entered: %s \n", str);

    cout << "Enter a string: ";
    cin.get(str, 100);
    cout << "You entered: " << str << endl;

    cout << "Enter a string: ";
    cin >> str;
    cout << "You entered: " << str << endl;




}
void stringIO() {
    string message("Hello");
    cout << message << endl;

    // Input a word (delimited by space) into a string
    cout << "Enter a message (no space): ";
    cin >> message;
    cout << message << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // flush cin up to newline (need <limits> header)

 // Input a line into a string
    cout << "Enter a message (with spaces): ";
    getline(cin, message);  // Read input from cin into message
    cout << message << endl;
}

void stringOperations() {
    string msg = "Game Over!";
    cout << msg << endl;
    cout << msg.length() << endl;  // length of string
    cout << msg.at(1) << endl;     // char at index 1
    cout << msg[1] << endl;        // same as above
    cout << msg.empty() << endl;   // test for empty string
    cout << msg.substr(3, 3) << endl; // sub-string begins at
    // pos 3 of size 3
    cout << msg.replace(3, 3, "why") << endl; // replace sub-string
    cout << msg.append("end") << endl;        // append behind
    cout << msg + "end" << endl;              // same as above
    cout << msg.insert(3, "insert") << endl;  // insert after pos 3

    string msg1;
    msg1 = msg;   // copy
    cout << msg1 << endl;

    cout << "Enter a line: ";
    getline(cin, msg);   // read a line of input
    cout << msg << endl;
}




void inlineMacro() {
    cout << SQUARE(5) << endl;  // expand to 5*5 (25)
    int x = 2, y = 3;
    cout << SQUARE(x) << endl;  // expand to x*x (4)

    // Problem with the following macro expansions
    cout << SQUARE(5 + 5) << endl;   // expand to 5+5*5+5 - wrong answer
    cout << square(5 + 5) << endl;   // Okay square(10)
    cout << SQUARE(x + y) << endl;   // expand to x+y*x+y - wrong answer
    cout << square(x + y) << endl;   // Okay
    // can be fixed using #define SQUARE(x) (x)*(x)

    cout << SQUARE(++x) << endl;   // expand to ++x*++x (16) - x increment twice
    cout << x << endl;             // x = 4
    cout << square(++y) << endl;   // Okay ++y, (y*y) (16)
    cout << y << endl;             // y = 4
}

void mathFunctions() {
    double x = 2.3;
    double y = 0.25;
    int z = -10;
    cout << "Sine value of x=2.3 : " << sin(x) << endl;
    cout << "Cosine value of x=2.3 : " << cos(x) << endl;
    cout << "Tangent value of x=2.3 : " << tan(x) << endl;
    cout << "Square root value of y=0.25 : " << sqrt(y) << endl;
    cout << "Absolute value of z=-10 : " << abs(z) << endl;
    cout << "Power value: x^y = (2.3^0.25) : " << pow(x, y) << endl;
    cout << "Hypotenuse having other two sides as x and" << " y: " << hypot(x, y) << endl;
    cout << "Floor value of x=4.56 is : " << floor(x) << endl;
    x = -4.57;
    cout << "Absolute value of x=-4.57 is : " << fabs(x) << endl;
    x = 1.0;
    cout << "Arc Cosine value of x=1.0 : " << acos(x) << endl;
    cout << "Arc Sine value of x=1.0 : " << asin(x) << endl;
    cout << "Arc Tangent value of x=1.0 : " << atan(x) << endl;
    y = 12.3;
    cout << "Ceiling value of y=12.3 : " << ceil(y) << endl;
    x = 57.3; // in radians
    cout << "Hyperbolic Cosine of x=57.3 : " << cosh(x) << endl;
    cout << "Hyperbolic tangent of x=57.3 : " << tanh(x) << endl;
    y = 100.0;
    cout << "Log value of y=100.0 is : " << log(y) << endl;     // Natural base with 'e'
}

double getArea(double radius) {
    return radius * radius * PI;
}

void callGetArea() {
    double radius1 = 1.1, area1, area2;

    area1 = getArea(radius1); // call function getArea()
    cout << "area 1 is " << area1 << endl;

    area2 = getArea(2.2); // call function getArea()
    cout << "area 2 is " << area2 << endl;

    cout << "area 3 is " << getArea(3.3) << endl; // call function getArea()

}

int add(int a, int b) {
    int sum;
    sum = a + b;
    return sum;
}
float add(float a, float b) {
    return a + b;
}
double add(double a, double b) {
    return a + b;
}
void callOverloaded() {
    int r1 = add(1, 2);
    float r2 = add(5.8, 1.6);
    double r3 = add(1.3, 2.5);
    cout << " Result r1 = " << r1 << endl;
    cout << " Result r2 = " << r2 << endl;
    cout << " Result r3 = " << r3 << endl;
}

bool isOdd(int number) {
    if (number % 2 == 1) {
        return true;
    }
    else {
        return false;
    }
}
/*
bool isEven(int number) {
    return (number % 2 == 0);
}

bool isOdd(int number) {
    return !(number % 2 == 0);  // OR return !isEven(number);
}
*/


int fun1(int n1, int n2, int n3) {
    // cannot repeat default arguments in function definition
    return n1 + n2 + n3;
}

int fun2(int n1, int n2, int n3) {
    return n1 + n2 + n3;
}

void callDefault() {
    cout << fun1(4, 5, 6) << endl; // No default
    cout << fun1(4, 5) << endl;    // 4, 5, 3(default)
    cout << fun1(4) << endl;       // 4, 2(default), 3(default)
    cout << fun1() << endl;        // 1(default), 2(default), 3(default)

    cout << fun2(4, 5, 6) << endl; // No default
    cout << fun2(4, 5) << endl;    // 4, 5, 3(default)
    // cout << fun2(4) << endl;
          // error: too few arguments to function 'int fun2(int, int, int)'
}
