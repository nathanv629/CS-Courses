/*
	BCJ
	El-haghassan, Bilal (MW 11:10)
	Van, Nathan (MW 11:10)
	Bui, Catherine (MW 11:10)
	Luna, Julian (MW 11:10)
	Kim, Juyeon (MW 11:10)

	May 09, 2020

	CS A250
	Project 1 - Part B & C
*/

#ifndef CANDIDATELIST_H
#define CANDIDATELIST_H

#include "CandidateType.h"

#include <iostream>
#include <string>
#include <iomanip>

class Node
{
public:
	Node() : link(nullptr) {}
    Node(const CandidateType& newCandidate, Node *theLink) 
		: candidate(newCandidate), link(theLink){}
    Node* getLink( ) const { return link; }
	CandidateType getCandidate( ) const { return candidate; }
    void setCandidate(const CandidateType& newCandidate)
		{ candidate = newCandidate; }
    void setLink(Node *theLink) { link = theLink; }
	~Node() {}
private:
    CandidateType candidate;
    Node *link;		//pointer that points to next node
};

class CandidateList
{
public:
	// Default constructor
	CandidateList();

	// addCandidate
	void addCandidate(const CandidateType& canType);

	// getWinner
	int getWinner() const;

	// isEmpty
	bool isEmpty() const;

	// searchCandidate
	Node* searchCandidate(int ID) const;

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
	
	// clearList
	void clearList();

	// Destructor
	~CandidateList();

private:
	// searchCandidate
	bool searchCandidate(int ID, Node*& canType) const;

	Node *first; 	// pointer to the first candidate in the list
	Node *last;		// pointer to last candidate in the list
	int count;		// number of candidates in the list	
};

#endif
