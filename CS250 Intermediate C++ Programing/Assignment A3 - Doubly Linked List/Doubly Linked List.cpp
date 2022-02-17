/*
	Van, Nathan

	February 20, 2020

	CS A250
	Lab 3
*/

#include "DoublyList.h"

using namespace std;

// createAList
void DoublyList::createAList()
{
	/*
		NOTE:
			
			* You will need to declare one pointer and 
			  you may re-use this pointer throughout the function, but
			  you are NOT allowed to create additional pointers.

			* Pay CLOSE attention to instructions.
			
			************* IMPORTANT ****************

			*** DO NOT REMOVE EXISTING COMMENTS. ***			
	*/

	/*----------------------------------------------------------------
	SECTION 1
	------------------------------------------------------------------*/

	// Create a dynamic node that stores the value 2 and make 
	// this node be the first node of the calling object.
	// List becomes: 2
	// Use the overloaded constructor.
	// Do NOT create a pointer.
	// Your code here...

	first = new Node(2, nullptr, nullptr);
	last = first;

	// Update count;
	// Your code here...

	++count;

	cout << "SECTION 1 - TEST ALL" << endl;
	testAll();

	/*----------------------------------------------------------------
	SECTION 2
	------------------------------------------------------------------*/

	// Create another node that stores the value 3 and 
	// insert this node to the left of the node that is 
	// storing value 2.
	// List becomes: 3 2
	// Do NOT create a pointer.
	// Your code here...

	first = new Node(3, nullptr, last);
	last->setPrev(first);

	// Update count;
	// Your code here...

	++count;

	cout << "\nSECTION 2 - TEST ALL" << endl;
	testAll();

	/*----------------------------------------------------------------
	SECTION 3
	------------------------------------------------------------------*/

	// Create another node that stores the value 4 and
	// insert this node to the right of the node that is
	// storing value 3.
	// List becomes: 3 4 2
	// NO MORE than 3 statements.
	// Your code here...

	Node* newNode = new Node(4, first, last);
	first->setNext(newNode);
	last->setPrev(newNode);

	// Update count;
	// Your code here...

	++count;
	
	cout << "\nSECTION 3 - TEST ALL" << endl;
	testAll();

	/*----------------------------------------------------------------
	SECTION 4
	------------------------------------------------------------------*/

	// Delete the first node.
	// List becomes: 4 2
	// Your code here...

	newNode = first;
	first = first->getNext();
	first->setPrev(nullptr);
	delete newNode;
	newNode = nullptr;

	// Update count.
	// Your code here...

	--count;

	cout << "\nSECTION 4 - TEST ALL" << endl;
	testAll();

	/*----------------------------------------------------------------
	SECTION 5
	------------------------------------------------------------------*/

	// Insert three nodes at the end of the list storing 
	// 5 6 7 in this order.
	// List becomes: 4 2 5 6 7
	// Do NOT use the pointer you created.
	// Your code here...

	last = new Node(5, last, nullptr);
	last->getPrev()->setNext(last);
	last = new Node(6, last, nullptr);
	last->getPrev()->setNext(last);
	last = new Node(7, last, nullptr);
	last->getPrev()->setNext(last);

	// Update count.
	// One statement only.
	// Your code here...

	count += 3;

	cout << "\nSECTION 5 - TEST ALL" << endl;
	testAll();

	/*----------------------------------------------------------------
	SECTION 6
	------------------------------------------------------------------*/

	// Move last node to second position.
	// Here steps are very important. Carefully think 
	// how you can move nodes around without losing any
	// nodes and keeping all pointers pointing to the
	// correct nodes.
	// Note: 
	//		You may NOT create an additional node.
	//		NO loops are necessary.
	// List becomes: 4 7 2 5 6
	// Your code here...

	newNode = last;
	last = last->getPrev();
	last->setNext(nullptr);
	newNode->setNext(first->getNext());
	newNode->setPrev(first);
	first->setNext(newNode);
	newNode->getNext()->setPrev(newNode);

	cout << "\nSECTION 6 - TEST ALL" << endl;

	testAll();

	/*----------------------------------------------------------------
	SECTION 7
	------------------------------------------------------------------*/
	
	// Move the first node in between the node before last and
	// last node (the second node will become the first node
	// in the list, and the first node will become the before-last 
	// node in the list).
	//		You may NOT create an additional node.
	//		No loops are necessary.
	// List becomes: 7 2 5 4 6
	// Your code here...

	newNode = first;
	first = first->getNext();
	first->setPrev(nullptr);
	newNode->setNext(last);
	newNode->setPrev(last->getPrev());
	last->getPrev()->setNext(newNode);
	last->setPrev(newNode);

	cout << "\nSECTION 7 - TEST ALL" << endl;

	testAll();

	/*----------------------------------------------------------------
	SECTION 8
	------------------------------------------------------------------*/

	// WITHOUT moving any nodes, swap around the values to 
	// create an ordered list. 
	// Note that there is no need to move the value 5.
	// You may declare an int, BUT do NOT use any literals.
	// List becomes: 2 4 5 6 7
	// Your code here...

	int temp = first->getData();
	first->setData(last->getData());
	last->setData(temp);
	temp = first->getData();
	first->setData(last->getPrev()->getData());
	last->getPrev()->setData(temp);
	temp = first->getData();
	first->setData(first->getNext()->getData());
	first->getNext()->setData(temp);

	cout << "\nSECTION 8 - TEST ALL" << endl;

	testAll();

	/*----------------------------------------------------------------
	SECTION 9
	------------------------------------------------------------------*/

	// Add two nodes storing 1 and 3 to complete the ordered list.
	// List becomes: 1 2 3 4 5 6 7
	// Your code here...

	newNode = new Node(1, nullptr, first);
	first->setPrev(newNode);
	first = newNode;
	newNode = new Node(3, first->getNext(),
		first->getNext()->getNext());
	newNode->getNext()->setPrev(newNode);
	newNode->getPrev()->setNext(newNode);

	// Add 2 to count.
	// Your code here...

	count += 2;

	cout << "\nSECTION 9 - TEST ALL" << endl;
	testAll();

	/*----------------------------------------------------------------
	SECTION 10
	------------------------------------------------------------------*/

	/*
	Go back to check the following:
		Are there any sections that have more than one blank line?
		If so, do not leave unnecessary white space.
		Leave only one blank line.
	
		Are your statements too long that is necessary to scroll 
		horizontally? If so, break your statements in readable portions.
	
		Instructions said to create and use ONLY ONE pointer.
		Go back and check that you did not create more than one pointer.
	  
		Re-visit your code for efficiency.
	*/

}