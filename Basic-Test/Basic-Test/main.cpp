//
//  main.cpp
//  Basic-Test
//
//  Created by Gaelin Shupe on 8/21/17.
//  Copyright © 2017 Gaelin Shupe. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int* pA = &a;
    int* pB = &b;
    int* pC = &c;
    int* pD = &d;
    cout << "(" << pA << ") > " << *pA << endl;
    cout << "(" << pB << ") > " << *pB << endl;
    cout << "(" << pC << ") > " << *pC << endl;
    cout << "(" << pD << ") > " << *pD << endl;
    cout << endl;
    for (int i = -2000; i < 35; i ++) {
        cout << "(" << pD + i << ") > " << *(pD+i) << endl;
        *(pD+i)=0;
    }
    
}

