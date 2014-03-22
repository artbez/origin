#include "hashfunction.h"

HashFunction::HashFunction(int number, int size)
{
    this->number = number;
    this->size = size;
}

int HashFunction::hash(const QString &qStr)
{
    int value = 0;
    const int lengthOfString = qStr.length();
    const int prime = 317;
    switch(number)
    {
    case 0:
    {
        for (int i = 0; i < lengthOfString; ++i)
            value = (value + qStr[i].toLatin1()) % size;
        break;
    }
    case 1:
    {
        for (int i = 0; i < qStr.length(); i++)
            value = (value * prime  + qStr[i].toLatin1()) % size;
        break;
    }
    }
    return value;
}
