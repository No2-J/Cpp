#include "week02.h"

// (Function Implementation) (Function Definations)

void formattedOutput() {
    // Floating point numbers
    double pi = 3.14159265;
    cout << fixed << setprecision(4); // fixed format with 4 decimal places
    cout << pi << endl;
    cout << "|" << setw(8) << pi << "|" << setw(10) << pi << "|" << endl;
    // setw() is not sticky, only apply to the next operation.
    cout << setfill('-');
    cout << "|" << setw(8) << pi << "|" << setw(10) << pi << "|" << endl;
    cout << scientific;  // in scientific format with exponent
    cout << pi << endl;

    // booleans
    bool done = false;
    cout << done << endl;  // print 0 (for false) or 1 (for true)
    cout << boolalpha;     // print true or false
    cout << done << endl;
}

void formattedInput() {

    string areaCode, phoneCode;
    string inStr;

    cout << "Enter your phone number in this format (xxx)xxx-xxxx : ";
    cin.ignore();   // skip '('
    cin >> setw(3) >> areaCode;
    cin.ignore();   // skip ')'
    cin >> setw(3) >> phoneCode;
    cin.ignore();   // skip '-'
    cin >> setw(4) >> inStr;
    phoneCode += inStr;

    cout << "Phone number is (" << areaCode << ")"
        << phoneCode.substr(0, 3) << "-"
        << phoneCode.substr(3, 4) << endl;

}

void sizeofTypes() {
    cout << "sizeof(char) is " << sizeof(char) << " bytes " << endl;
    cout << "sizeof(short) is " << sizeof(short) << " bytes " << endl;
    cout << "sizeof(int) is " << sizeof(int) << " bytes " << endl;
    cout << "sizeof(long) is " << sizeof(long) << " bytes " << endl;
    cout << "sizeof(long long) is " << sizeof(long long) << " bytes " << endl;
    cout << "sizeof(float) is " << sizeof(float) << " bytes " << endl;
    cout << "sizeof(double) is " << sizeof(double) << " bytes " << endl;
    cout << "sizeof(long double) is " << sizeof(long double) << " bytes " << endl;
    cout << "sizeof(bool) is " << sizeof(bool) << " bytes " << endl;
}

void integerlimits() {
    cout << "int max = " << INT_MAX << endl;
    cout << "int min = " << INT_MIN << endl;
    cout << "unsigned int max = " << UINT_MAX << endl;
    cout << "long long max = " << LLONG_MAX << endl;
    cout << "long long min = " << LLONG_MIN << endl;
    cout << "unsigned long long max = " << ULLONG_MAX << endl;
    cout << "Bits in char = " << CHAR_BIT << endl;
    cout << "char max = " << CHAR_MAX << endl;
    cout << "char min = " << CHAR_MIN << endl;
    cout << "signed char max = " << SCHAR_MAX << endl;
    cout << "signed char min = " << SCHAR_MIN << endl;
    cout << "unsigned char max = " << UCHAR_MAX << endl;
}
void overflow() {
    // Range of int is [-2147483648, 2147483647]
    int i1 = 2147483647;      // max int
    cout << i1 + 1 << endl;   // -2147483648 (overflow)
    cout << i1 + 2 << endl;   // -2147483647
    cout << i1 * i1 << endl;  // 1

    int i2 = -2147483648;     // min int
    cout << i2 - 1 << endl;   // 2147483647 (underflow)
    cout << i2 - 2 << endl;   // 2147483646
    cout << i2 * i2 << endl;  // 0
}


void mixTypesOperations() {
    int i1 = 2, i2 = 4;
    double d1 = 2.5, d2 = 5.0;

    // Print floating-points in fixed format with 1 decimal place
    cout << fixed << setprecision(1);  // need <iomanip>

    cout << i1 << " + " << i2 << " = " << i1 + i2 << endl;  // 6
    cout << d1 << " + " << d2 << " = " << d1 + d2 << endl;  // 7.5
    cout << i1 << " + " << d2 << " = " << i1 + d2 << endl;  // 7.0  <==

    cout << i1 << " - " << i2 << " = " << i1 - i2 << endl;  // -2
    cout << d1 << " - " << d2 << " = " << d1 - d2 << endl;  // -2.5
    cout << i1 << " - " << d2 << " = " << i1 - d2 << endl;  // -3.0 <==

    cout << i1 << " * " << i2 << " = " << i1 * i2 << endl;  // 8
    cout << d1 << " * " << d2 << " = " << d1 * d2 << endl;  // 12.5
    cout << i1 << " * " << d2 << " = " << i1 * d2 << endl;  // 10.0 <==

    cout << i1 << " / " << i2 << " = " << i1 / i2 << endl;  // 0    <==
    cout << d1 << " / " << d2 << " = " << d1 / d2 << endl;  // 0.5
    cout << i1 << " / " << d2 << " = " << i1 / d2 << endl;  // 0.4  <==
}
void incrementDecrement() {
    int mark = 76;        // declare & assign
    cout << mark << endl; // 76

    mark++;               // increase by 1 (post-increment)
    cout << mark << endl; // 77

    ++mark;               // increase by 1 (pre-increment)
    cout << mark << endl; // 78

    mark = mark + 1;      // also increase by 1 (or mark += 1)
    cout << mark << endl; // 79

    mark--;               // decrease by 1 (post-decrement)
    cout << mark << endl; // 78

    --mark;               // decrease by 1 (pre-decrement)
    cout << mark << endl; // 77

    mark = mark - 1;      // also decrease by 1 (or mark -= 1)
    cout << mark << endl; // 76
}

void ConvertTemperature() {
    double celsius, fahrenheit;

    // Format floating-points in fixed with 2 decimal places
    cout << fixed << setprecision(2);

    cout << "Enter the temperature in celsius: ";
    cin >> celsius;
    fahrenheit = celsius * 9 / 5 + 32;
    // 9/5*celsius + 32 gives wrong answer! Why?
    cout << celsius << "C is " << fahrenheit << "F" << endl;

    cout << "Enter the temperature in fahrenheit: ";
    cin >> fahrenheit;
    celsius = (fahrenheit - 32) * 5 / 9;
    // 5/9*(fahrenheit - 32) gives wrong answer! Why?
    cout << fahrenheit << "F is " << celsius << "C" << endl;
}



void sumOddEven() {
    int sumOdd = 0; // For accumulating odd numbers, init to 0
    int sumEven = 0; // For accumulating even numbers, init to 0
    int upperbound;  // Sum from 1 to this upperbound
    int absDiff;     // The absolute difference between the two sums

    // Prompt user for an upperbound
    cout << "Enter the upperbound: ";
    cin >> upperbound;

    // Use a while-loop to repeatedly add 1, 2, 3,..., to the upperbound
    int number = 1;
    while (number <= upperbound) {
        if (number % 2 == 0) {  // Even number
            sumEven += number;   // Add number into sumEven
        }
        else {                // Odd number
            sumOdd += number;    // Add number into sumOdd
        }
        ++number; // increment number by 1
    }

    // Compute the absolute difference between the two sums
    if (sumOdd > sumEven) {
        absDiff = sumOdd - sumEven;
    }
    else {
        absDiff = sumEven - sumOdd;
    }

    // Print the results
    cout << "The sum of odd numbers is " << sumOdd << endl;
    cout << "The sum of even numbers is " << sumEven << endl;
    cout << "The absolute difference is " << absDiff << endl;

}

void sumNumbers() {
    int sum = 0;     // Store the accumulated sum
    int upperbound;
    cout << "Enter the upperbound: ";
    cin >> upperbound;

    // Sum from 1 to the upperbound
    for (int number = 1; number <= upperbound; ++number) {
        sum += number;
    }
    cout << "Sum is " << sum << endl;
    cout << "Average is " << (double)sum / upperbound << endl;

    // Sum only the odd numbers
    int count = 0;     // counts of odd numbers
    sum = 0;           // reset sum
    for (int number = 1; number <= upperbound; number = number + 2) {
        ++count;
        sum += number;
    }
    cout << "Sum of odd numbers is " << sum << endl;
    cout << "Average is " << (double)sum / count << endl;
}

void statNumbers() {
    int numberIn;      // input number (positive integer)
    int count = 0;     // count of inputs, init to 0
    int sum = 0;       // sum of inputs, init to 0
    int max = 0;       // max of inputs, init to minimum
    int min = INT_MAX; // min of inputs, init to maximum (need <climits>)
    int sentinel = -1; // Input terminating value

    // Read Inputs until sentinel encountered
    cout << "Enter a positive integer or " << sentinel << " to exit: ";
    while (cin >> numberIn && numberIn != sentinel) {
        // Check input for positive integer
        if (numberIn > 0) {
            ++count;
            sum += numberIn;
            if (max < numberIn) max = numberIn;
            if (min > numberIn) min = numberIn;
        }
        else {
            cout << "error: input must be positive! try again..." << endl;
        }
        cout << "Enter a positive integer or " << sentinel << " to exit: ";
    }

    // Print result
    cout << endl;
    cout << "Count is " << count << endl;
    if (count > 0) {
        cout << "Maximum is " << max << endl;
        cout << "Minimum is " << min << endl;
        cout << fixed << setprecision(2);
        // print floating point to 2 decimal places (need <iomanip>)
        cout << "Average is " << (double)sum / count << endl;
    }
}

void nonPrimeList() {
    int upperbound;
    cout << "Enter the upperbound: ";
    cin >> upperbound;
    for (int number = 2; number <= upperbound; ++number) {
        // Not a prime, if there is a factor between 2 and sqrt(number)
        int maxFactor = (int)sqrt(number);
        for (int factor = 2; factor <= maxFactor; ++factor) {
            if (number % factor == 0) {   // Factor?
                cout << number << " ";
                break;   // A factor found, no need to search for more factors
            }
        }
    }
    cout << endl;
}

void continueExe() {
    int upperbound = 100;
    int sum = 0;
    for (int number = 1; number <= upperbound; ++number) {
        if (number % 11 == 0) continue;  // Skip the rest of the loop body, continue to the next iteration
        sum += number;
    }
    // It is better to re-write the loop as:
    for (int number = 1; number <= upperbound; ++number) {
        if (number % 11 != 0) sum += number;
    }
}

void mystery() {
    int number = 1;
    while (true) {
        ++number;
        if ((number % 3) == 0) continue;
        if (number == 10) break;
        if ((number % 2) == 0) {
            number += 3;
        }
        else {
            number -= 3;
        }
        cout << number << " ";
    }
    cout << endl;
}