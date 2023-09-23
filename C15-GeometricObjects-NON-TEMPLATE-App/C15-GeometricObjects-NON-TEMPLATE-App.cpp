// C15-GeometricObjects-NON-TEMPLATE-App.cpp : 
// Purpose: 
// Demonstrate the use of polymorphism with a hierarchy of abstract 
// geometric objects materialized in as circles and rectangles.
//-----------------------------------------------------------------
#pragma once
#include "GeometricObject.h"
#include "Circle.h"
#include "Rectangle.h"


//Prototypes----------------------------------------------------
void experiment01();
void experiment02();
void experiment03();
void experiment04();

int main()
{
	//experiment01();			//create a few geometric objects
	//experiment02();			//make a list of 'concrete' static geometric objects
	//experiment03();			//create a timestamp
	experiment04();				//create a list of 'dynamic' geometric objects

	cout << "\nAll done!\n";
}

//-----------------------------------------------------------------
void experiment01() {
	//CAUTION. If you add 'pure virtual' method(s) to the 
	//GeomtericObject class, this fragment will fail!
	//-------------------------------------------------------------
	//GeometricObject g1;
	//cout << "g1 " << g1.toString() << endl;

	//GeometricObject g2("red", true);
	//cout << "g2 " << g2.toString() << endl;
}
//----------------------------------------------------------------------------

void experiment02()
{
	Circle c1;
	Circle c2("RED", true, 1);
	Rectangle r1("BLUE", true, 10, 20);

	//Make a list of various types of geometric objects
	vector<GeometricObject*> v;
	v.push_back(&c1);
	v.push_back(&c2);
	v.push_back(&r1);

	cout << "Circle list-----------------------------------\n";
	for (GeometricObject* g : v) {

		//can g be cast as a Circle?
		if (dynamic_cast<Circle*>(g) != nullptr) {
			Circle* c = dynamic_cast<Circle*>(g);
			cout << "\n I'm a Circle >>> " << c->toString() << endl;
		}

		//can g be cast as a Rectangle?
		if (dynamic_cast<Rectangle*>(g) != nullptr) {
			Rectangle* r = dynamic_cast<Rectangle*>(g);
			cout << "\n I'm a Rectangle >>> " << r->toString() << endl;
		}
	}
	//-------------------------------------------------------------
    //Nothing to delete. 
	//Objects c1, c2, and r1 are handled by the OS/compiler.
	//Observe that v.push_back() makes a copy of the object
	//and stores the copy in the vector. When the vector is
	//destroyed, the copies are destroyed, but the original
	//objects are retained.
	//-------------------------------------------------------------
}//experiment02


void experiment03()
{
	/***************************************************************************************************
	1. Open your project in Visual Studio.
	2. Go to "Project" > "Properties" to open the project properties.
	3. In the properties window, navigate to "Configuration Properties" > "C/C++" > "Preprocessor."
	4. In the "Preprocessor Definitions" field, add _CRT_SECURE_NO_WARNINGS.
	5. Save your project settings.

	************************************************************************************************** */
	time_t currentTime = time(nullptr);
	cout << "(Epoch) Current time: " << currentTime << endl;
	// Convert the time to a string and print it
	cout << "(Local) Current time: " << asctime(localtime(&currentTime));

}


//-----------------------------------------------------------------
void experiment04()
{

	Circle* c1 = new Circle();
	Circle* c2 = new Circle("RED", true, 1);
	Rectangle* r1 = new Rectangle("BLUE", true, 10, 20);

	//Make a list of various types of geometric objects
	vector<GeometricObject*> v;
	v.push_back(c1);
	v.push_back(c2);
	v.push_back(r1);

	cout << "Circle list-----------------------------------\n";
	for (GeometricObject* g : v) {

		////OPTION 1 ---------------------------------------
		////can g be cast as a Circle?
		//if (dynamic_cast<Circle*>(g) != nullptr) {
		//	Circle* c = dynamic_cast<Circle*>(g);
		//	cout << " I'm a Circle >>> " << c->toString() << endl;
		//}

		////can g be cast as a Rectangle?
		//if (dynamic_cast<Rectangle*>(g) != nullptr) {
		//	Rectangle* r = dynamic_cast<Rectangle*>(g);
		//	cout << " I'm a Rectangle >>> " << r->toString() << endl;
		//}

		//OPTION 2 ---------------------------------------
		if (typeid(*g) == typeid(Circle))
			cout << "\n I'm a Circle >>> " << ((Circle*)g)->toString() << endl;
		if (typeid(*g) == typeid(Rectangle))
			cout << "\n I'm a Rectangle >>> " << ((Rectangle*)g)->toString() << endl;

	}

	//Housekeeping
	// Objects pointed by c1, c2, and r1 are in the heap. 
	// The vector v contains pointers to these objects, 
	// but does not own them. We are the 'owners' and 
	// must explicitly delete them. 
	cout << "\nHousekeeping-----------------------------------\n";
	delete c1;
	delete c2;
	delete r1;

}//experiment04

