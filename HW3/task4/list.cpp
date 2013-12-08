#include <iostream>
#include <cstdlib>
#include "list.h"

namespace ListSpace
{

	void init(List &l)
	{
		ListElement * le = new ListElement;
		le->value = -1;
		le->next = NULL;
		l.head = le;
	}

	void printList(List &l)
	{
		ListElement *le = l.head;
		while (le->next != NULL)
		{	
			std::cout << le->next->value << " ";
			le = le->next; 	
		}
	}

	int length(List &l)
	{
		ListElement *le = l.head;
		int count = 0;
		while (le->next != NULL)
		{
			count++;
			le = le->next;	
		}
		return count;
	}	

	void insert(ListElement *le, int position, List &l)
	{
		ListElement *newEl = l.head;
		while ((position > 0) && (newEl != NULL))
		{
			position--;
			newEl = newEl->next;
		}

		le->next = newEl->next;
		newEl->next = le;
	}

	ListElement * createElement(int n)
	{
		ListElement *el = new ListElement;
		el->value = n;
		el->next = NULL;
		return el;
	}	

	int locate(ListElement *x, List &l)
	{
		ListElement *el = l.head;
		int count = 0;
		while (el->next != NULL)
		{
			if (x->value == el->next->value)
			{
				return count; 
			} 
			el = el->next;
			count++;
		}
		return -1;		
	}

	int getValue(int position, List &l)
	{
		ListElement *el = l.head;
		while ((el->next != NULL) && (position > 0))
		{
			el = el->next;
			position--;		
		}
		return el->next->value;
	}

	ListElement * getElement (int position, List &l)
	{
		ListElement *el = l.head;
		while ((el->next != NULL) && (position > 0))
		{
			el = el->next;
			position--;		
		}
		return el->next;	
	}	

	void deleteElement(int value, List &l)
	{
		ListElement *el = l.head;
		while (el->next != NULL)
		{
			if (el->next->value == value)
			{
				ListElement *crusher = el->next; 
				el->next = el->next->next;
				delete crusher;	
				return ;
			}		
			el = el->next;
		}
	}	

	void pop(int position, List &l)
	{
		ListElement *el = l.head;
		while ((el->next != NULL) && (position > 0))
		{
			el = el->next;
			position--;		
		}

		ListElement *crusher = el->next; 
		el->next = el->next->next;
		delete crusher;	
	}	

	void removeAll(ListElement *x)
	{
		if (x != NULL) 
		{
			removeAll(x->next);
			delete x;
		}
	}	

	void deleteList(List &l)
	{	
		removeAll(l.head);
		l.head = NULL;
	}

	void addSortedValue(ListElement * x, List &l)
	{
		ListElement * el = l.head;
		while ((el->next != NULL) && (x->value > el->next->value))
		{
			el = el->next;
		}

		x->next = el->next;
		el->next = x;
	}

	void toCyclicList(List &l)
	{
		ListElement * le = getElement(length(l) - 1, l);
		le->next = l.head->next;
	}
	
	void removeAllInCyclicList(ListElement *x, int number)
	{
		if ((x != NULL) && (number >= 0)) 
		{
			removeAllInCyclicList(x->next, number - 1);
			x->next = NULL;
			delete x;
		}
	}	

	void deleteCyclicList(List &l, int size)
	{	
		removeAllInCyclicList(l.head, size);
		l.head = NULL;
	}


                                                                       
}
 