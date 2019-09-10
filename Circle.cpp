#include "Circle.hpp"
#include <math.h>
#include <iostream>

Circle::Circle(double r)
    : r_(r)
{}

Circle::Circle(const Circle & other)
{
    r_ = other.getRadius();
    
}


Circle::Circle(Circle && other) : r_(other.getRadius())
{
    std::cout << "Circle::Circle(Circle && other) " << r_<< std::endl;
}

double Circle::getArea() const noexcept
{
    return M_PI * r_ * r_;
}

double Circle::getPerimeter() const noexcept
{
    return 2 * M_PI * r_;
}

double Circle::getRadius() const
{
    return r_;
}

double Circle::checkPi() const
{
    return M_PI;
}

void Circle::print() const
{
    std::cout << "Circle: radius: " << getRadius() << std::endl
              << "          area: " << getArea() << std::endl
              << "     perimeter: " << getPerimeter() << std::endl
              << "            PI: " << checkPi() << std::endl;
}
