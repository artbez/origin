#include <iostream>
#include "list.h"

using std::cin;
using std::cout;

using namespace ListSpace;

int main()
{
	int number = 0;
	int unlucker = 0;

	cout << "Enter 2 numbers \n";
	cin >> number;
	cin >> unlucker;
	List l;
	init(l);

	for (int i = 0; i < number; ++i)
	{
		insert(createElement(i + 1), i, l);
	}

	toCyclicList(l);

	int count = -1;
	int repeat = number - 1;
	for (int i = 0; i < repeat; ++i)
	{
		count = (count + unlucker) % number;
		pop(count, l);
		number--;
		count--;

		for (int j = 0; j < number; ++j)
		{
			cout << getValue(j, l) << " ";
		}

		cout << "\n";
	}
	cout << "The answer is " << l.head->next->value; 
	    
	deleteCyclicList(l, 1);

	return 0;
}