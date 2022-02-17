/*
	Van, Nathan
	Bui, Catherine
	Kim, Juyeon

	April 11, 2020

	CS 250
	Lab 10
*/

#include <iostream>
#include <string>
#include <set>
#include <map>


using namespace std;

// Declaration function printSet.
// The function passes a list and prints all
// the elements on one line, separated by a space.
// Use a range-based FOR loop. If you do not know
// what this means, search the Web.
void printSet(set<int>&);

int main()
{

	/***************************************************************************
	* SETS
	***************************************************************************/
	cout << "  ***  STL SET CLASS  ***  \n\n";

	// Create a set of ints named set1 and use the initializer list to insert the 
	// following integers in this order: 2, 7, 5, 6, 9, 1 and 3.
	set<int> set1 = { 2,7,5,6,9,1,3 };

	// Print the set using the printSet function you implemented.
	printSet(set1);

	// What do you notice in the printout?

		/*The set automatically sorted in numeric order*/

	// size_type  erase (const value_type& val);
	// Use the function erase to erase the integer 9 from set1, but this
	// time use cout to print the return value.  What is the return
	// value?

		/*The return value is 1, which is number of elements erased*/

	// Print out set1.
	cout << "Number of elements erased:" << set1.erase(9) << endl;
	printSet(set1);

	// size_type  erase (const value_type& val);
	// Use the function erase to erase integer 2 from set1, but
	// this time use cout to print the return value.
	// What is the return value?	
	cout << "Number of elements erased:" << set1.erase(2);

	// If you do not know what the return value is, then
	// check set::erase in cplusplus.com
	cout << endl;

	// Print set1.
	printSet(set1);

	// iterator  erase (const_iterator position);
	// This function is different from the previous one,
	// because instead of passing a value, it passes a 
	// position indicated by an iterator.
	// Delete the second element in the set without creating
	// an iterator variable, but do use the prefix increment
	// operator.
	set1.erase(++set1.cbegin());

	// Print set1.
	printSet(set1);

	// pair<iterator,bool> insert (const value_type& val);
	// Use the function insert to insert 4 and 8 in set1.
	set1.insert(4);
	set1.insert(8);

	// Print set1.
	printSet(set1);
	
	set<int>::iterator first = set1.begin();
	set<int>::iterator second = ++set1.begin();
	// iterator erase(const_iterator first, const_iterator last);
	// Use function erase to delete the first and second element
	// in set1. Use the given iterators created above.
	// Note that you should write one statement only.
	set1.erase(first, ++second);

	// Print set1.
	printSet(set1);

	// Your output should be: 5 6 7 8
	// If it is not, you need to carefully view the function erase
	// to understand how it works.

	cout << "\n\n----------------------------------------------------";
	cout << "\n\nThe output for the next sections depends on your implementation.";
	
	/***************************************************************************
	* MAPS
	***************************************************************************/
	cout << "\n\n----------------------------------------------------";
	cout << "\n  ***  STL MAP CLASS  ***  \n\n";

	// Create a few maps using the different constructors shown in the slides.
	// Use the following functions to manipulate the maps:
	// pair<iterator,bool> insert (const value_type& val);
	// void insert (InputIterator first, InputIterator last);
	// iterator  erase(const_iterator position);
	// size_type erase(const key_type& k);
	// iterator  erase(const_iterator first, const_iterator last);
	// Print each map without creating a print function, but by using
	// a loop.
	map<char, int> aMap1;
	map<char, int> aMap2;
	map<int, int> aMap4;

	aMap1['A'] = 100;
	aMap1['B'] = 80;
	aMap1['C'] = 70;

	map<char, int> aMap3{
		{'w', 1},
		{'x', 10},
		{'y', 20},
		{'z', 30}
	};

	for (int i = 1; i < 5; ++i)
	{
		aMap4.insert(make_pair(i, (i * 10)));
	}

	cout << "Map 1: ";
	for (auto i : aMap1)
	{
		cout << "(" << i.first << ", " << i.second << ")";
	}
	cout << endl;
	cout << "Map 2: ";
	for (auto i : aMap2)
	{
		cout << "(" << i.first << ", " << i.second << ")";
	}
	cout << endl;
	cout << "Map 3: ";
	for (auto i : aMap3)
	{
		cout << "(" << i.first << ", " << i.second << ")";
	}
	cout << endl;
	cout << "Map 4: ";
	for (auto i : aMap4)
	{
		cout << "(" << i.first << ", " << i.second << ")";
	}
	cout << endl;

	// pair<iterator,bool> insert (const value_type& val);
	pair<map<char, int>::iterator, bool> ret;
	ret = aMap1.insert(pair<char, int>('C', 60));

	if (ret.second == false)
	{
		cout << "element 'C' already existed "
			<< "with a value of " << ret.first->second << endl;
	}

	cout << "Map 1: ";
	for (auto i : aMap1)
	{
		cout << "(" << i.first << ", " << i.second << ")";
	}
	cout << endl;

	// void insert (InputIterator first, InputIterator last);
	aMap2.insert(aMap1.begin(), aMap1.find('C'));

	cout << "Map 2: ";
	for (auto i : aMap2)
	{
		cout << "(" << i.first << ", " << i.second << ")";
	}
	cout << endl;

	// iterator  erase(const_iterator position);
	map<char, int>::const_iterator it1 = aMap1.find('B');
	aMap1.erase(it1);

	cout << "Map 1: ";
	for (auto i : aMap1)
	{
		cout << "(" << i.first << ", " << i.second << ")";
	}
	cout << endl;

	// size_type erase(const key_type& k);
	aMap2.erase('A');

	cout << "Map 2: ";
	for (auto i : aMap2)
	{
		cout << "(" << i.first << ", " << i.second << ")";
	}
	cout << endl;

	// iterator  erase(const_iterator first, const_iterator last);
	map<char, int>::const_iterator it2 = aMap3.find('z');
	aMap3.erase(aMap3.begin(), it2);

	cout << "Map 3: ";
	for (auto i : aMap3)
	{
		cout << "(" << i.first << ", " << i.second << ")";
	}
	cout << endl;


	cout << "\n\n----------------------------------------------------";

	cout << endl;
	system("Pause");
	return 0;
}

// Definition function printSet
void printSet(set<int> &l)
{
	for (auto i : l)
		cout << i << " ";
	cout << endl;
}