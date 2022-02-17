/*
	Van, Nathan

	February 6, 2020

	CS A250
	Lab 7
*/

#ifndef CIRCLE_H
#define CIRCLE_H

// Class definition
// Your code here...
class Circle
{
public:
	Circle();
	Circle(double radius, double pi);
	
	double getRadius() const;
	double getPi() const;

	void setRadius(double radius);
	void setPi(double pi);

	double calculateArea() const;
	void printDimensions() const;
	
	~Circle();
private:
	double radius, pi;
};

#endif

