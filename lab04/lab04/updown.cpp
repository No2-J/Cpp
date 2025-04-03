#include "updown.h"

void upDownGame(int* target) {
    int guess;
    int attempts = 0;
    bool guessed = false;

    cout << "Guess the number between 1 and 100!" << endl;

    while (!guessed) {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess < *target) {
            cout << "Too low! " << endl;
        }
        else if (guess > *target) {
            cout << "Too high! " << endl;
        }
        else {
            cout << "You guessed the number in " << attempts << " attempts." << endl;
            guessed = true;
        }
    }
}

void playUpDownGame() {
    srand(time(0));
    int number = (rand() % 100) + 1;
    int* ptr = &number;
    //int& ref = number;

    upDownGame(ptr);
    //upDownGame(&number);
}