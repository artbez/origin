#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "linkedstack.h"

using std::cin;
using std::cout;

int calculateByOpz(char * str)
{
    const int size = 100;
    int lengthOfStr = strlen(str) - 1;

    LinkedStack * myStack = new LinkedStack();

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

            myStack->push(atoi(constructor));

            delete[] constructor;
        }

        else
        {
            if (myStack->length() != 0)
            {
                int first = myStack->getFirst();
                myStack->pop();

                if (myStack->length() != 0)
                {
                    int second = 0;
                    second = myStack->getFirst();
                    myStack->pop();

                    switch(str[i])
                    {
                        case '*':
                        {
                            myStack->push(first * second);
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
                                myStack->push(second / first);
                            }
                            break;
                        }
                        case '+':
                        {
                            myStack->push(first + second);
                            break;
                        }
                        case '-':
                        {
                            myStack->push(second - first);
                            break;
                        }
                    }
                }
                else
                {
                    if (str[i] == '-')
                    {
                        myStack->push(-first);
                    }
                }
            }
        }
    }

    int answer = myStack->getFirst();

    myStack->deleteStack();
    delete[] str;


    return answer;
}
