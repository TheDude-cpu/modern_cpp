#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"

using namespace std;

using Collection = vector<Shape*>; // Collection;

auto sortByArea(Shape* first, Shape* second)
{
    if(first == NULL || second == NULL)
    {
        return false;
    }
    return (first->getArea() < second->getArea());
}

auto perimeterBiggerThan20(Shape* s)
{
    if(s)
    {
        return (s->getPerimeter() > 20);
    }
    return false;
}

auto areaLessThan10(Shape* s)
{
    if(s)
    {
        return (s->getArea() < 10);
    }
    return false;
}

void printCollectionElements(const Collection& collection)
{
    for(Collection::const_iterator it = collection.begin(); it != collection.end(); ++it)
    {
        if(*it != NULL)
        {
            (*it)->print();
        }
    }
}

void printAreas(const Collection& collection)
{
    for(vector<Shape*>::const_iterator it = collection.begin(); it != collection.end(); ++it)
    {
        if(*it != NULL)
        {
            cout << (*it)->getArea() << std::endl;
        }
    }
}

void findFirstShapeMatchingPredicate(const Collection& collection,
                                     bool (*predicate)(Shape* s),
                                     std::string info)
{
    Collection::const_iterator iter = std::find_if(collection.begin(), collection.end(), predicate);
    if(*iter != NULL)
    {
        cout << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    }
    else
    {
        cout << "There is no shape matching predicate " << info << endl;
    }
}
/*
    Write a function that calculates n-th Fibonacci's number. Do not mark it constexpr.
    Add in first line of main() computing 45-th Fibonacci's number. Measure the time of program execution (time ./modern_cpp)
    Mark fibonacci function as constexpr, compile the program and measure the time of execution once again.
*/
int fibonacciN (int n)
{
    //int n = 0 ; 
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fibonacciN(n-1)+fibonacciN(n-2);
}

int main()
{
    static_assert(M_PI > 3.14, "M_PI is smallest then 3,14");
    std::cout<<fibonacciN(45) <<std::endl;
    
    Circle obj(10);
    Circle new_obj(std::move(obj));
    Collection shapes;
    shapes.push_back(new Circle(2.0));
    shapes.push_back(new Circle(3.0));
    shapes.push_back(NULL);
    shapes.push_back(new Circle(4.0));
    shapes.push_back(new Rectangle(10.0, 5.0));
    shapes.push_back(new Square(3.0));
    shapes.push_back(new Circle(4.0));

    printCollectionElements(shapes);

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), sortByArea);

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    Square* square = new Square(4.0);
    shapes.push_back(square);

    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThan10, "area less than 10");

    return 0;
}

