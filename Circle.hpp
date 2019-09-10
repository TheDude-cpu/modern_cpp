#pragma once

#include "Shape.hpp"

class Circle final : public Shape
{
public:
    Circle(double r);
    Circle(const Circle & other);
    Circle(Circle && other);

    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
    double getRadius() const;
    double checkPi() const;
    void print() const final;

private:
    Circle(); // doesn't allow to call default constructor
    
    double r_;
 
};
