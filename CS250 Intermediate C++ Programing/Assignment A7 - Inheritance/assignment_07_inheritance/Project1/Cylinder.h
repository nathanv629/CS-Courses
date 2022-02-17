/*
	Van, Nathan

	February 6, 2020

	CS A250
	Lab 7
*/

#ifndef CYLINDER_H
#define CYLINDER_H

#include "Circle.h"

// Class definition
// Your code here...
class Cylinder : public Circle
{
public:
	Cylinder();
	Cylinder(double radius, double pi, double height);

	double getHeight() const;
	void setHeight (double height);

	double calculateVolume() const;
	void printDimensions() const;

	~Cylinder();
private:
	double height;
};

#endif
