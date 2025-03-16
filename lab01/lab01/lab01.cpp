#include "lab.h"

void UpDown() {
    int n, min = 1, max = 99, input, i, score = 10;
    cout << "Up and Down Game\n\n";
    srand(time(0));
    n = rand() % 100;
    for (i = 0; i < 10; i++) {
        cout << "Guess Betewwn 1 ~ 99 : ";
        cin >> input;
        if (n == input) { break; }
        else if (n > input) {
            cout << "You entered too low number\n";
            min = input;
            score--;
        }
        else if (n < input) {
            cout << "You entered too high number\n";
            max = input;
            score--;
        }
    }
    if (n == input) {
        cout << "You got it! in tries " << i << endl;
        cout << "Your score is " << score * 10;
    }
    else {
        cout << "You could not got it! in tries " << i << endl;
        cout << "Your score is 0";
    }
}


void TaxCalculator() {
    double tax = 0.0;
    int income;
    cout << fixed << setprecision(2);
    cout << "Enter total Income : ";
    cin >> income;
    if (income <= 1200) {
        tax = income * 0.06;
    }
    else if ((income <= 4600) && (income > 1200)) {
        tax = 1200 * 0.06 + (income-1200) * 0.15;
    }
    else if ((income > 4600) && (income <= 8800)) {
        tax = 1200 * 0.06 + (4600 - 1200) * 0.15 + (income-4600) * 0.24;
    }
    else if ((income > 8800) && (income <= 15000)) {
        tax = 1200 * 0.06 + (4600 - 1200) * 0.15 + (8800 - 4600) * 0.24 + (income-8800) * 0.35;
    }
    else if ((income > 15000)) {
        tax = 1200 * 0.06 + (4600 - 1200) * 0.15 + (8800 - 4600) * 0.24 + (15000 - 8800) * 0.35 + (income-15000) * 0.38;
    }
    cout << "Total Income : " << income;
    cout << "\nTotal Tax : " << tax;
    cout << "\nIncome after Tax : " << income - tax << endl;
}

void pyramid() {
    int height;
    cout << "Enter Hight : ";
    cin >> height;
    for (int i = 1; i < height; i++) {
        for (int j = 0; j < height - i; j++)
            cout << "   ";// Printing spaces
        for (int j = 0; j < i; j++)
            cout << setw(3) << j * 2 + 1;
        for (int j = i - 2; j >= 0; j--)
            cout << setw(3) << j * 2 + 1;
        cout << "\n";
    }
}
void FindPrime() {
    int n, howmany=0;
    cout << "Enter a number : ";
    cin >> n;
    cout << "Prime numbers between 2 and " << n << " are";
    for (int num = 2; num <= n; num++) {
        bool isPrime = true;
        for (int i = 2; i < num; i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            cout << num << " ";
            howmany++;
        }
    }
    cout << "\nTotal number of Primes is " << howmany;
}
