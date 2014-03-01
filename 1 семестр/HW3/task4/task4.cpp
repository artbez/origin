#include <iostream>
#include <stdlib.h>
#include "list.h"

using std::cout;
using std::cin;

using namespace ListSpace;

void addValue(ListElement * x, List &l);
    
enum UserCommand {
	quit, 
	addEl, 
	removeEl, 
	printL
};     

UserCommand toCommand(int a);

int main()
{
	List l; 
	init(l);
	bool flag = true;
	while (flag)
	{
		cout << "Enter a command \n";
		int number = 0;
		cin >> number;
		UserCommand command = quit;
		command = toCommand(number);
				
		switch (command)
		{
			case quit: 
			{
				flag = false; 
				deleteList(l);
				break;
			}
			case addEl: 
			{
				int value = 0;
				cout << "Enter a number to add\n";
				cin >> value;
				addSortedValue(createElement(value), l);
				break;
			}
			case removeEl:
			{
				int value = 0;
				cout << "Enter a number to remove\n";
				cin >> value;
				deleteElement(value, l);
				break;
			}
			case printL:
			{
				printList(l);
				cout << "\n";
			}
		}  	
		   	
	}
	return 0;
}

UserCommand toCommand(int a)
{
	switch (a)
	{
		case 0: return quit;
		case 1: return addEl;
		case 2: return removeEl;
		case 3: return printL;
	}
}


