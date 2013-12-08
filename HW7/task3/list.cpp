#include <iostream>
#include <cstdlib>
#include "list.h"

namespace ListSpace
{
	void init(List &l)
	{
		ListElement * le = new ListElement;
		Pair p;
		p.str = initMyString();
		p.number = 0;
		le->value = p;
		le->next = NULL;
		l.head = le;
	}

	void printList(const List &l)
	{
		ListElement *le = l.head;
		while (le->next != NULL)
		{	
			printPair(le->next->value);
			std::cout << " ";
			le = le->next; 	
		}
	}

	int length(const List &l)
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

	void insert(MyString &str, const List &l)
	{
		ListElement *newEl = l.head;
		while (newEl->next != NULL)
		{
			if (isStringsEqual(str, newEl->next->value.str))
			{
				newEl->next->value.number++;
				deleteMyString(str);
				return;
			}
			newEl = newEl->next;
		}
		newEl -> next = createElement(str);
	}

	ListElement * createElement(MyString &str)
	{
		ListElement *el = new ListElement;
		Pair p;
		p.number = 1;
		p.str = str;

		el->value = p;
		el->next = NULL;
		return el;
	}	

	Pair getValue(int position, const List &l)
	{
		ListElement *el = l.head;
		while ((el->next != NULL) && (position > 0))
		{
			el = el->next;
			position--;		
		}
		return el->next->value;
	}

	bool findInList(MyString &str, const List &l)
	{
		ListElement *le = l.head;
		while (le->next != NULL)
		{
			if (isEqual(le->next->value.str, str))
				return true;
			le = le->next;	
		}
		return false;
	}

	bool isEmpty(const List &l)
	{
		return (l.head->next == NULL);
	}

	ListElement * getElement (int position, const List &l)
	{
		ListElement *el = l.head;
		while ((el->next != NULL) && (position > 0))
		{
			el = el->next;
			position--;		
		}
		return el->next;	
	}		

	void removeAll(ListElement *x)
	{
		if (x != NULL) 
		{
			removeAll(x->next);
			deletePair(x->value);
			delete x;
		}
	}	

	void deleteList(List &l)
	{	
		removeAll(l.head);
		l.head = NULL;
	}                                                                      
}
 