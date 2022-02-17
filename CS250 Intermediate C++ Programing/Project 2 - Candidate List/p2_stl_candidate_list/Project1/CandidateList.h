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

#ifndef CANDIDATELIST_H
#define CANDIDATELIST_H

#include "CandidateType.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <list>

class CandidateList
{
public:
	// Default constructor
	CandidateList();

	// addCandidate
	void addCandidate(const CandidateType& other);

	// getWinner
	int getWinner() const;

	// isEmpty
	bool isEmpty() const;
	// searchCandidate
	bool searchCandidate(int numID) const;

	// printCandidateName
	void printCandidateName(int ID) const;
	// printAllCandidates
	void printAllCandidates() const;
	// printKingdomVotes
	void printKingdomVotes(int ID, int index) const;
	// printCandidateTotalVotes
	void printCandidateTotalVotes(int ID) const;
	// printFinalResults
	void printFinalResults() const;
	/*********************************************
	*******FUNCTION ADDED FOR SELECTION #6********
	*********************************************/
	void printAvgVotesPerKingdom() const;

	// Destructor
	~CandidateList();

private:
	// searchCandidate
	bool searchCandidate(int numID, 
		std::list<CandidateType>::const_iterator& iter) const;

	// printHeader
	void printHeader() const;
	// printCandidate
	void printCandidate
	(std::list<CandidateType>::const_iterator iter
	 , int rank) const;

	std::list<CandidateType> candidates;
};

#endif
