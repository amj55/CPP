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

void setZero(int array[], int size);
void inputArray(int alpha[]);
void doubleArray(const int alpha[], int beta[]);
void copyGamma(int inStock[][4], int gamma[]);

void copyAlphaBeta(int alpha[], int beta[], int gamma[]);
void printArray(int alpha);

void setInStock(int inStock[][6], int delta[]);
void printTwoDim(int array[][6]);

int main() {
  int inStock[10][4];
  int alpha[20];
  int beta[20];
  int gamma[4] = {11, 13, 15, 17};
  int delta[10] = {3, 5, 2, 6, 10, 9, 7, 11, 1, 8};

  setZero();

  cout << "Alpha after initialization" << endl;
  printArray(parameters);
  cout << "***********************************************" << endl << endl;

  inputArray(parameters);

  cout << "Alpha after reading 20 numbers" << endl;
  printArray(parameters);
  cout << "***********************************************" << endl << endl;

  doubleArray(parameters);

  cout << "Beta after a call to doubleArray" << endl;
  printArray(parameters);
  cout << "***********************************************" << endl << endl;

  copyGamma(parameters);

  cout << "inStock after a call to copyGamma" << endl;
  printTwoDim(parameters);
  cout << "***********************************************" << endl << endl;

  copyAlphaBeta(parameters);

  cout << "inStock after a call to copyAlphaBeta" << endl;
  printTwoDim(parameters);
  cout << "***********************************************" << endl << endl;

  setInStock(parameters);

  cout << "inStock after a call to setInStock" << endl;
  printTwoDim(parameters);
  cout << "***********************************************" << endl << endl;

  return 0;
}

void setZero(int array[], int size) {
  for (int c = 0; c < size; c++) array[c] = 0;
}

void inputArray(int alpha[]) {
  int tmp;
  for (int c = 0; c < 20; c++) {
    cin >> tmp;
    alpha[c] = tmp;
  }
}

void doubleArray(const int alpha[], int beta[]) {
  for (int c = 0; c < 20; c++) beta[c] = alpha[c] * 2;
}

void copyGamma(int inStock[][4], const int gamma[]) {
  for (int r = 10 - 1; r > 0; r--)
    for (int c = 0; c < 4; c++)
      inStock[r][c] = inStock[r - 1][c] * 3;
  inStock[0] = gamma;
}

void copyAlphaBeta(const int alpha[], const int beta[], const int gamma[]) {
  /* implementation */
}

void printArray(const int alpha[]) {
  for (int c = 0, r = 0; c < 20; c++, r++) {
    if (r == 15) {
      cout << endl;
      r = 0;
    }
    cout << c << ((c == 19) ? "" : ", ");
  }
}

void setInStock(int inStock[][], const int delta[]) {
  int tmp;
  for (int r = 0; r < inStock.size(); r++) {
    cin >> tmp;
    inStock[r][0] = tmp;
  }
  for (int r = 0; r < inStock.size(); r++)
    for (int c = 1; c < inStock[r].size() && c < delta.size(); c++)
      inStock[r][c] = inStock[r][c - 1] * 2 - delta[c];
}

void printTwoDim(const int array[][]) {
  for (int r = 0; r < array.size(); r++) {
    for (int c = 1; c < array[r].size(); c++) cout << array[r][c];
    cout << endl;
  }
}
