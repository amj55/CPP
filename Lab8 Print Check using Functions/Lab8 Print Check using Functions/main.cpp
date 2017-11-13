//
//  main.cpp
//  Lab8 Print Check using Functions
//
//  Created by Gaelin Shupe on 11/13/17.
//  Copyright © 2017 Gaelin Shupe. All rights reserved.
//
// Chapter 7: Programming Exercise 1

#include <iostream>

using namespace std;

void initialize(Parameters);
void getHoursRate(Parameters);
double payCheck(Parameters);
void printCheck(Parameters);
void funcOne(Parameters);
void nextChar(Parameters);

int main() {
  int x, y;
  char z;
  double rate, hours;
  double amount;

  initialize(int& x;);

  cout << "After initialization: x = " << x << ", y = " << y << ", z = " << z
       << endl;

  getHoursRate(Parameters);
  amount = payCheck(Parameters);
  printCheck(Parameters);

  x = 35;
  y = 20;
  cout << "Before calling funcOne: x = " << x << ", y = " << y << endl;
  funcOne(Parameters);
  cout << "After funcOne: x = " << x << endl;

  z = 'B';
  cout << "z = " << z << endl;
  nextChar(Parameters);
  cout << "After nextChar: z = " << z << endl;

  return 0;
}

void initialize(Parameters) {}

void getHoursRate(Parameters) {}

double payCheck(Parameters) {}

void printCheck(Parameters) {}

void funcOne(Parameters) {}

void nextChar(Parameters){}
