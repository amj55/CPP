// Circle class contains x-y coordinate pair and radius.

#ifndef circle_h
#define circle_h

#include <iostream>

#include "point.h"  // Point

class Circle : public Point {

public:
    // default constructor
    Circle( int = 0, int = 0, double = 0.0 );

    void setRadius( double );   // set radius
    double getRadius() const;   // return radius

    double getDiameter() const;       // return diameter
    double getCircumference() const;  // return circumference
    double getArea() const;           // return area

    void print() const;         // output Circle4 object

private:
    double radius;  // Circle4's radius

}; // end class Circle

#endif /* defined(__OOP__circle__) */
