//
//  main.cpp
//  Lab9 Arrays and Strings
//
//  Created by Gaelin Shupe on 11/13/17.
//  Copyright © 2017 Gaelin Shupe. All rights reserved.
//
// Chapter 9: Programming Exercise 8

#include <iostream>
#include <iomanip>

using namespace std;

void setZero(int[], int);
void inputArray(int[]);
void doubleArray(const int[], int[]);
void copyGamma(int[][4], const int[]);

void copyAlphaBeta(const int[], const int[], int[][4]);
void printArray(const int[]);

void setInStock(int[][4], const int[]);
void printTwoDim(const int[][4]);

int main() {
    int inStock[10][4];
    int alpha[20];
    int beta[20];
    int gamma[4] = {11, 13, 15, 17};
    int delta[10] = {3, 5, 2, 6, 10, 9, 7, 11, 1, 8};

    setZero(alpha, 20);

    cout << "Alpha after initialization" << endl;
    printArray(alpha);
    cout << "***********************************************" << endl << endl;

    inputArray(alpha);

    cout << "Alpha after reading 20 numbers" << endl;
    printArray(alpha);
    cout << "***********************************************" << endl << endl;

    doubleArray(alpha, beta);

    cout << "Beta after a call to doubleArray" << endl;
    printArray(beta);
    cout << "***********************************************" << endl << endl;

    copyGamma(inStock, gamma);

    cout << "inStock after a call to copyGamma" << endl;
    printTwoDim(inStock);
    cout << "***********************************************" << endl << endl;

    copyAlphaBeta(alpha, beta, inStock);

    cout << "inStock after a call to copyAlphaBeta" << endl;
    printTwoDim(inStock);
    cout << "***********************************************" << endl << endl;

    setInStock(inStock, delta);

    cout << "inStock after a call to setInStock" << endl;
    printTwoDim(inStock);
    cout << "***********************************************" << endl << endl;

    return 0;
}

void setZero(int array[], int size) {
    for(int c = 0; c < size; c++) array[c] = 0;
}

void inputArray(int alpha[]) {
    int tmp;
    for(int c = 0; c < 20; c++) {
        cout << " #(" << c << "): ";
        cin >> tmp;
        alpha[c] = tmp;
    }
}

void doubleArray(const int alpha[], int beta[]) {
    for(int c = 0; c < 20; c++) beta[c] = alpha[c] * 2;
}

void copyGamma(int inStock[][4], const int gamma[]) {
    for(int r = 0; r < 10; r++)
        for(int c = 0; c < 4; c++) {
            if(r == 0) inStock[0][c] = gamma[c];
            inStock[r][c] = inStock[r - 1][c] * 3;
        }
}

void copyAlphaBeta(const int alpha[], const int beta[], int inStock[][4]) {
    for(int r = 0, c = 0, p = 0; p < 20; c++, p++) {
        if(c == 4) {
            c = 0;
            r++;
        }
        inStock[r][c] = alpha[p];
    }
    for(int r = 19, c = 3, p = 19; p >= 0; c--, p--) {
        if(c == -1) {
            c = 3;
            r--;
        }
        inStock[r][c] = beta[p];
    }
}

void printArray(const int alpha[]) {
    for(int c = 0, r = 0; c < 20; c++, r++) {
        if(r == 15) {
            cout << endl;
            r = 0;
        }
        cout << alpha[c] << ((c == 19) ? "" : ", ");
    }
    cout << endl;
}

void setInStock(int inStock[][4], const int delta[]) {
    int tmp;
    for(int r = 0; r < 10; r++) {
        cout << "#(" << r << "): ";
        cin >> tmp;
        inStock[r][0] = tmp;
    }
    for(int r = 0; r < 10; r++)
        for(int c = 1; c < 4; c++)
            inStock[r][c] = inStock[r][c - 1] * 2 - delta[c];
}

void printTwoDim(const int inStock[][4]) {
    for(int r = 0; r < 10; r++) {
        for(int c = 0; c < 4; c++) cout << inStock[r][c] << ", ";
        cout << endl;
    }
}
