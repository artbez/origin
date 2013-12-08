#include <iostream>
#include "stack.h"

using std::cout;
using std::cin;
using std::endl;
using namespace StackSpace;

int main()
{
	int numOfV = 0;
	cout << "Enter the number of Vasya's workbooks" << endl;
	cin >> numOfV;

	Stack stackOfV;
	init(stackOfV);
	cout << "Enter the Vasya's stack\n";
	for (int i = 0; i < numOfV; ++i)
	{
		int k = 0;
		cin >> k;
		add(k, stackOfV);	
	}

	int numOfP = 0;
	cout << "Enter the number of Petya's workbooks" << endl;
	cin >> numOfP;

	Stack stackOfP;
	init(stackOfP);

	cout << "Enter the Petya's stack\n";
	for (int i = 0; i < numOfP; ++i)
	{
		int k = 0;
		cin >> k;
		add(k, stackOfP);	
	}

	Stack result;
	init(result);
	int lengthOfResult = length(stackOfP) + length(stackOfV);
	
	for (int i = 0; i < lengthOfResult; ++i)
	{
		if ((!isEmpty(stackOfV)) && (!isEmpty(stackOfP)))
		{
			if (getFirst(stackOfV) < getFirst(stackOfP))
			{
				add(getFirst(stackOfV), result);
				pop(stackOfV);
			}
			else
			{
				add(getFirst(stackOfP), result);
				pop(stackOfP);
			}
		}
		else
		{
			if (!isEmpty(stackOfP))
			{
				add(getFirst(stackOfP), result);
				pop(stackOfP);
			}
			else
			{
				add(getFirst(stackOfV), result);
				pop(stackOfV);	
			}
		}
	}	

	cout << "The answer is ";
	printList(result);
	deleteStack(result);
	deleteStack(stackOfP);
	deleteStack(stackOfV);
	

	return 0;
}