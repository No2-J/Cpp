#pragma once
#include<iostream>
#include<iomanip>
#include<ctime>
#include<conio.h>
#include<string>
#include<fstream>
using namespace std;
class Hangman;

class Hangman {
private:
    string progress[72];
    string problem = "";
    string answer = "";
    string guessed = "";
    int nTries = 0;
    const int maxTries = 7;
public:
    void load(const char* progName = "HangmanProgress.txt") {
        ifstream fin(progName);
        if (fin) {
            //getline(fin, progress[0]);
            for (int i = 0; i < 72; i++)
                getline(fin, progress[i]);
        }
    }
    void print() {
        system("cls");
        cout << "     <Hangman Game> \n";
        for (int i = 0; i < 8; i++)
            cout << '\t' << progress[nTries * 8 + i] << endl;
        cout << "\n\n Answer :  " << answer;
        cout << "\n\n Guesses : " << guessed;
    }

    int countMatched(char ch) {
        int nMatched = 0;
        for (int pos = -1; ; ) {
            pos = problem.find(ch, pos + 1);
            if (pos < 0) break;
            answer[pos] = ch;
            nMatched++;
        }
        return nMatched;
    }
    void guess() {
        char ch = _getch();
        if (ch >= 'a' && ch <= 'z') {
            int pos = guessed.find(ch);
            if (pos < 0) {
                guessed[ch - 'a'] = ch;
                if (countMatched(ch) == 0) nTries++;
            }
        }
    }
    void play(string prob) {
        load();
        problem = prob;
        answer = string(problem.length(), '-');
        guessed = string(24, '.');
        nTries = 0;
        while (nTries < maxTries && answer != problem) {
            print();
            guess();
        }
        print();
        cout << "\n\t" << ((nTries == maxTries) ? "Hanged :  " : "Guessed Correctly : ") << endl;
    }
};