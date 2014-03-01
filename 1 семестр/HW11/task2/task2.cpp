#include <iostream>
#include <string.h>

using std::cin;
using std::cout;
using std::getline;

bool isDigit(char ch);
bool isSign(char ch);
bool isEpsilon(char ch);
bool isDot(char ch);

enum State{
    start, integerPart, dotPart, epsilonPart, afterEpsilonPart
};

bool isFinishState(State curState);

bool isDouble(char *& str, const int size)
{
    State curState = start;
    int index = 0;
    while(index < size)
    {
        char curChar = str[index];
        switch(curState)
        {
        case start:
            if (isSign(curChar))
            {
                curState = integerPart;
                index++;
                if (!((index != size) && isDigit(str[index])))
                    return false;
            }
            else if (isDigit(curChar))
                curState = integerPart;
            else
                return false;
            break;

        case integerPart:
            if (isDigit(curChar))
                index++;
            else if (isDot(curChar))
            {
               curState = dotPart;
               index++;
               if (!((index != size) && isDigit(str[index])))
                   return false;
            }
            else if (isEpsilon(curChar))
            {
                curState = epsilonPart;
                index++;
                if (!((index != size) && (isDigit(str[index]) || isSign(str[index]))))
                    return false;
            }
            else
                return false;
            break;

        case dotPart:
            if (isDigit(curChar))
                index++;
            else if (isEpsilon(curChar))
            {
                curState = epsilonPart;
                index++;
                if (!((index != size) && (isDigit(str[index]) || isSign(str[index]))))
                    return false;
            }
            else
                return false;
            break;

        case epsilonPart:
            if (isSign(curChar))
            {
                curState = afterEpsilonPart;
                index++;
                if (!((index != size) && isDigit(str[index])))
                    return false;
            }
            else if (isDigit(curChar))
                curState = afterEpsilonPart;
            else
                return false;
            break;

        case afterEpsilonPart:
            if (isDigit(curChar))
                index++;
            else
                return false;
            break;
        }
    }

    if (isFinishState(curState))
        return true;
    return false;
}

int main()
{
    const int size = 1000;
    char * str = new char[size];
    cin.getline(str, size);

    cout << (isDouble(str, strlen(str)) ? "Yes, this is double"
                                       : "No, this is not double");
    delete[] str;
    return 0;
}

bool isDigit(char ch)
{
    return (ch >= '0' && ch <= '9');
}

bool isSign(char ch)
{
    return (ch == '+' || ch == '-');
}

bool isEpsilon(char ch)
{
    return (ch == 'E');
}

bool isDot(char ch)
{
    return (ch == '.');
}

bool isFinishState(State curState)
{
    return (curState == integerPart || curState == dotPart
            || curState == afterEpsilonPart);
}
