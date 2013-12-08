#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

using std::cin;
using std::cout;

using namespace StackSpace;

void addChar(int ch, char * answer, int &mainIndex);

char *toOpz(char * str)
{
	int lengthOfStr = strlen(str);                             
	Stack myStack;
	init(myStack);

	char *answer = new char[10 * lengthOfStr];
	int mainIndex = 0;

	for (int i = 0; i < lengthOfStr; ++i)
	{
		switch(str[i])
		{
			case '*':
			case '/':
			{
				while((!isEmpty(myStack)) &&  ((getFirst(myStack) == '*') || (getFirst(myStack) == '/')))
				{
					addChar(getFirst(myStack), answer, mainIndex);
					pop(myStack);
				}
				   
				add(str[i], myStack);
				break;
			}
			case '(':
			{
				add(str[i], myStack);
				break;
			}
			case '+':
			case '-':
			{
				while((!isEmpty(myStack)) && (getFirst(myStack) != '('))
				{
					addChar(getFirst(myStack), answer, mainIndex);
					pop(myStack);
				}
				   
				add(str[i], myStack);
				break;
			}                                     
			case ')':
			{
				while(!isEmpty(myStack) && (getFirst(myStack) != '('))
				{
					addChar(getFirst(myStack), answer, mainIndex);
					pop(myStack);
				}
				
				if (!isEmpty(myStack))
				{
					pop(myStack);
				}
				else
				{
					cout << "Error!!!\n";
					return 0;
				}
				break;
			}
			default:
			{
				if (str[i] == ' ')
				{
					break;
				}
				while((str[i] <= '9') && (str[i] >= '0'))
				{
					answer[mainIndex] = str[i];
					mainIndex++;
					i++;
				}
				answer[mainIndex] = ' ';
				mainIndex++;
				i--;
			}
		}	
	}

	const int sizeOfStack = length(myStack);
	for (int i = 0; i < sizeOfStack; ++i)
	{
		if ((char) getFirst(myStack) == '(')
		{
			cout << "Error";
			return 0;
		}
		
		addChar(getFirst(myStack), answer, mainIndex);
		pop(myStack);
	}

	answer[mainIndex] = '\0';
	 
	deleteStack(myStack);
	delete[] str;

	return answer;
}

void addChar(int ch, char * answer, int &mainIndex)
{
	answer[mainIndex] = (char) ch;
	mainIndex++;
	answer[mainIndex] = ' ';
	mainIndex++;
}