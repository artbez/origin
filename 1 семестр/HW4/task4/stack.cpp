#include <iostream>
#include <cstdlib>
#include "stack.h"

namespace StackSpace
{

	void init(Stack &l)
	{
		l.head = NULL;
	}

	void printList(Stack &l)
	{
		ListElement *le = l.head;
		while (le != NULL)
		{	
			std::cout << le->value << " ";
			le = le->next; 	
		}
	}

	int getFirst(Stack &l)
	{
		return l.head->value;
	}

	void pop(Stack &l)
	{
		ListElement *crusher = l.head; 
		l.head = l.head->next;
		delete crusher;	
	}	

	bool isEmpty(Stack &l)
	{
		return (l.head == NULL);
	}
	int length(Stack &l)
	{
		ListElement *le = l.head;
		int count = 0;
		while (le != NULL)
		{
			count++;
			le = le->next;	
		}
		return count;
	}	

	ListElement * createElement(int n)
	{
		ListElement *el = new ListElement;
		el->value = n;
		el->next = NULL;
		return el;
	}	

	void add(int value, Stack &l)
	{
		ListElement *newEl = createElement(value);	
		newEl->next = l.head;
		l.head = newEl;
	}

	void removeAll(ListElement *x)
	{
		if (x != NULL) 
		{
			removeAll(x->next);
			delete x;
		}
	}	

	void deleteStack(Stack &l)
	{	
		removeAll(l.head);
		l.head = NULL;
	}
                                                                       
}
 