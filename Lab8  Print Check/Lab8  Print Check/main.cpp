//
//  main.cpp
//  Lab8  Print Check
//
//  Created by Gaelin Shupe on 11/1/17.
//  Copyright © 2017 Gaelin Shupe. All rights reserved.
//

#include <iostream>

using namespace std;

void initialize(int &x, int &y, char &z);
void getHoursRate(double &hours, double &rate);
double payCheck(double hours, double rate);
void printCheck(double hours, double rate, double pay);
void funcOne(int &x, int y);
void nextChar(char &z);

int main() {
  cout << "Lab8a:" << endl;
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

  cout << endl << "Lab8b:" << endl;
  
  char chars[80];
  cout << "Enter a string to convert to uppercase:" << endl;
  cin.clear();
  cin.get(chars, 80);
  cout << "Upper: `";
  for (int c = 0; c < 80; c++) cout << toupper(chars[c]);
  cout << "`" << endl << "Flipped: `";
  for (int c = 79; c >= 0; c--) cout << chars[c];
  cout << "`" << endl;

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
  cout << "Hours: " << hours << " Rate: " << rate << " Amount due:" << pay
       << endl;
}

void funcOne(int &x, int y) {
  int number = 0;
  cout << "Input a number:";
  cin >> number;
  x = 2 * x + y - number;
}

void nextChar(char &z) { z = (int)z + 1; }

