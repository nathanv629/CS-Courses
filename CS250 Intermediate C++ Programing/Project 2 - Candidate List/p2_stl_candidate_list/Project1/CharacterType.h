/*
	BCJ
	El-haghassan, Bilal (MW 11:10)
	Van, Nathan (MW 11:10)
	Bui, Catherine (MW 11:10)
	Luna, Julian (MW 11:10)
	Kim, Juyeon (MW 11:10)

	May 22, 2020

	CS A250
	Project 2
*/

#ifndef CHARACTERTYPE_H
#define CHARACTERTYPE_H

#include <iostream>
#include <string>

class CharacterType
{
public:
	// Default constructor
	CharacterType();
	// Overloaded constructor
	CharacterType(const std::string& givenName,
		const std::string& famName, int idNum);

	// setCharacterInfo
	void setCharacterInfo(const std::string& newFirst,
		const std::string& newLast, int newId);

	// getFirstName
	std::string getFirstName() const;
	// getLastName
	std::string getLastName() const;
	// getID
	int getID() const;

	// printName
	void printName() const;
	// printCharacterInfo
	void printCharacterInfo() const;
	// printID
	void printID() const;
	
	// Destructor
	~CharacterType();

private:
	std::string firstName;
	std::string lastName;
	int id;
};

#endif 

