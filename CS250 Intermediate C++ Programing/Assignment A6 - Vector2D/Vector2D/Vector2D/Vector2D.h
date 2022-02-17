/*
	Van, Nathan

	February 25, 2020

	CS A250
	Lab 6
*/

#include <iostream>

#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D
{
	friend std::ostream& operator<<(std::ostream& out,
		const Vector2D& obj);
public:
	Vector2D();
	Vector2D(int x, int y);
	int operator*(const Vector2D& obj) const;
	bool operator==(const Vector2D& obj) const;
	~Vector2D();
private:
	int x, y;
};

#endif
