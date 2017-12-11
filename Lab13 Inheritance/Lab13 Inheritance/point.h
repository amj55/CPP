//  point.h

#ifndef point_h
#define point_h

class Point {

public:
    Point( int = 0, int = 0 ); // default constructor
 
    void setX( int );          // set x in coordinate pair
    int getX() const;          // return x from coordinate pair

    void setY( int );          // set y in coordinate pair
    int getY() const;          // return y from coordinate pair

    void print() const;        // output Point object

private:
    int x;  // x part of coordinate pair
    int y;  // y part of coordinate pair
    
}; // end class Point

#endif /* defined(point_h) */

