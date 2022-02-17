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

#include "CandidateType.h"

using namespace std;

// Implement all functions in the SAME order
// as listed in the interface file.

CandidateType::CandidateType()
{
	totalVotes = 0;
	numOfKingdoms = NUM_OF_KINGDOMS;
	kingdomVotes = new int[numOfKingdoms];
}

CandidateType::CandidateType(const CandidateType& other)
	: CharacterType(other.getFirstName(), other.getLastName()
		, other.getID())
{
	totalVotes = other.totalVotes;
	numOfKingdoms = other.numOfKingdoms;

	kingdomVotes = new int[numOfKingdoms];
	for (int i = 0; i < other.numOfKingdoms; ++i)
		kingdomVotes[i] = other.kingdomVotes[i];
}

CandidateType& CandidateType::operator=(const CandidateType& other)
{

	if (this == &other)
		cerr << "Attempted assignment to self" << endl;
	else
	{
		totalVotes = other.totalVotes;
		numOfKingdoms = other.numOfKingdoms;

		kingdomVotes = new int[numOfKingdoms];
		for (int i = 0; i < numOfKingdoms; ++i)
			kingdomVotes[i] = other.kingdomVotes[i];

		setCharacterInfo(other.getFirstName(),
			other.getLastName(), other.getID());
	}
	return *this;
}

void CandidateType::updateVotesByKingdom(int index, int newVotes)
{
	kingdomVotes[index] = newVotes;
	totalVotes += newVotes;
}

int CandidateType::getTotalVotes() const
{
	return totalVotes;
}

int CandidateType::getVotesByKingdom(int index) const
{
	return kingdomVotes[index];
}

void CandidateType::printCandidateInfo() const
{

	CharacterType::printID();
	cout << " - ";
	CharacterType::printName();
}

void CandidateType::printCandidateTotalVotes() const
{
	CharacterType::printName();
	cout << "\n=> Total Votes (all kingdoms): " << totalVotes;
}

CandidateType::~CandidateType()
{
	delete [] kingdomVotes;
	kingdomVotes = nullptr;
}