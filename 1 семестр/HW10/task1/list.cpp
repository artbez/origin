#include <iostream>
#include "list.h"
 
namespace ListSpace
{
	List * init()
	{
		List * list = new List();
		list->head = new ListElement();
		list->head->next = NULL;
		list->head->curTree = NULL;
	
		return list;
	}

	void addSortedList(TreeSpace::Tree * tree, List * list)
	{
		ListElement *listElement = list->head;
		while(listElement->next != NULL && listElement->next->curTree->root->value < tree->root->value)
		{
			listElement = listElement->next;
		}
		ListElement * newEl = new ListElement();
		newEl->curTree = tree;
		newEl->next = listElement->next;
		listElement->next = newEl;
	}

	TreeSpace::Tree * getFirst(List *& list)
	{
		return list->head->next->curTree;
	}

	void pop(List *& list)
	{
		ListElement * le = list->head->next;
		list->head->next = list->head->next->next;
		delete le;
	}

	void deleteAll(ListElement *& listElement)
	{
		if (listElement->next != NULL)
		{
			deleteAll(listElement->next);
			TreeSpace::deleteTree(listElement->next->curTree);
			delete listElement->next;
		}
	}

	void deleteList(List *& list)	
	{
		deleteAll(list->head);
		delete list->head->curTree;
		delete list->head;
		list->head = nullptr;
	}

	int size(List * list)
	{
		ListElement *le = list->head;
		int count = 0;
		while (le->next != NULL)
		{
			count++;
			le = le->next;	
		}
		return count;
	}
}