#pragma once

enum class Color {
        RED,
        BROWN,
        BLACK,
};

class Shape 
{
    Color color;
public:
    virtual ~Shape() {}

    virtual double getArea() const noexcept = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;
    
};
