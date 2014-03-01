#include "listonarray.h"
#include <iostream>

ListOnArray::ListOnArray()
{
    mainArray = new int[MAX_LENGTH];
    currentLength = 0;
}

ListOnArray::~ListOnArray()
{
    this->deleteList();
}

void ListOnArray::printList()
{
    for (int i = 0; i < this->currentLength; ++i)
    {
        std::cout << mainArray[i] << "; ";
    }
}

int ListOnArray::length()
{
    return this->currentLength;
}

void ListOnArray::insert(int position, int value)
{
    if (currentLength == MAX_LENGTH)
    {
        std::cerr << "Error. The maximum of elements is " << MAX_LENGTH << "\n";
        this->deleteList();
        exit(0);
    }
    int * newArray = new int[MAX_LENGTH];

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
        this->deleteList();
        exit(0);
    }
    int * newArray = new int[MAX_LENGTH];
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
