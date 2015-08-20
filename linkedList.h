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
		linkedList(); //c_tor
		~linkedList(); //d_tor
		node<T>* getHead() const;
		T getItemAtIndex(int index) const;
		void insertIntoList(T item);
		int getNumItems() const;
		void removeFromList(int begin); //single line
		void removeFromList(int begin, int end); //inclusive 
		bool inRange(int i) const;
		void insertAtIndex(T item, int pos);
		void overwrite(T item, int pos);
		node<T>* findNode(int pos) const;
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
node<T>* linkedList<T>::getHead() const
{
	return head;
}

template <class T> 
T linkedList<T>::getItemAtIndex(int index) const
{
	node<T>* curPtr = findNode(index);
	if(curPtr)
	{
		return curPtr->getItem();
	}
	return 0;
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

template <class T> 
int linkedList<T>::getNumItems() const
{
	return numItems;
}

template <class T>
void linkedList<T>::removeFromList(int begin)
{
	if(inRange(begin))
	{
		node<T>* curPtr = head;
		node<T>* tempPtr;
		for(int i = 0; i < begin; i++)
		{
			curPtr = curPtr->getNext();
		}
		curPtr->getPrev()->setNext(curPtr->getNext());
		curPtr->getNext()->setPrev(curPtr->getPrev());
		delete curPtr;
		--numItems;
	}
}

template <class T>
void linkedList<T>::removeFromList(int begin, int end)
{
	node<T>* curPtrBegin = head;
	node<T>* curPtrEnd = tail->getPrev();

	curPtrBegin = findNode(begin);
	curPtrEnd = findNode(end);

	if(curPtrBegin && curPtrEnd)
	{
		curPtrBegin->getPrev()->setNext(curPtrEnd->getNext());
		curPtrEnd->getNext()->setPrev(curPtrBegin->getPrev());

		node<T>* curPtr = curPtrBegin;
		node<T>* tempPtr;
		while(curPtr != curPtrEnd->getNext())
		{
			tempPtr = curPtr->getNext();
			delete curPtr;
			curPtr = tempPtr;
			--numItems;
		}
	}

}

template <class T>
void linkedList<T>::insertAtIndex(T item, int pos)
{

		node<T>* curPtr = findNode(pos);
		if(curPtr)
		{
			node<T>* newNode = new node<T>;
			newNode->insertIntoNode(item);
			node<T>* prevNode = curPtr->getPrev();
			prevNode->setNext(newNode);
			newNode->setPrev(prevNode);
			newNode->setNext(curPtr);
			curPtr->setPrev(newNode);
			++numItems;
		}
	
}

template <class T>
bool linkedList<T>::inRange(int i) const
{
	return i > 0 && i <= numItems;
}

template <class T>
void linkedList<T>::overwrite(T item, int pos)
{
	node<T>* curPtr = findNode(pos);
	if(curPtr)
	{
		curPtr->setItem(item);
	}
}

template <class T>
node<T>* linkedList<T>::findNode(int pos) const
{
	if(inRange(pos))
	{
		node<T>* curPtr = head;
		for(int i = 0; i < pos; i++)
		{
			curPtr = curPtr->getNext();
		}
		return curPtr;
	}
	return NULL;
}



#endif