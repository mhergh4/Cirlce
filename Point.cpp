
#include <iostream>
#include "Point.h"

using namespace std;

Point::Point() : _x{0}, _y{0} {}
Point::Point(double x, double y) : _x{x}, _y{y} {}

void Point::setXY(double x2, double y2)
{
    setX(x2);
    setY(y2);
}
void Point::setX(double x1)
{
    _x = x1;
}
void Point::setY(double y1)
{
    _y = y1;
}
double Point::getX() const
{
    return _x;
}
double Point::getY() const
{
    return _y;
}

bool Point::operator==(const Point &point)
{
    if (this->getX() == point.getX() && this->getY() == point.getY())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Point::operator!=(const Point &point)
{
    return !(*this == point);
}

Point Point::operator+(const Point &point) const
{
    double x = this->getX() + point.getX();
    double y = this->getY() + point.getY();
    Point pnt(x, y);
    return pnt;
}

Point Point::operator-(const Point &point) const
{
    double x = getX() - point.getX();
    double y = getY() - point.getY();
    Point pnt(x, y);
    return pnt;
}

const Point &Point::operator=(const Point &point)
{
    setX(point.getX());
    setY(point.getY());

    return *this;
}

const Point&  Point::operator+=(const Point& point){
    double x = this->getX() + point.getX();
    double y = this->getY() + point.getY();
    this->setXY(x,y);

    return *this;
}

const Point& Point::operator-=(const Point& point){
    double x = this->getX() - point.getX();
    double y = this->getY() - point.getY();
    this->setXY(x,y);

    return *this;
}

bool Point::operator<(const Point& point){
    if(this->getX() > point.getX()){
        return false;
    } else if(this->getX() < point.getX()){
        return true;
    } else {
        return this->getY() < point.getY();
    }
}

bool Point::operator<=(const Point& point){
    if(this->getX() <= point.getX() || this->getY() <= point.getY()){
        return true;
    } else {
        return false;
    }
}

bool Point::operator>=(const Point& point){
    if(this->getX() >= point.getX() || this->getY() >= point.getY()){
        return true;
    } else {
        return false;
    }
}

bool Point::operator>(const Point& point){
    if(this->getX() > point.getX()){
        return true;
    } else if(this->getX() < point.getX()){
        return false;
    } else {
        return this->getY() > point.getY();
    }
}

// Point&  Point:: operator++(){
//     double x = getX() + 1;
//     double y = getY() + 1;
//     setXY(x,y);
//     return *this;
// }

// Point  Point:: operator++(int){
//     Point temp{*this};
//     double x = getX() + 1;
//     double y = getY() + 1;
//     setXY(x,y);
//     return temp;
// }
// Point&  Point:: operator--(){
//     double x = getX() - 1;
//     double y = getY() - 1;
//     setXY(x,y);
//     return *this;
// }

// Point  Point:: operator--(int){
//     Point temp{*this};
//     double x = getX() - 1;
//     double y = getY() - 1;
//     setXY(x,y);
//     return temp;
// }
