/*
* Made by Gaelin
* Simple homework helper program.
* Asks for coefficients of a quadratic then calculates the roots.
*/


#include <iostream>
#include <iomanip>
#include <math.h>
#include <windows.h>
#define _r "\33[0m\33[37m"
#define _l "\33[1m"
#define _n "\33[4m"
using namespace std;

int main() {
    system("title Homework Helper");
    cout << setfill(' ') /*<< fixed */ << noshowpoint << setprecision(4);
    cout << "Welcome to the homework helper" << endl;
    cout << "Quadratic solver:" << endl;
    double a, b, c;
    cout << "Format: ax² + bx + c" << endl;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    cout << "Calculating:" << endl;
    cout << "x = " << _n << "-(" << b << ") +-[" << b << "^2 - 4(" << a << ")(" << c << ")]" << _r <<
         endl << setw(20) << "2(" << a << ")" << endl;
    double pre = pow(b, 2) - (4 * a * c);
    double root1, root2;
    if(pre >= 0) {
        root1 = (-b + pow(pre, 1 / 2)) / (2 * a);
        root2 = (-b - pow(pre, 1 / 2)) / (2 * a);
        cout << "Roots:" << endl << " x=" << root1 << endl << " x=" << root2 << endl;
    } else {
        pre *= -1;
        root1 = (-b + pow(pre, 1 / 2)) / (2 * a);
        root2 = (-b - pow(pre, 1 / 2)) / (2 * a);
        cout << "Roots: " << _l << "Warning:" << _r << " Imaginary roots" << endl << " x=" << root1 << "i"
             << endl << " x=" << root2 << "i" << endl;
    }
//    x=-b+/-sqrt(b2-2ac)/2a
    return 0;
}
