#include "week04.h"

void writeFile(string fname) {
    ofstream fout(fname);  // default mode is ios::out | ios::trunc
    if (!fout) {
        cerr << "error: open file for output failed!" << endl;
        abort();
    }
    fout << "apple" << endl;
    fout << "orange" << endl;
    fout << "banana" << endl;
    fout << "strawberry" << endl;
    fout.close();
}

void readFile(string fname) {
    ifstream fin(fname);  // default mode ios::in
    if (!fin) {
        cerr << "error: open file for input failed!" << endl;
        abort();
    }

    cout << "\n Reading file ch by ch" << endl;
    char ch;
    while (fin.get(ch)) {  // till end-of-file
        cout << ch;
    }


    cout << "\n Reading file line by line " << endl;
    fin.clear();
    fin.seekg(0);
    string line;
    while (!fin.eof()) {
        getline(fin, line);
        cout << line << endl;
    }

    fin.close();
}