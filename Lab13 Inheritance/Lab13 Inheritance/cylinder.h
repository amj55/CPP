//  cylinder.h

#ifndef cylinder_h
#define cylinder_h

#include <iostream>

#include "circle.h"  // Circle class definition


class Cylinder : public Circle {

public:
    // default constructor
    Cylinder( int = 0, int = 0, double = 0.0, double = 0.0 );

    void setHeight( double );   // set Cylinder's height
    double getHeight() const;   // return Cylinder's height

    double getArea() const;     // return Cylinder's area
    double getVolume() const;   // return Cylinder's volume
    void print() const;         // output Cylinder

private:
    double height;              // Define Cylinder's height as double
    
}; // end class Cylinder

#endif /* defined(__OOP__cylinder__) */
