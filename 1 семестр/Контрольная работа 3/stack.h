namespace StackSpace
{	
	struct ListElement 
	{
		int value;
		ListElement *next;
	};

	struct Stack 
	{
		ListElement *head;
	};

	void init(Stack &l);
	void printRemotedStack(Stack &l);
	bool isEmpty(Stack &l);
	int getFirst(Stack &l);
	void printList(Stack &l);
	void add(int value, Stack &l);
	void pop(Stack &l);
	int length(Stack &l);
	void deleteStack(Stack &l);
}