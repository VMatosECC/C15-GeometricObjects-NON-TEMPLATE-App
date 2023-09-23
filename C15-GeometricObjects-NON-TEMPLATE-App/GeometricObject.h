#pragma once
#include "mylibraries.h"

class GeometricObject
{
private:
    //Data members
    string color;   //Red, White, Blue
    bool   filled;  //True: opaque, False:transparent

public:
    const double PI = 3.14;

    // Mutators - Setters
    void setColor(string colorValue) {
        //TODO validate color, and title-caps
        this->color = colorValue;
    }

    void setFilled(bool filledValue) {
        this->filled = filledValue;
    }

    // Accessors - Getters
    string getColor() { return color; }
    bool   getFilled() { return filled; }

    // Constructors
    GeometricObject(string colorValue = "Blue", bool filledValue = true) {
        setColor(colorValue);
        setFilled(filledValue);
    }

    //Destructor
    //No delete statements, these objects are handled by the OS/compiler
    ~GeometricObject() { cout << "GeometricObject destructor " << this << endl; }

    //User-Defined Methods
    string toString() {
        stringstream sout;
        string filledStr = (getFilled() ? "true" : "false");
        sout << this << " GeometricObject [Color: " << getColor()
            << ", Filled: " << filledStr << "]";
        return sout.str();
    }

    //Virtual methods
    //My childrem MUST override these methods 
    virtual double getArea() = 0;           // pure virtual function
    virtual double getPerimeter() = 0;      // pure virtual function

};


