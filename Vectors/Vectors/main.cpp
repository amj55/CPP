//
//  main.cpp
//  Vectors
//
//  Created by Gaelin Shupe on 11/3/17.
//  Copyright © 2017 Gaelin Shupe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char* argv[]) {
  cout << "Enter numbers (0 to end):" << endl;
  vector<int> nums;
  int num = -1;
  while (true) {
    cin >> num;
    if (num == 0) break;
    nums.push_back(num);
  }
  cout << "You entered:" << endl;
  for (int c = 0; c < nums.size(); c++) {
    cout << nums[c] << ((c == nums.size() - 1) ? " " : ", ");
  }
  cout << endl << "Done!" << endl;
}
