//Steven An 2015
#ifndef NODE_H
#define NODE_H

template <class T> 
class node
{
	private:
		T item;
		node* next;
		node* prev;
	public:
		T getItem() const;
		node* getNext() const;
		node* getPrev() const;
		void insertIntoNode(T item);
		void setNext(node* ptr);
		void setPrev(node* ptr);
};

template <class T> 
void node<T>::setNext(node* ptr)
{
	next = ptr;
}

template <class T> 
void node<T>::setPrev(node* ptr)
{
	prev = ptr;
}

template <class T> 
T node<T>::getItem() const
{
	return item;
}

template <class T> 
node<T>* node<T>::getNext() const
{
	return next;
}

template <class T> 
node<T>* node<T>::getPrev() const
{
	return prev;
}

template <class T> 
void node<T>::insertIntoNode(T item)
{
	this->item = item;
}


#endif