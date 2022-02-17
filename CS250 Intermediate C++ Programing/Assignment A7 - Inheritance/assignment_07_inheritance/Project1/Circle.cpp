/*
	Van, Nathan

	February 6, 2020

	CS A250
	Lab 7
*/

#include "Circle.h"

#include <iostream>
using namespace std;

// Class implementation
// Your code here...
Circle::Circle()
{
	radius = 0.0;
	pi = 3.142;
}
Circle::Circle(double r, double p)
{
	radius = r;
	pi = p;
}
double Circle::getRadius() const
{
	return radius;
}
double Circle::getPi() const
{
	return pi;
}
void Circle::setRadius(double r)
{
	radius = r;
}
void Circle::setPi(double p)
{
	pi = p;
}
double Circle::calculateArea() const
{
	return pi * radius * radius;
}
void Circle::printDimensions() const
{
	cout << "Radius: " << radius << "\nPi: " << pi << endl;
}
Circle::~Circle()
{

}
