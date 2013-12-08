#include "pair.h"

namespace ListSpace
{	
	struct ListElement 
	{
		Pair value;
		ListElement *next;
	};

	struct List 
	{
		ListElement *head;
	};

	void init(List &l);
	void printList(const List &l);
	int length(const List &l);
	void insert(MyString &str, const List &l);
	ListElement * createElement(MyString &str);
	bool findInList(MyString &str, const List &l);
	Pair getValue(int position, const List &l);
	ListElement * getElement(int position, const List &l);
	bool isEmpty(const List &l);
	void deleteList(List &l);
}