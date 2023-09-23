#pragma once
#include "GeometricObject.h"


//HEADER Portion --------------------------------------------------
class Circle : public GeometricObject
{
private:
    //Data Members
    double radius;

public:
    //Mutators - Setters
    void setRadius(double radiusValue);

    //Accessors - Getters
    double getRadius();

    //Constructors
    Circle(string color = "green", bool filledValue = true, double radius = 0);

    //User-Defined Methods
    string toString();

    double getArea() override;       //MUST be included because the parent SAID SO! (pure virtual)
    double getPerimeter() override;


};

//IMPLEMENTATION Section -------------------------------------------

void Circle::setRadius(double radiusValue) {
    radius = abs(radiusValue);
}

double Circle::getRadius() {
    return radius;
}

Circle::Circle(string colorValue, bool filledValue, double radiusValue)
    : GeometricObject(colorValue, filledValue)
{
    setRadius(radiusValue);
}

string Circle::toString()
{
    stringstream sout;
    sout << this
        << " Circle [ Radius: " << getRadius()
        << ", Color: " << getColor()
        << ", Filled: " << getFilled()
        << ",\n\t Parent " << GeometricObject::toString()
        << ",\n\t Area: " << getArea()
        << ", Perimeter: " << getPerimeter()
        << " ]";
    return sout.str();
}


double Circle::getArea()
{
    return (PI * getRadius() * getRadius());
}

double Circle::getPerimeter()
{
    return (2 * PI * getRadius());
}


