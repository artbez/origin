#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

using std::cin;
using std::cout;

using namespace StackSpace;

int calculateByOpz(char * str)                                       
{
	const int size = 100;
	int lengthOfStr = strlen(str) - 1;
	
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

	int answer = getFirst(myStack);
	
	deleteStack(myStack);
	delete[] str;


	return answer;
}