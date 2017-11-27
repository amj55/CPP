//
//  main.cpp
//  Lab11 Bucky's Using Variables in Classes
//
//  Created by Gaelin Shupe on 11/27/17.
//  Copyright © 2017 Gaelin Shupe. All rights reserved.
//

// Import iostream
#include <iostream>
// Set namespace to standard
using namespace std;

// Class definition named `ExampleClass`
class ExampleClass {
  // Makes containing methods and variables public. They can be accessed by another class
public:
  // Example setter method
  void setName(string newName) {
    // Set variable value
    name = newName;
  }
  // Example getter method
  string getName() {
    // Return value
    return name;
  }
  
// Makes containing methods and variables private. They can only be accessed by this class
private:
  // Private variable declaration
  string name = "First Name";
};

int main() {
  // Create class object
  ExampleClass classObject;
  // Output the name
  cout << "Current name: " << classObject.getName() << endl;
  // Set the name
  classObject.setName("My Other Name");
  // Output the name again
  cout << "New name: " << classObject.getName() << endl;
  return 0;
}

