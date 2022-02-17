/*
	Van, Nathan
	Bui, Catherine

	June 17, 2020

	CS A200
	Lab 1
*/

#include "Members.h"

using namespace std;

 //Definition overloaded insertion operator
ostream& operator<<(ostream& cout, const Members& member)
{
	auto it = member.members->cbegin();

	while (it != member.members->cend())
	{
		cout << it->first << ": ";

		auto setIt = it->second.cbegin();
		while (setIt != it->second.cend())
		{
			cout << *setIt << " ";
			++setIt;
		}
		++it;
		cout << endl;
	}
	return cout;
}

// Definition default constructor
Members::Members()
{
	members = new map <string, set<string>>;
	numOfMembers = 0;
}

// Definition copy constructor
Members::Members(const Members& toCopy)
{
	members = new map<string, set<string>>;
	*members = *toCopy.members;
	numOfMembers = toCopy.numOfMembers;
}

// Definition overloaded assignment operator
Members& Members::operator=(const Members& param)
{
	if (this == &param)
		cerr << "Attempted to self-assignment!";
	else
	{
		members = new map<string, set<string>>;
		*members = *param.members;
		numOfMembers = param.numOfMembers;
	}
	return *this;
}

// Definition addMember
void Members::addMember(const string& toAdd)
{
	members->insert(pair<string, set<string>>(toAdd, {}));
	++numOfMembers;
}

// Definition makeFriends
void Members::makeFriends(const string& memberOne,
	const string& memberTwo) const
{
	auto itOne = members->find(memberOne);
	itOne->second.insert(memberTwo);
	auto itTwo = members->find(memberTwo);
	itTwo->second.insert(memberOne);
}

// Definition deleteMember
void Members::deleteMember(const string& toDelete)
{
	auto it = members->begin();
	for (it; it != members->cend(); ++it)
		it->second.erase(toDelete);

	it = members->find(toDelete);
	members->erase(it);
	--numOfMembers;
}

// Definition totalMembers
int Members::totalMembers() const
{
	return numOfMembers;
}

// Definition function totalFriends
int Members::totalFriends(const string& member) const
{
	int totalFriends = static_cast<int>((members->find(member))->
		second.size());
	return totalFriends;
}

// Definition printAllMembers
void Members::printAllMembers() const
{
	for (auto i : *members)
		cout << i.first << endl;
}

// Definition printFriends
void Members::printFriends(const string& member) const
{
	cout << member << ": ";
	auto it = members->find(member);
	for (auto iterSet : it->second)
		cout << iterSet << " ";
	cout << endl;
}

// Definition deleteAllMembers
void Members::deleteAllMembers()
{
	members->erase(members->begin(), members->end());
	numOfMembers = 0;
}

// Destructor
Members::~Members()
{
	deleteAllMembers();
	delete members;
	members = nullptr;
}
