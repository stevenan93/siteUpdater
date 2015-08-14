//Steven An 2015
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "node.h"


template <class T> 
class linkedList
{
	private:
		node<T>* head;
		node<T>* tail;
		int numItems;
	public:
		node<T>* getHead() const;
		void insertIntoList(T item);
		int getNumItems() const;
		linkedList(); //c_tor
		~linkedList(); //d_tor
		T getItemAtIndex(int index) const;
};

template <class T> 
linkedList<T>::linkedList()
{
	head = new node<T>;
	tail = new node<T>;
	head->setNext(tail); 
	tail->setPrev(head); //head-> <-tail

	head->setPrev(NULL);
	tail->setNext(NULL); //NULL<-head-> <-tail->NULL
	numItems = 0;
}

template <class T> 
linkedList<T>::~linkedList()
{
	node<T> *curPtr = head->getNext();
	node<T> *temp;
	while(curPtr)
	{
		temp = curPtr->getNext();
		delete curPtr;
		curPtr = temp;
	}
	delete head;
	numItems = 0;
}

template <class T> 
T linkedList<T>::getItemAtIndex(int index) const
{
	node<T>* curPtr = head->getNext();
	if(index < 0 || index > numItems)
	{
		return 0;
	}
	else
	{
		for(int i = 0; i < index; i++)
		{
			curPtr = curPtr->getNext();
		}
		return curPtr->getItem();
	}
}


template <class T> 
int linkedList<T>::getNumItems() const
{
	return numItems;
}

template <class T> 
void linkedList<T>::insertIntoList(T item)
{
	node<T>* newNode = new node<T>;
	newNode->insertIntoNode(item);

	node<T>* temp = new node<T>;
	temp = tail->getPrev();

	tail->setPrev(newNode);

	newNode->setNext(tail);
	newNode->setPrev(temp);
	temp->setNext(newNode);
	++numItems;
}



#endif