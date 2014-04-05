#include <iostream>
#include "sum.h"

Sum::~Sum()
{
    delete leftChild;
    delete rightChild;
}

void Sum::print()
{
    std::cout <<"(+ ";
    leftChild->print();
    std::cout << " ";
    rightChild->print();
    std::cout << ")";
}

int Sum::count()
{
    return leftChild->count() + rightChild->count();
}
