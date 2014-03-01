#include "tree.h"

namespace ListSpace
{
	struct ListElement
	{
		TreeSpace::Tree * curTree;
		ListElement * next;
	};
	struct List
	{
		ListElement * head;
	};

	List * init();
	void addSortedList(TreeSpace::Tree * tree, List * list);
	TreeSpace::Tree * getFirst(List *& list);
	void pop(List *& list);
	void deleteList(List *& list);
	int size(List * list);
}