#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

using std::cin;
using std::cout;
using std::getline;

using namespace StackSpace;

int main()                                       
{
	const int size = 100;
	char *str = new char[size];
	cout << "Eneter an post-fix expression\n";
	cin.getline (str, size);
	int lengthOfStr = strlen(str);

	Stack myStack;
	init(myStack);

	for (int i = 0; i < lengthOfStr; ++i)
	{
		while(str[i] == ' ')
		{
				i++;
		}

		if (str[i] >= '0' && str[i] <= '9')
		{

			char *constructor = new char[size];
			int indexOfC = 0;
			while((str[i] >= '0') && (str[i] <= '9'))
			{
				constructor[indexOfC] = str[i];
				indexOfC++;
				i++;
			}
			i--;
		
			add(atoi(constructor), myStack);
				
			delete[] constructor;	
		}

		else
		{
			if (!isEmpty(myStack))
			{
				int first = getFirst(myStack);
				pop(myStack);
				
				if (!isEmpty(myStack))
				{
					int second = 0;
					second = getFirst(myStack);
					pop(myStack);			

					switch(str[i])
					{
						case '*': 
						{
							add(first * second, myStack); 
							break;
						}
						case '/':
						{
							if (second == 0)
							{
								cout << "We cannot divivde by 0\n";
								return 0;
							}
							else
							{
								add(second / first, myStack);
							}
							break;
						}
						case '+':
						{
							add(first + second, myStack);
   		     		        break;
             		   	}
             	 	    case '-':
              	 	    {
               		 		add(second - first, myStack);
               		 		break;
                	  	}
        			}
				}
				else
				{
					if (str[i] == '-')
					{
					    add(-first, myStack);
					}
				}
			}
		}		
	}

	cout << getFirst(myStack);
	deleteStack(myStack);
	delete[] str;

	return 0;
}