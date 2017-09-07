#include <iostream>
#include <iomanip>
#include <windows.h>
#include <math.h>
#define _l "\33[1m"
#define _n "\33[4m"
#define _r "\33[0m"
using namespace std;

int main() {
    system("title Homework Helper");
    cout << setfill(' ') /*<< fixed*/ << showpoint << setprecision(4);
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
    } else {
        pre*=-1;
        root1 = (-b + pow(pre, 1/2))/(2*a);
        root2 = (-b - pow(pre, 1/2))/(2*a);
    }
    cout << "1: " << root1 << " 2: " << root2 << endl;

//    x=-b+/-sqrt(b2-2ac)/2a



    return 0;
}
