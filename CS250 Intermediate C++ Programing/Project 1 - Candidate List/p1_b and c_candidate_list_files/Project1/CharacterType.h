/*
	BCJ
	El-haghassan, Bilal (MW 11:10)
	Van, Nathan (MW 11:10)
	Bui, Catherine (MW 11:10)
	Luna, Julian (MW 11:10)
	Kim, Juyeon (MW 11:10)

	May 03, 2020

	CS A250
	Project 1 - Part A
*/

#ifndef CHARACTERTYPE_H
#define CHARACTERTYPE_H

#include <iostream>
#include <string>

class CharacterType
{
public:
	// Default constructor
	// Overloaded constructor
	CharacterType();
	CharacterType(const std::string& givenName
		, const std::string& famName, int idNum);

	// setCharacterInfo
	void setCharacterInfo(const std::string& newFirst
		, const std::string& newLast, int newId);

	// getFirstName
	// getLastName
	// getID
	std::string getFirstName() const;
	std::string getLastName() const;
	int getID() const;

	// printName
	// printCharacterInfo
	// printID
	void printName() const;
	void printCharacterInfo() const;
	void printID() const;

	// Destructor
	~CharacterType();

private:
	std::string firstName;
	std::string lastName;
	int id;
};

#endif 

