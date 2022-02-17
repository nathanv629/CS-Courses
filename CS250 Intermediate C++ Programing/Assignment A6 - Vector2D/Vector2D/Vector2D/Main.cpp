/*
	Van, Nathan

	February 25, 2020

	CS A250
	Lab 6
*/

#include "Vector2D.h"

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int x = 0,
		y = 0;
	char retry = 'y';

	cout << " *** Two-dimensional Vectors ***\n";

	do
	{
		cout << "\nVector 1\n    Enter x and y: ";
		cin >> x >> y;
		Vector2D v1(x, y);

		cout << "Vector 2\n    Enter x and y: ";
		cin >> x >> y;
		Vector2D v2(x, y);

		cout << "\nVectors are:\n";
		cout << "    " << v1 << endl;
		cout << "    " << v2 << endl;

		if (v1 == v2)
			cout << "\nVectors are equivalent." << endl;
		else
			cout << "\nVectors are not equivalent." << endl;

		cout << "\nDot product = " << (v1 * v2) << endl;

		cout << "\n----------------------------------------------------\n";
		cout << "\nWould you like to try again? (y/n) ";
		cin >> retry;
		
	} while (retry == 'y');

	cout << endl;
	system("Pause");
	return 0;
}

