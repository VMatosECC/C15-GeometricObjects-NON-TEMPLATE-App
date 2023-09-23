#pragma once

#include "GeometricObject.h"


//HEADER Portion --------------------------------------------------
class Rectangle : public GeometricObject
{
private:
    //Data Members
    double width;
    double height;

public:
    //Mutators - Setters
    void setWidth(double widthValue) { width = widthValue; }
    void setHeight(double heightValue) { height = heightValue; }

    //Accessors - Getters
    double getWidth() { return width; }
    double getHeight() { return height; }

    //Constructors
    Rectangle(string colorValue = "green", bool filledValue = true,
        double widthValue = 0, double heightValue = 0)
        : GeometricObject(colorValue, filledValue)
    {
        setHeight(heightValue);
        setWidth(widthValue);
    }

    //User-Defined Methods
    string toString() {
        stringstream sout;
        sout << this
            << " Rectangle [Height: " << getHeight()
            << ", Width: " << getWidth()
            << ",\n\t" << GeometricObject::toString()
            << ",\n\tArea: " << getArea()
            << ", Perimeter: " << getPerimeter()
            << "]";
        return sout.str();
    }

    double getArea()      override { return (getWidth() * getHeight()); }
    double getPerimeter() override { return 2 * (getWidth() + getHeight()); }


};


