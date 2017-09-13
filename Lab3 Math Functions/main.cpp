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
#define _a "\33[31m"
#define _b "\33[32m"
#define _c "\33[33m"
#define _d "\33[34m"
using namespace std;

int main() {
    system("title Homework Helper");
    cout << _a << "aaaaa" << _r << _b << "bbbbb" << _r << _c << "ccccc" << _r << _d << "ddddd" << endl;
    cout << "";
    return 0;
    cout << setfill(' ') /*<< fixed */<< noshowpoint << setprecision(4);
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
    cout << "x = " << _n << "-(" << b << ") +-[" << b << "^2 - 4(" << a << ")(" << c << ")]" << _r << endl << setw(20) << "2(" << a << ")" <<endl;
    double pre = pow(b, 2) - (4 * a * c);
    cout << pre << endl;
    double root1, root2;
    if (pre >= 0) {
        root1 = (-b + pow(pre, 1/2))/(2*a);
        root2 = (-b - pow(pre, 1/2))/(2*a);
        cout << "Roots:" << endl << " x=" << root1 << endl << " x=" << root2 << endl;
    } else {
        pre*=-1;
        root1 = (-b + pow(pre, 1/2))/(2*a);
        root2 = (-b - pow(pre, 1/2))/(2*a);
        cout << "Roots: " << _l << "Warning:" << _r << " Imaginary roots" <<  " x=" << root1 << "i" << endl << " x=" << root2 << "i" << endl;
    }
    cout << "1: " << root1 << " 2: " << root2 << endl;


//    x=-b+/-sqrt(b2-2ac)/2a



    return 0;
}
