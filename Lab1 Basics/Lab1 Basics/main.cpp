//
//  main.cpp
//  Lab1 Basics
//
//  Created by Gaelin Shupe on 8/28/17.
//  Copyright © 2017 Gaelin Shupe. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    int SECRET = 11;
    double RATE = 12.5;
    double num1, num2, newNum;
    string name;
    double hoursWorked, wages;
    cout << "Enter two numbers seperated by a space." << endl;
    cin >> num1 >> num2;
    cout << "First number = " << num1 << "\nSecond number = " << num2 <<endl;
    newNum = num1 * 2.0 + num2;
    cout << "New number = " << newNum << endl;
    newNum += SECRET;
    cout << "New number = " << newNum << endl;
    cout << "Last name: " << endl;
    cin >> name;
    do {
        cout << "Hours worked: " << endl;
        cin >> hoursWorked;
    } while (hoursWorked > 70 | hoursWorked < 0);
    wages = hoursWorked * RATE;
    cout << "Name: " << name <<
        "\nPay Rate: $" << RATE <<
        "\nHours Worked: " << hoursWorked <<
        "\n\nSalary: $" << wages << endl;
    return 0;
}
