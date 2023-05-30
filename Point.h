
#ifndef POINT_H
#define POINT_H

#include <iostream>

using namespace std;

class Point
{
    friend ostream& operator<<(ostream&, const Point&);
    friend istream& operator>>(ostream& , Point& );

public:
    Point();
    Point(double, double);
    void setXY(double, double);
    void setX(double);
    void setY(double);
    double getX() const;
    double getY() const;

    bool operator==(const Point&);
    bool operator!=(const Point&);
    bool operator<(const Point&);
    bool operator<=(const Point&);
    bool operator>=(const Point&);
    bool operator>(const Point&);
    Point operator+(const Point &) const;
    const Point& operator=(const Point&);
    Point operator-(const Point &) const;
    const Point& operator+=(const Point&);
    const Point& operator-=(const Point&);
    

    // Point &operator++();
    // Point operator++(int);
    // Point &operator--();
    // Point operator--(int);

private:
    double _x{0};
    double _y{0};
};

#endif