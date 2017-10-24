//
//  main.cpp
//  Lab 7 Tree of Stars
//
//  Created by Gaelin Shupe on 10/24/17.
//  Copyright © 2017 Gaelin Shupe. All rights reserved.
//

#include <iostream>

using namespace std;

string chars(int amount, char character);

int main(int argc, const char * argv[]) {
    int lines;
    cout << "Lines: ";
    cin >> lines;
    for (int line = 0; line < lines; line++) {
        string spaces = chars(lines - line, ' ');
        string stars = chars(line * 2 + 1, '*');
        cout << spaces << stars << endl;
    }
    for (int line = 0; line < lines; line++) cout << chars(lines - lines/6, ' ') << chars(lines/3, '*') << endl;
    for (int line = lines - 1; line >= 0; line--) {
        string spaces = chars(lines - line, ' ');
        string stars = chars(line * 2 + 1, '*');
        cout << spaces << stars << endl;
    }
}

string chars(int amount, char character) {
    string out = "";
    for (int c = 0; c < amount; c++) out += character;
    return out;
}

