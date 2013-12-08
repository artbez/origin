#include <iostream>
#include "stack.h"

using std::cout;
using std::cin;

using namespace StackSpace;

int main()
{
	const int size = 100;
	char *str = new char[100];
	cin >> str;

	Stack st;
	init(st);

	
	bool flag = true;

	for (int i = 0; i < size; ++i)
	{
		switch (str[i])
		{
			case '}': 
			{
				if ((!isEmpty(st)) && (getFirst(st) == '{'))
				{
					pop(st);	
				}
				else
				{
					flag = false;
				}
				break;
			}
			
			case ']': 
			{
				if ((!isEmpty(st)) && (getFirst(st) == '['))
				{
					pop(st);	
				}
				else
				{
					flag = false;
				}

				break;
			}
			
			case ')': 
			{
				if ((!isEmpty(st)) && (getFirst(st) == '('))
				{
					pop(st);	
				}
				else
				{
					flag = false;
				}

				break;
			}
			
			case '(':
			{
				add('(', st);
				break;
			}
		
			case '{':
			{
				add('{', st);
				break;
			}

			case '[':
			{
				add('[', st);
				break;
			}

		}	
	}

	if ((isEmpty(st)) && (flag))
	{
		cout << "It's correct";
	}
	else
	{
		cout << "It's not correct";
		deleteStack(st);
	}
	delete[] str;
	
	return 0;
}
