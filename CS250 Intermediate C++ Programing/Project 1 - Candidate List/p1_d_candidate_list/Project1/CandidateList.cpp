/*
	BCJ
	El-haghassan, Bilal (MW 11:10)
	Van, Nathan (MW 11:10)
	Bui, Catherine (MW 11:10)
	Luna, Julian (MW 11:10)
	Kim, Juyeon (MW 11:10)

	May 20, 2020

	CS A250
	Project 1 - Part D
*/

#include "CandidateList.h"

using namespace std;

// Function declarations
// Same order as in class definition

CandidateList::CandidateList()
	: first(nullptr), last(nullptr), count(0) {}

void CandidateList::addCandidate(const CandidateType& addCan)
{
	if (first == nullptr)
	{
		first = new Node(addCan, nullptr);
		last = first;
	}
	else 
	{
		last->setLink(new Node(addCan, nullptr));
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
		Node* highest = first;
		Node* temp = first->getLink();

		while (temp != nullptr)
		{
			if (highest->getCandidate().getTotalVotes() <
				temp->getCandidate().getTotalVotes())
			{
				highest = temp;
				temp = temp->getLink();
			}
			else
				temp = temp->getLink();
		}
		return highest->getCandidate().getID();
	}
}

bool CandidateList::isEmpty() const
{
	return (first == nullptr);
}

bool CandidateList::searchCandidate(int numID) const
{
	Node* temp = nullptr;
	return searchCandidate(numID, temp);
}

void CandidateList::printCandidateName(int ID) const
{
	Node* temp = nullptr;
	if (searchCandidate(ID, temp))
		temp->getCandidate().printName();
}

void CandidateList::printAllCandidates() const
{
	if (first == nullptr)
		cerr << "=> List is empty." << endl;
	else
	{
		Node* curr = first;
		while (curr != nullptr)
		{
			curr->getCandidate().printCandidateInfo();
			cout << endl;
			curr = curr->getLink();
		}
	}
}

void CandidateList::printKingdomVotes(int ID, int index) const
{
	Node* temp = nullptr;
	if (searchCandidate(ID, temp))
	{
		cout << setw(5) << right << "*" << setw(3)
			<< temp->getCandidate().getVotesByKingdom(index)
			<< "( => )" << KINGDOMS[index] << endl;
	}
}

void CandidateList::printCandidateTotalVotes(int ID) const
{
	Node* temp = nullptr;
	if (searchCandidate(ID, temp))
	{
		cout << setw(6) << right << "=>" << " Total votes: "
			<< temp->getCandidate().getTotalVotes() << endl;
	}
}

void CandidateList::printFinalResults() const
{
	if (first == nullptr)
		cerr << "=> List is empty." << endl; 
	else
	{
		cout << string(12, '*') << " FINAL RESULTS " 
			<< string (12, '*') << "\n" << endl;

		cout << setw(15) << left << "LAST" << setw(10) << "FIRST"
			<< setw(9) << "TOTAL" << "POS" << endl;

		cout << setw(15) << left << "NAME" << setw(10) << "NAME"
			<< setw(11) << "VOTES" << "#" << endl;

		cout << string(39, '_') << "\n" << endl;

		Node* highest = first;
		Node* curr = first->getLink();
		
		while (curr != nullptr)
		{
			if (highest->getCandidate().getTotalVotes()
				< curr->getCandidate().getTotalVotes())
			{
				highest = curr;
			}
			curr = curr->getLink();
		}
		
		int position = 1,
			mostVotes = highest->getCandidate().getTotalVotes() + 1;

		for (int i = 0; i < count; ++i)
		{
			highest = first;
			curr = first->getLink();
			while (curr != nullptr)
			{
				if (highest->getCandidate().getTotalVotes()
					>= mostVotes)
					highest = highest->getLink();
				else if (highest->getCandidate().getTotalVotes()
					< curr->getCandidate().getTotalVotes() &&
					curr->getCandidate().getTotalVotes()
					< mostVotes)
					highest = curr;
				if (highest->getCandidate().getTotalVotes()
					== mostVotes - 1)
					curr = nullptr;
				else
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
				cout << string(39, '-') << endl;
			++position;

			mostVotes = highest->getCandidate().getTotalVotes();
		}
		cout << string(39, '_') << endl;
	}
}

void CandidateList::clearList()
{
	if (first != nullptr)
	{
		Node* curr = first;
		while (first != nullptr)
		{
			first = curr->getLink();
			delete curr;
			curr = first;
		}
		last = nullptr;
		count = 0;
	}
}

CandidateList::~CandidateList() 
{
	clearList();
}

bool CandidateList::searchCandidate(int numID,
	Node*& candidate) const
{
	if (first == nullptr)
		cerr << "=> List is empty." << endl;
	else
	{
		Node* temp = first;
		while (temp != nullptr)
		{
			if (temp->getCandidate().getID() == numID)
			{
				candidate = temp;
				return true;
			}
			temp = temp->getLink();
		}
		cout << setw(6) << right << "=>"
			<< " ID not in the list.\n";
	}
	return false;
}