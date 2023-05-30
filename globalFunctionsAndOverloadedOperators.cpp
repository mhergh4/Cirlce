#include <iostream>
#include <math.h>
#include <sstream>
#include <stdexcept>
#include <iomanip>



ostream& operator<<(ostream& output, const Circle& circle)
{
    output << circle.info();
}

ostream& operator<<(ostream& output, const Point& point)
{
    output << "The coordinats is (" << point.getX() << "," << point.getY() <<")";
}

istream& operator>>(istream& input, Circle& circle){
    input.ignore();
    double x, y, radius;
    input >> setw(1) >> x;
    input.ignore();
    input >> setw(1) >> y;
    input.ignore(2);
    input >> setw(1) >> radius;
    Point pnt(x,y);

    circle.setRadius(radius).setPoint(&pnt);

    return input;
}

istream& operator>>(istream& input, Point& point){

    input.ignore(2);
    double x, y;
    input >> setw(1) >> x;
    input.ignore();
    input >> setw(1) >> y;
    input.ignore();
    point.setXY(x,y);

    return input;
}

const double distanceOfCircles(const Circle &c1, const Circle &c2)
{   
    double x1 = c1.getPoint().getX();
    double y1 = c1.getPoint().getY();
    double x2 = c2.getPoint().getX();
    double y2 = c2.getPoint().getY();

    return sqrt(pow(x1 - x2, 2) + pow( y1 - y2 , 2));
}

const int howManyPoints(const Circle &c1, const Circle &c2)
{
    if (c1.getPoint().getX() == c2.getPoint().getX() && c1.getPoint().getY() == c2.getPoint().getY()) {
        return -1;
    } else if (distanceOfCircles(c1, c2) < (c1.getRadius() + c2.getRadius())) {
        return 2;
    } else if (distanceOfCircles(c1, c2) == (c1.getRadius() + c2.getRadius())) {
        return 1;
    } else {
        return 0;
    }
}

const double circleLenght(Circle &c)
{
    return 2 * M_PI * c.getRadius();
}

 double circleArea(Circle &c)
{
    return M_PI * c._radius * c._radius;
}

void moveByX(Circle &c, double lenght)
{
    if (c.getPoint().getX() + lenght < 0)
    {
        throw std::invalid_argument("Circle should be in the first section ");
    }
    else
    {
        double x = c.getPoint().getX();
        c.getPoint().setX(x + lenght);
    }
}

void moveByY(Circle &c, double lenght)
{
    if (c.getPoint().getY() + lenght < 0)
    {
        throw std::invalid_argument("Circle should be in the first section ");
    }
    else
    {
        double y = c.getPoint().getY();
        c.getPoint().setY(y + lenght);
    }
}

void increaseTheArea(Circle &c, float k)
{
    if (((c.getPoint().getX() - c.getRadius() * pow(k, 0.5)) < 0) || ((c.getPoint().getY() - c.getRadius() * pow(k, 0.5)) < 0))
    {
        throw std::invalid_argument("Circle should be in the first section ");
    }
    else
    {
        double rad = c.getRadius();
        c.setRadius(rad * pow(k, 0.5));
    }
}

Point& operator++(Point& p){
    double x = p.getX() + 1;
    double y = p.getY() + 1;
    p.setXY(x,y);
    return p;
}

Point operator++(Point& p, int dummy){
    Point temp{p};
    double x = p.getX() + 1;
    double y = p.getY() + 1;
    p.setXY(x,y);
    return temp;
}

Point& operator--(Point& p){
    double x = p.getX() - 1;
    double y = p.getY() - 1;
    p.setXY(x,y);
    return p;
}


Point operator--(Point& p, int dummy){
    Point temp{p};
    double x = p.getX() - 1;
    double y = p.getY() - 1;
    p.setXY(x,y);
    return temp;
}
