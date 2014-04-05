#include <iostream>
#include "neg.h"

Neg::~Neg()
{
    delete leftChild;
    delete rightChild;
}

void Neg::print()
{
    std::cout <<"(- ";
    leftChild->print();
    std::cout << " ";
    rightChild->print();
    std::cout << ")";
}

int Neg::count()
{
    return leftChild->count() - rightChild->count();
}
