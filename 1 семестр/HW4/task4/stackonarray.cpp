#include "stackonarray.h"
#include <iostream>

StackOnArray::~StackOnArray()
{
    this->deleteStack();
}

void StackOnArray::printStack()
{
    for (int i = 0; i < this->currentLength; ++i)
    {
        std::cout << mainArray[i] << "; ";
    }
}

int StackOnArray::length()
{
    return this->currentLength;
}

void StackOnArray::push(int value)
{
    if (currentLength == MAX_LENGTH)
    {
        std::cerr << "Error. The maximum of elements is " << MAX_LENGTH << "\n";
        this->deleteStack();
        exit(0);
    }
    int * newArray = new int[MAX_LENGTH];

    newArray[0] = value;
    for (int i = 0; i < currentLength; ++i)
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

void StackOnArray::pop()
{
    if (currentLength == 0)
    {
        std::cerr << "Error. There stack is empty " << "\n";
        this->deleteStack();
        exit(0);
    }

    for (int i = 0; i < currentLength; ++i)
    {
        mainArray[i] = mainArray[i + 1];
    }

    currentLength--;
}

void StackOnArray::deleteStack()
{
    delete[] mainArray;
    currentLength = 0;
}

int StackOnArray::getFirst()
{
    if (currentLength == 0)
    {
        delete[] mainArray;
        std::cerr << "Error. The stack is empty";
        exit(0);
    }

    return mainArray[0];
}
