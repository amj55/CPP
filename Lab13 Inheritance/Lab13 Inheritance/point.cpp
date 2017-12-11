// point.cpp
#include <iostream>

using std::cout;

#include "point.h"   // Point class definition

// default constructor
Point::Point( int xValue, int yValue ) 
    : x( xValue ), y( yValue ) 
    //x = xValue;
    //y = yValue;
{

    // empty body

    
} // end Point constructor

// set x in coordinate pair
void Point::setX( int xValue )
{
    x = xValue; // no need for validation

} // end function setX
    
// return x from coordinate pair
int Point::getX() const
{
    return x;

} // end function getX

// set y in coordinate pair
void Point::setY( int yValue )
{
    y = yValue; // no need for validation

} // end function setY

// return y from coordinate pair
int Point::getY() const
{
    return y;

} // end function getY
       
    
// output Point object
void Point::print() const
{
    cout << '(' << x << ", " << y << ')';

} // end function print
