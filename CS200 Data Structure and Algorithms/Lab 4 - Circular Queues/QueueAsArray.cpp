/*
	Bui, Catherine
	Van, Nathan
	Faludi, Scott

	July 21, 2020

	CS A200
	Lab 4
*/

#include "QueueAsArray.h"

// Definition default constructor
QueueAsArray::QueueAsArray()
{
	maxQueueSize = MAX_SIZE;
	queueArray = new int[maxQueueSize];
	queueFront = 0;
	queueBack = 0;
}

// Definition overloaded constructor
QueueAsArray::QueueAsArray(int capacity)
{
	maxQueueSize = capacity;
	queueArray = new int[maxQueueSize];
	queueFront = 0;
	queueBack = 0;
}

// Definition function isEmpty
bool QueueAsArray::isEmpty() const
{
	return (queueFront == queueBack);
}

// Definition function isFull
bool QueueAsArray::isFull() const
{
	return (queueBack == queueFront - 1);
}

// Definition function front
int QueueAsArray::front() const
{
	if (queueFront == queueBack)
	{
		cerr << "Queue is empty.";
		return -999;
	}
	else
		return queueArray[queueFront];
}

// Definition function back
int QueueAsArray::back() const
{
	if (queueFront == queueBack)
	{
		cerr << "Queue is empty.";
		return -999;
	}
	else
		return queueArray[queueBack];
}

// Definition function enqueue
void QueueAsArray::enqueue(int element)
{

	if (queueBack == queueFront - 1)
		cerr << "Cannot add to a full queue.\n";
	else
	{
		queueArray[queueBack] = element;
		queueBack = (queueBack + 1) % maxQueueSize;
		queueArray[queueBack] = element;
	}
}

// Definition function dequeue
void QueueAsArray::dequeue()
{
	bool empty = isEmpty();
	if (empty)
		cerr << "Cannot remove from an empty queue.";
	else
		queueFront = (queueFront + 1) % maxQueueSize;
}

// Declaration function size
int QueueAsArray::size() const
{
	return (maxQueueSize - queueFront + queueBack) % maxQueueSize;
}

// Definition function clear
void QueueAsArray::clear()
{
	queueFront = 0;
	queueBack = queueFront;
}

// Definition destructor
QueueAsArray::~QueueAsArray()
{
	delete[] queueArray;
}
