/*
	Van, Nathan

	February 25, 2020

	CS A250
	Lab 6
*/

#include "Vector2D.h"
using namespace std;

Vector2D::Vector2D()
{
	x = 0;
	y = 0;
}
Vector2D::Vector2D(int xCor, int yCor)
{
	x = xCor;
	y = yCor;
}
ostream& operator<<(ostream& out, const Vector2D& obj)
{
	return out << "<" << obj.x << "," << obj.y << ">";
}
int Vector2D::operator*(const Vector2D& obj) const
{
	return (x * obj.x) + (y * obj.y);
}
bool Vector2D::operator==(const Vector2D& obj) const
{
	return x == obj.x && y == obj.y;
}
Vector2D::~Vector2D()
{
	
}