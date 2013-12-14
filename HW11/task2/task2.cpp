#include <iostream>
#include <string.h>

using std::cin;
using std::cout;
using std::getline;

bool isDigit(char ch);
bool isSign(char ch);
bool isEpsilon(char ch);
bool isDot(char ch);

enum state{
    Start, IntegerPart, DotPart, EpsilonPart, AfterEpsilonPart
};

bool isFinishState(state curState);

bool isDouble(char *& str, const int size)
{
    state curState = Start;
    int index = 0;
    while(index < size)
    {
        char curChar = str[index];
        switch(curState)
        {
        case Start:
            if (isSign(curChar))
            {
                curState = IntegerPart;
                index++;
                if (!((index != size) && isDigit(str[index])))
                    return false;
            }
            else if (isDigit(curChar))
                curState = IntegerPart;
            else
                return false;
            break;

        case IntegerPart:
            if (isDigit(curChar))
                index++;
            else if (isDot(curChar))
            {
               curState = DotPart;
               index++;
               if (!((index != size) && isDigit(str[index])))
                   return false;
            }
            else if (isEpsilon(curChar))
            {
                curState = EpsilonPart;
                index++;
                if (!((index != size) && (isDigit(str[index]) || isSign(str[index]))))
                    return false;
            }
            else
                return false;
            break;

        case DotPart:
            if (isDigit(curChar))
                index++;
            else if (isEpsilon(curChar))
            {
                curState = EpsilonPart;
                index++;
                if (!((index != size) && (isDigit(str[index]) || isSign(str[index]))))
                    return false;
            }
            else
                return false;
            break;

        case EpsilonPart:
            if (isSign(curChar))
            {
                curState = AfterEpsilonPart;
                index++;
                if (!((index != size) && isDigit(str[index])))
                    return false;
            }
            else if (isDigit(curChar))
                curState = AfterEpsilonPart;
            else
                return false;
            break;

        case AfterEpsilonPart:
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

bool isFinishState(state curState)
{
    return (curState == IntegerPart || curState == DotPart
            || curState == AfterEpsilonPart);
}
