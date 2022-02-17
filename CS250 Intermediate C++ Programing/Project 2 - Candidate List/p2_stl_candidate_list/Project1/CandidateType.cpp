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

#include "CandidateType.h"

using namespace std;

// Implement all functions in the SAME order
// as listed in the interface file.

CandidateType::CandidateType()
{
	totalVotes = 0;
	numOfKingdoms = NUM_OF_KINGDOMS;
	kingdomVotes = new int[numOfKingdoms] {0};
}

CandidateType::CandidateType(const CandidateType& other)
	: CharacterType(other.getFirstName(), other.getLastName(),
		other.getID())
{
	numOfKingdoms = other.numOfKingdoms;
	kingdomVotes = new int[numOfKingdoms];

	for (int i = 0; i < other.numOfKingdoms; ++i)
		kingdomVotes[i] = other.kingdomVotes[i];
	totalVotes = other.totalVotes;
}

CandidateType& CandidateType::operator=(const CandidateType& other)
{
	if (&other == this)
		cerr << "Attempted assignment to itself.";
	else
	{
		if (NUM_OF_KINGDOMS != other.numOfKingdoms)
		{
			delete[] kingdomVotes;
			kingdomVotes = new int[other.numOfKingdoms];
		}
		numOfKingdoms = other.numOfKingdoms;

		for (int i = 0; i < numOfKingdoms; ++i)
			kingdomVotes[i] = other.kingdomVotes[i];
		totalVotes = other.totalVotes;

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
	printID();
	cout << " - ";
	printName();
}

void CandidateType::printCandidateTotalVotes() const
{
	printName();
	cout << "\n    => Total Votes (all kingdoms): " << totalVotes;
}

bool CandidateType::operator==(int id) const
{
	return getID() == id;
}

CandidateType::~CandidateType()
{
	delete [] kingdomVotes;
	kingdomVotes = nullptr;
}