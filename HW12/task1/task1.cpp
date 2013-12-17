#include <iostream>
#include <string.h>
#include "myDouble.h"

using std::cin;
using std::cout;

bool initial(int &indexOfStr, char *& str, const int length); // initial -> preMul sum
bool preMul(int &indexOfStr, char *& str, const int length); // preMul -> preBrack mul
bool sum(int &indexOfStr, char *& str, const int length); // sum -> (+|-) preMul sum | eps
bool mul(int &indexOfStr, char *& str, const int length); // mul -> (*|/) preBrack mul | eps
bool preBrack(int &indexOfStr, char *& str, const int length); // preBrack -> (initial) | eps
bool isNum(int &indexOfStr, char *& str, const int length); // is this a number

int main()
{
    const int size = 1000;
    char * str = new char[size];
    cin >> str;
    int index = 0;
    const int length = strlen(str);
    cout << (((initial(index, str, length)) && (index == length)) ? "This is correct"
                                                                 : "This is not correct");
    delete[] str;
    return 0;
}

bool initial(int &indexOfStr, char *& str, const int length)
{
    if (indexOfStr == length)
        return true;
    return (preMul(indexOfStr, str, length) * sum(indexOfStr, str, length));
}

bool preMul(int &indexOfStr, char *& str, const int length)
{
    if (indexOfStr == length)
        return true;
    return (preBrack(indexOfStr, str, length) * mul(indexOfStr, str, length));
}

bool sum(int &indexOfStr, char *& str, const int length)
{
    if (indexOfStr == length)
        return true;
    int curIndex = indexOfStr;
    if ((str[indexOfStr] == '+') || (str[indexOfStr] == '-'))
    {
        indexOfStr++;
        return (preMul(indexOfStr, str, length) * sum(indexOfStr, str, length));
    }
    indexOfStr = curIndex;
    return true;
}

bool mul(int &indexOfStr, char *& str, const int length)
{
    if (indexOfStr == length)
        return true;
    int curIndex = indexOfStr;
    if ((str[indexOfStr] == '*') || (str[indexOfStr] == '/'))
    {
        indexOfStr++;
        return (preBrack(indexOfStr, str, length) * mul(indexOfStr, str, length));
    }
    indexOfStr = curIndex;
    return true;
}

bool preBrack(int &indexOfStr, char *& str, const int length)
{
    int curIndex = indexOfStr;
    if ((str[indexOfStr] == '(') && (initial(++indexOfStr, str, length) && str[indexOfStr] == ')'))
    {
        indexOfStr++;
        return true;
    }
    indexOfStr = curIndex;
    if (isNum(indexOfStr, str, length))
        return true;
    indexOfStr = curIndex;
    return false;
}

bool isNum(int &indexOfStr, char *& str, const int length)
{
    return (isDouble(str, length, indexOfStr));
}
