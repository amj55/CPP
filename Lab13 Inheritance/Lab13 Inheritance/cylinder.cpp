//  cylinder.cpp

#include <iostream>

using std::cout;

#include "cylinder.h"

// default constructor
Cylinder::Cylinder(int xValue, int yValue, double radiusValue, double heightValue)
    : Circle(xValue, yValue, radiusValue)
{
    setHeight(heightValue);

} // end Cylinder constructor

// set Cylinder's height
void Cylinder::setHeight(double heightValue)
{
    height = (heightValue < 0.0) ? -heightValue : heightValue;
}

// get Cylinder's height
double Cylinder::getHeight() const
{
    return height;
}

// redefine Circle function getArea to calculate Cylinder area
double Cylinder::getArea() const
{
    return getCircumference() * getHeight() + 2 * Circle::getArea();
}

// calculate Cylinder volume
double Cylinder::getVolume() const {
    return Circle::getArea() * getHeight();
}

// output Cylinder object
void Cylinder::print() const {
    Circle::print();
    cout << ": Height = " << getHeight();
}
