#include "listonarray.h"
#include <iostream>

ListOnArray::~ListOnArray()
{
    deleteList();
}

void ListOnArray::printList()
{
    for (int i = 0; i < currentLength; ++i)
    {
        std::cout << mainArray[i] << "; ";
    }
}

int ListOnArray::length()
{
    return currentLength;
}

void ListOnArray::insert(int position, int value)
{
    if (currentLength == maxLength)
    {
        std::cerr << "Error. The maximum of elements is " << maxLength << "\n";
        deleteList();
        exit(0);
    }
    int * newArray = new int[maxLength];

    for (int i = 0; i < position; ++i)
    {
        newArray[i] = mainArray[i];
    }

    newArray[position] = value;
    for (int i = position; i < currentLength; ++i)
    {
        newArray[i + 1] = mainArray[i];
    }
    currentLength++;

    for (int i = 0; i < currentLength; ++i)
    {
        mainArray[i] = newArray[i];
    }

    delete[] newArray;
}

void ListOnArray::deleteElement(int position)
{
    if (currentLength <= position)
    {
        std::cerr << "Error. There is no element with this index " << "\n";
        deleteList();
        exit(0);
    }
    int * newArray = new int[maxLength];
    for (int i = 0; i < position; ++i)
    {
        newArray[i] = mainArray[i];
    }
    for (int i = position + 1; i < currentLength; ++i)
    {
        newArray[i - 1] = mainArray[i];
    }
    currentLength--;

    for (int i = 0; i < currentLength; ++i)
    {
        mainArray[i] = newArray[i];
    }

    delete[] newArray;
}

void ListOnArray::deleteList()
{
    delete[] mainArray;
    currentLength = 0;
}

int ListOnArray::get(int index)
{
    if (index >= length())
    {
        std::cerr << "Error. The index is no element with this index";
        deleteList();
        exit(0);
    }

    return mainArray[index];
}
