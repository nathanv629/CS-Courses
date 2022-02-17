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
#include "CandidateType.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	// test cases
	cout << "---------------------------------------" <<
		"-------------------------" << endl;
	cout << "TEST CASE: CharacterType Class" << endl;
	cout << "---------------------------------------" <<
		"-------------------------\n" << endl;

	CharacterType newChar;
	CharacterType newChar2 ("Nathan", "Van", 1234);
	
	cout << "---------------------Default Constructor" <<
		"------------------------\n\n";

	cout << "TEST (getFirstName): ";
	cout << newChar.getFirstName(); 
	cout << "   EXPECTED OUTPUT: ";

	cout << "\nTEST (getLastName): ";
	cout << newChar.getLastName();
	cout << "   EXPECTED OUTPUT: ";

	cout << "\nTEST (getID): ";
	cout << newChar.getID();
	cout << "   EXPECTED OUTPUT: 0";

	cout << "\nTEST (printName): ";
	newChar.printName();
	cout << "   EXPECTED OUTPUT: , ";

	cout << "\nTEST (printCharacterInfo): ";
	newChar.printCharacterInfo();
	cout << "   EXPECTED OUTPUT: ID# 0";

	cout << "\nTEST (printID): ";
	newChar.printID();
	cout << "   EXPECTED OUTPUT: ID# 0";

	cout << "\n\n---------------------Overload Constructor" <<
		"-----------------------\n\n";

	cout << "TEST (getFirstName): ";
	cout << newChar2.getFirstName();
	cout << "   EXPECTED OUTPUT: Nathan";

	cout << "\nTEST (getLastName): ";
	cout << newChar2.getLastName();
	cout << "   EXPECTED OUTPUT: Van";

	cout << "\nTEST (getID): ";
	cout << newChar2.getID();
	cout << "   EXPECTED OUTPUT: 1234"; 

	cout << "\nTEST (printName): ";
	newChar2.printName();
	cout << "   EXPECTED OUTPUT: Van, Nathan";

	cout << "\nTEST (printCharacterInfo): ";
	newChar2.printCharacterInfo();
	cout << "   EXPECTED OUTPUT: ID# 1234 Nathan Van";

	cout << "\nTEST (printID): ";
	newChar2.printID();
	cout << "   EXPECTED OUTPUT: ID# 1234";

	cout << "\n\n--------------------------------" <<
		"--------------------------------\n";
	cout << "TEST CASE: CandidateType Class\n";
	cout << "-----------------------------------" <<
		"-----------------------------\n\n";

	CandidateType newCan;
	
	cout << "-------------------Default Constructor" <<
		"--------------------------\n\n";

	cout << "TEST (getFirstName): " << newCan.getFirstName();
	cout << "   EXPECTED OUTPUT: ";

	cout << "\nTEST (getLastName): " << newCan.getLastName();
	cout << "   EXPECTED OUTPUT: ";

	cout << "\nTEST (getID): " << newCan.getID();
	cout << "   EXPECTED OUTPUT: 0";

	cout << "\nTEST (printName): ";
	newCan.printName();
	cout << "   EXPECTED OUTPUT: ,";

	cout << "\nTEST (printCharacterInfo): ";
	newCan.printCharacterInfo();
	cout << "   EXPECTED OUTPUT: ID# 0";

	cout << "\nTEST (printID): ";
	newCan.printID();
	cout << "   EXPECTED OUTPUT: ID# 0";

	cout << "\nTEST (printCandidateInfo): ";
	newCan.printCandidateInfo();
	cout << "   EXPECTED OUTPUT:  -";

	cout << "\nTEST (printCandidateTotalVotes): ";
	newCan.printCandidateTotalVotes();
	cout << "   EXPECTED OUTPUT: 0";

	cout << "\n\n---------Default Constructor" <<
		"(After setCharacterInfo)------------\n\n";

	newCan.setCharacterInfo("Julian", "Luna", 9876);

	cout << "TEST (getFirstName): " << newCan.getFirstName();
	cout << "   EXPECTED OUTPUT: Julian";

	cout << "\nTEST (getLastName): " << newCan.getLastName();
	cout << "   EXPECTED OUTPUT: Luna";

	cout << "\nTEST (getID): " << newCan.getID();
	cout << "   EXPECTED OUTPUT: 9876";

	cout << "\nTEST (printName): ";
	newCan.printName();
	cout << "   EXPECTED OUTPUT: Luna, Julian";

	cout << "\nTEST (printCharacterInfo): ";
	newCan.printCharacterInfo();
	cout << "   EXPECTED OUTPUT: ID# 9876 Julian Luna";
	cout << endl;

	cout << "\nTEST (printID): ";
	newCan.printID();
	cout << "   EXPECTED OUTPUT: ID# 9876";

	cout << "\nTEST (printCandidateInfo): ";
	newCan.printCandidateInfo();
	cout << "   EXPECTED OUTPUT: ID# 9876 - Luna, Julian";

	cout << "\nTEST (printCandidateTotalVotes): ";
	newCan.printCandidateTotalVotes();
	cout << "\nEXPECTED OUTPUT: Luna, Julian" <<
		"\n=>Total Votes (all kingdoms): 0";

	cout << "\n\n----------------------Copy Constructor" <<
		"--------------------------\n\n";
	
	CandidateType newCan2(newCan);

	cout << "TEST (getFirstName): " << newCan2.getFirstName();
	cout << "   EXPECTED OUTPUT: Julian";

	cout << "\nTEST (getLastName): ";
	cout << newCan2.getLastName();
	cout << "   EXPECTED OUTPUT: Luna";

	cout << "\nTEST (getID): ";
	cout << newCan2.getID();
	cout << "   EXPECTED OUTPUT: 9876";

	cout << "\nTEST (printName): ";
	newCan2.printName();
	cout << "   EXPECTED OUTPUT: Luna, Julian";

	cout << "\nTEST (printCharacterInfo): ";
	newCan2.printCharacterInfo();
	cout << "   EXPECTED OUTPUT: ID# 9876 Julian Luna";

	cout << "\nTEST (printID): ";
	newCan2.printID();
	cout << "   EXPECTED OUTPUT: ID# 9876";

	cout << "\nTEST (printCandidateInfo): ";
	newCan2.printCandidateInfo();
	cout << "   EXPECTED OUTPUT: ID#9876 - Luna, Julian";

	cout << "\nTEST (printCandidateTotalVotes): ";
	newCan2.printCandidateTotalVotes();
	cout << "\nEXPECTED OUTPUT: Luna, Julian" <<
		"\n=>Total Votes (all kingdoms): 0";

	cout << "\n\nTEST (updateVotesByKingdom): ";
	newCan2.updateVotesByKingdom(0,5);
	newCan2.updateVotesByKingdom(1, 10);
	newCan2.updateVotesByKingdom(2, 15);
	newCan2.updateVotesByKingdom(3, 20);
	newCan2.updateVotesByKingdom(4, 25);
	newCan2.updateVotesByKingdom(5, 30);
	newCan2.updateVotesByKingdom(6, 0);
	
	cout << "\nVotes by Kingdom: \n";
	for (int i = 0; i < NUM_OF_KINGDOMS; ++i)
	{
		cout << KINGDOMS[i] << " - " << newCan2.getVotesByKingdom(i);
		cout << endl;
	}

	cout << "\nExpected: " << endl;
	cout << "The North - 5" << endl;
	cout << "The Vale - 10" << endl;
	cout << "The Stormlands - 15" << endl;
	cout << "The Reach - 20 " << endl;
	cout << "The Westerlands - 25" << endl;
	cout << "The Iron Islands - 30" << endl;
	cout << "Dorne - 0" << endl;

	cout << "\nTEST (printCandidateTotalVotes): ";
	newCan2.printCandidateTotalVotes();
	cout << endl;
	cout << "EXPECTED OUTPUT: Luna, Julian" <<
		"\n=>Total Votes (all kingdoms): 105";

	cout << "\n\n------------------ Assignment Operator (=)" <<
		"----------------------\n\n";

	CandidateType newCan3 = newCan2;

	cout << "TEST (getFirstName): " << newCan3.getFirstName();
	cout << "   EXPECTED OUTPUT: Julian";

	cout << "\nTEST (getLastName): " << newCan3.getLastName();
	cout << "   EXPECTED OUTPUT: Luna";

	cout << "\nTEST (getID): " << newCan3.getID();
	cout << "   EXPECTED OUTPUT: 9876";

	cout << "\nTEST (printName): ";
	newCan3.printName();
	cout << "   EXPECTED OUTPUT: Luna, Julian";

	cout << "\nTEST (printCharacterInfo): ";
	newCan3.printCharacterInfo();
	cout << "   EXPECTED OUTPUT: ID# 9876 Julian Luna";

	cout << "\nTEST (printID): ";
	newCan3.printID();
	cout << "   EXPECTED OUTPUT: ID# 9876";

	cout << "\nTEST (printCandidateInfo): ";
	newCan3.printCandidateInfo();
	cout << "   EXPECTED OUTPUT: ID#9876 - Luna, Julian";

	cout << "\nTEST (printCandidateTotalVotes): ";
	newCan3.printCandidateTotalVotes();
	cout << "\nEXPECTED OUTPUT: Luna, Julian" <<
		"\n=>Total Votes (all kingdoms): 105";

	cout << "\n\nTEST (updateVotesByKingdom): ";
	newCan3.updateVotesByKingdom(0, 0);
	newCan3.updateVotesByKingdom(1, 30);
	newCan3.updateVotesByKingdom(2, 25);
	newCan3.updateVotesByKingdom(3, 20);
	newCan3.updateVotesByKingdom(4, 15);
	newCan3.updateVotesByKingdom(5, 10);
	newCan3.updateVotesByKingdom(6, 5);

	cout << "\nVotes by Kingdom: \n";
	for (int i = 0; i < NUM_OF_KINGDOMS; ++i)
	{
		cout << KINGDOMS[i] << " - " << newCan3.getVotesByKingdom(i);
		cout << endl;
	}

	cout << "\nExpected: " << endl;
	cout << "The North - 0" << endl;
	cout << "The Vale - 30" << endl;
	cout << "The Stormlands - 25" << endl;
	cout << "The Reach - 20" << endl;
	cout << "The Westerlands - 15" << endl;
	cout << "The Iron Islands - 10" << endl;
	cout << "Dorne - 5" << endl;

	cout << "\nTEST (printCandidateTotalVotes): ";
	newCan3.printCandidateTotalVotes();
	cout << "\nEXPECTED OUTPUT: Luna, Julian" <<
		"\n=>Total Votes (all kingdoms): 210";

	cout << "\n\nTESTING selfassignment" << endl;
	newCan3 = newCan3;
	cout << "Expected: Attempted assignment to self\n";

	cout << endl;

	system("Pause");
	return 0;
}