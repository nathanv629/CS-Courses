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

#include "CharacterType.h"

using namespace std;

// Implement all functions in the SAME order
// as listed in the interface file.

CharacterType::CharacterType() : id(0) {}

CharacterType::CharacterType(const string& givenName
	, const string& famName, int idNum)
	: firstName(givenName), lastName(famName), id(idNum) {}

void CharacterType::setCharacterInfo(const string& newFirst
	, const string& newLast, int newId)
{
	firstName = newFirst;
	lastName = newLast;
	id = newId;
}

string CharacterType::getFirstName() const
{
	return firstName;
}

string CharacterType::getLastName() const
{
	return lastName;
}

int CharacterType::getID() const
{
	return id;
}

void CharacterType::printName() const
{
	cout << lastName << ", " << firstName;
}

void CharacterType::printCharacterInfo() const
{
	cout << "ID# " << id << " " << firstName << " " << lastName;
}

void CharacterType::printID() const
{
	cout << "ID# " << id;
}

CharacterType::~CharacterType() {}