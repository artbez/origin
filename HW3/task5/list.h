namespace ListSpace
{	
	struct ListElement 
	{
		int value;
		ListElement *next;
	};

	struct List 
	{
		ListElement *head;
	};

	void init(List &l);
	void printList(List &l);
	int length(List &l);
	void insert(ListElement *le, int position, List &l);
	ListElement * createElement(int n);
	int locate(ListElement *x, List &l);
	int getValue(int position, List &l);
	ListElement * getElement(int position, List &l);
	void deleteElement(int value, List &l);
	void pop(int position, List &l);
	void deleteList(List &l);
	void addSortedValue(ListElement *le, List &l);
	void deleteCyclicList(List &l, int size);
	void toCyclicList(List &l);
}