
#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h"
#include <iostream>

using namespace std;

class Circle
{
    friend  double circleArea(Circle &);
    friend ostream& operator<<(ostream&, const Circle&);
    friend istream& operator>>(ostream& , Circle& );

public:
    Circle(double, double , double );

    Circle(const Circle&);

    Circle() ;

    Circle(double rad) ;

    Circle(double x, double y) ;

    ~Circle();

    Circle& setRadius(double);

    Circle& setPoint(Point*);

    size_t getCount() const ;
    double getRadius() const ;

    Point getPoint() const ;

    std::string info() const;

    bool pointToCircle(const Point& ) const;

    Circle& operator=(const Circle&);



private:
    double _radius{0};
    Point* _centerPtr;
    static size_t _count;

};

#endif