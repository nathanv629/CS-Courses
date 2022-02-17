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

#include "CandidateList.h"

using namespace std;

// Function declarations
// Same order as in class definition

CandidateList::CandidateList() {}

void CandidateList::addCandidate(const CandidateType& addCan)
{
	candidates.push_back(addCan);
}

int CandidateList::getWinner() const
{
	auto iter = ++candidates.cbegin();
	auto itEnd = candidates.cend();
	auto winner = candidates.cbegin();

	while (iter != itEnd)
	{
		if (iter->getTotalVotes() >
			winner->getTotalVotes())
		{
			winner = iter;
		}
		++iter;
	}
	return winner->getID();
}

bool CandidateList::isEmpty() const
{
	return (candidates.empty());
}

bool CandidateList::searchCandidate(int numID) const
{
	auto iter = candidates.cbegin();
	return searchCandidate(numID, iter);
}

void CandidateList::printCandidateName(int ID) const
{
	auto iter = candidates.cbegin();
	if (searchCandidate(ID, iter))
		iter->printName();
}

void CandidateList::printAllCandidates() const
{
	auto iter = candidates.cbegin();
	auto itEnd = candidates.cend();
	while (iter != itEnd)
	{
		iter->printCandidateInfo();
		cout << endl;
		++iter;
	}
}

void CandidateList::printKingdomVotes(int ID, int index) const
{
	auto iter = candidates.cbegin();
	if (searchCandidate(ID, iter))
	{
		cout << setw(5) << right << "*" << setw(3)
			<< iter->getVotesByKingdom(index)
			<< "( => )" << KINGDOMS[index] << endl;
	}
}

void CandidateList::printCandidateTotalVotes(int ID) const
{
	auto iter = candidates.cbegin();
	if (searchCandidate(ID, iter))
	{
		cout << setw(6) << right << "=>" << " Total votes: "
			<< iter->getTotalVotes() << endl;
	}
}

void CandidateList::printFinalResults() const
{
	auto iter = ++candidates.cbegin();
	auto itEnd = candidates.cend();
	auto highest = candidates.cbegin();

	printHeader();
	
	while (iter != itEnd)
	{
		if (iter->getTotalVotes()
			> highest->getTotalVotes())
		{
			highest = iter;
		}
		++iter;
	}
	
	int	mostVotes = highest->getTotalVotes() + 1;

	for (int pos = 1; pos <= static_cast<int>(candidates.size()); 
		++pos)
	{
		highest = candidates.cbegin();
		iter = ++candidates.cbegin();

		while (iter != itEnd)
		{
			//avoid highest > mostVotes at the start
			if (highest->getTotalVotes()
				>= mostVotes)
				highest = ++highest;
			else if (highest->getTotalVotes()
				< iter->getTotalVotes() &&
				iter->getTotalVotes()
				< mostVotes)
				highest = iter;
			++iter;

			// if highest = 88 and mostVotes = 89, exit while loop
			if (highest->getTotalVotes() == mostVotes - 1)
				iter = itEnd;
		}

		printCandidate(highest, pos);

		if (pos % 5 == 0)
			cout << string(39, '-') << endl;
	
		mostVotes = highest->getTotalVotes();
	}
	cout << string(39, '_') << endl;
}

/*********************************************
* FUNCTION ADDED FOR SELECTION #6
*********************************************/
void CandidateList::printAvgVotesPerKingdom() const
{
	cout << string(6, '*') << " AVERAGE VOTES PER KINGDOM "
		<< string(6, '*') << "\n\n";
	cout << setw(20) << left << "KINGDOM" << setw(10) << "AVERAGE"
		<< "KINGDOM\n";
	cout << setw(20) << left << "NAME" << setw(16) << "VOTES"
		<< "#\n";
	cout << string(39, '_') << "\n\n";

	for (int index = 0; index < NUM_OF_KINGDOMS; ++index)
	{
		auto iter = candidates.cbegin();
		auto itEnd = candidates.cend();
		int size = static_cast<int>(candidates.size());
		double sum = 0.0,
			average = 0.0;

		while (iter != itEnd)
		{
			sum += iter->getVotesByKingdom(index);
			++iter;
		}
		average = sum / size;

		cout << left << setw(20) << KINGDOMS[index]
			<< setw(12) << fixed << showpoint << setprecision(2)
			<< average << setw(4) << "" << setw(2)
			<< index + 1 << endl;
		cout << string(39, '-') << endl;
	}
}

CandidateList::~CandidateList() {}

bool CandidateList::searchCandidate
(int numID,	list<CandidateType>::const_iterator& iter) const
{
	iter = find(iter, candidates.cend(), numID);

	if (iter != candidates.cend() &&
		iter->getID() == numID)
		return true;
	else
		cerr << "    => ID not in the list." << endl;
	return false;
}

void CandidateList::printHeader() const
{
	cout << string(12, '*') << " FINAL RESULTS "
		<< string(12, '*') << "\n\n";
	cout << setw(15) << left << "LAST" << setw(10) << "FIRST"
		<< setw(9) << "TOTAL" << "POS\n";
	cout << setw(15) << left << "NAME" << setw(10) << "NAME"
		<< setw(11) << "VOTES" << "#\n";
	cout << string(39, '_') << "\n\n";
}

void CandidateList::printCandidate
(list<CandidateType>::const_iterator iter, int rank) const
{
	cout << left << setw(15) << iter->getLastName()
		<< setw(12) << iter->getFirstName()
		<< right << setw(3) << iter->getTotalVotes()
		<< setw(5) << "" << setw(2) << rank << endl;
}
