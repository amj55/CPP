//
//  main.cpp
//  Lab10 Bucky's Intro
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
  // Makes containing methods public. They can be accessed by another class
 public:
  // Public method declaration
  void publicMethod1() {
    /* implementation */
    cout << "This is some text!" << endl;
  }
  // Public method declaration
  void publicMethod2() {
    /* implementation */
    privateMethod1();
  }

  // Makes containing methods private. They can only be accessed by this class
 private:
  // Private method declaration
  void privateMethod1() { cout << "This is the second method" << endl; }
};

int main() {
  // Create class object
  ExampleClass classObject;
  // Call methods from object
  classObject.publicMethod1();
  classObject.publicMethod2();
  // Cannot do `classObject.privateMethod1()` Will cause errors
  return 0;
}
