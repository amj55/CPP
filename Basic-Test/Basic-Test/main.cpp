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
  cout << "No" << endl;
  char ch, ch1, ch2, ch3;
  int x = -1, y = -1, alpha = -1;
  double z = -1;
  
  cout << "'" << (6 < 5 || 'g' > 'a' && 7 < 4) << "'" << endl;
  //cout << "'" << x << "', '" << z << "', '" << y << "'" << endl;
  //cout << "'" << ch1 << "', '" << ch2 << "', '" << ch3 << "'" << endl;
    vector<int> v1;
    vector<int> v2;
    v1.push_back(1);
    v2.push_back(2);
    cout << v1[0] << endl;
    cout << v2[0] << endl;
}
