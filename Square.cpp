#include "Square.hpp"
#include <iostream>

Square::Square(double x)
    : Rectangle(x, x)/*, color()*/
{}

Square::Square(const Square &other)
    : Rectangle(other.getX(), other.getX())
{}

double Square::getArea() const noexcept
{
    return getX() * getX();
}

double Square::getPerimeter() const
{
    return 4 * getX();
}

void Square::print() const
{
    std::cout << "Square:      x: " << getX() << std::endl
              << "          area: " << getArea() << std::endl
              << "     perimeter: " << getPerimeter() << std::endl;
}
