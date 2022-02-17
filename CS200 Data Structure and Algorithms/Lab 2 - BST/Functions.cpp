/*
	Van, Nathan
	Bui, Catherine
	Faludi, Scott
	Kim, Lisa

	July 01, 2020

	CS A200
	Lab 2
*/

#include "BST.h"

Node* findMin(Node* rt)
{
	while (rt->llink != nullptr)
		rt = rt->llink;
	return rt;
}

void caseOne(Node* &rt)
{
	delete rt;
	rt = nullptr;
}

void caseTwoRight(Node* &rt)
{
	Node* temp = rt;
	rt = rt->rlink;
	delete temp;
}

void caseTwoLeft(Node* &rt)
{
	Node* temp = rt;
	rt = rt->llink;
	delete temp;
}

 Node* BST::deleteElement(Node* &rt, int data)
{
	if (totalNodes == 0)
		cerr << "Cannot delete from an empty tree.";
	else if (rt == nullptr)
	{
		cerr << "The element to delete is not in the tree.";
		return rt;
	}
	else if (data > rt->data)
		rt->rlink = deleteElement(rt->rlink, data);
	else if (data < rt->data)
		rt->llink = deleteElement(rt->llink, data);
	else {
		//Case 1: No child
		if (rt->llink == nullptr &&
			rt->rlink == nullptr)
		{
			caseOne(rt);
			--totalNodes;
		}
		//Case 2: One child
		//    Right Subtree
		else if (rt->llink == nullptr)
		{
			caseTwoRight(rt);
			--totalNodes;
		}
		//    Left Subtree
		else if (rt->rlink == nullptr)
		{
			caseTwoLeft(rt);
			--totalNodes;
		}
			//Case 3: Two children
		else
		{
			Node* temp = findMin(rt->rlink);
			rt->data = temp->data;
			rt->rlink = deleteElement(rt->rlink, 
				temp->data);
		}
	}
	return rt;
}

void BST::deleteElem(int data)
{ 
	deleteElement(root, data);
}
