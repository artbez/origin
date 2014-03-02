#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "toOpz.h"

using std::cin;
using std::cout;

void addChar(int ch, char * answer, int &mainIndex);

char *toOpz(char * str)
{
    int lengthOfStr = strlen(str);
    LinkedStack * myStack = new LinkedStack();

    char *answer = new char[10 * lengthOfStr];
    int mainIndex = 0;

    for (int i = 0; i < lengthOfStr; ++i)
    {
        switch(str[i])
        {
            case '*':
            case '/':
            {
            while((myStack->length() != 0) &&  ((myStack->getFirst() == '*') || (myStack->getFirst() == '/')))
                {
                    addChar(myStack->getFirst(), answer, mainIndex);
                    myStack->pop();
                }

                myStack->push(str[i]);
                break;
            }
            case '(':
            {
                myStack->push(str[i]);
                break;
            }
            case '+':
            case '-':
            {
                while((myStack->length() != 0) && (myStack->getFirst() != '('))
                {
                    addChar(myStack->getFirst(), answer, mainIndex);
                    myStack->pop();
                }

                myStack->push(str[i]);
                break;
            }
            case ')':
            {
                while(myStack->length() != 0 && (myStack->getFirst() != '('))
                {
                    addChar(myStack->getFirst(), answer, mainIndex);
                    myStack->pop();
                }

                if (myStack->length() != 0)
                {
                    myStack->pop();
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

    const int sizeOfStack = myStack->length();
    for (int i = 0; i < sizeOfStack; ++i)
    {
        if ((char) myStack->getFirst() == '(')
        {
            cout << "Error";
            return 0;
        }

        addChar(myStack->getFirst(), answer, mainIndex);
        myStack->pop();
    }

    answer[mainIndex] = '\0';

    myStack->deleteStack();
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
