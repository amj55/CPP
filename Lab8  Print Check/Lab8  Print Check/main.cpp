
//
//  main.cpp
//  Lab8  Print Check
//
//  Created by Gaelin Shupe on 11/1/17.
//  Copyright © 2017 Gaelin Shupe. All rights reserved.
//

// Chapter 7: Programming Exercise 1

#include <iostream>

using namespace std;

void initialize(int &x, int &y, char &z);
void getHoursRate(double &hours, double &rate);
double payCheck(double hours, double rate);
void printCheck(double hours, double rate, double pay);
void funcOne(int &x, int y);
void nextChar(char &z);

int main() {
  int x, y;
  char z;
  double rate, hours;
  double pay;

  initialize(x, y, z);

  cout << "After initialization: x = " << x << ", y = " << y << ", z = " << z
       << endl;

  getHoursRate(hours, rate);
  pay = payCheck(hours, rate);
  printCheck(hours, rate, pay);

  x = 35;
  y = 20;
  cout << "Before calling funcOne: x = " << x << ", y = " << y << endl;
  funcOne(x, y);
  cout << "After funcOne: x = " << x << endl;

  z = 'B';
  cout << "z = " << z << endl;
  nextChar(z);
  cout << "After nextChar: z = " << z << endl;

  return 0;
}

void initialize(int &x, int &y, char &z) {
  x = 0;
  y = 0;
  z = 0;
}

void getHoursRate(double &hours, double &rate) {
  cout << "Enter hours worked:";
  cin >> hours;
  cout << "Enter Rate per hour:";
  cin >> rate;
}

double payCheck(double hours, double rate) {
  double pay = rate * rate;
  if (hours > 40) {
    pay += rate * (hours - 40) * .5;
  }
  return pay;
}

void printCheck(double hours, double rate, double pay) {
  
}

void funcOne(int &x, int y) {}

void nextChar(char &z) {}

}

