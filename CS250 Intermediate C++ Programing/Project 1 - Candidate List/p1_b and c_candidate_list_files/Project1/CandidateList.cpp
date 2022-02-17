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

#include "CandidateList.h"

using namespace std;

// Function declarations
// Same order as in class definition

CandidateList::CandidateList() : first(nullptr)
, last(nullptr), count(0) {}

void CandidateList::addCandidate(const CandidateType& canType)
{
	if (first == nullptr) // nothing 
	{
		first = new Node(canType, nullptr);
		last = first;
	}
	else // 1 or more
	{
		last->setLink(new Node(canType, nullptr));
		last = last->getLink();
	}
	++count;
}

int CandidateList::getWinner() const
{
	if (first == nullptr)
	{
		cerr << "=> List is empty." << endl;
		return 0;
	}
	else
	{
		CandidateType highest = first->getCandidate();
		Node* temp = first->getLink();

		while (temp != nullptr)
		{
			if (highest.getTotalVotes() <
				temp->getCandidate().getTotalVotes())
			{
				highest = temp->getCandidate();
				temp = temp->getLink();
			}
			else
				temp = temp->getLink();
		}
		return highest.getID();
	}
}

bool CandidateList::isEmpty() const
{
	return first == nullptr;
}

Node* CandidateList::searchCandidate(int ID) const
{
	Node* temp = nullptr;
	return (searchCandidate(ID, temp)) ? temp : temp;
}

void CandidateList::printCandidateName(int ID) const
{
	Node* temp = nullptr;
	if(searchCandidate(ID, temp))
		temp->getCandidate().printName();
}

void CandidateList::printAllCandidates() const
{
	if (isEmpty())
		cerr << "=> List is empty." << endl;
	else
	{
		Node* temp = first;
		while (temp != nullptr)
		{
			temp->getCandidate().printCandidateInfo();
			cout << endl;
			temp = temp->getLink();
		}
	}
}

void CandidateList::printKingdomVotes(int ID, int index) const
{
	Node* temp = nullptr;
	if (searchCandidate(ID, temp))
	{
		cout << "    * " << setw(2)
			<< temp->getCandidate().getVotesByKingdom(index)
			<< "( => )" << KINGDOMS[index] << endl;
	}
}

void CandidateList::printCandidateTotalVotes(int ID) const
{
	Node* temp = nullptr;
	if (searchCandidate(ID, temp))
		cout << "    => Total votes: " << setw(3)
		<< temp->getCandidate().getTotalVotes() << endl;
}

void CandidateList::printFinalResults() const
{
	cout << "************ FINAL RESULTS ************" << endl;
	cout << left << setw(4) << "LAST" << setw(11) << "" << setw(5)
		<< "FIRST" << setw(5) << "" << setw(4) << "TOTAL"
		<< setw(4) << "" << right << setw(3) << "POS" << endl;

	cout << setw(4) << "NAME" << setw(11) << "" << setw(4)
		<< "NAME" << setw(6) << "" << setw(4) << "VOTES"
		<< setw(4) << "" << right << setw(3) <<  "#" << endl;

	cout << "_______________________________________" << endl;
	
	int position = 1, previousHigh = 999;
	Node* highest = first;
	Node* curr = first->getLink();

	for (int i = 0; i < count; ++i)
	{

		while (curr != nullptr)
		{
			while (highest->getCandidate().getTotalVotes()
				>= previousHigh)
				highest = highest->getLink();

			if (highest->getCandidate().getTotalVotes()
				< curr->getCandidate().getTotalVotes() &&
				curr->getCandidate().getTotalVotes()
				< previousHigh)
				highest = curr;

			curr = curr->getLink();
		}

		cout
			<< left << setw(15)
			<< highest->getCandidate().getLastName()
			<< setw(12)
			<< highest->getCandidate().getFirstName()
			<< right << setw(3)
			<< highest->getCandidate().getTotalVotes()
			<< setw(5)
			<< "" << setw(2) << position << endl;

		if (position % 5 == 0)
			cout << "---------------------------------------" << endl;
		++position;

		previousHigh = highest->getCandidate().getTotalVotes();
		curr = first->getLink();
		highest = first;
	}

	cout << "_______________________________________" << endl;
}

void CandidateList::clearList()
{
	Node* temp = first;
	
	while (temp != nullptr)
	{
		first = first->getLink();
		delete temp;
		temp = first;
	}
	count = 0;
	last = nullptr;
}

CandidateList::~CandidateList()
{
	clearList();
}

bool CandidateList::searchCandidate(int ID, Node*& p) const
{
	if (isEmpty())
		cerr << "    => List is empty." << endl;
	else
	{
		Node* temp = first;
		while (temp != nullptr)
		{
			if (temp->getCandidate().getID() == ID)
			{
				p = temp;
				return true;
			}
			temp = temp->getLink();
		}
		cerr << "    => ID not in the list." << endl;
	}
	return false;
}