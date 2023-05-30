
#include <iostream>
#include <math.h>
#include <sstream>
#include <stdexcept>
#include <iomanip>

#include "Circle.h"
#include "Point.h"
#include "globalFunctionsAndOverloadedOperators.cpp"

int main()
{
    try
    {
        Circle c1(3, 5, 5);
        Circle c2(4, 5, 5);
        Circle c3(3, 10, 10);
        Circle c4;
        Circle c5;
        Point p1(4,4);
        Point p2;
        Point p3(5,5);

        p1+p2;
        p1.operator+(p2);

        p1++;
        // std::cout<<p1.getX()<<" "<<p1.getY()<<endl;
     
        // std::cout<<c4;

        c2=c1;

        std::cout<<c2;

        // std::cout<<"Enter the coordinants of cirlce center and radius like this - (x0,y0) radius"<<std::endl;
        // cin>>c5;
        // cout<<c5;       

        // std::cout<<"\nEnter the coordinants of cirlce center  like this - (x0,y0)"<<std::endl;
        // cin>>p2;
        // cout<<p2;
        std::cout<<"p1+p3 is "<<p1+p3<<endl;
        std::cout<<"p1-p3 is "<<p1-p3<<endl;
        p2 = p1-p3;
        std::cout<<p2<<endl;
        std::cout<<p1<<endl;
        // std::cout<<"\n"<<p3<<endl;

        // p1 -= p3;
        // std::cout<<p1<<endl;
        std::cout<<(p2>=p1)<<endl;
        
        std::cout<<"\nIs p1 and p3 not equal? ";
        if(p1!=p3){
            std::cout<<"Yes\n";
        } else {
            std::cout<<"No\n";
        }
        std::cout << "\nIs (5,6) the poin of c2 ";
        Point p(5, 6);
        if (c2.pointToCircle(p))
            std::cout << "yes" << std::endl;
        else
            std::cout << "no" << std::endl;
        std::cout << "\n";

        if(howManyPoints(c2,c3) == -1) {
            std::cout<<"c2 and c3 circles have a infinity intersection points"<<std::endl;
        } else {
             std::cout<<"c2 and c3 circles have a "<< howManyPoints(c2,c3)<<" points"<<std::endl;
        }

        std::cout << "\n";
        std::cout << "The area of c3 circle is " << circleArea(c3) << std::endl;

        std::cout << "\n";
        std::cout << "The lenght of c3 circle is " << circleLenght(c3) << std::endl;

        std::cout << "\n";
        std::cout << c3.info();

        std::cout << "\n";
        moveByX(c1, -1);
        moveByY(c1, -1);
        std::cout << "The area of c1 circle is " << circleArea(c1) << std::endl;

        std::cout << "\n";
        increaseTheArea(c1, 0.5);
        std::cout << "The area of c1 circle is " << circleArea(c1) << std::endl;

        std::cout << "\n";
        std::cout << c1.info();

        std::cout << "\n";
        std::cout << "The area of c3 circle is " << circleArea(c3) << std::endl;

        std::cout << "\n";
        std::cout << "The count of circles is " << c3.getCount() << std::endl;
    }
    catch (std::invalid_argument &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
