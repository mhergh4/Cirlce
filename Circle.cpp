
#include <iostream>
#include <math.h>
#include <sstream>
#include <stdexcept>

#include "Circle.h"

using namespace std;

size_t Circle::_count = 0;

    Circle:: Circle(double rad, double x, double y) : _radius(rad) {
        _centerPtr = new Point(x,y);
        _count ++;
    }

    Circle::Circle(const Circle& other) : _radius(other._radius), _centerPtr(new Point(*other._centerPtr)) {}

    Circle:: Circle() : Circle(1, 0, 0) {}

    Circle:: Circle(double rad) : Circle(rad, 0, 0) {}

    Circle:: Circle(double x, double y) : Circle(1, x, y) {}

    Circle:: ~Circle()
    {
        std::cout << std::endl << "The object is deleted" << std::endl;
        delete _centerPtr;
        _count--;
    }

    Circle& Circle::setRadius(double rad)
    {
        if (rad > 0) {
            _radius = rad;
        } else {
            throw std::invalid_argument("Radius should be > 0");
        }
        return *this;
    }

    Circle& Circle::setPoint(Point* point)
    {
        delete _centerPtr;
        _centerPtr = new Point(*point);
        return *this;
    }

    size_t Circle::getCount() const { return _count; }
    double Circle::getRadius() const { return _radius; }

    Point Circle::getPoint() const { return *_centerPtr;}

    string Circle::info() const
    {
        std::ostringstream output;
        output << "The radius of the circle is " << getRadius() << std ::endl
                  << "and the center of the circle - (" <<_centerPtr->getX() << ";" << _centerPtr->getY() << ")" << std ::endl;
        return output.str();
    }

    bool Circle::pointToCircle(const Point& p) const
    {
        double x1 = p.getX();
        double y1 = p.getY();
        double x0 = _centerPtr->getX();
        double y0 = _centerPtr->getY();

        return sqrt(pow(x1 - x0, 2) + pow( y1 - y0 , 2)) <= _radius;
    }

    Circle& Circle::operator=(const Circle& other)
{
    if (this != &other) {
        
        _radius = other._radius;
        delete _centerPtr;
        _centerPtr = new Point(*other._centerPtr);
    }
    return *this;
}




    


