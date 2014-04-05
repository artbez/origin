#include <iostream>
#include "dev.h"

Dev::~Dev()
{
    delete leftChild;
    delete rightChild;
}

void Dev::print()
{
    std::cout <<"(/ ";
    leftChild->print();
    std::cout << " ";
    rightChild->print();
    std::cout << ")";
}

int Dev::count()
{
    return leftChild->count() / rightChild->count();
}
