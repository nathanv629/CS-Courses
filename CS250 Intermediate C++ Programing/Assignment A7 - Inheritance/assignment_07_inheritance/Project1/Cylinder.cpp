/*
	Van, Nathan

	February 6, 2020

	CS A250
	Lab 7
*/

#include "Cylinder.h"

#include <iostream>
using namespace std;

// Class implementation
// Your code here...
Cylinder::Cylinder(): Circle()
{
	height = 0.0;
}
Cylinder::Cylinder(double radius, double pi, double h) 
	: Circle(radius,pi)
{
	height = h;
}
double Cylinder::getHeight() const
{
	return height;
}
void Cylinder::setHeight(double h)
{
	height = h;
}
double Cylinder::calculateVolume() const
{
	return Circle::calculateArea() * height;
}
void Cylinder::printDimensions() const
{
	cout << "Radius: " << Circle::getRadius() << "\nPi: "
		<< Circle::getPi() << "\nHeight: " << height << endl;
}
Cylinder::~Cylinder()
{

}